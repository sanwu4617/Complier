#include "tree.h"
int nodeCount;
void TreeNode::addChild(TreeNode* child) {
    if (this->child == nullptr)
        this->child = child;
    else
    {
        TreeNode* temp = this->child;
        while (temp->sibling != nullptr)
            temp = temp->sibling;
        temp->sibling = child;
    }
}
void TreeNode::addSibling(TreeNode* sibling) {
    TreeNode* temp = this;
    while (temp->sibling != nullptr)
        temp = temp->sibling;
    temp->sibling = sibling;
}
TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno = lineno;
    this->nodeType = type;
}
void TreeNode::genNodeId() {
    nodeID = nodeCount;
    nodeCount++;
    if (child != nullptr)
        child->genNodeId();
    if (sibling != nullptr)
        sibling->genNodeId();
}
void TreeNode::printNodeInfo() {
    switch (nodeType)
    {
    case NODE_CONST:
        cout << "const\t\t";
        break;
    case NODE_VAR:
        cout << "variable\t";
        break;
    case NODE_EXPR:
        cout << "expression\t";
        break;
    case NODE_TYPE:
        cout << "type\t\t";
        break;
    case NODE_ASSIGN:
        cout << "assign\t\t";
        break;
    case NODE_STMT:
        cout << "statement\t";
        break;
    case NODE_PROG:
        cout << "program\t";
        break;
    case NODE_SIGN:
        cout << "sign\t\t";
        break;
    case NODE_OP:
        cout << "operator\t";
        break;
    case NODE_KEY:
        cout << "key\t\t";
        break;
    case NODE_FUNC:
        cout << "function\t";
        break;
    default:
        cout << "unknown\t";
        break;
    }
    if (type == TYPE_INT)
    {
        cout << "Type:int\t";
    }
    else if (type == TYPE_BOOL)
    {
        cout << "Type:bool\t";
    }
    else if (type == TYPE_STRING)
        cout << "Type:string\t";
    else if (type == TYPE_CHAR)
    {
        cout << "Type:char\t";
    }
    else
        cout << "Type:unknown\t";
    printChildrenId();
    printSpecialInfo();
    cout << endl;
}
void TreeNode::printChildrenId() {
    TreeNode* temp = nullptr;
    if (child == nullptr)
        return;
    if (child != nullptr)
        temp = child;
    cout << "children:[";
    while (temp != nullptr)
    {
        cout << "@" << temp->nodeID << " ";
        temp = temp->sibling;
    }
    cout << "\t] ";
}
void TreeNode::printAST() {
    cout << "Ino@" << lineno << "\t" << "@" << nodeID << "\t";
    printNodeInfo();
    if (child != nullptr)
        child->printAST();
    if (sibling != nullptr)
        sibling->printAST();
}
// You can output more info...
void TreeNode::printSpecialInfo() {
    switch (this->nodeType) {
    case NODE_CONST:
        if (type != nullptr)
        {
            if (type == TYPE_INT)
            {
                cout << "type:int";
                cout << "\tvalue:" << int_val;
            }
            else if (type == TYPE_BOOL)
            {
                cout << "type:bool";
                cout << "\t\tvalue:" << b_val;
            }
            else if (type == TYPE_STRING)
                cout << "type:string";
            else if (type == TYPE_CHAR)
            {
                cout << "type:char";
                cout << "\tvalue:" << ch_val;
            }
            else
                cout << "type:unknown";
        }
        break;
    case NODE_VAR:
        cout << "varname:" << var_name;
        cout << "\tid:" << id_num;
        break;
    case NODE_EXPR:
        if (optype != 0)
        {
            switch (optype)
            {
            case OP_ADD:
                cout << "expr: add";
                break;
            case OP_SUB:
                cout << "expr: sub";
                break;
            case OP_MUL:
                cout << "expr: mul";
                break;
            case OP_DIV:
                cout << "expr: div";
                break;
            case OP_REM:
                cout << "expr: rem";
                break;
            case OP_EQ:
                cout << "expr: eq";
                break;
            case OP_NE:
                cout << "expr: ne";
                break;
            case OP_LE:
                cout << "expr: le";
                break;
            case OP_GE:
                cout << "expr: ge";
                break;
            case OP_LT:
                cout << "expr: lt";
                break;
            case OP_GT:
                cout << "expr: gt";
                break;
            case OP_AND:
                cout << "expr: and";
                break;
            case OP_OR:
                cout << "expr: or";
                break;
            case OP_NOT:
                cout << "expr: not";
                break;
            case OP_PLUS:
                cout << "expr: plus";
                break;
            case OP_MINUS:
                cout << "expr: minus";
                break;
            case OP_COMMA:
                cout << "expr: comma";
                break;
            case OP_ADDADD:
                cout << "expr: addadd";
                break;
            case OP_SUBSUB:
                cout << "expr: subsub";
                break;
            case OP_GETADD:
                cout << "expr: getadd";
                break;
            default:
                break;
            }
        }
        break;
    case NODE_ASSIGN:
        if (optype != 0)
        {
            switch (optype)
            {
            case OP_ADD:
                cout << "assign: add assign";
                break;
            case OP_SUB:
                cout << "assign: sub assign";
                break;
            case OP_MUL:
                cout << "assign: mul assign";
                break;
            case OP_DIV:
                cout << "assign: div assign";
                break;
            case OP_REM:
                cout << "assign: rem assign";
                break;
            case OP_AND:
                cout << "assign: and assign";
                break;
            case OP_OR:
                cout << "assign: or assign";
                break;
            default:
                break;
            }
        }
        break;
    case NODE_STMT:
        if (stype != 0)
        {
            switch (stype)
            {
            case STMT_SKIP:
                cout << "stmt:skip";
                break;
            case STMT_DECL:
                cout << "stmt:decl";
                break;
            case STMT_ASSIGN:
                cout << "stmt:assign";
                break;
            case STMT_EXPR:
                cout << "stmt:expr";
                break;
            case STMT_IF:
                cout << "stmt:if";
                break;
            case STMT_FOR:
                cout << "stmt:for";
                break;
            case STMT_WHILE:
                cout << "stmt:while";
                break;
            case STMT_RETURN:
                cout << "stmt:return";
                break;
            case STMT_BLOCK:
                cout << "stmt:block";
                break;
            case STMT_PRINTF:
                cout << "stmt:printf";
                break;
            case STMT_SCANF:
                cout << "stmt:scanf";
                break;
            case STMT_FUNC:
                cout << "stmt:func";
                break;
            default:
                cout << "unknown";
            }
        }
        break;
    case NODE_TYPE:
        if (type != nullptr)
        {
            if (type == TYPE_INT)
                cout << "type:int";
            else if (type == TYPE_BOOL)
                cout << "type:bool";
            else if (type == TYPE_STRING)
                cout << "type:string";
            else if (type == TYPE_CHAR)
                cout << "type:char";
        }
        break;
    default:
        break;
    }
}

string TreeNode::sType2String(StmtType type) {
    return "?";
}
string TreeNode::nodeType2String(NodeType type) {
    return "<>";
}
string TreeNode::opType2String(OperatorType type) {
    return "+";
}
void setType(TreeNode* node) {
    TreeNode* temp = node->child->sibling;
    Type* decl_type = node->child->type;
    while (temp->child != nullptr)
    {
        if (temp->sibling != nullptr)
            temp->sibling->type = decl_type;
        temp = temp->child;
        temp->type = decl_type;
    }
    temp->type = decl_type;
}
bool checkBool(Type* type, int lineno)
{
    if (type == TYPE_BOOL || type == TYPE_INT || type == TYPE_CHAR)
    {
cout<<"Check bool.";
        if (type == TYPE_INT)
            cout << " Transformed int to bool.";
        if (type == TYPE_CHAR)
            cout << " Transformed char to bool.";
        cout << endl;
return true;
    }
return false;
}
