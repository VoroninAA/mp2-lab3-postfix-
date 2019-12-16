#include "postfix.h"
#include "stack.h"
#include <algorithm>
#include <map>
#include <iostream>

string TPostfix::ToPostfix()
{
	if (!CheckInputCorrectness())	//Проверка корректности изначального выражения
		throw infix;

  TStack<char> st1(infix.length());
  TStack<char> st2(infix.length());
  for each (char c in infix)
  {
	  if (c == '(') 
		  st2.Push(c);
	  
	  if (c == ')') {
		  while (st2.GetTopElement() != '(')
			  st1.Push(st2.Pop());
		  st2.Pop();
	  }

	  if (CheckOperand(c))
			  st1.Push(c);

	  if (CheckOperation(c))

		  if ((st2.IsEmpty())|| (GetPriority(c)) >= GetPriority(st2.GetTopElement()))
			  st2.Push(c);
	  else
		  {
			  while (GetPriority(st2.GetTopElement()) < GetPriority(c) || st2.IsEmpty()) {
				  if (st2.GetTopElement() == '(')
					  st2.Pop();
				  else
					  st1.Push(st2.Pop());
			  }
			  st2.Push(c);
		  }

		  

  }
  //Перекладываем оставшееся выражение из второго стека
  while (!st2.IsEmpty())
  {
	  st1.Push(st2.Pop());
  }
  //Формируем выводную строку
  while(!st1.IsEmpty())
  postfix +=(st1.Pop());
  reverse(postfix.begin(), postfix.end());
  return postfix;
}

double TPostfix::Calculate()
{
	double result(0);
	TStack<double> st(postfix.length());
	for each (char c in postfix)
	{
		if (CheckOperand(c)) {
			double inputoperand;
			cout << "Введите значение переменной- " << c << endl;
			cin >> inputoperand;
			st.Push(inputoperand);
		}
		if (CheckOperation(c))
		{
			double o1, o2;
			o1 = double(st.Pop());
			o2 = double(st.Pop());

			if(c=='+')
				result = o1+o2;

			if (c == '-')
				result = o2 - o1;

			if (c == '*')
				result = o1 * o2;

			if (c == '/')
				result = o2 / o1;

			st.Push(result);
		}



	}
	return result;
}

const bool TPostfix::CheckInputCorrectness()
{
	TStack<char> st(int(infix.length()));
	for each (char c in infix)
	{
		if (c == '(')
			st.Push('(');
		if (c == ')' && st.IsEmpty())
			return 0;
		if (c == ')')
			st.Pop();
	}
	if (st.IsEmpty())
		return 1;
	else
		return 0;
}
const bool TPostfix::CheckOperand(char c) {
	if (c >= 'A' && c <= 'z')
		return 1;
	else return 0;
}
const bool TPostfix::CheckOperation(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	else return 0;
}
int TPostfix::GetPriority(char c) {
	switch (c)
	{
	case '(': {
		return 1;
	}
		
	case '+': {
		return 2;
	}
	case '-': {
		return 2;
	}
	case '*': {
		return 3;
	}
	case '/': {
		return 3;
	}

	}

	return -1;
}