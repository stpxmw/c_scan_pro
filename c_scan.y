%{
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "c_scan_common.h"

#define YYERROR_VERBOSE 1
#define YYDEBUG 1
int yylex();
void yyerror(const char *s);
extern Node *struct_link_list;
%}

%union {
	struct SYMBOL_INFO_T *symbol_info;
	struct Param_t_list *param_list;
	struct Function_D *function_d;
	struct Function_Pre *function_pre;
}

%type <symbol_info> IDENTIFIER CONSTANT EXTERN STRUCT CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID UNION
%type <symbol_info> type_specifier declaration_specifiers  struct_or_union storage_class_specifier
%type <symbol_info>  parameter_declaration abstract_declarator type_qualifier function_specifier pointer '*' '(' ')'
%type <param_list> parameter_list parameter_type_list direct_abstract_declarator identifier_list
%type <function_d> direct_declarator declarator init_declarator_list init_declarator
%type <function_pre> declaration function_definition external_declaration translation_unit declaration_list block_item block_item_list

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	{
		Function_Pre* dummy_next_node = (Function_Pre*)RW_MALLOC(sizeof(Function_Pre) );
		$$ = dummy_next_node;
	}
	| declaration_specifiers init_declarator_list ';'
	{
		/* $1 means ret type, $2 means init param list and fuction name may be also have "*" */
		Function_D *tem_fuc_trace = $2;
		SYMBOL_INFO_T *temp_symbol_info0 = $1;

		if (tem_fuc_trace->fun_type NEQ FUN_NO_FUNC) //this is function reduce
		{
			Function_Pre* next_node =(Function_Pre*)RW_MALLOC(sizeof(Function_Pre) );
			memset(next_node,0,sizeof(Function_Pre));
			next_node->function_d = $2;
			//next_node->fun_location_desc.file_name =
			next_node->fun_location_desc.line =next_node->function_d->func_loc.line;
			next_node->fun_location_desc.column =next_node->function_d->func_loc.column;
			next_node->ret_value_type = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
			memset(next_node->ret_value_type,0,MAX_SYMBOL_LEN);
			memcpy(next_node->ret_value_type,temp_symbol_info0->symbol_name, strlen(temp_symbol_info0->symbol_name));
			if(tem_fuc_trace->is_ret_val_point EQ 1)
			{
				strcat(next_node->ret_value_type," ");
				strcat(next_node->ret_value_type,tem_fuc_trace->point_str);
			}
			if (FUN_IS_FUNC_BUT_UNKOWN_TYPE NEQ tem_fuc_trace->fun_type)
			{
				assert(0);
			} else {
				tem_fuc_trace->fun_type = FUN_DECLARATON;
			}

			printf("FUCTION_NAME:%s\n",tem_fuc_trace->fun_name);
			print_params(tem_fuc_trace->param_list);
			printf("function type is \"%d\"\n", tem_fuc_trace->fun_type);
			printf("ret TYPE is \"%s\"\n", next_node->ret_value_type);
			printf("func:line %d, col: %d\n", next_node->fun_location_desc.line,next_node->fun_location_desc.column);

			$$ = next_node;

		} else { // this is struct or other state reduce like struct declare, we can not add all struct to it
			Function_D *temp_symbol_info = $2;
                        printf("STRUCT OR UNION NAME--> \"%s\"\n",temp_symbol_info->fun_name );
                        if ((NULL NEQ temp_symbol_info) && (NULL NEQ temp_symbol_info->fun_name) )
                        {
				if( (strcmp(temp_symbol_info0->symbol_name, "typedef struct") == 0)
				  ||(strcmp(temp_symbol_info0->symbol_name, "struct") == 0) ){
					insertAtHead(&struct_link_list,temp_symbol_info->fun_name,NULL);
#ifdef BISON_DEBUG
                        		printf("BISON_DEBUG ADD STRUCT TO LIST -->\"%s\"\n",temp_symbol_info->fun_name );
#endif

				 }
                        }
                        FREE_FUNC_D_NODE($2);
                        Function_Pre* dummy_next_node = (Function_Pre*)RW_MALLOC(sizeof(Function_Pre) );
                        $$ = dummy_next_node;

		}
	}
	;

