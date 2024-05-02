#ifndef C_SCAN_C_SCAN_COMMON_H
#define C_SCAN_C_SCAN_COMMON_H

#include "stdio.h"
#include "c_scan_main.h"

#define MAX_SYMBOLS_NUM 100000
#define MEMORY_USED 0xFFFFEEEE
#define MEMORY_UNUSED 0xEEEEFFFF
#define MEMORY_UNIT_SIZE sizeof(MEMORY_UNIT)
#define EQ ==
#define NEQ !=
#define ZERO 0

#define RW_MALLOC malloc
#define RW_FREE free

#ifdef FAST_MEMORY_MODE
#define P_MALLOCA pd_malloc(__LINE__)
#define P_FREE pd_free
#else
#define P_MALLOCA malloc
#define P_FREE free
#endif

typedef struct {
    int val_int;
    char *val_char;
}VALUE;

typedef struct {
    char* symbol_name;//attention! this field must be free before MEMORY_UNIT
    int lineno;
    int column;
    VALUE val;
}SYMBOL_INFO_T;

typedef struct {
    int flag;
    int alloc_line;
    SYMBOL_INFO_T t;
}MEMORY_UNIT;


void read_file(const char* path);

void lex_yacc_parser_init(void);
void lex_yacc_parser_deinit(void);

void p_memory_init(void);
void p_memory_deinit(void);

void memory_leak_check(void);

void* pd_malloc();
void* pd_free(void * ptr);





#endif //C_SCAN_C_SCAN_COMMON_H
