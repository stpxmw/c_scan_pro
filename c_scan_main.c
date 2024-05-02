#include <stdio.h>
#include "c_scan_common.h"




int main() {
    int len = 0;
    lex_yacc_parser_init();
    //printf("Hello, World!\n");
    read_file("../test.txt");
    //test();
    len = sizeof(MEMORY_UNIT);
    printf("len %d \n", len);
    lex_yacc_parser_deinit();
    return 0;
}