declaration_specifiers
	: storage_class_specifier
	{
		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(0);
		}
		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
		SYMBOL_INFO_T* cur_node = $1;
		SYMBOL_INFO_T* old_node = $$;
		if (cur_node NEQ old_node) {
			strcat(next_node->symbol_name,old_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node->symbol_name);
		} else {
			strcat(next_node->symbol_name,cur_node->symbol_name);
		}
		$$ = next_node;

        	if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
        	{
#ifdef BISON_DEBUG
        		//printf("BISON_DEBUG-->storage_class_specifier get token \"%s\"\n",next_node->symbol_name );
#endif
		}
	}
	| storage_class_specifier declaration_specifiers
	{
		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(0);
		}
		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
		SYMBOL_INFO_T* cur_node = $1;
		SYMBOL_INFO_T* cur_node2 = $2;
		SYMBOL_INFO_T* old_node = $$;
		if ( (cur_node NEQ old_node) && (cur_node2 NEQ old_node) ) {
			strcat(next_node->symbol_name,old_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);
		} else {
			strcat(next_node->symbol_name,cur_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);
		}
		$$ = next_node;

		if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
		{
#ifdef BISON_DEBUG
			//printf("BISON_DEBUG-->storage_class_specifier2 get token \"%s\"\n",next_node->symbol_name );
#endif
		}
	}

	| type_specifier
{
		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(0);
		}
		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
		SYMBOL_INFO_T* cur_node = $1;
		strcat(next_node->symbol_name,cur_node->symbol_name);
		$$ = next_node;
        	if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
        	{
#ifdef BISON_DEBUG
        		//printf("BISON_DEBUG-->storage_class_specifier3 get token \"%s\"\n",next_node->symbol_name );
#endif
		}
	}
	| type_specifier declaration_specifiers
{
		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(0);
		}
		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
		SYMBOL_INFO_T* cur_node = $1;
		SYMBOL_INFO_T* cur_node2 = $2;
		SYMBOL_INFO_T* old_node = $$;
		if ( (cur_node NEQ old_node) && (cur_node2 NEQ old_node) ) {
			strcat(next_node->symbol_name,old_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);
		} else {
			strcat(next_node->symbol_name,cur_node->symbol_name);
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);

		}
		$$ = next_node;

		if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
		{
#ifdef BISON_DEBUG
			//printf("BISON_DEBUG-->storage_class_specifier4 get token \"%s\"\n",next_node->symbol_name );
#endif
		}
	}
	| type_qualifier
	{
		$$ = $1;
	}

	| type_qualifier declaration_specifiers
	{
        		SYMBOL_INFO_T* next_node = (SYMBOL_INFO_T*)P_MALLOCA;
        		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
        		if (NULL EQ next_node->symbol_name) {
        			assert(0);
        		}
        		memset(next_node->symbol_name, 0, MAX_SYMBOL_LEN);
        		SYMBOL_INFO_T* cur_node = $1;
        		SYMBOL_INFO_T* cur_node2 = $2;
        		SYMBOL_INFO_T* old_node = $$;
        		if ( (cur_node NEQ old_node) && (cur_node2 NEQ old_node) ) {
        			strcat(next_node->symbol_name,old_node->symbol_name);
        			strcat(next_node->symbol_name," ");
        			strcat(next_node->symbol_name,cur_node->symbol_name);
        			strcat(next_node->symbol_name," ");
        			strcat(next_node->symbol_name,cur_node2->symbol_name);
        			//free buffer for current node
        		} else {
        			strcat(next_node->symbol_name,cur_node->symbol_name);
        			strcat(next_node->symbol_name," ");
        			strcat(next_node->symbol_name,cur_node2->symbol_name);

        		}
        		$$ = next_node;

        		if ((NULL NEQ next_node) && (NULL NEQ next_node->symbol_name) )
        		{
        #ifdef BISON_DEBUG
        			//printf("BISON_DEBUG-->storage_class_specifier5 get token \"%s\"\n",next_node->symbol_name );
        #endif
        		}
        	}
	| function_specifier
	{

	}

	| function_specifier declaration_specifiers

	{
		$$ = $2;
        }
	;

init_declarator_list
	: init_declarator
	{
		$$ = $1;
	}
	| init_declarator_list ',' init_declarator
	{
	//currently do not support
	}

	;

