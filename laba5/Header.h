#pragma once
#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include<vector>
#include <Windows.h>

using namespace std;

struct ORDER {
    string PLAT;
    string POL;
    double SUMMA = 0;
};

struct STATEMENT {
    string NAME;
    string SURNAME;
    string PATR;
    double grade1 = 0;
    double grade2 = 0;
    double grade3 = 0;
};

void create(vector<ORDER>& a);
void sort_array(vector<ORDER>& a);
bool findPLAT(vector<ORDER>& a, const string& find);
void function1();
void create2(vector<STATEMENT>& a);

void print_array2(vector<STATEMENT>& a, const double& average);
double average_grade(vector<STATEMENT>& a);
void sort2(vector<STATEMENT>& a);
void print_array3(vector<STATEMENT>& a);
void function2();
#endif
