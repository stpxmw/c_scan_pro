//
// Created by 许满伟 on 2024/5/1.
//
#include "c_scan_common.h"
#include "stdio.h"
#include "assert.h"
extern FILE *yyin;
extern int yyparse();
void test(void)
{
    printf("hello");
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