init_declarator
	: declarator
	{
	 	$$ = $1;
	}
	| declarator '=' initializer
	{
		$$ = $1;
	}

	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	{
		SYMBOL_INFO_T *temp_symbol_info = $2;
		if ((NULL NEQ temp_symbol_info) && (NULL NEQ temp_symbol_info->symbol_name) )
		{
			insertAtHead(&struct_link_list,temp_symbol_info->symbol_name,NULL);
#ifdef BISON_DEBUG
                	//printf("IDENTIFIER get token %s \n",temp_symbol_info->symbol_name );
#endif
		}

	}

	| struct_or_union '{' struct_declaration_list '}'

	| struct_or_union IDENTIFIER
	{
		SYMBOL_INFO_T *temp_symbol_info = $2;
		if ((NULL NEQ temp_symbol_info) && (NULL NEQ temp_symbol_info->symbol_name) )
		{
			insertAtHead(&struct_link_list,temp_symbol_info->symbol_name,NULL);
#ifdef BISON_DEBUG
			//printf("IDENTIFIER get token %s \n", temp_symbol_info->symbol_name);
#endif
		}
	}
	| struct_or_union TYPE_NAME //add by me 20240503
	;

struct_or_union
	: STRUCT
	{
	  $$ = $1;
	}
	| UNION
	{
	  $$ = $1;
	}
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	{
	  FREE_FUNC_D_NODE($1);
	}
	| ':' constant_expression
	| declarator ':' constant_expression
	{
	 FREE_FUNC_D_NODE($1);
	}
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	;

function_specifier
	: INLINE
	;

declarator
	: pointer direct_declarator
	{
		SYMBOL_INFO_T *temp_symbol = $1;
		Function_D *temp_func_d = $2;
		temp_func_d->is_ret_val_point = 1;
		memcpy(temp_func_d->point_str,temp_symbol->symbol_name,strlen(temp_symbol->symbol_name));
            	$$ = $2;
        }
	| direct_declarator
	{
		Function_D *temp_func_d = $1;
		temp_func_d->is_ret_val_point = 0;
		$$ = $1;
	}
	;


direct_declarator
	: IDENTIFIER
	{
		Function_D* next_node =(Function_D*)RW_MALLOC(sizeof(Function_D));
		memset(next_node,ZERO,sizeof(Function_D));
		SYMBOL_INFO_T *temp_id  = $1;
		next_node->fun_type = FUN_NO_FUNC;
		next_node->fun_name = strdup(temp_id->symbol_name);
		$$ = next_node;
		ASSIGN_SYMBOL_LOC_TO_FUNC_D($$,$1);
	}
	| '(' declarator ')'
	{
	 //currently we do not support like ----void *test(int(*Test2)(int a, int b) )-----
	 //we need rel the buffer
	 FREE_FUNC_D_NODE($2);
	 $$ = NULL;
	}

	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	{
	 FREE_FUNC_D_NODE($1);
	 $$ = NULL;
	}
	| direct_declarator '[' type_qualifier_list ']'
	{
	FREE_FUNC_D_NODE($1);
	$$ = NULL;
	}
	| direct_declarator '[' assignment_expression ']'
	{
	FREE_FUNC_D_NODE($1);
	$$ = NULL;
	}
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	{
	FREE_FUNC_D_NODE($1);
	$$ = NULL;
	}
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	{
	FREE_FUNC_D_NODE($1);
	$$ = NULL;
	}
	| direct_declarator '[' type_qualifier_list '*' ']'
	{
	FREE_FUNC_D_NODE($1);
	$$ = NULL;
	}
	| direct_declarator '[' '*' ']'
	{
	FREE_FUNC_D_NODE($1);
	$$ = NULL;
	}

	| direct_declarator '[' ']'
	{
	FREE_FUNC_D_NODE($1);
	$$ = NULL;
	}
	| direct_declarator '(' parameter_type_list ')'
	{
		Param_t_list *temp_param_list = $3;//$1 is function name ;$3 is the fuction params
		Function_D *temp_symbol_info = $1;
		Function_D *next_node = (Function_D*)RW_MALLOC(sizeof(Function_D));
		memset(next_node,ZERO,sizeof(Function_D));
		next_node->param_list = temp_param_list;
		next_node->fun_name = temp_symbol_info->fun_name;
		next_node->fun_type = FUN_IS_FUNC_BUT_UNKOWN_TYPE;
		ASSIGN_FUNC_D_LOC_TO_FUNC_D(next_node,$1);

		//printf("FUN_IS_FUNC --> \"%s\"\n",next_node->fun_name ); //this is the only function decl
		if ((NULL NEQ temp_param_list) && (NULL NEQ temp_param_list->param_list) )
		{
#ifdef BISON_DEBUG
		  //print_params(temp_param_list);
		}
#endif
		$$ = next_node;
		RW_FREE($1);
	}
	| direct_declarator '(' identifier_list ')'
	{
{
		Param_t_list *temp_param_list = $3;//$1 is function name ;$3 is the fuction params
		Function_D* temp_symbol_info = $1;
		Function_D* next_node = (Function_D*)RW_MALLOC(sizeof(Function_D));
		memset(next_node,ZERO,sizeof(Function_D));
		next_node->param_list = temp_param_list;
		next_node->fun_name = temp_symbol_info->fun_name;
		next_node->fun_type = FUN_IS_FUNC_BUT_UNKOWN_TYPE;
		ASSIGN_FUNC_D_LOC_TO_FUNC_D(next_node,$1);
		//printf("parameter_type_list:get token \"%s\"\n",next_node->fun_name ); //this is the only function decl
		if ((NULL NEQ temp_param_list) && (NULL NEQ temp_param_list->param_list) )
		{
#ifdef BISON_DEBUG
		  printf("parameter_type_list:get token \"%s\"\n",temp_param_list->param_list[0].param_type );
		}
#endif
		$$ = next_node;
		RW_FREE($1);
	}
	}

	| direct_declarator '(' ')'
	{
		Function_D *temp_symbol_info = $1;
		Function_D* next_node = (Function_D*)RW_MALLOC(sizeof(Function_D));
		memset(next_node,ZERO,sizeof(Function_D));
		next_node->fun_name = temp_symbol_info->fun_name;
		next_node->fun_type = FUN_IS_FUNC_BUT_UNKOWN_TYPE;
		ASSIGN_FUNC_D_LOC_TO_FUNC_D(next_node,$1);
#ifdef BISON_DEBUG
		 //printf("function without params:\"%s\"\n",next_node->fun_name ); //this is the only function decl
#endif
		$$ = next_node;
		RW_FREE($1);
       }
	;
