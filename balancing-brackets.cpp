#include <iostream>
using namespace std;

class Stack
{
	char* arr;
	int top;
public:

	Stack(int size)
	{
		arr = new char[size];
		top = -1;
	}

	bool empty()
	{
		return (top == -1);
	}

	void push(char c)
	{
		top++;
		arr[top] = c;
	}

	char pop()
	{
		if (empty())
		{
			cout << "No element to pop" << endl;
			return ' ';
		}
		top--;
		return arr[top + 1];
	}

	char peek()
	{
		if (empty())
		{
			cout << "No element to return" << endl;
			return ' ';
		}
		return arr[top];
	}

	int length()
	{
		return top;
	}

};

int main()
{
	string str = "{{[]()}[()]}";
	
	int size = str.length() / 2;

	Stack stack(size);

	int count = 0;

	for (char bracket : str)
	{
		if (bracket == '(' || bracket == '[' || bracket == '{')
		{
			stack.push(bracket);
		}

		if (bracket == ')' || bracket == ']' || bracket == '}')
		{
			count++;
			if (stack.peek() == '(' && bracket == ')')
			{
				stack.pop();
				count--;
			}
			else if (stack.peek() == '[' && bracket == ']')
			{
				stack.pop();
				count--;
			}
			else if (stack.peek() == '{' && bracket == '}')
			{
				stack.pop();
				count--;
			}
		}
	}

	if (stack.empty() == true && count == 0)
	{
		cout << "Balanced" << endl;
	}
	else
	{
		cout << "UnBalanced" << endl;
	}

	return 0;
}