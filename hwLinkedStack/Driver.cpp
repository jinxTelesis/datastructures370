#pragma once
#include <iostream>
#include "Header.h"


using namespace std;


void testCopy(linkedStackType<int> OStack);


int main()
{
	linkedStackType<int> stack;
	linkedStackType<int> otherStack;
	linkedStackType<int> newStack;

	stack.push(34);
	stack.push(43);
	stack.push(27);

	newStack = stack;

	cout << "After the assignment operator, newStack: " << endl;

	while (!newStack.isEmptyStack())
	{
		cout << newStack.top() << endl;
		newStack.pop();
	}



	system("pause");
	return 0;
}

void testCopy(linkedStackType<int> Ostack)
{
	cout << "Stack in the function testCopy:" << endl;

	while (!Ostack.isEmptyStack())
	{
		cout << Ostack.top() << endl;
		Ostack.pop();
	}
}

