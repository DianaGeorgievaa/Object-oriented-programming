# pragma once
int const MAX_LENGTH = 100;
class Stack
{
public:
	Stack();// constructor
	Stack(Stack const&);//copy constructor 
	~Stack();// destructor 
	Stack& operator=(Stack const &);// operator =
	bool IsStackEmpty()const;// checks if the stack is empty
	double peek() const;// finds the top element
	void push(double);// push the element on the top of the stack
	double pop();//remove the last elemet
	int length()const;// for the length of the stack

private:
	double *array;// dynamic array with the elements of the stack
	int size;
	int top;// index for the last element
	bool IsStackFull()const;//cheks if the stack is full
	void grow();
};


