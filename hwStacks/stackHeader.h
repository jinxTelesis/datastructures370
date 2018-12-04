#pragma once

#include <iostream>
#include <cassert>
#include "Header.h"

using namespace std;

template<class Type>
class stackType : public stackADT<Type>
{
public:
	const stackType<Type>& operator=(const stackType&);
		// Overload the assignment operator.

	void initializeStack();
	bool isEmptyStack() const;
	bool isFullStack() const;
	void push(const Type& newItem);
	Type top() const;
	void pop();

	stackType(int stackSize = 100);
	stackType(const stackType<Type>& otherStack);
	bool isEqual(const stackType<Type>& otherStack) const;
	~stackType();

private:
	int maxStackSize;
	int stackTop;
	Type *list;
	void copyStack(const stackType<Type>& otherStack);


};

template <class Type>
void stackType<Type>::initializeStack()
{
	stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
	return(stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
	return(stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
	if(!isFullStack())
	{
		list[stackTop] = newItem;

		stackTop++;
	}
	else
	{
		cout << "Cannot add to a full stack." << endl;
	}

}

template<class Type>
Type stackType<Type>::top() const
{
	assert(stackTop != 0);

	return list[stackTop - 1];
}

template <class Type>
void stackType<Type>::pop()
{
	if (!isEmptyStack())
	{
		stackTop--;
	}
	else
	{
		cout << "Cannot remove from an empty stack." << endl;
	}
}

template <class Type>
stackType<Type>::stackType(int stackSize)
{
	if (stackSize <= 0)
	{
		cout << "Size of the array to hold the stack must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;

		this->maxStackSize = stackSize;
	}
	else
	{
		stackTop = 0;
		this->maxStackSize = stackSize;
		list = new Type[maxStackSize];
	}
}


template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{

	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;

	// copy otherStack into this stack
	for (int j = 0; j < stackTop; j++)
	{
		list[j] = otherStack.list[j];
	}
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
	list = NULL;
	copyStack(otherStack);
}

template<class Type>
const stackType<Type>& stackType<Type>::operator=
(const stackType<Type>& otherStack)
{
	if (this != &otherStack)
	{
		copyStack(otherStack);
	}

	return *this;
}

template <class Type>
stackType<Type>::~stackType()
{
	delete[] list;
}

template<class Type>
bool stackType<Type>::isEqual(const stackType<Type>& otherStack) const
{
	// check to make sure have same amount of elements first
	// then check each element in a line 

	if (stackTop == otherStack.stackTop)
	{
		
		for (int j = 0; j < stackTop; j++)
		{
			if (list[j] == otherStack.list[j])
			{
				// do nothing will exit below
			}
			else
			{
				return false;
			}

		}
	}
	else // can't be same
	{
		return false;
	}
	return true;
}




