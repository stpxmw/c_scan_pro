#include "stdio.h"
#include <stdlib.h>
#include <memory.h>
#include "assert.h"
#include "c_scan_common.h"

extern FILE *yyin;
extern int yyparse();
void* inital_memory = NULL;

unsigned char* first_search_location = ZERO;
unsigned char* search_location = ZERO;//we use this flag to speed up memory search
unsigned char* last_search_location = ZERO;//we use this flag to speed up memory search

Node *struct_link_list = NULL; //define the struct or enum or union list, which used for parse c.i, when finish the parse of one file, this link should be free

void assign_symbol_loc(SYMBOL_INFO_T* dest, SYMBOL_INFO_T* src)
{
   dest->no_name =  src->no_name;
   dest->column = src->column;
   dest->lineno  = src->lineno;
}

void print_params(Param_t_list *p)
{
    printf("START PRINT PARAMS --> ");
    int no = p->no_param;
    int i = 0;
    for (i = 0;i< no;i++)
    {
        printf("%s |",p->param_list[i].param_type);
    }
    printf("\n");
}

void print_symbols(SYMBOL_INFO_T* p)
{
    if ( (p NEQ NULL) && (NULL NEQ p->symbol_name))
    {
        printf("symbol name is \"%s\" \n", p->symbol_name);
    }else{
        printf("point is NULL! \n");
    }
}

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: unable to create new node\n");
        exit(1);
    }
    newNode->data = strdup(data);  // 为字符串分配空间并复制内容
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node** head, char* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


Node* findNode(Node* head, char* data) {
    Node* current = head;
    while (current != NULL && strcmp(current->data, data) != 0) {
        current = current->next;
    }
    return current;
}

