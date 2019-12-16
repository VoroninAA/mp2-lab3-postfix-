#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <typename T>
class TStack
{
protected:
  T *pMem;  // Память для стека
  int size; //Размер стека
  int top;	//Номер верхнего элемента стека
public:
	TStack(int _size);			//Конструктор
	TStack(const TStack &_t);	//Конструктор копирования
	const bool IsEmpty();		//Проверка на пустоту
	const bool IsFull();		//Проверка на полноту
	void Push(T _t);			//Добавление элемента
	T Pop();					//Извлечение элемента
	T GetTopElement();			//Просмотр верхнего элемента
	~TStack();					//Деструктор
};

template<typename T>
TStack<typename T>::TStack(int _size) {
	
		size = _size;
		top = -1;
		if ((size < 1) || (size > MaxStackSize))
			throw size;
		pMem = new T[size];
	
} //Конструктор

template<typename T>
TStack<typename T>::TStack(const TStack& _s) {
	top = _s.top;
	if (size != _s.size) {
		pMem= nullptr;
		size = _s.size;
		pMem = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			pMem[i] = _s.pMem[i];
		}
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			pMem[i] = _s.pMem[i];
		}
	}
} // Конструктор копирования

template<typename T>
const bool TStack<typename T>::IsEmpty() {
	if (top == -1)
		return 1;
	else return 0;
}

template<typename T>
const bool TStack<typename T>::IsFull() {
	if (top == size-1)
		return 1;
	else return 0;
}

template<typename T>
void TStack<typename T>::Push(T _t) {
	if ((top+1)==size)
		throw size;
	else
	{
		top += 1;
		pMem[top] = _t;
	}
}

template<typename T>
T TStack<typename T>::Pop() {
	if (top != -1) {
		top -= 1;
		return pMem[top + 1];
	}
	else throw top;
}

template<typename T>
T TStack<typename T>::GetTopElement() {
	return pMem[top];
}
template<typename T>
TStack<typename T>::~TStack() {
		delete[] pMem;
}

#endif
