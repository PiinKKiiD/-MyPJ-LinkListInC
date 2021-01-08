#include "RPN.h"
#include "Lib.h"
NODESt * getNODESt(char c)
{
	NODESt * p;
	p = (NODESt*)malloc(sizeof(struct NODESt));
	p->c = c;
	p->next = nullptr;
	return p;
}

NODESt * splitHeadStack(ListSt & l)
{
	NODESt * p = l.head;
	l.head = l.head->next;
	p->next = nullptr;
	return p;
}

void joinHead(ListSt & l, NODESt *p)
{
	if (l.head == l.tail && l.head == nullptr)
	{
		l.head = l.tail = p;
		return;
	}
	else
	{
		p->next = l.head;
		l.head = p;
		return;
	}
	l.tail->next = nullptr;
}

int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void joinTailStack(ListSt & l, NODESt * p)
{
	if (l.head == nullptr)
		l.head = l.tail = p;
	else
	{
		NODESt *temp = new NODESt;
		temp = l.head;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = p;
		l.tail = temp;
	}
}

void infixToPostfix(string s)
{
	ListSt l;
	l.head = l.tail = nullptr;
	NODESt * p = getNODESt('H');
	joinHead(l , p);
	int len = s.length();
	ListSt nl;
	nl.head = nl.tail = nullptr;
	for (int i = 0; i < len; i++)
	{
		//character
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			p = getNODESt(s[i]);
			joinTailStack(nl, p);
		}

		//'('
		else if (s[i] == '(')
		{
			p = getNODESt('(');
			joinHead(l, p);
		}

		else if (s[i] == ')')
		{
			while (l.head->c != 'H' && l.head->c != '(')
			{
				NODESt * temp = splitHeadStack(l);
				joinTailStack(nl, temp);
			}
			if (l.head->c == '(')
			{
				splitHeadStack(l);
			}
		}
		//operator
		else
		{
			while(l.head->c != 'H' && precedence(s[i]) <= precedence(l.head->c))
			{
				NODESt * temp = splitHeadStack(l);
				joinTailStack(nl, temp);
			}
			NODESt * tem = getNODESt(s[i]);
			joinHead(l, tem);
		}

	}
	//remain
	while (l.head->c != 'H')
	{
		NODESt *t = splitHeadStack(l);
		joinTailStack(nl, t);
	}
	showRPN(nl);
	std::cout << endl;
}

void showRPN(ListSt l)
{
	if (l.head == l.tail && l.head == nullptr)
		return;
	else
	{
		NODESt * p = l.head;
		while (p != nullptr)
		{
			std::cout << p->c;
			p = p->next;
			
		}
	}
}

void menu()
{
	int ch;
	do {
		cout << "\n---------------------------------\n";
		cout << "\n\tMENU\t\t\t\t\n0.\t\tExit\n1.\t\tJosephus\t\t\n2.\t\tPostfix\t\t\n";
		cout << "-->";
		cin >> ch;
		switch (ch)
		{
		case 0: break;
		case 1: 
		{
			cout<<"\n\tTHE JOSEPHUS PROBLEM\n";
			int money, number;
			List l;
			inputValue(number, money);
			int *output = new int[number];
			l.Head = l.Tail = nullptr;

			//accomplish these problems

			Josephus(money, number, l, output);
			delete output;
			break;
		}
		case 2:
		{
			"\n\tINFIX TO POSTFIX\n";
			string exp;
			cout << "Input expression: ";
			cin >> exp;
			infixToPostfix(exp);
		}
		}
	} while (ch);
}