void deleteNode(Node** head, char* data) {
    Node* current = *head;
    Node* previous = NULL;

    // 空链表或未找到节点
    if (current == NULL || strcmp(current->data, data) == 0) {
        return;
    }

    // 查找节点
    while (strcmp(current->data, data) != 0 && current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // 如果找到节点，则删除它
    if (strcmp(current->data, data) == 0) {
        if (previous == NULL) {  // 删除的是头节点
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current->data);  // 释放字符串内存
        free(current);        // 释放节点内存
    }
}

// 向链表中插入节点
void insertNode(Node** head, void* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}



void p_memory_init(void)
{
    unsigned char* temp_init_memory_loc = NULL;
    inital_memory = (void*)RW_MALLOC(MAX_SYMBOLS_NUM*sizeof(MEMORY_UNIT));
    if (inital_memory EQ NULL)
    {
        printf("system has no enough memory!");
        assert(0);
    }
    memset(inital_memory,ZERO,MAX_SYMBOLS_NUM*sizeof(MEMORY_UNIT));
    search_location = (unsigned char* )inital_memory;
    first_search_location = search_location;

    last_search_location = search_location + (MAX_SYMBOLS_NUM-1)*sizeof(MEMORY_UNIT);

    //we need to init all the memory block
    temp_init_memory_loc = first_search_location;
    while(temp_init_memory_loc <= last_search_location)
    {
        *((int*)temp_init_memory_loc) = MEMORY_UNUSED;
        if (temp_init_memory_loc NEQ last_search_location)
        {
            temp_init_memory_loc += MEMORY_UNIT_SIZE;
        } else{
            break;
        }
    }
    if (temp_init_memory_loc != last_search_location){
        printf("memory init error! the memory boundary is not align!");
        assert(ZERO);
    }
}

void print_item_name(char *ptr,int len)
{
    int i;
//    for(i = 0;i< len;i++){
//        printf("%d ",*ptr++);
//    }
    for(i = 0;i< len;i++){
        printf("%c",*ptr++);
    }
}

void memory_leak_check(void)
{
    unsigned char *check_mem_ptr = NULL;
    int leak_num = 0;
    check_mem_ptr = first_search_location;
    while (check_mem_ptr <= last_search_location)
    {
        if ( MEMORY_USED EQ *((int *)check_mem_ptr) )
        {
            printf("warning! memory not released! may cause mem leak! :%p",check_mem_ptr);
            printf("   line: %d str name:---|",*((int *)(check_mem_ptr + sizeof(int))));
            print_item_name(((SYMBOL_INFO_T *)(check_mem_ptr + 2*sizeof(int)))->symbol_name,((SYMBOL_INFO_T *)(check_mem_ptr + 2*sizeof(int)))->no_name);
            printf("|---");
            printf("symbol location is : line:%d, col:%d ",((SYMBOL_INFO_T *)(check_mem_ptr + 2*sizeof(int)))->lineno,((SYMBOL_INFO_T *)(check_mem_ptr + 2*sizeof(int)))->column);
            printf("\n");
            leak_num++;
        }
        check_mem_ptr += MEMORY_UNIT_SIZE;
    }
    printf("Total leak num is %d\n", leak_num);
}


void p_memory_deinit(void){
    free(inital_memory);
}

void lex_yacc_parser_init(void)
{

#ifdef FAST_MEMORY_MODE
    p_memory_init();
#endif

}

void lex_yacc_parser_deinit(void)
{

#ifdef MEMORY_LEAK_CHECK
    memory_leak_check();
#endif

#ifdef FAST_MEMORY_MODE
    p_memory_deinit();
#endif



}

/*
 * [   MEMORY_UNIT     |  MEMORY_UNIT|MEMORY_UNIT|...]
 * [0-4byte][4-8byte]ptr[8-40byte] |
 * flag |SYMBOL_INFO_T |
 */
void* pd_malloc(int line)
{
    void *find_memory_unit = NULL;
    unsigned char* temp_search_location = search_location;
    //first we try to search memory in (search_location,last_search_location)
    while(temp_search_location <= last_search_location){
        if (*((int*)temp_search_location) EQ MEMORY_UNUSED){
            //this memory unit not used
            //assign val
            *((int*)temp_search_location) = MEMORY_USED;
            *((int*)(temp_search_location + sizeof(int))) = line;
            search_location = temp_search_location;
            find_memory_unit = (unsigned char*)temp_search_location;
            break;
        }else if(*((int*)temp_search_location) EQ MEMORY_USED) {
            if (temp_search_location NEQ last_search_location)
            {
                temp_search_location += MEMORY_UNIT_SIZE;
            }else{
                break;
            }
        } else{
            assert(0);
        }
    }
    if ((NULL EQ find_memory_unit) && (temp_search_location != last_search_location)){
        printf("memory search error!");
        assert(ZERO);
    }
    // if previous search cannot found ,we try to search memory in (first_search_location,search_location)
    if (NULL EQ find_memory_unit) {
        temp_search_location = first_search_location;
        while (temp_search_location <= search_location) {
            if (*((int*)temp_search_location) EQ MEMORY_UNUSED){
                //this memory unit not used
                //assign result
                *((int*)temp_search_location) = MEMORY_USED;
                *((int*)(temp_search_location + sizeof(int))) = line;
                search_location = temp_search_location;
                find_memory_unit = (unsigned char*)temp_search_location;
                break;
            }else if(*((int*)temp_search_location) EQ MEMORY_USED){
                if (temp_search_location NEQ last_search_location)
                {
                    temp_search_location += MEMORY_UNIT_SIZE;
                }else{
                    break;
                }
            }else{
                assert(0);
            }
        }
    }
    //warp around
    if (search_location EQ last_search_location)
    {
        search_location = first_search_location;
    }

    if (NULL EQ find_memory_unit){
        printf("error! memory alloc fail!,may be you need to expand MAX_SYMBOLS_NUM");
        assert(0);
    }else {

#ifdef MEMORY_DEBUG
        printf("MEMORY_DEBUG: MALLOC ADDR %p! LINE:%d \n",find_memory_unit,line);
#endif

        find_memory_unit += 2*sizeof(int);
    }



        return find_memory_unit;
}

void* pd_free(void *ptr)
{
    void *temp_ptr = NULL;
    temp_ptr = ptr-2*sizeof(int);

    if( MEMORY_USED EQ *( (int *)(temp_ptr)) )
    {
#ifdef MEMORY_DEBUG
        printf("MEMORY_DEBUG: FREE ADDR %p  \n",temp_ptr);
#endif

    }else if(MEMORY_UNUSED EQ *( (int *)(temp_ptr))) {
#ifdef MEMORY_DEBUG
        //printf("the mem block is not in used,do not free! \n");
        if (NULL NEQ (((SYMBOL_INFO_T*)temp_ptr)->symbol_name) ){
            assert(0);
        }
        return ptr;
#endif
    }else{
        printf("the mem block is damaged! \n");
        assert(0);
    }
    //flag it to be not used and memset it to be 0
    *( (int *)(temp_ptr)) = MEMORY_UNUSED;
    temp_ptr += sizeof(int);
    //clean line
    memset(temp_ptr,ZERO,sizeof(int));
    temp_ptr += sizeof(int);
    if (ptr NEQ temp_ptr){
        assert(ZERO);
    }
    if (NULL NEQ (((SYMBOL_INFO_T*)temp_ptr)->symbol_name) ){
        //const char* do not need to free by hands
        RW_FREE( (((SYMBOL_INFO_T*)temp_ptr)->symbol_name) );
        memset(  &(((SYMBOL_INFO_T*)temp_ptr)->symbol_name) ,ZERO,sizeof(char*));
    }
    //we clean it to zero
    memset(temp_ptr,ZERO,sizeof(SYMBOL_INFO_T));
    //return
    return ptr;
}

void read_file(const char* path)
{
    FILE *fp = NULL;
    fp = fopen(path,"r");
    if (fp != 0){
        yyin = fp;
    }else{
        assert(0);
    }
    do {
        yyparse();
    } while(!feof(fp));
    fclose(fp);
}
