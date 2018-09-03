#include <iostream>
#include "Stack.h"

// const variable for the operations
const int NUMBER_OPERATORS = 5;
const char math_operators[NUMBER_OPERATORS] = { '-', '+', '/', '*', '%' };
// function that calculates the expression
double calculate(char* math_expression);
// checks if one symbol in the expression is a number
bool CheckForNumber(char* number);
//current position in expression
int currentIndex = 0;
// get number from expression
char* ReturnNumber(char *mathExpr);

int main()
{
	char math_expression[MAX_LENGTH]; // in RPN
	std::cout << "Please,enter an expression in Reversed Polish Notation:" << std::endl;
	std::cin.getline(math_expression, MAX_LENGTH);
	std::cout << "The result of the expression is: " << calculate(math_expression) << std::endl;
	return 0;
}
double calculate(char* math_expression)
{   // variable for the length of the expression
	int math_expression_len = strlen(math_expression);

	char* n = new char[50];
	Stack s;
	int i = 0;

	while (currentIndex < math_expression_len)
	{
		n = ReturnNumber(math_expression);

		if (strlen(n) > 1)
		{
			s.push(atof(n));
		}
		else
		{
			if (CheckForNumber(n) == true)
			{
				s.push(atof(n));
			}
			else
			{
				char* math_operator = n;
				if (s.length() >= 1)
				{
					double first_element = s.pop();
					double second_element = s.pop();
					if (math_operator[0] == '+')
					{
						s.push(second_element + first_element);
					}
					else if (math_operator[0] == '-')
					{
						s.push(second_element - first_element);
					}
					else if (math_operator[0] == '*')
					{
						s.push(second_element*first_element);
					}
					else if (math_operator[0] == '/')
					{
						if (first_element != 0)
						{
							s.push(second_element / first_element);
						}
						else
						{
							std::cout << "You can't divide by 0! " << std::endl;
						}
					}
					else if (math_operator[0] == '%')
					{
						if (first_element != int(first_element) || second_element != int(second_element))
						{
							std::cout << "Invalid operation!" << std::endl;
							break;
						}
						s.push(int(second_element) % int(first_element));
					}
					else
					{
						std::cout << "Invalid expression!" << std::endl;
						return 0;
					}
				}
				else
				{
					std::cout << "Error!The expression is not full!" << std::endl;
					return 0;
				}
			}
		}
	}
	if (s.length() == 0)
	{
		double result = s.pop();
		return result;
	}
	else
	{
		std::cout << "Invalid expression!" << std::endl;
	}
}
bool CheckForNumber(char* number)
{
	int i = 0;
	while (i < NUMBER_OPERATORS)
	{   // if the element is operator
		if (number[0] == math_operators[i])
		{
			return false;
		}
		i++;
	}
	return true;
}

char * ReturnNumber(char *mathExpr)
{
	int len = strlen(mathExpr);
	char* num = new char[50];
	int index = 0;
	if (len > currentIndex)
	{
		for (int i = currentIndex; i < len; i++) // get number or operation from expression
		{  // if the element is not space
			if (mathExpr[i] != ' ')
			{
				num[index] = mathExpr[i];
				index++;
			}
			else
			{
				// we have whitespae in position 'i' so we get the number or operation from 
				//currentIndex to the len and continue to search next nmber or operation from currentIndex + 1 to length of expression
				currentIndex = i;
				break;
			}
			// if there are not more elements
			if (mathExpr[i] == '\0')
			{
				currentIndex = len;
			}
		}
	}
	num[index] = 0;
	currentIndex++;
	return num;
}