#pragma once
#ifndef COMMON_H
#define COMMON_H

#include "pch.h"
#include <stack>
#include <map>
#include "tree.h"
#include "type.h"
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::stack;
using std::unordered_map;
using std::pair;
using std::map;
extern std::stack<int> id_section;
extern std::map<int,string> typelist;
extern int block_count;
extern int ids;
extern bool for_section;
extern int count;
struct id_info{
int id;
Type** type;
};
extern std::map<std::pair<int, string>, id_info> idlist;

#define YYSTYPE TreeNode *


//#include "./main.tab.h"

#endif
