#include "Stack.h"
#include <iostream>

Stack::Stack()
{
	top = -1;
	size = MAX_LENGTH;
	array = new double[size];

}
Stack::Stack(Stack const& s) :size(s.size), top(s.top)
{
	array = new double[size];
	for (int i = 0; i <= top; i++)
		array[i] = s.array[i];
}
Stack& Stack::operator=(Stack const& s)
{
	if (this != &s)
	{
		size = s.size;
		top = s.top;
		delete[]array;
		array = new double[size];
		for (int i = 0; i <= top; i++)
			array[i] = s.array[i];
	}
	return *this;
}
void Stack::grow()
{
	double *newArray = new double[2 * size];
	for (int i = 0; i < size; i++)
		newArray[i] = array[i];
	delete[]array;
	array = newArray;
	size = size * 2;
}
Stack::~Stack()
{ 
	delete[]array;
}
bool Stack::IsStackEmpty()const
{
	return top == -1; 
}
double Stack::peek()const
{
	if (IsStackEmpty())
	{
		std::cout << "The stack is already full!" << std::endl;
		return 0;
	}

	return array[top];

}
void Stack::push(double y)
{  
	if (IsStackFull())
	{
		grow();
	}
	array[++top] = y;
}
bool Stack::IsStackFull()const
{
	return top == size - 1;
}
double Stack::pop()
{
	if (!IsStackEmpty())
	{
		return array[top--];

	}
	else
	{
		std::cout << "Error!The stack is empty!" << std::endl;
	}
	return 0;
}
int Stack::length()const
{
	return top; 
}
