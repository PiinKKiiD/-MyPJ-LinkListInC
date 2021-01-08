#pragma once
#include <iostream>
using namespace std;

struct NODE {
	int no;
	int money;
	NODE * next;
 };

struct List {
	NODE*Head;
	NODE*Tail;
};

void inputValue(int &num, int &mon);
void createData(int num, List& l);
void showData(List l);
NODE * getNode(int n, int m);
NODE * splitHead(List & l);
void joinTailList(List& l, NODE *p);
void divMon(List & l, int m, int *a);
void showJosephus(int *a, int number);
void Josephus(int &money, int &number, List &l, int *output);