pointer
	: '*'
	{
		 SYMBOL_INFO_T *temp_symbol_info = $1;
		 SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
		 memset(next_node,0,sizeof(SYMBOL_INFO_T));
		 next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		 memset(next_node->symbol_name,0, MAX_SYMBOL_LEN);
		 strcat(next_node->symbol_name,temp_symbol_info->symbol_name);
		 ASSIGN_SYMBOL_LOC(next_node,temp_symbol_info);
		 $$ = next_node;
	}
	| '*' type_qualifier_list
	{
	 $$ = $1;
	}
	| '*' pointer
	{
		 SYMBOL_INFO_T *temp_symbol_info = $1;
		 SYMBOL_INFO_T *temp_symbol_info2 = $2;
        	 SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
                 memset(next_node,0,sizeof(SYMBOL_INFO_T));
                 next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
                 memset(next_node->symbol_name,0, MAX_SYMBOL_LEN);
                 strcat(next_node->symbol_name,temp_symbol_info->symbol_name);
                 strcat(next_node->symbol_name," ");
                 strcat(next_node->symbol_name,temp_symbol_info2->symbol_name);
        	 ASSIGN_SYMBOL_LOC(next_node,temp_symbol_info2);
        	 $$ = next_node;

	}
	| '*' type_qualifier_list pointer
	{

	 		SYMBOL_INFO_T *temp_symbol_info = $1;
         		 SYMBOL_INFO_T *temp_symbol_info2 = $3;
                 	 SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
                          memset(next_node,0,sizeof(SYMBOL_INFO_T));
                          next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
                          memset(next_node->symbol_name,0, MAX_SYMBOL_LEN);
                          strcat(next_node->symbol_name,temp_symbol_info->symbol_name);
                          strcat(next_node->symbol_name," ");
                          strcat(next_node->symbol_name,temp_symbol_info2->symbol_name);
                 	 ASSIGN_SYMBOL_LOC(next_node,temp_symbol_info2);
                 	 $$ = next_node;
	}
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	{
		$$ = $1;
	}
	| parameter_list ',' ELLIPSIS
	{
		$$ = $1;
	}
	;

parameter_list
	: parameter_declaration
	{
		SYMBOL_INFO_T *temp_symbol_info= $1;
		Param_t_list* param_list = (Param_t_list*)RW_MALLOC(sizeof(Param_t_list));
		memset(param_list,0,sizeof(Param_t_list));
		memcpy(param_list->param_list[param_list->no_param].param_type,temp_symbol_info->symbol_name,strlen(temp_symbol_info->symbol_name));
		param_list->no_param++;
		$$ = param_list;

	}
	| parameter_list ',' parameter_declaration
	{
		SYMBOL_INFO_T *temp_symbol_info= $3;
		Param_t_list* param_list = $1;
		memcpy(param_list->param_list[param_list->no_param].param_type,temp_symbol_info->symbol_name,strlen(temp_symbol_info->symbol_name));
		param_list->no_param++;
		$$ = $1;

	}
	;

