#include <stdio.h>
#include "c_scan_common.h"

extern Node *struct_link_list;


int main() {
    int len;
    int i = 0;
    while(i<10) {
    lex_yacc_parser_init();
    //printf("Hello, World!\n");
    read_file("../test.txt");
    //test();
    len = sizeof(MEMORY_UNIT);
    printf("len %d \n", len);

    lex_yacc_parser_deinit();
        freeList(struct_link_list);
        i++;
    }
    printList(struct_link_list);
    return 0;
}
