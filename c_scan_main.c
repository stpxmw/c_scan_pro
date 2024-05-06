#include <stdio.h>
#include "c_scan_common.h"

extern Node *struct_link_list;
extern Node * function_ref_link_list;

int main() {
    int len;
    int i = 0;
    while(1) {
    lex_yacc_parser_init();
    read_file("./test.txt");

    lex_yacc_parser_deinit();
        printList(struct_link_list);
        freeList(struct_link_list);
        struct_link_list = NULL;
        i++;
        printf_all_func_ref_list(function_ref_link_list);

        break;
    }

    free_function_rel_list(function_ref_link_list);
    function_ref_link_list = NULL;


    return 0;
}
