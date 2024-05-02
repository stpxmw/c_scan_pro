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
//unsigned char* free_location = ZERO;//we use this flag to speed up memory search
unsigned char* last_search_location = ZERO;//we use this flag to speed up memory search

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

void memory_leak_check(void)
{
    unsigned char *check_mem_ptr = NULL;
    check_mem_ptr = first_search_location;
    while (check_mem_ptr <= last_search_location)
    {
        if ( MEMORY_USED EQ *((int *)check_mem_ptr) )
        {
            printf("warning! memory not released! may cause mem leak! :%p",check_mem_ptr);
            printf("   line: %d\n",*((int *)(check_mem_ptr + sizeof(int))));
        }
        check_mem_ptr += MEMORY_UNIT_SIZE;
    }
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
    int find_flag = ZERO;
    int i = ZERO;
    void *find_memory_unit = NULL;
    unsigned char* temp_search_location = search_location;
    //first we try to search memory in (search_location,last_search_location)
    while(temp_search_location <= last_search_location){
        if (*((int*)temp_search_location) EQ MEMORY_UNUSED){
            //this memory unit not used
            //assign result
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
        printf("the mem block %p is in  used,start free! \n",temp_ptr);
#endif

    }else if(MEMORY_UNUSED EQ *( (int *)(temp_ptr))) {
#ifdef MEMORY_DEBUG
        printf("the mem block is not in used,do not free! \n");
#endif
    }else{
        printf("the mem block is damaged! \n");
        assert(0);
    }
    //flag it to be not used and memset it to be 0
    *( (int *)(temp_ptr)) = MEMORY_UNUSED;
    temp_ptr += sizeof(int);
    memset(temp_ptr,ZERO,sizeof(int));
    temp_ptr += sizeof(int);
    if (ptr NEQ temp_ptr){
        assert(ZERO);
    }
    if (NULL NEQ (((SYMBOL_INFO_T*)temp_ptr)->symbol_name) ){
        //const char* do not need to free by hands
        //RW_FREE( ((SYMBOL_INFO_T*)temp_ptr)->symbol_name);
    }
    //then we clean it to zero
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
