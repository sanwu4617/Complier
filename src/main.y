%{
#include "common.h"
#define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror(char const*);
    void setType(TreeNode*);
    %}
%token T_CHAR T_BOOL T_INT

%token IDENTIFIER INTEGER CHAR BOOL STRING

%token IF ELSE

%token LPAREN RPAREN LBRACE RBRACE LSQUBR RSQUBR SEMICOLON COMMA

%token EQ NE GE LE GT LT ASSIGN PLUS SUB MUL DIV REM

%token ADDADD SUBSUB ADDASS SUBASS MULASS DIVASS REMASS ANDASS ORASS

%token WHILE FOR RETURN

%token BREAK CASE CONST CONTINUE DEFAULT DELETE DO ENUM FALSE NEW NULLPTR STRUCT SWITCH TRUE UNION VOID

%token PRINTF SCANF MAIN

%right ELSE

%left COMMA

%right ASSIGN

%left OR

%left AND

%left EQ NE GE LE GT LT

%left ADD SUB

%left MUL DIV REM

%left NOT

%left GETADD

%right ADDADD SUBSUB
%%

program
: statements{ root = new TreeNode(0, NODE_PROG); root->addChild($1); };

block
: LBRACE statements RBRACE{ 
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_BLOCK;
    node->addChild($2);
    $$ = node; 
};

statements
: statement{ $$ = $1; }
| statements statement{ $$ = $1; $$->addSibling($2); }
;

statement
: SEMICOLON{ $$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP; }
| declaration SEMICOLON{ $$ = $1; }
| assign_stmt{ $$ = $1; }
| expr SEMICOLON{ $$ = $1; }
| if_stmt{ $$ = $1; }
| for_stmt{ $$ = $1; }
| while_stmt{ $$ = $1; }
| return_stmt{ $$ = $1; }
| printf_stmt{ $$ = $1; }
| scanf_stmt{ $$ = $1; }
| block{ $$ = $1; }
| main_func{ $$ = $1; }
;

idlist
: idlist COMMA IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        iter_id = idlist.find(pair<int, string>(id_section.top(), $3->var_name));
        if (iter_id == idlist.end())
        {
            pair<int, string> p(id_section.top(), $3->var_name);
            id_info temp;
            temp.id = ids;
            temp.type = &$1->type;
            idlist.insert(pair<pair<int, string>, id_info>(p, temp));
            $3->id_num = ids;
            ids++;
        }
        else
        {
            cout << "Variable " << $3->var_name << " is redefined at line " << $3->lineno << "." << endl;
        }
    }
    else
    {
        pair<int, string> p(0, $3->var_name);
        id_info temp;
        temp.id = ids;
        temp.type = &$1->type;
        idlist.insert(pair<pair<int, string>, id_info>(p, temp));
        $3->id_num = ids;
        ids++;
    }
}
| IDENTIFIER{
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->addChild($1);
    $$ = node;
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        iter_id = idlist.find(pair<int, string>(id_section.top(), $1->var_name));
        if (iter_id == idlist.end())
        {
            pair<int, string> p(id_section.top(), $1->var_name);
            id_info temp;
            temp.id = ids;
            temp.type = &$1->type;
            idlist.insert(pair<pair<int, string>, id_info>(p, temp));
            $1->id_num = ids;
            ids++;
        }
        else
        {
            cerr << "Variable " << $1->var_name << " is redefined at line " << $1->lineno << "." << endl;
        }
    }
    else
    {
        pair<int, string> p(0, $1->var_name);
        id_info temp;
        temp.id = ids;
        temp.type = &$1->type;
        idlist.insert(pair<pair<int, string>, id_info>(p, temp));
        $1->id_num = ids;
        ids++;
    }
}
;
declaration
: T IDENTIFIER ASSIGN expr{  // declare and init
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    node->addChild($4);
    $$ = node;
    setType(node);
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        iter_id = idlist.find(pair<int, string>(id_section.top(), $2->var_name));
        if (iter_id == idlist.end())
        {
            pair<int, string> p(id_section.top(), $2->var_name);
            id_info temp;
            temp.id = ids;
            temp.type = &$1->type;
            idlist.insert(pair<pair<int, string>, id_info>(p, temp));
            $2->id_num = ids;
            ids++;
        }
        else
        {
            cerr << "Variable " << $2->var_name << " is redefined at line " << $2->lineno << "." << endl;
        }
    }
    else
    {
        pair<int, string> p(0, $2->var_name);
        id_info temp;
        temp.id = ids;
        temp.type = &$1->type;
        idlist.insert(pair<pair<int, string>, id_info>(p, temp));
        $2->id_num = ids;
        ids++;
    }
}

