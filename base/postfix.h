#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
protected:
	//Поля класса
  string infix;								//Входная строка
  string postfix;							//Строка после перевода в послфиксную форму
public:	

  TPostfix()
  {
    infix = "(a + b)";
  }						//												//Конструктор по умолчанию
  TPostfix(string s) {
	  infix = s;
  }				//Конструтор(формирует вводную строку из полученной)

  //Доступ к полям
  string GetInfix() { return infix; }		//Полуичть значение входной строки
  string GetPostfix() { return postfix; }	//Получить постфиксное значение

  //Основные методы класса
  string ToPostfix();						//Перевод в постиксную запись
  double Calculate();						//Ввод переменных, вычисление по постфиксной форме

  //Вспомогательные методы
  const bool CheckInputCorrectness();		//Проверка корректности вводимого выражения
  const bool CheckOperand(char c);			//Проверка входного симпола на операнд
  const bool CheckOperation(char c);		//Проверка входного символа на операцию
  int GetPriority(char c);					//Получение приоритета операции
};

#endif