parameter_declaration
	: declaration_specifiers declarator
	{
				//do nothing used in  delarator,but if it is a point we need to return
				//we define it is function_d so cannot use symbol_info_t
                		SYMBOL_INFO_T *cur_node1 = $1;

                		Function_D *cur_node2 = $2;

                		SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
                		memset(next_node,ZERO,sizeof(SYMBOL_INFO_T));

                		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
                		if (NULL EQ next_node->symbol_name) {
                			assert(ZERO);
                		}
                		memset(next_node->symbol_name, ZERO, MAX_SYMBOL_LEN);

                		strcat(next_node->symbol_name,cur_node1->symbol_name);
                		if (1 EQ cur_node2->is_ret_val_point ) {
                			strcat(next_node->symbol_name," ");
                                        strcat(next_node->symbol_name,cur_node2->point_str);
                		}
                		$$ = next_node;
                		FREE_FUNC_D_NODE($2);
                		//print_symbols(next_node);
#ifdef BISON_DEBUG

#endif

	}
	| declaration_specifiers abstract_declarator
	{
		//do nothing used in abstract delarator,but if it is a point we need to return
		SYMBOL_INFO_T *cur_node1 = $1;
		SYMBOL_INFO_T *cur_node2 = $2;
		SYMBOL_INFO_T *next_node = (SYMBOL_INFO_T *)P_MALLOCA;
		memset(next_node,ZERO,sizeof(SYMBOL_INFO_T));

		next_node->symbol_name = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		if (NULL EQ next_node->symbol_name) {
			assert(ZERO);
		}
		memset(next_node->symbol_name, ZERO, MAX_SYMBOL_LEN);

		strcat(next_node->symbol_name,cur_node1->symbol_name);
		if (ZERO EQ memcmp(cur_node2->symbol_name,"*",1) ) {
			strcat(next_node->symbol_name," ");
			strcat(next_node->symbol_name,cur_node2->symbol_name);
		}
		$$ = next_node;
        }
	| declaration_specifiers
	{
		$$ = $1;
        }
	;

