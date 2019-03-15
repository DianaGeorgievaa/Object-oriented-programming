# pragma once
int const MAX_LENGTH = 100;
class Stack
{
public:
	Stack();
	Stack(Stack const&);
	~Stack();
	Stack& operator=(Stack const &);
	bool IsStackEmpty()const;
	double peek() const;
	void push(double);
	double pop();
	int length()const;
private:
	double *array;
	int size;
	int top;
	bool IsStackFull()const;
	void grow();
};


