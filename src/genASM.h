#ifndef GENASM_H
#define GENASM_H

#include "pch.h"
#include "type.h"
struct Children_Str{
    string* child_str;
    int children_num;
    int max;
    Children_Str(int max0=4);
    Children_Str& operator= (string str);
    Children_Str& operator+= (string str);
    string& operator[] (int n);
};
extern int temp_count;
extern int label_count;
string InttoStr(int);
#endif