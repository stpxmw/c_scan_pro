#include "stdio.h"
#include <stdlib.h>
#include <memory.h>
#include "assert.h"
#include "c_scan_common.h"
#define MAX_SYMBOLS_NUM 100000
#define MEMORY_USED 0xFFFEEEEU
#define MEMORY_UNUSED 0xEEEEFFFFU
#define MEMORY_UNIT_SIZE sizeof(MEMORY_UNIT)

#define RW_MALLOC malloc
#define RW_FREE free

#ifdef FAST_MEMORY_MODE
#define P_MALLOCA pd_malloc
#define P_FREE pd_free
#else
#define P_MALLOCA malloc
#define P_FREE free
#endif

extern FILE *yyin;
extern int yyparse();
void* inital_memory = NULL;

unsigned char* first_search_location = 0;
unsigned char* search_location = 0;//we use this flag to speed up memory search
unsigned char* free_location = 0;//we use this flag to speed up memory search
unsigned char* last_search_location = 0;//we use this flag to speed up memory search

void p_memory_init(void)
{
    unsigned char* temp_init_memory_loc = NULL;
    inital_memory = (void*)malloc(MAX_SYMBOLS_NUM*sizeof(MEMORY_UNIT));
    memset(inital_memory,0,MAX_SYMBOLS_NUM*sizeof(MEMORY_UNIT));
    search_location = (unsigned char* )inital_memory;
    first_search_location = search_location;
    last_search_location = search_location + MAX_SYMBOLS_NUM*sizeof(MEMORY_UNIT);
    //we need to init all the memory block
    temp_init_memory_loc = first_search_location;
    while(temp_init_memory_loc <= last_search_location)
    {
        *((int*)temp_init_memory_loc) = MEMORY_UNUSED;
    }
    if (temp_init_memory_loc != last_search_location){
        printf("memory init error! the memory boundary is not align!");
        assert(0);
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

#ifdef FAST_MEMORY_MODE
    p_memory_deinit();
#endif

}

/*
 * [   MEMORY_UNIT     |  MEMORY_UNIT|MEMORY_UNIT|...]
 * [0-8byte][8-40byte] |
 * flag |SYMBOL_INFO_T |
 */
void* pd_malloc()
{
    int find_flag = 0;
    int i = 0;
    void *find_memory_unit = NULL;
    unsigned char* temp_search_location = search_location;
    //first we try to search memory in (search_location,last_search_location)
    while(temp_search_location <= last_search_location){
        if (*((int*)temp_search_location) != MEMORY_USED){
            //this memory unit not used
            //assign result
            *((int*)temp_search_location) = MEMORY_USED;
            *((int*)(temp_search_location + sizeof(int))) = __LINE__;
            search_location = temp_search_location;
            find_memory_unit = (unsigned char*)temp_search_location;
        }else{
            temp_search_location += MEMORY_UNIT_SIZE;
        }
    }
    if ((NULL == find_memory_unit) && (search_location != last_search_location)){
        printf("memory search error!");
        assert(0);
    }
    // if previous search cannot found ,we try to search memory in (first_search_location,search_location)
    if (NULL == find_memory_unit) {
        temp_search_location = first_search_location;
        while (temp_search_location <= search_location) {
            if (*((int*)temp_search_location) != MEMORY_USED){
                //this memory unit not used
                //assign result
                *((int*)temp_search_location) = MEMORY_USED;
                *((int*)(temp_search_location + sizeof(int))) = __LINE__;
                search_location = temp_search_location;
                find_memory_unit = (unsigned char*)temp_search_location;
            }else{
                temp_search_location += MEMORY_UNIT_SIZE;
            }
        }
    }
    if (NULL == find_memory_unit){
        printf("error! memory alloc fail!,may be you need to expand MAX_SYMBOLS_NUM");
    }else {
        find_memory_unit += sizeof(int);
    }
        return find_memory_unit;
}

void* pd_free(void * ptr)
{
    return (void*)0;
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