| T idlist{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);
    node->addChild($2);
    $2->type = $1->type;
    setType(node);
    $$ = node;
}
;

T: T_INT{ $$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT; }
| T_CHAR{ $$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR; }
| T_BOOL{ $$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL; }
;

expr
: IDENTIFIER{
    $$ = $1;
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        stack<int> temp;
        while (!id_section.empty())
        {
            iter_id = idlist.find(pair<int, string>(id_section.top(), $$->var_name));
            if (iter_id == idlist.end())
            {
                temp.push(id_section.top());
                id_section.pop();
            }
            else
            {
                $$->id_num = iter_id->second.id;
                $$->type = *iter_id->second.type;
                break;
            }
            if (id_section.empty())
            {
                cerr << "Undefined identifier " << $1->var_name << " at line " << $1->lineno << "." << endl;
                break;
            }
        }
        while (!temp.empty())
        {
            id_section.push(temp.top());
            temp.pop();
        }
    }
    else
    {
        $$->id_num = -1;
        cerr << "Undefined identifier " << $1->var_name << " at line " << $1->lineno << "." << endl;
    }
}
| INTEGER{ $$ = $1; }
| CHAR{ $$ = $1; }
| STRING{ $$ = $1; }
| expr ADD expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_ADD;
    node->addChild($1);
    node->addChild($3);
    node->type = $1->type;
    $$ = node;
}
| expr SUB expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_SUB;
    node->addChild($1);
    node->addChild($3);
    node->type = $1->type;
    $$ = node;
}
| expr MUL expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_MUL;
    node->addChild($1);
    node->addChild($3);
    node->type = $1->type;
    $$ = node;
}
| expr DIV expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_DIV;
    node->addChild($1);
    node->addChild($3);
    node->type = $1->type;
    $$ = node;
}
| expr REM expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_REM;
    node->addChild($1);
    node->addChild($3);
    node->type = $1->type;
    $$ = node;
}
| expr EQ expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_EQ;
    node->addChild($1);
    node->addChild($3);
    node->type = TYPE_BOOL;
    $$ = node;
}
| expr NE expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_NE;
    node->addChild($1);
    node->addChild($3);
    node->type = TYPE_BOOL;
    $$ = node;
}
| expr LE expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_LE;
    node->addChild($1);
    node->addChild($3);
    node->type = TYPE_BOOL;
    $$ = node;
}
| expr GE expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_GE;
    node->addChild($1);
    node->addChild($3);
    node->type = TYPE_BOOL;
    $$ = node;
}
| expr LT expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_LT;
    node->addChild($1);
    node->addChild($3);
    node->type = TYPE_BOOL;
    $$ = node;
}
| expr GT expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_GT;
    node->addChild($1);
    node->addChild($3);
    node->type = TYPE_BOOL;
    $$ = node;
}
| expr AND expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_AND;
    node->addChild($1);
    node->addChild($3);
    node->type = $1->type;
    $$ = node;
}
| expr OR expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_OR;
    node->addChild($1);
    node->addChild($3);
    node->type = $1->type;
    $$ = node;
}
| expr COMMA expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_COMMA;
    node->addChild($1);
    node->addChild($3);
    node->type = $1->type;
    $$ = node;
}
| NOT expr{
    TreeNode * node = new TreeNode($1->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_NOT;
    node->addChild($2);
    node->type = $1->type;
    $$ = node;
}
| SUB expr{
    TreeNode * node = new TreeNode($1->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_MINUS;
    node->addChild($2);
    node->type = $1->type;
    $$ = node;
}
| ADD expr{
    TreeNode * node = new TreeNode($1->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_PLUS;
    node->addChild($2);
    node->type = $1->type;
    $$ = node;
}
| expr ADDADD{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_ADDADD;
    node->addChild($1);
    node->type = $1->type;
    $$ = node;
}
| expr SUBSUB{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_SUBSUB;
    node->addChild($1);
    node->type = $1->type;
    $$ = node;
}
| GETADD expr{
    TreeNode * node = new TreeNode($2->lineno, NODE_EXPR);
    node->stype = STMT_EXPR;
    node->optype = OP_GETADD;
    node->addChild($2);
    node->type = nullptr;
    $$ = node;
}
;

left_val
: IDENTIFIER{
    $$ = $1;
    map<pair<int, string>, id_info>::iterator iter_id;
    if (id_section.size() > 0)
    {
        stack<int> temp;
        while (!id_section.empty())
        {
            iter_id = idlist.find(pair<int, string>(id_section.top(), $$->var_name));
            if (iter_id == idlist.end())
            {
                temp.push(id_section.top());
                id_section.pop();
            }
            else
            {
                $1->id_num = iter_id->second.id;
                $1->type = *iter_id->second.type;
                break;
            }
        }
        while (!temp.empty())
        {
            id_section.push(temp.top());
            temp.pop();
        }
    }
    else
    {
        $$->id_num = -1;
    }
};

assign_stmt
: left_val ASSIGN expr SEMICOLON{
    TreeNode * node = new TreeNode($2->lineno, NODE_ASSIGN);
    node->stype = STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| left_val ADDASS expr SEMICOLON{
    TreeNode * node = new TreeNode($2->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_ADD;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| left_val SUBASS expr SEMICOLON{
    TreeNode * node = new TreeNode($2->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_SUB;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| left_val MULASS expr SEMICOLON{
    TreeNode * node = new TreeNode($2->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_MUL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| left_val DIVASS expr SEMICOLON{
    TreeNode * node = new TreeNode($2->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_DIV;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| left_val REMASS expr SEMICOLON{
    TreeNode * node = new TreeNode($2->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_REM;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| left_val ANDASS expr SEMICOLON{
    TreeNode * node = new TreeNode($2->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_AND;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| left_val ORASS expr SEMICOLON{
    TreeNode * node = new TreeNode($2->lineno, NODE_ASSIGN);
    node->stype = STMT_EXPR;
    node->optype = OP_OR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| left_val ASSIGN assign_stmt{
    TreeNode * node = new TreeNode($2->lineno, NODE_ASSIGN);
    node->stype = STMT_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

if_stmt
:  IF LPAREN expr RPAREN statement{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_IF;
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
|  IF LPAREN expr RPAREN statement ELSE statement{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_IF;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    $$ = node;
};

for_stmt
: FOR LPAREN statement statement expr RPAREN statement
{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_FOR;
    node->addChild($3);
    node->addChild($4);
    node->addChild($5);
    node->addChild($7);
    $$ = node;
};

while_stmt
: WHILE LPAREN expr RPAREN statement{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_WHILE;
    node->addChild($3);
    node->addChild($5);
    $$ = node;
};

return_stmt
: RETURN SEMICOLON{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_RETURN;
    $$ = node;
}
| RETURN expr SEMICOLON{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_RETURN;
    node->addChild($2);
    $$ = node;
};

printf_stmt
: PRINTF LPAREN STRING RPAREN SEMICOLON{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_PRINTF;
    node->addChild($3);
    $$ = node;
}
| PRINTF LPAREN STRING COMMA expr RPAREN SEMICOLON{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_PRINTF;
    node->addChild($3);
    node->addChild($5);
    $$ = node;
};

scanf_stmt
: SCANF LPAREN STRING RPAREN SEMICOLON{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_SCANF;
    node->addChild($3);
    $$ = node;
}
| SCANF LPAREN STRING COMMA expr RPAREN SEMICOLON{
    TreeNode * node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_SCANF;
    node->addChild($3);
    node->addChild($5);
    $$ = node;
};

main_func
: T_INT MAIN LPAREN RPAREN block{
    TreeNode * node = new TreeNode($1->lineno, NODE_FUNC);
    node->stype = STMT_FUNC;
    node->addChild($5);
    $$ = node;
}
| VOID MAIN LPAREN RPAREN block{
    TreeNode * node = new TreeNode($1->lineno, NODE_FUNC);
    node->stype = STMT_FUNC;
    node->addChild($5);
    $$ = node;
}
%%

int yyerror(char const* message)
{
    cout << message << " at line " << lineno << endl;
    return -1;
}
