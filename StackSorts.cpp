//*************************************************************
// Author: D.S. Malik
//
// This program tests various operations of a stack.
//*************************************************************
#pragma once
#include <iostream>
#include "myStack.h"
#include <String>

using namespace std;

void testCopyConstructor(stackType<int> otherStack);
stackType<int> sortStack(stackType<int> &s);

void sortedInsert(stackType<int> &s, int x);
void sortStackRecursive(stackType<int> &s);
stackType<int> sortStack3(stackType<int> &s);

//void mystery(stackType<String>&s, stackType<String>& t);

int main()
{
	stackType<int> stack(50);
	stackType<int> copyStack(50);
	stackType<int> dummyStack(100);

	stack.initializeStack();
	stack.push(23);
	stack.push(45);
	stack.push(38);
	stack.push(71);
	stack.push(40);
	stack.push(17);

	copyStack = sortStack3(stack);

	while (!copyStack.isEmptyStack())
	{
		cout << copyStack.top() << " ";
		copyStack.pop();
	}

	


	//stack.initializeStack();

	//stack.push(23);
	//stack.push(45);
	//stack.push(38);
	//stack.push(17);
	//stack.push(19);
	//stack.push(32);

	//stack = sortStack(stack);
	//sortStackRecursive(stack);


	//while (!stack.isEmptyStack())
	//{
	//	cout << stack.top() << " ";
	//	stack.pop();
	//}



	system("pause");

	return 0;
}


void testCopyConstructor(stackType<int> otherStack)
{
	if (!otherStack.isEmptyStack())
		cout << "otherStack is not empty." << endl
		<< "The top element of otherStack: "
		<< otherStack.top() << endl;
}

void sortedInsert(stackType<int> &s, int x)  
{

	if (s.isEmptyStack() || x > s.top())
	{
		s.push(x);
		return;
	}

	int temp = s.top();
	s.pop();
	sortedInsert(s, x);

	s.push(temp);
}




void sortStackRecursive(stackType<int> &s)
{
	if (!s.isEmptyStack())
	{
		int x = s.top();
		s.pop(); // annoying this is two operations

		sortStackRecursive(s);

		sortedInsert(s, x);
	}
}





stackType<int> sortStack(stackType<int> &s)
{
	stackType<int> stack2(50);

	while (!s.isEmptyStack())
	{
		int temp = s.top();
		s.pop();

		while (!stack2.isEmptyStack() && stack2.top() > temp)
		{
			s.push(stack2.top());
			stack2.pop();

		}
		stack2.push(temp);
	}

	return stack2;
}


stackType<int> sortStack3(stackType<int> &s)
{
	stackType<int> stack2(100);

	while (!s.isEmptyStack())
	{

		int temp = s.top();
		s.pop();

		while (!stack2.isEmptyStack() && stack2.top() > temp)
		{
			s.push(stack2.top());
			stack2.pop();
		}
		stack2.push(temp);
	}
	return stack2;
}
