#include "Lib.h"

void inputValue(int & num, int & mon)
{
	cout << "Number = ";
	cin >> num;
	cout << "Money = ";
	cin >> mon;
}

void createData(int num, List & l)
{
	NODE * p = getNode(1, 0);
	l.Head = l.Tail = p;
	for (int i = 1; i < num; i++)
	{
		NODE *q = getNode(i + 1, 0);
		joinTailList(l, q);
	}
}

void showData(List l)
{
	if (l.Head == l.Tail && l.Head == nullptr)
		cout << "Empty List!" << endl;
	else
	{
		cout << "(no - money) : ";
		NODE *p = l.Head;
		while (p != nullptr)
		{
			cout << "(" << p->no << " - " << p->money << ")  ";
			p = p->next;
		}
		cout << endl;
	}
}

NODE * getNode(int n, int m)
{
	NODE * p;
	p = (NODE*)malloc(sizeof(struct NODE));
	p->money = m;
	p->no = n;
	p->next = nullptr;
	return p;
}

NODE * splitHead(List & l)
{
	NODE * ret = l.Head;
	l.Head = l.Head->next;
	ret->next = nullptr;
	return ret;
}

void joinTailList(List & l, NODE *p)
{
	l.Tail->next = p;
	l.Tail = l.Tail->next;
}

void divMon(List & l, int m, int *a)
{
	if (m == 0 || m < 0 || (l.Head == l.Tail) && (l.Head == nullptr) )
		return;
	else if (l.Head == l.Tail)
	{
		l.Head->money += m;
		a[l.Head->no-1] += m;
		return;
	}
	else if (m < 10 )
	{
		l.Head->money += m;
		a[l.Head->no-1] += m;
		NODE* p = splitHead(l);
		joinTailList(l, p);
		return;
	}
	else
	{
		l.Head->money += 10;
		a[l.Head->no-1] += 10;
		NODE*q = splitHead(l);
		joinTailList(l, q);
		q = splitHead(l);
		m -= 10;
		divMon(l, m,a);
	}
}

void showJosephus(int * a, int number)
{
	for (int i = 0; i < number; i++)
	{
		cout << "pirate " << i + 1 << " : " << a[i] << endl;
	}
}

void Josephus(int & money, int & number, List & l, int * output)
{
	for (int i = 0; i < number; i++)
		output[i] = 0;
	createData(number, l);
	showData(l);
	divMon(l, money, output);
	cout << "After The Josephus problem solved : " << endl;
	showJosephus(output, number);
}
