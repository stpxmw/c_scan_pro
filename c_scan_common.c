#include "stdio.h"
#include <stdlib.h>
#include <memory.h>
#include "assert.h"
#include "c_scan_common.h"

extern FILE *yyin;
extern int yyparse();
void* inital_memory = NULL;

char current_file_name[MAX_FILE_NAME_LEN] = "";

unsigned char* first_search_location = ZERO;
unsigned char* search_location = ZERO;//we use this flag to speed up memory search
unsigned char* last_search_location = ZERO;//we use this flag to speed up memory search

Node *struct_link_list = NULL; //define the struct or enum or union list, which used for parse c.i, when finish the parse of one file, this link should be free

Node *function_ref_link_list = NULL;//define the link list for store function def.

void free_func_node_t(Function_List_Node_t* p)
{
    if (NULL NEQ p)
    {
        if (p->fun_name NEQ NULL)
        {
            RW_FREE(p->fun_name);
            p->fun_name = NULL;
        }
        if (p->ret_value_type NEQ NULL)
        {
            RW_FREE(p->ret_value_type);
            p->ret_value_type =NULL;
        }
        RW_FREE(p);
    }
}




void free_sub_node_list(Node * p)
{
    Node* current = p;
    Node* next = NULL;
    Function_List_Node_t *cur_node = NULL;

    while (current != NULL) {
        next = current->next;
        cur_node =(Function_List_Node_t *) (current->local_ptr);
        free_func_node_t(cur_node);
        if(current->data NEQ 0){
            RW_FREE(current->data);
        }
        RW_FREE(current);
        current = next;
    }
}


void free_function_rel_list(Node * p)
{
    Node* current = p;
    Node* next = NULL;
    Node* sub_node = NULL;
    while (current != NULL) {
        //printf("%s -> ", current->data);
        next = current->next;
        sub_node = (Node*)(current->local_ptr);
        free_sub_node_list(sub_node);
        if(current->data NEQ 0){
            RW_FREE(current->data);
        }
        RW_FREE(current);
        current = next;
    }
    //free head data
}



void printf_func_node_t(Function_List_Node_t * p)
{
    printf("FUNCTION: %s,TYPE: %d, RET TYPE: %s, LINE: %d, COL: %d ",p->fun_name,p->fun_type,p->ret_value_type,p->fun_location_desc.line,p->fun_location_desc.column);
}


void printf_sub_node_list(Node* p)
{
    Node* current = p;
    Function_List_Node_t *cur_node = NULL;
    while (current != NULL) {
        cur_node =(Function_List_Node_t *) (current->local_ptr);
        printf_func_node_t(cur_node);
        printf(" |||  ");
        current = current->next;
    }
}


void printf_all_func_ref_list(Node * p)
{
    Node* current = p;
    Node* sub_node = NULL;
    while (current != NULL) {
        //printf("%s -> ", current->data);
        printf("function name :%s -> ", current->data);
        sub_node = (Node*)current->local_ptr;
        printf_sub_node_list(sub_node);
        current = current->next;
        printf("\n");
    }

}

void add_func_node_to_ref_list(Function_List_Node_t *p)
{
    Node* find_header = NULL;
    //firstly, we need to check if list has already the same func name
    if (NULL NEQ (find_header = findNode(function_ref_link_list,p->fun_name) ) )
    {
        //we find it !
        //we need to add it to the list to the header,
        //Node* sub_header = (Node*)(find_header->local_ptr);

        //add to the sub_header
        //Node* new_sub_node = createNode(p->fun_name,(void*)p);
        insertAtHead((Node **) &(find_header->local_ptr), p->fun_name, (void *)p);

        //find_header->local_ptr = sub_header;//!!!!


    } else {


        //we can not find, and add it to the header
        Node* new_sub_node = createNode(p->fun_name,(void*)p);
        insertAtHead(&function_ref_link_list,p->fun_name,(void *)new_sub_node);

    }

}

Function_List_Node_t *transfer_func_to_list_node(Function_Pre *p)
{
    Function_List_Node_t * ret = (Function_List_Node_t *)RW_MALLOC(sizeof(Function_List_Node_t));
    memset(ret,ZERO,sizeof(Function_List_Node_t));
    if (NULL EQ p)
    {
        printf("ERROR, CAN NOT TRANSFERO VOID POIONTER");
        RW_FREE(ret);
        ret = NULL;
    } else {
        if (NULL EQ p->function_d)
        {
            RW_FREE(ret);
            ret = NULL;
            return (Function_List_Node_t *)NULL;//sometimes it is no function
        }

        ret->fun_name = strdup(p->function_d->fun_name);
        ret->fun_type = p->function_d->fun_type;
        if (NULL NEQ p->function_d->param_list){
            ret->no_param = p->function_d->param_list->no_param;
            memcpy(ret->param_list,p->function_d->param_list->param_list,sizeof(Param_t)*MAX_FUN_PARAM_NUM);
        }
        ret->ret_value_type = strdup(p->ret_value_type);
        memcpy(&(ret->fun_location_desc),&(p->fun_location_desc),sizeof(Func_Loc_t));//this func_loc_t name is not used
    }
    return ret;
}

