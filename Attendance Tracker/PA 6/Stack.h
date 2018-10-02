#pragma once

#include <iostream>
#include <string>

using namespace std;

class Stack
{
public:
	Stack(); // constructor
	Stack(const Stack &newStack); // copy constructor
	~Stack(); // destructor

	void push(string dateAbsent);
	int pop();
	int peek();
	int isEmpty();
private:
	string datesAbsent[10];
	int top;
};