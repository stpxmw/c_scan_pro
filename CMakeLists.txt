cmake_minimum_required(VERSION 3.24)
project(c_scan_pro C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")

# 查找Yacc和Lex工具
find_package(BISON)
find_package(FLEX)

# 如果找到了Yacc和Lex，则设置变量
if(BISON_FOUND AND FLEX_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${BISON_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLEX_FLAGS}")

    # 指定你的Yacc和Lex源文件
    set(YACC_SOURCE ${CMAKE_SOURCE_DIR}/c_scan.y)
    set(LEX_SOURCE ${CMAKE_SOURCE_DIR}/c_scan.l)

    # 生成 Parser 和 Scanner 的 C/C++ 代码
    BISON_TARGET(yacc_parser ${YACC_SOURCE} ${CMAKE_SOURCE_DIR}/c_scan.tab.c DEFINES_FILE ${CMAKE_SOURCE_DIR}/c_scan.tab.h)
    FLEX_TARGET(lex_parser ${LEX_SOURCE} ${CMAKE_SOURCE_DIR}/lex.yy.c)

    # 将生成的 Parser 和 Scanner 代码添加到你的项目中
    add_executable(c_scan_pro c_scan_main.c
            c_scan_main.h)

    # 目标依赖
else()
    message(FATAL_ERROR "Yacc and/or Lex not found.")
endif()

add_library(lex_parser lex.yy.c)
add_library(yacc_parser c_scan.tab.c c_scan.tab.h)
add_library(commom_lib c_scan_common.h c_scan_common.c)

target_link_libraries(c_scan_pro yacc_parser commom_lib lex_parser)