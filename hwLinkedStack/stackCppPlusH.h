#pragma once
#include "Header1.h"
#include <assert.h>

template<class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class linkedStackType : public stackADT<Type>
{
public:
	const linkedStackType<Type>& operator=
		(const linkedStackType<Type>&);
	// Overload the assignment operator

	bool isEmptyStack() const;

	bool isFullStack() const;

	bool isEqual(const linkedStackType<Type>& otherStack) const;

	void initializeStack();

	void push(const Type& newItem);

	Type top() const;

	void pop();

	linkedStackType();
	// default constructor

	linkedStackType(const linkedStackType<Type>& otherStack);
	// copy constructor

	~linkedStackType();
	// Destructor

private:
	nodeType<Type> *stackTop;
	void copyStack(const linkedStackType<Type>& otherStack);
	
};

template<class Type> // default constructor
linkedStackType<Type>::linkedStackType()
{
	stackTop = NULL;
}


template<class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
{
	stackTop = NULL;
	copyStack(otherStack);
}

template<class Type>
linkedStackType<Type>::~linkedStackType()
{
	initializeStack();
}

template<class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack)
{
	nodeType<Type> *newNode, *current, *last;

	if (stackTop != NULL)
	{
		stackTop = NULL;
	}


	if (otherStack.stackTop == NULL)
	{
		stackTop = NULL;
	}
	else
	{
		current = otherStack.stackTop; //set current to point to the stack to be copied

		stackTop = new nodeType<Type>; // copy the stackTop element of the stack // create node
		stackTop->info = current->info; // copy the info
		stackTop->link = NULL; // set the link field to NULL
		last = stackTop; // set last to point to the node
		current = current->link; // set current to point to the next node

								 // part two

		while (current != NULL)
		{
			newNode = new nodeType<Type>;

			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}

template<class Type> // checks if stack is empty
bool linkedStackType<Type>::isEmptyStack() const
{
	return(stackTop == NULL);
}

template<class Type>
bool linkedStackType<Type>::isFullStack() const
{
	return false;
}

template<class Type>
void linkedStackType<Type>::initializeStack()
{
	nodeType<Type> *temp; // first node

	while (stackTop != NULL)
	{
		temp = stackTop; // set temp to stack top
		stackTop = stackTop->link; // set stack top to next

		delete temp; // delete temp
	}
}


template<class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
	nodeType<Type> *newNode; // pointer

	newNode = new nodeType<Type>;  // memory

	newNode->info = newElement; // passes in the data
	newNode->link = stackTop; // inserts link before stack top
	stackTop = newNode;// sets stackTop to point to the top node
}

template<class Type>
Type linkedStackType<Type>::top() const
{
	assert(stackTop != NULL);

	return stackTop->info;
}

template<class Type>
void linkedStackType<Type>::pop()
{
	nodeType<Type> *temp;

	if (stackTop != NULL)
	{
		temp = stackTop;

		stackTop = stackTop->link;

		delete temp;
	}
	else
	{
		cout << "Cannot remove from an empty stack." << endl;
	}
}


template<class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type>& otherStack)
{
	if (this != &otherStack)
	{
		copyStack(otherStack);
	}

	return *this;
}

template<class Type>
bool linkedStackType<Type>::isEqual(const linkedStackType<Type>& otherStack) const
{
	nodeType<Type> *thisStack;
	nodeType<Type> *otherStackLocal;

	if (stackTop == NULL)
	{
		return false;
	}

	if (otherStack == NULL)
	{
		return false;
	}

	

	*thisStack = stackTop;
	*otherStackLocal = otherStack.stackTop;
	// check both their lengths can only travse shortest

	int thisStackLength = 0;
	int otherStackLength = 0;
	while(thisStack != NULL)
	{
		thisStackLength++;
	}

	while (otherStackLocal != NULL)
	{
		otherStackLength++;
	}

	if (thisStackLength != otherStackLocal)
	{
		return false;
	}


	while (thisStack != NULL && otherStackLocal != NULL)
	{
		
		if (thisStack->info == otherStackLocal->info)
		{
			// do nothing checking true till end
		}
		else
		{
			return false;
		}
		
		thisStack = thisStack->link; // move it down the line
		otherStackLocal = otherStackLocal->link;

	}

	return true;
}





