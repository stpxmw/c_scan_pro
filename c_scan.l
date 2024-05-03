D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			([Ee][+-]?{D}+)
P                       ([Pp][+-]?{D}+)
FS			(f|F|l|L)
IS                      ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%{
#include <stdio.h>
#include <assert.h>
#include "c_scan.tab.h"
#include "c_scan_common.h"
void count( );
void comment();

void* pd_malloc();
void* pd_free(void * ptr);
Node* findNode(Node* head, char* data);

int yywrap(void);
int check_type();

extern int column;
extern int lineno;
extern Node *struct_link_list;

%}

%%
"/*"			{ comment(); }
"//"[^\n]*              { /* consume //-comment */ }


"auto"			{ count(0); return(AUTO); }
"_Bool"			{ count(0); return(BOOL); }
"break"			{ count(0); return(BREAK); }
"case"			{ count(0); return(CASE); }
"char"			{count(0);return(CHAR);}
"_Complex"		{ count(0); return(COMPLEX); }
"const"			{count(0);return(CONST);}
"continue"		{ count(0); return(CONTINUE); }
"default"		{ count(0); return(DEFAULT); }
"do"			{ count(0); return(DO); }
"double"		{ count(0); return(DOUBLE); }
"else"			{ count(0); return(ELSE); }
"enum"			{ count(0); return(ENUM); }
"extern"		{count(0);return(EXTERN);}
"float"			{ count(0); return(FLOAT); }
"for"			{ count(0); return(FOR); }
"goto"			{ count(0); return(GOTO); }
"if"			{ count(0); return(IF); }
"_Imaginary"	{ count(0); return(IMAGINARY); }
"inline"		{count(0);return(INLINE);}
"int"			{count(0);return(INT);}
"long"			{ count(0); return(LONG); }
"register"		{ count(0); return(REGISTER); }
"restrict"		{ count(0); return(RESTRICT); }
"return"		{ count(0); return(RETURN); }
"short"			{ count(0); return(SHORT); }
"signed"		{ count(0); return(SIGNED); }
"sizeof"		{ count(0); return(SIZEOF); }
"static"		{ count(0); return(STATIC); }
"struct"		{ count(0); return(STRUCT); }
"switch"		{ count(0); return(SWITCH); }
"typedef"		{ count(0); return(TYPEDEF); }
"union"			{ count(0); return(UNION); }
"unsigned"		{ count(0); return(UNSIGNED); }
"void"			{ count(0); return(VOID); }
"volatile"		{ count(0); return(VOLATILE); }
"while"			{ count(0); return(WHILE); }

{L}({L}|{D})*		{count(0);return(check_type());}



0[xX]{H}+{IS}?		{ count(0); return(CONSTANT); }
0[0-7]*{IS}?		{ count(0); return(CONSTANT); }
[1-9]{D}*{IS}?		{ count(0); return(CONSTANT); }
L?'(\\.|[^\\'\n])+'	{ count(0); return(CONSTANT); }

{D}+{E}{FS}?		{ count(0); return(CONSTANT); }
{D}*"."{D}+{E}?{FS}?	{ count(0); return(CONSTANT); }
{D}+"."{D}*{E}?{FS}?	{ count(0); return(CONSTANT); }
0[xX]{H}+{P}{FS}?	{ count(0); return(CONSTANT); }
0[xX]{H}*"."{H}+{P}{FS}?     { count(0); return(CONSTANT); }
0[xX]{H}+"."{H}*{P}{FS}?     { count(0); return(CONSTANT); }


L?\"(\\.|[^\\"\n])*\"	{ count(0); return(STRING_LITERAL); }

"..."			{ count(0); return(ELLIPSIS); }
">>="			{ count(0); return(RIGHT_ASSIGN); }
"<<="			{ count(0); return(LEFT_ASSIGN); }
"+="			{ count(0); return(ADD_ASSIGN); }
"-="			{ count(0); return(SUB_ASSIGN); }
"*="			{ count(0); return(MUL_ASSIGN); }
"/="			{ count(0); return(DIV_ASSIGN); }
"%="			{ count(0); return(MOD_ASSIGN); }
"&="			{ count(0); return(AND_ASSIGN); }
"^="			{ count(0); return(XOR_ASSIGN); }
"|="			{ count(0); return(OR_ASSIGN); }
">>"			{ count(0); return(RIGHT_OP); }
"<<"			{ count(0); return(LEFT_OP); }
"++"			{ count(0); return(INC_OP); }
"--"			{ count(0); return(DEC_OP); }
"->"			{ count(0); return(PTR_OP); }
"&&"			{ count(0); return(AND_OP); }
"||"			{ count(0); return(OR_OP); }
"<="			{ count(0); return(LE_OP); }
">="			{ count(0); return(GE_OP); }
"=="			{ count(0); return(EQ_OP); }
"!="			{ count(0); return(NE_OP); }
";"			{ count(0); return(';'); }
("{"|"<%")		{ count(0); return('{'); }
("}"|"%>")		{ count(0); return('}'); }
","			{ count(0); return(','); }
":"			{ count(0); return(':'); }
"="			{ count(0); return('='); }
"("			{ count(0); return('('); }
")"			{ count(0); return(')'); }
("["|"<:")		{ count(0); return('['); }
("]"|":>")		{ count(0); return(']'); }
"."			{ count(0); return('.'); }
"&"			{ count(0); return('&'); }
"!"			{ count(0); return('!'); }
"~"			{ count(0); return('~'); }
"-"			{ count(0); return('-'); }
"+"			{ count(0); return('+'); }
"*"			{ count(0); return('*'); }
"/"			{ count(0); return('/'); }
"%"			{ count(0); return('%'); }
"<"			{ count(0); return('<'); }
">"			{ count(0); return('>'); }
"^"			{ count(0); return('^'); }
"|"			{ count(0); return('|'); }
"?"			{ count(0); return('?'); }

[ \t\v\n\f]		{ count(1);  }
.			{ /* Add code to complain about unmatched characters */ }

%%

int yywrap(void)
{
    return 1;
}

void comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		//putchar(c);
		;

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		//putchar(c1);
		;
}


int column = 0;
int lineno = 1;


void count(int not_need_record_flag)
{
	int i,len;
    if (!not_need_record_flag){
        SYMBOL_INFO_T *temp_info = (SYMBOL_INFO_T *)P_MALLOCA;

        temp_info->lineno = lineno;
        temp_info->column = column;
        len = strlen(yytext);
        temp_info->symbol_name = strdup(yytext);
        if (NULL EQ temp_info->symbol_name){
            assert(0);
        }
        memcpy(temp_info->symbol_name,yytext,len);
        temp_info->no_name = len;
#ifdef FLEX_DEBUG
        printf("FLEX DEBUG READ TOKEN: \" %s \" \n",yytext);
#endif
        yylval.symbol_info =temp_info;
    }


	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
		{
			column = 0;
            lineno++;
        }
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
    fflush(stdout);
	//ECHO;
}


int check_type()
{

    //pseudo code --- this is what it should check
/*
	if (yytext == "ST")
		return(TYPE_NAME);

	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/
    if (findNode(struct_link_list,yytext)){
        return(TYPE_NAME);
    }else{
        return(IDENTIFIER);
    }

}