identifier_list
	: IDENTIFIER
	{
	  Param_t_list *next_node = (Param_t_list *)RW_MALLOC(sizeof(Param_t_list));
	  SYMBOL_INFO_T *temp_symbol_info= $1;
	  memset(next_node,0,sizeof(Param_t_list));
	  memcpy(next_node->param_list[next_node->no_param].param_type, temp_symbol_info->symbol_name, strlen(temp_symbol_info->symbol_name));
	  next_node->no_param++;
	  $$ = next_node;
	}
	| identifier_list ',' IDENTIFIER
	{

	  Param_t_list *next_node = $1;
	  SYMBOL_INFO_T *temp_symbol_info= $3;
	  memcpy(next_node->param_list[next_node->no_param].param_type, temp_symbol_info->symbol_name, strlen(temp_symbol_info->symbol_name));
	  next_node->no_param++;
	  $$ = next_node;
        }
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	{
		$$ = $1;
	}
	| direct_abstract_declarator
	{
		$$ = NULL;
	}
	| pointer direct_abstract_declarator
	{
		//abstract declarator usually used in runtime, we can not check it by using static analyzer
		$$ = NULL;
	}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '[' '*' ']'
	| direct_abstract_declarator '[' '*' ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	{
		RW_FREE($2);
	}
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	{
		//abstract declarator usually used in runtime, we can not check it by using static analyzer
		//but we need to free buffer
		RW_FREE($3);
	}
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| designation initializer
	| initializer_list ',' initializer
	| initializer_list ',' designation initializer
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' block_item_list '}'
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	{
	//to do in the feature
	Function_List_Node_t *fun_node = NULL;
        Function_Pre *dummy = $1;
        if (NULL NEQ dummy->function_d)
        {
        	dummy->function_d->fun_type = FUN_CALL;
                fun_node = transfer_func_to_list_node(dummy);
                if (NULL NEQ fun_node)
                {
                 add_func_node_to_ref_list(fun_node);
                }else {
                 	free_func_node_t(fun_node);
              }
        }
	 FREE_AST_NODE($1);
	}
	| statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	| FOR '(' declaration expression_statement ')' statement
	{
		FREE_AST_NODE($3);
	}
	| FOR '(' declaration expression_statement expression ')' statement
	{
		FREE_AST_NODE($3);
	}
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	{
		Function_List_Node_t *fun_node = NULL;
		fun_node = transfer_func_to_list_node($1);
		if (NULL NEQ fun_node)
		{
		 add_func_node_to_ref_list(fun_node);
		}
		 else {
                 			free_func_node_t(fun_node);
                 		}
		$$ = $1;
		FREE_AST_NODE($1);
	}
	| declaration
	{
		Function_List_Node_t *fun_node = NULL;
		Function_Pre *dummy = $1;
		fun_node = transfer_func_to_list_node($1);
		if (NULL NEQ fun_node)
		{
                 add_func_node_to_ref_list(fun_node);
		} else {
			free_func_node_t(fun_node);
		}

		//assert(0);
		$$ = $1;
		FREE_AST_NODE($1);
	}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	{
	/*
	for origin c grammer,it like this, we do not advise use this way, so we assert!
		int
		add_values (x, y)
		    int x;int y;
		{
		  return x + y;
		}
	*/
	assert(0);
	}
	| declaration_specifiers declarator compound_statement
	{
	/* $1 means ret type, $2 means init param list and fuction name may be also have "*" */
	Function_D *tem_fuc_trace = $2;
	SYMBOL_INFO_T *temp_symbol_info0 = $1;

	if (tem_fuc_trace->fun_type NEQ FUN_NO_FUNC) //this is function reduce
	{
		Function_Pre* next_node =(Function_Pre*)RW_MALLOC(sizeof(Function_Pre) );
		memset(next_node,0,sizeof(Function_Pre));
		next_node->function_d = $2;
		//next_node->fun_location_desc.file_name =
		next_node->fun_location_desc.line =next_node->function_d->func_loc.line;
                next_node->fun_location_desc.column =next_node->function_d->func_loc.column;
		next_node->ret_value_type = (char *)RW_MALLOC(MAX_SYMBOL_LEN);
		memset(next_node->ret_value_type,0,MAX_SYMBOL_LEN);
		memcpy(next_node->ret_value_type,temp_symbol_info0->symbol_name, strlen(temp_symbol_info0->symbol_name));
		if(tem_fuc_trace->is_ret_val_point EQ 1)
		{
			strcat(next_node->ret_value_type," ");
			strcat(next_node->ret_value_type,tem_fuc_trace->point_str);
		}
		if (FUN_IS_FUNC_BUT_UNKOWN_TYPE NEQ tem_fuc_trace->fun_type)
		{
			assert(0);
		} else {
			tem_fuc_trace->fun_type = FUN_DEFINE;
		}

		printf("FUCTION_NAME:%s\n",tem_fuc_trace->fun_name);
		if (NULL NEQ tem_fuc_trace->param_list)
		{
		print_params(tem_fuc_trace->param_list);
		} else {
		printf("No params !\n");
		}

		printf("TYPE is \"%d\"\n", tem_fuc_trace->fun_type);
		printf("ret TYPE is \"%s\"\n", next_node->ret_value_type);
		$$ = next_node;
	} else { // this is struct or other state reduce and it is also func
		//this will not reach
		assert(0);
		Function_D *temp_symbol_info = $2;
		printf("STRUCT OR UNION NAME--> \"%s\"\n",temp_symbol_info->fun_name );
		if ((NULL NEQ temp_symbol_info) && (NULL NEQ temp_symbol_info->fun_name) )
		{
			if( (strcmp(temp_symbol_info0->symbol_name, "typedef struct") == 0)
			  ||(strcmp(temp_symbol_info0->symbol_name, "struct") == 0) ){

				insertAtHead(&struct_link_list,temp_symbol_info->fun_name,NULL);
#ifdef BISON_DEBUG
				printf("BISON_DEBUG ADD STRUCT TO LIST -->\"%s\"\n",temp_symbol_info->fun_name );
#endif
			 $$ = $2;
			 }
		}
		FREE_FUNC_D_NODE($2);

	}
}
	;

declaration_list
	: declaration
	{
		$$ = $1;
	}
	| declaration_list declaration
	{
		$$ = $2;
	}
	;
%%

extern char* yytext;
extern int column;

void yyerror(const char *s)

{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}