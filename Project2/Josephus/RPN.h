#pragma once

#include <iostream>
#include <string>
using namespace std;

struct NODESt {
	char c;
	NODESt *next;
};
struct ListSt {
	NODESt*head;
	NODESt*tail;
};
NODESt *getNODESt(char c);
NODESt *splitHeadStack(ListSt &l);
void joinHead(ListSt &l, NODESt * p);
int precedence(char c);
void joinTailStack(ListSt&l, NODESt *p);
void infixToPostfix(string s);
void showRPN(ListSt l);
void menu();
