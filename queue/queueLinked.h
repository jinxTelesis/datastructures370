#pragma once

#include "queueADT.h"
#include <assert.h>

template<class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class linkedQueueType : public queueADT<Type>
{
public:
	const linkedQueueType<Type>& operator=(const linkedQueueType<Type>&);

	bool isEmptyQueue() const;

	bool isFullQueue() const;

	void initializeQueue();

	Type front() const;

	Type back() const;

	void addQueue(const Type& queueElement);

	void deleteQueue();

	linkedQueueType();

	linkedQueueType(const queueType<Type>& otherQueue);

	~queueType();
	//Destructor

private:
	nodeType<Type> *queueFront;
	nodeType<Type> *queueRear;
};

template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
	return(queueFront == NULL);
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
	return false;
}

template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
	nodeType<Type> *temp;

	while (queueFront != NULL)
	{
		temp = queueFront;
		queueFront - queueFront->link;
	}

	queueRear = NULL;
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
	nodeType<Type> *newNode; // pointer

	newNode = new nodeType<Type>; // creates the actual node

	newNode->info = newElement; // sets node info to element
	newNode->link = NULL; // sets link to null

	if (queueFront == NULL)
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else
	{
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}

template<class Type>
Type linkedQueueType<Type>::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
}

template<class Type>
Type linkedQueueType<Type>::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
}

template<class Type>
void linkedQueueType<Type>::deleteQueue()
{
	nodeType<Type> *temp;

	if (!isEmptyQueue())
	{
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;

		if (queueFront == NULL)
		{
			queueRear = NULL;
		}
	}
	else
	{
		cout << "Cannot remove from an empty queue " << endl;
	}
}

template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
	queueFront = NULL;
	queueRear = NULL;
} // default constructor?
