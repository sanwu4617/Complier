#include "common.h"
int TreeNode::check()
{
    return check(this);
}
int TreeNode::check(TreeNode* root0)
{
    int return_num = 0;
    if (root0->child != nullptr)
        return_num += root0->child->check(root0->child);
    return_num += checknode();
    if (root0->sibling != nullptr)
        return_num += root0->sibling->check(root0->sibling);
    return return_num;
}
int TreeNode::checknode()
{
    if (child == nullptr)
        return 0;
    if (nodeType == NODE_EXPR)
    {
        switch (optype)
        {
        case OP_ADD:
        case OP_SUB:
        case OP_MUL:
            if (child->type == TYPE_INT && child->sibling->type == TYPE_INT)
            {
                type = TYPE_INT;
                cout << "Checked line " << lineno << "." << endl;
                return 0;
            }
            else
            {
                type = TYPE_INT;
                cout << "Type Error at line " << lineno << "." << endl;
                return 1;
            }
        case OP_DIV:
        case OP_REM:
            if (child->type == TYPE_INT && child->sibling->type == TYPE_INT)
            {
                type = TYPE_INT;
                cout << "Checked line " << lineno << ".";
                if (child->sibling->int_val == 0)
                    cout << " Divided by zero!";
                cout << endl;
                return 0;
            }
            else
            {
                type = TYPE_INT;
                cout << "Type Error at line " << lineno << "." << endl;
                return 1;
            }
        case OP_EQ:
        case OP_NE:
        case OP_LE:
        case OP_GE:
        case OP_LT:
        case OP_GT:
            if (child->type == TYPE_INT && child->sibling->type == TYPE_INT)
            {
                type = TYPE_BOOL;
                cout << "Checked line " << lineno << "." << endl;
                return 0;
            }
            else
            {
                type = TYPE_BOOL;
                cout << "Type Error at line " << lineno << "." << endl;
                return 1;
            }
        case OP_AND:
        case OP_OR:
            if (checkBool(child->type, lineno) && checkBool(child->sibling->type, lineno))
            {
                type = TYPE_BOOL;
                cout << "Checked line " << lineno << "." << endl;
                return 0;
            }
            else
            {
                type = TYPE_BOOL;
                cout << "Type Error at line " << lineno << "." << endl;
                return 1;
            }
        case OP_NOT:
            if (checkBool(child->type, lineno))
            {
                type = TYPE_BOOL;
                cout << "Checked line " << lineno << "." << endl;
                return 0;
            }
            else
            {
                type = TYPE_BOOL;
                cout << "Type Error at line " << lineno << "." << endl;
                return 1;
            }
        case OP_PLUS:
        case OP_MINUS:
        case OP_ADDADD:
        case OP_SUBSUB:
            if (child->type == TYPE_INT)
            {
                type = TYPE_INT;
                cout << "Checked line " << lineno << "." << endl;
                return 0;
            }
            else
            {
                type = TYPE_INT;
                cout << "Type Error at line " << lineno << "." << endl;
                return 1;
            }
        case OP_GETADD:
            if (child->type == TYPE_INT || child->type == TYPE_CHAR || child->type == TYPE_BOOL)
            {
                type = child->type;
                cout << "Checked line " << lineno << "." << endl;
                return 0;
            }
            else
            {
                type = TYPE_INT;
                cout << "Type Error at line " << lineno << "." << endl;
                return 1;
            }
        case OP_COMMA:
        default:
            return 0;
        }
    }
    if (nodeType == NODE_STMT)
    {
        if (stype == STMT_IF)
        {
            cout << "Checked line " << lineno << ": if statement.";
            checkBool(child->type, lineno);
        }
        if (stype == STMT_FOR)
        {
            cout << "Checked line " << lineno << ": for statement.";
            checkBool(child->sibling->type, lineno);
            checkBool(child->sibling->sibling->type, lineno);
        }
        if (stype == STMT_WHILE)
        {
            cout << "Checked line " << lineno << ": while statement.";
            checkBool(child->type, lineno);
        }
    }
    return 0;
}