#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"
#include "genASM.h"

enum NodeType
{
    NODE_CONST,
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,
    NODE_ASSIGN,
    NODE_STMT,
    NODE_PROG,
    NODE_SIGN,
    NODE_OP,
    NODE_KEY,
    NODE_FUNC
};

enum OperatorType
{
    OP_ZERO,   //����ռλ��ʹOP_ADD��1��ʼ
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_REM,
    OP_EQ,
    OP_NE,
    OP_LE,
    OP_GE,
    OP_LT,
    OP_GT,
    OP_AND,
    OP_OR,
    OP_NOT,
    OP_PLUS,
    OP_MINUS,
    OP_COMMA,
    OP_ADDADD,
    OP_SUBSUB,
    OP_GETADD
};

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
    STMT_ASSIGN,
    STMT_EXPR,
    STMT_IF,
    STMT_FOR,
    STMT_WHILE,
    STMT_RETURN,
    STMT_BLOCK,
    STMT_PRINTF,
    STMT_SCANF,
    STMT_FUNC
}
;
extern int nodeCount;

struct TreeNode {
public:
    int nodeID;  // ������ҵ��������
    int lineno;  //�к�
    NodeType nodeType;

    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);

    void printNodeInfo();   //����ڵڼ��е���Ϣ
    void printChildrenId();  //����ӽڵ㼰����Ϣ

    void printAST(); // ������Լ� + �����ǵ�id����������ÿ���������AST��
    void printSpecialInfo();

    void genNodeId();   //Ϊÿ���ڵ�����һ��������ID

    void genASM();
    Children_Str genTreeASM();
    string genNodeASM(Children_Str child);
int check();
int check(TreeNode*);
int checknode();

public:
    OperatorType optype;  // ����Ǳ���ʽ
    Type* type;  // ���������͡�����ʽ��㣬�����͡�
    StmtType stype;
    int int_val;
    char ch_val;
    bool b_val;
    string str_val;
    string var_name;
    int id_num;
    list<string> ASM;
public:
    static string nodeType2String(NodeType type);
    static string opType2String(OperatorType type);
    static string sType2String(StmtType type);

public:
    TreeNode(int lineno, NodeType type);
};
extern TreeNode* root;
bool checkBool(Type* type, int lineno);

#endif
