#include "Stack.h"

// Function implementation adapted partly from:
// http://www.includehelp.com/code-snippets/stack-implementation-using-cpp-class-with-push-pop-traverse.aspx

Stack::Stack()
{
	top = -1;
}

Stack::Stack(const Stack &newStack)
{

}

Stack::~Stack()
{

}

void Stack::push(string dateAbsent)
{
	++top;
	datesAbsent[top] = dateAbsent;
}

int Stack::pop()
{
	string data = nullptr;
	if (isEmpty() == 1)
	{
		return 0;
	}
	else
	{
		data = datesAbsent[top];
		--top;
		return 1;
	}
}

int Stack::peek()
{
	if (isEmpty() == 1)
	{
		cout << "No absences." << endl;
		return 0;
	}
	else
	{
		cout << top << endl;
		return 1;
	}
}

int Stack::isEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}