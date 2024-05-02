#ifndef C_SCAN_C_SCAN_COMMON_H
#define C_SCAN_C_SCAN_COMMON_H

#include "stdio.h"

typedef struct {
    int val_int;
    char *val_char;
}VALUE;

typedef struct {
    const char* symbol_name;//attention! this field must be free before MEMORY_UNIT
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

void* pd_malloc();
void* pd_free(void * ptr);





#endif //C_SCAN_C_SCAN_COMMON_H