void rel_func_d_node(Function_D *p)
{
    if (NULL NEQ p)
    {
        if(NULL NEQ p->param_list)
        {
            RW_FREE(p->param_list);
            memset(&(p->param_list), ZERO, sizeof(Param_t_list*));
        }
        if (NULL NEQ p->fun_name)
        {
            RW_FREE(p->fun_name);
            memset(&(p->fun_name), ZERO, sizeof(char*));
        }
    RW_FREE(p);
    memset(&(p), ZERO, sizeof(Function_D*));
    }
}

void rel_ast_node_buffer(Function_Pre *p)
{
    if (NULL NEQ p)
    {
        if(NULL NEQ p->ret_value_type) {
            RW_FREE(p->ret_value_type);
            memset(&(p->ret_value_type), ZERO, sizeof(char *));
        }
        if (NULL NEQ p->function_d) {
            if (NULL NEQ p->function_d->fun_name) {
                RW_FREE(p->function_d->fun_name);
                memset(&(p->function_d->fun_name), ZERO, sizeof(char *));
            }
            if (NULL NEQ p->function_d->param_list) {
                RW_FREE(p->function_d->param_list);
                memset(&(p->function_d->param_list), ZERO, sizeof(Param_t_list*));
            }
            RW_FREE(p->function_d);
            memset(&(p->function_d), ZERO, sizeof(Function_D*));
        }
        RW_FREE(p);
        memset(&p, ZERO, sizeof(Function_Pre*));
    } else{
        printf("point is NULL, don't rel\n");
    }
}


void assign_symbol_loc(SYMBOL_INFO_T* dest, SYMBOL_INFO_T* src)
{
   dest->no_name =  src->no_name;
   dest->column = src->column;
   dest->lineno  = src->lineno;
}

void assign_symbol_loc_to_func_d(Function_D* dest, SYMBOL_INFO_T* src)
{
    dest->func_loc.line =  src->lineno;
    dest->func_loc.column = src->column;
}

void assign__func_d_loc_to_func_d(Function_D* dest, Function_D* src)
{
    dest->func_loc.line =  src->func_loc.line;
    dest->func_loc.column = src->func_loc.column;
}

void print_params(Param_t_list *p)
{
    if (NULL EQ p)
    {
        return;
    }
    printf("START PRINT PARAMS --> ");
    int no = p->no_param;
    int i;
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

Node* createNode(char* data, void* local_ptr) {
    Node* newNode = (Node*)RW_MALLOC(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: unable to create new node\n");
        exit(1);
    }
    newNode->data = strdup(data);  // 为字符串分配空间并复制内容
    newNode->local_ptr = local_ptr;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node** head, char* data,void* local_ptr) {
    Node* newNode = createNode(data,local_ptr);
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
        RW_FREE(current->data);  // 释放字符串内存
        if (NULL NEQ current->local_ptr)
            free(current->local_ptr);
        RW_FREE(current);        // 释放节点内存
    }
}

void freeList(Node* head) {
    Node* current = head;
    Node* next = NULL;
    char* data;
    //current = head->next;
    while (current != NULL) {
        next = current->next;
        data = current->data;
        RW_FREE(data);
        if(current->local_ptr)
        {
            RW_FREE(current->local_ptr);
        }
        RW_FREE(current);
        current = next;
    }
    //head->next = NULL;
    //RW_FREE(head->data);
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
#ifndef MEMORY_AUTO_REL
            printf("warning! memory not released! may cause mem leak! :%p",check_mem_ptr);
            printf("   line: %d str name:---|",*((int *)(check_mem_ptr + sizeof(int))));
            print_item_name(((SYMBOL_INFO_T *)(check_mem_ptr + 2*sizeof(int)))->symbol_name,((SYMBOL_INFO_T *)(check_mem_ptr + 2*sizeof(int)))->no_name);
            printf("|---");
            printf("symbol location is : line:%d, col:%d ",((SYMBOL_INFO_T *)(check_mem_ptr + 2*sizeof(int)))->lineno,((SYMBOL_INFO_T *)(check_mem_ptr + 2*sizeof(int)))->column);
            printf("\n");
#endif
            leak_num++;
        }
#ifdef MEMORY_AUTO_REL
        P_FREE(check_mem_ptr+2*sizeof(int));
#endif
        check_mem_ptr += MEMORY_UNIT_SIZE;
    }
    printf("Total leak num is %d\n", leak_num);
}


void p_memory_deinit(void){
    RW_FREE(inital_memory);
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
        RW_FREE( ((SYMBOL_INFO_T*)temp_ptr)->symbol_name );
        memset( &(((SYMBOL_INFO_T*)temp_ptr)->symbol_name) ,ZERO,sizeof(char*));
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
