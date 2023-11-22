#include "common.h"
int temp_count = 0;
int label_count = 0;
int str_count=0;
list<string> bssASM;
list<string> textASM;
list<string> rodataASM;
string InttoStr(int a)
{
	string str;
	if (a == 0)
		return "0";
	char c[10] = { 0 };
	int i = 0;
	for (i = 0; a > 0; i++)
	{
		c[i] = a % 10;
		a /= 10;
	}
	for (i -= 1; i >= 0; i--)
	{
		str += c[i] + '0';
	}
	return str;
}
Children_Str::Children_Str(int max0)
{
	max = max0;
	child_str = new string[max];
	children_num = 0;
}
Children_Str& Children_Str::operator=(string str)
{
	child_str[0] = str;
	children_num = 0;
	return *this;
}
Children_Str& Children_Str::operator+=(string str)
{
	if (children_num < max - 1)
	{
		child_str[children_num + 1] = str;
		children_num++;
	}
	return *this;
}
string& Children_Str::operator[] (int n)
{
	return child_str[n];
}
void TreeNode::genASM()
{
	//为变量分配内存空间：放在.bss段
	bssASM.push_back(string(".bss"));
	map<pair<int, string>, id_info>::iterator iter;
	for (iter = idlist.begin(); iter != idlist.end(); iter++)
	{
		int id_num = iter->second.id;
		Type** type = iter->second.type;
		if (*type == TYPE_INT)
		{
			bssASM.push_back(string(".comm var_"+InttoStr(id_num)+",4,4"));
			/*
			ASM.push_back(string("global var_" + InttoStr(id_num)));
			ASM.push_back(string(".bss"));
			ASM.push_back(string(".align 4"));
			ASM.push_back(string(".type var_" + InttoStr(id_num) + ", @object"));
			ASM.push_back(string(".size var_" + InttoStr(id_num) + ", 4"));
			ASM.push_back(string("var_" + InttoStr(id_num)));
			ASM.push_back(string(".zero 4"));*/
		}
		if (*type == TYPE_BOOL || *type == TYPE_CHAR)
		{
			bssASM.push_back(string(".comm var_"+InttoStr(id_num)+",1,1"));
			/*
			ASM.push_back(string("global var_" + InttoStr(id_num)));
			ASM.push_back(string(".type var_" + InttoStr(id_num) + ", @object"));
			ASM.push_back(string(".size var_" + InttoStr(id_num) + ", 1"));
			ASM.push_back(string("var_" + InttoStr(id_num)));
			ASM.push_back(string(".zero 1"));*/
		}
	}
	//生成rodata段段首部
	rodataASM.push_back(".section .rodata");
	//从根节点开始递归生成汇编代码
	textASM.push_back(string(".text"));
	genTreeASM();
	textASM.splice(textASM.end(),ASM);   //因为递归生成的汇编代码在变量ASM中
	//将临时变量加入bss段
	for(int i=0;i<temp_count;i++)
	{
		bssASM.push_back(string(".comm temp_"+InttoStr(i)+",4,4"));
	}
	//连接各段汇编代码
	list<string> zero;
	ASM=zero;
	if(bssASM.size()>1)
	{
		ASM.splice(ASM.end(),bssASM);
	}
	if(rodataASM.size()>1)
	{
		ASM.splice(ASM.end(),rodataASM);
	}
	if(textASM.size()>1)
	{
		ASM.splice(ASM.end(),textASM);
	}

	list<string>::iterator iter0;
	for (iter0 = ASM.begin(); iter0 != ASM.end(); iter0++)
	{
		if (string(*iter0)[0] != 'l' || string(*iter0)[1] != 'a')
			cout << "\t";
		cout << *iter0 << endl;
	}
}
Children_Str TreeNode::genTreeASM()
{
	Children_Str str;
	if (child != nullptr)
		str = child->genTreeASM();
	Children_Str ret;
	ret = genNodeASM(str);    //将子节点传来的字符串集合作为参数
	if (sibling != nullptr)
		ret += sibling->genTreeASM()[0];
	return ret;    //返回本节点和兄弟节点的字符串集合
}
string TreeNode::genNodeASM(Children_Str children_str)
{
	TreeNode* temp1;
	switch (nodeType)
	{
	case NODE_VAR:
		return "var_" + InttoStr(int_val);
	case NODE_CONST:
	    if(type==TYPE_INT)
		    return "$" + InttoStr(int_val);
		if(type==TYPE_CHAR)
		    return "$" + InttoStr(int_val);
		if(type==TYPE_STRING)
		{
			rodataASM.push_back(string("str_"+InttoStr(str_count)+":"));
		    rodataASM.push_back(string(".string "+str_val));
			return "str_"+InttoStr(str_count++);
		}
	case NODE_FUNC:
		ASM.push_back(".text");
		ASM.push_back(".globl main");
		ASM.push_back(".type main, @function");
		ASM.push_back("main:");
		ASM.splice(ASM.end(), child->ASM);
		return "";
	case NODE_PROG:
		ASM.splice(ASM.end(), child->ASM);
	default:
		switch (stype)
		{
		case STMT_SKIP:
			return "";
		case STMT_DECL:
			if (child->sibling->sibling != nullptr)
			{
				ASM.push_back(string("movl $" + InttoStr(child->sibling->sibling->int_val) + ", var_" + InttoStr(child->sibling->id_num)));
				//cout << "movl $" << child->sibling->sibling->int_val << ", var_" << child->sibling->id_num << endl;
			}
			return "";
		case STMT_ASSIGN:
			ASM.splice(ASM.end(), child->sibling->ASM);
			ASM.push_back(string("movl " + children_str[1] + ", var_" + InttoStr(child->id_num)));
			//cout << "movl " << children_str[1] << ", var_" << child->id_num << endl;
			return "var_"+InttoStr(child->id_num);
		case STMT_EXPR:
			switch (optype)
			{
			case OP_ADD:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("addl " + children_str[1] + ", %eax"));
				ASM.push_back(string("movl %eax, temp_" + InttoStr(temp_count)));
				return "temp_" + InttoStr(temp_count++);
			case OP_SUB:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("subl " + children_str[1] + ", %eax"));
				ASM.push_back(string("movl %eax, temp_" + InttoStr(temp_count)));
				return "temp_" + InttoStr(temp_count++);
			case OP_MUL:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("imull " + children_str[1] + ", %eax"));
				ASM.push_back(string("movl %eax, temp_" + InttoStr(temp_count)));
				ASM.push_back(string("xor %edx,%edx"));    //清空edx寄存器  
				return "temp_" + InttoStr(temp_count++);
			case OP_DIV:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("movl " + children_str[1] + ", %ebx"));
				ASM.push_back(string("idivl %ebx"));
				ASM.push_back(string("movl %eax, temp_" + InttoStr(temp_count)));
				ASM.push_back(string("xor %edx,%edx"));    //清空edx寄存器 
				return "temp_" + InttoStr(temp_count++);
			case OP_REM:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("movl " + children_str[1] + ", %ebx"));
				ASM.push_back(string("idivl %ebx"));
				ASM.push_back(string("movl %edx, temp_" + InttoStr(temp_count)));
				ASM.push_back(string("xor %edx,%edx"));    //清空edx寄存器 
				return "temp_" + InttoStr(temp_count++);
			case OP_EQ:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("cmpl " + children_str[1] + ", %eax"));
				ASM.push_back(string("jz label_" + InttoStr(label_count)));
				ASM.push_back(string("movl $0, temp_" + InttoStr(temp_count)));
				ASM.push_back(string("jmp label_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count) + ":"));
				ASM.push_back(string("movl $1, temp_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count + 1) + ":"));
				label_count += 2;
				temp_count += 1;
				return "temp_" + InttoStr(temp_count - 1);
			case OP_NE:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("cmpl " + children_str[1] + ", %eax"));
				ASM.push_back(string("jnz label_" + InttoStr(label_count)));
				ASM.push_back(string("movl $0, temp_" + InttoStr(temp_count)));
				ASM.push_back(string("jmp label_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count) + ":"));
				ASM.push_back(string("movl $1, temp_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count + 1) + ":"));
				label_count += 2;
				temp_count += 1;
				return "temp_" + InttoStr(temp_count - 1);
			case OP_LE:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("cmpl " + children_str[1] + ", %eax"));
				ASM.push_back(string("jle label_" + InttoStr(label_count)));
				ASM.push_back(string("movl $0, temp_" + InttoStr(temp_count)));
				ASM.push_back(string("jmp label_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count) + ":"));
				ASM.push_back(string("movl $1, temp_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count + 1) + ":"));
				label_count += 2;
				temp_count += 1;
				return "temp_" + InttoStr(temp_count - 1);
			case OP_GE:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("cmpl " + children_str[1] + ", %eax"));
				ASM.push_back(string("jge label_" + InttoStr(label_count)));
				ASM.push_back(string("movl $0, temp_" + InttoStr(temp_count)));
				ASM.push_back(string("jmp label_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count) + ":"));
				ASM.push_back(string("movl $1, temp_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count + 1) + ":"));
				label_count += 2;
				temp_count += 1;
				return "temp_" + InttoStr(temp_count - 1);
			case OP_LT:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("cmpl " + children_str[1] + ", %eax"));
				ASM.push_back(string("jl label_" + InttoStr(label_count)));
				ASM.push_back(string("movl $0, temp_" + InttoStr(temp_count)));
				ASM.push_back(string("jmp label_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count) + ":"));
				ASM.push_back(string("movl $1, temp_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count + 1) + ":"));
				label_count += 2;
				temp_count += 1;
				return "temp_" + InttoStr(temp_count - 1);
			case OP_GT:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("cmpl " + children_str[1] + ", %eax"));
				ASM.push_back(string("jg label_" + InttoStr(label_count)));
				ASM.push_back(string("movl $0, temp_" + InttoStr(temp_count)));
				ASM.push_back(string("jmp label_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count) + ":"));
				ASM.push_back(string("movl $1, temp_" + InttoStr(label_count + 1)));
				ASM.push_back(string("label_" + InttoStr(label_count + 1) + ":"));
				label_count += 2;
				temp_count += 1;
				return "temp_" + InttoStr(temp_count - 1);
			case OP_AND:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("andl " + children_str[1] + ", %eax"));
				ASM.push_back(string("movl %eax, temp_" + InttoStr(temp_count)));
				return "temp_" + InttoStr(temp_count++);
			case OP_OR:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("orl " + children_str[1] + ", %eax"));
				ASM.push_back(string("movl %eax, temp_" + InttoStr(temp_count)));
				return "temp_" + InttoStr(temp_count++);
			case OP_NOT:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("notl %eax"));
				ASM.push_back(string("movl %eax, temp_" + InttoStr(temp_count)));
				return "temp_" + InttoStr(temp_count++);
			case OP_PLUS:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("movl %eax, temp_" + InttoStr(temp_count)));
				return "temp_" + InttoStr(temp_count++);
			case OP_MINUS:
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("movl $0, %ebx"));
				ASM.push_back(string("subl $eax, %ebx"));
				ASM.push_back(string("movl %ebx, temp_" + InttoStr(temp_count)));
				return "temp_" + InttoStr(temp_count++);
			case OP_ADDADD:    //只支持i++单独出现这种情况，a=i++视为a=++i
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("addl $1, %eax"));
				ASM.push_back(string("movl $eax, "+children_str[0]));
				return children_str[0];
			case OP_SUBSUB:    //只支持i++单独出现这种情况，a=i++视为a=++i
				ASM.push_back(string("movl " + children_str[0] + ", %eax"));
				ASM.push_back(string("subl $1, %eax"));
				ASM.push_back(string("movl $eax, "+children_str[0]));
				return children_str[0];
			case OP_GETADD:   //只支持scanf中的取地址
			    return children_str[0];
			default:
				return "";
			}
		case STMT_IF:
			ASM.push_back(string("movl " + children_str[0] + ", %eax"));
			ASM.push_back(string("cmpl $0, %eax"));
			ASM.push_back(string("jz label_" + InttoStr(label_count)));
			ASM.splice(ASM.end(), child->sibling->ASM);    //将if部分的语句插入进去
			if (child->sibling->sibling != nullptr)     //表示有else部分
			{
				ASM.push_back(string("jmp label_") + InttoStr(label_count + 1));
				ASM.push_back(string("label_") + InttoStr(label_count) + ":");
				ASM.splice(ASM.end(), child->sibling->sibling->ASM);
				ASM.push_back(string("label_") + InttoStr(label_count + 1) + ":");
				label_count += 2;
			}
			else       //表示没有else部分
				ASM.push_back(string("label_" + InttoStr(label_count++) + ":"));
			return "";
		case STMT_FOR:
			ASM.splice(ASM.end(), child->ASM);    //第一个条件
			ASM.push_back(string("label_" + InttoStr(label_count) + ":"));
			ASM.splice(ASM.end(), child->sibling->ASM);   //第二个条件
			ASM.push_back(string("movl " + children_str[1] + ", %eax"));
			ASM.push_back(string("cmpl $0, %eax"));
			ASM.push_back(string("jz label_" + InttoStr(label_count + 1)));
			ASM.splice(ASM.end(), child->sibling->sibling->sibling->ASM);
			ASM.splice(ASM.end(), child->sibling->sibling->ASM);
			ASM.push_back(string("jmp label_" + InttoStr(label_count)));
			ASM.push_back(string("label_" + InttoStr(label_count + 1) + ":"));
			label_count += 2;
			return "";
		case STMT_WHILE:
			ASM.push_back(string("label_" + InttoStr(label_count) + ":"));
			ASM.splice(ASM.end(), child->ASM);   //循环条件
			//ASM.push_back(string(""));
			ASM.push_back(string("movl " + children_str[0] + ", %eax"));
			ASM.push_back(string("cmpl $0, %eax"));
			ASM.push_back(string("jz label_" + InttoStr(label_count + 1)));
			ASM.splice(ASM.end(), child->sibling->ASM);
			ASM.push_back(string("jmp label_" + InttoStr(label_count)));
			ASM.push_back(string("label_" + InttoStr(label_count + 1) + ":"));
			label_count += 2;
			return "";
		case STMT_RETURN:
			if (child->sibling != nullptr)
			{
				ASM.splice(ASM.end(), child->sibling->ASM);
				ASM.push_back("movl " + children_str[1] + ", %eax");
			}
			ASM.push_back(string("ret"));
			return "";
		case STMT_PRINTF:
		    if(child->sibling==nullptr)
			{
				ASM.push_back("movl "+children_str[0]+", (%esp)");
				ASM.push_back("call printf");
				ASM.push_back("movl $0, %eax");
			}
			else if(child->sibling->sibling==nullptr)
			{
				ASM.push_back("movl "+children_str[1]+", %eax");
				ASM.push_back("movl %eax, %esp");
				ASM.push_back("movl "+children_str[0]+", (%esp)");
				ASM.push_back("call printf");
				ASM.push_back("movl $0, %eax");		
			}
		case STMT_SCANF:
		    if(child->sibling==nullptr)
			{
				ASM.push_back("movl "+children_str[0]+", (%esp)");
				ASM.push_back("call scanf");
				ASM.push_back("movl $0, %eax");
			}
			else if(child->sibling->sibling==nullptr)
			{
				ASM.push_back("leal "+children_str[1]+", %eax");
				ASM.push_back("movl %eax, %esp");
				ASM.push_back("movl "+children_str[0]+", (%esp)");
				ASM.push_back("call printf");
				ASM.push_back("movl $0, %eax");			
			}
		case STMT_BLOCK:
			temp1 = child;
			while (temp1 != nullptr)
			{
				ASM.splice(ASM.end(), temp1->ASM);
				temp1 = temp1->sibling;
			}
			return "";
		default:
			return "";
		}
		return "";
	}
}

