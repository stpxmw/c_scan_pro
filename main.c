#include <stdio.h>
#include "c_scan_common.h"

#define FAST_MEMORY_MODE
#define MEMORY_LEAK_CHECK


int main() {
    int len = 0;
    //printf("Hello, World!\n");
    read_file("../test.txt");
    //test();
    len = sizeof(MEMORY_UNIT);
    printf("len %d", len);
    return 0;
}
