#ifndef C_SCAN_C_SCAN_COMMON_H
#define C_SCAN_C_SCAN_COMMON_H

#include "stdio.h"
#include "c_scan_main.h"

#define MAX_SYMBOLS_NUM 2000000
#define MEMORY_USED 0xFFFFEEEE
#define MEMORY_UNUSED 0xEEEEFFFF
#define MEMORY_UNIT_SIZE sizeof(MEMORY_UNIT)
#define EQ ==
#define NEQ !=
#define ZERO 0
#define MAX_FUN_PARAM_NUM 10
#define MAX_SYMBOL_LEN 50

#define RW_MALLOC malloc
#define RW_FREE free

#ifdef FAST_MEMORY_MODE
#define P_MALLOCA pd_malloc(__LINE__)
#define P_FREE pd_free
#else
#define P_MALLOCA malloc(sizeof(SYMBOL_INFO_T))
#define P_FREE free
#endif

#define ASSIGN_FUNC_D_LOC_TO_FUNC_D  assign__func_d_loc_to_func_d
#define ASSIGN_SYMBOL_LOC_TO_FUNC_D assign_symbol_loc_to_func_d
#define ASSIGN_SYMBOL_LOC assign_symbol_loc
#define FREE_AST_NODE rel_ast_node_buffer
#define FREE_FUNC_D_NODE rel_func_d_node

typedef enum {
    ENUM_TYPEDEF,
    ENUM_ENUM,
    ENUM_STRUCT,
    ENUM_UNION,
}AST_t;

typedef struct {
    char * file_name;
    int line;
    int column;
}Func_Loc_t;

typedef struct {
    int is_pointer;
    char param_type[MAX_SYMBOL_LEN];
}Param_t;

typedef enum {
    FUN_NO_FUNC,
    FUN_IS_FUNC_BUT_UNKOWN_TYPE,
    FUN_DEFINE,
    FUN_DECLARATON,
    FUN_CALL
}Fun_Type_t;

typedef struct {
    int no_param;
    Param_t param_list[MAX_FUN_PARAM_NUM];
}Param_t_list;

typedef struct Function_D {
    char* fun_name;
    Fun_Type_t fun_type;
    Param_t_list *param_list;
    int is_ret_val_point;
    char point_str[MAX_SYMBOL_LEN];
    Func_Loc_t func_loc;
} Function_D;

typedef struct Function_Pre {
    char* ret_value_type;
    Function_D *function_d;
    Func_Loc_t fun_location_desc;
} Function_Pre;

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

typedef struct {
    int val_int;
    char *vval_charal_char;
}VALUE;

typedef struct {
    char* symbol_name;//attention! this field must be free before MEMORY_UNIT
    int no_name;
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

void* pd_malloc(int line);
void* pd_free(void * ptr);

Node* createNode(char* data);
void insertAtHead(Node** head, char* data);
void deleteNode(Node** head, char* data);
void printList(Node* head);
void freeList(Node* head);
Node* findNode(Node* head, char* data);
void print_symbols(SYMBOL_INFO_T* p);
void print_params(Param_t_list *p);
void assign_symbol_loc(SYMBOL_INFO_T* dest, SYMBOL_INFO_T* src);
void assign_symbol_loc_to_func_d(Function_D* dest, SYMBOL_INFO_T* src);
void assign__func_d_loc_to_func_d(Function_D* dest, Function_D* src);
void rel_ast_node_buffer(Function_Pre *p);
void rel_func_d_node(Function_D *p);
#endif //C_SCAN_C_SCAN_COMMON_H
