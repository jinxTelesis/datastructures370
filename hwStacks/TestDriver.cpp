#include <iostream>
#include "stackHeader.h"
#include <string>

using namespace std;

void testCopyConstructor(stackType<int> otherStack);

int main()
{
	stackType<int> stack(50);
	stackType<int> copyStack(50);
	stackType<int> dummyStack(100);

	copyStack.initializeStack();
	copyStack.push(21);
	copyStack.push(45);
	copyStack.push(38);
	

	stack.initializeStack();
	stack.push(23);
	stack.push(45);
	stack.push(38);

	if (stack.isEqual(copyStack))
	{
		cout << "Same stack" << endl;
	}
	else
	{
		cout << "Different stack" << endl;
	}

	

	
	/*
	copyStack = stack;

	while (!stack.isEmptyStack())
	{
		cout << stack.top() << " ";
		stack.pop();
		//copyStack.pop();
	}
	cout << endl;
	*/

	/*
	copyStack = stack;
	testCopyConstructor(stack);

	if (!stack.isEmptyStack())
	{
		cout << "The original stack is not empty" << endl
			<< "The top element of the original stack: "
			<< copyStack.top() << endl;
	}

	dummyStack = stack;

	cout << "The elements of dummyStack: ";

	while (!dummyStack.isEmptyStack())
	{
		cout << dummyStack.top() << " ";
		dummyStack.pop();
	}
	cout << endl;
	*/
	



	system("pause");
	return 0;
}

void testCopyConstructor(stackType<int> otherStack)
{
	if (!otherStack.isEmptyStack())
	{
		cout << "otherStack is not empty." << endl
			<< "The top element of otherStack: "
			<< otherStack.top() << endl;
	}
}
