#pragma once

#include <assert.h>
#include "queueADT.h"

template<class Type>
class queueType : public queueADT<Type>
{
public:
	const queueType<Type>& operator=(const queueType<Type>&);
	// Overload the assignment operator.

	bool isEmptyQueue() const;

	bool isFullQueue() const;

	void initializeQueue();


	Type front() const;
	

	Type back() const;
	

	void addQueue(const Type& queueElement);
	

	void deleteQueue();
	

	queueType(int queueSize = 100);
	

	queueType(const queueType<Type>& otherQueue);
	// Copy constructor

	~queueType();
	//Destructor

private:
	int maxQueueSize; // keep track of max queue size
	int count; // count
	int queueFront; // queue front
	int queueRear; // queue rear

	Type *list; // pointer to list
};

template<class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return (count == 0);
}

template<class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return(count == maxQueueSize);
}

template<class Type>
void queueType<Type>::initializeQueue()
{
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}

template<class Type>
Type queueType<Type>::front() const
{
	assert(!isEmptyQueue());
	return list[queueFront];
}

template<class Type>
Type queueType<Type>::back() const
{
	assert(!isEmptyQueue());
	return list[queueRear];
}

template<class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
	if (!isFullQueue())
	{
		queueRear = (queueRear + 1) % maxQueueSize;

		count++;
		list[queueRear] = newElement;
	}
	else
	{
		cout << "Cannot add to a full queue." << endl;
	}
}

template<class Type>
void queueType<Type>::deleteQueue()
{
	if (!isEmptyQueue())
	{
		count--;
		queueFront = (queueFront + 1) % maxQueueSize;
	}
	else
	{
		cout << "Cannot remove from an empty queue" << endl;
	}
}

template<class Type>
queueType<Type>::queueType(int queueSize)
{
	if (queueSize <= 0)
	{
		cout << "Size of the array to hold the queue must "
			<< "be positive." << endl;

		maxQueueSize = 100;
	}
	else
	{
		maxQueueSize = queueSize;
	}

	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
	list = new Type[maxQueueSize];
}

template<class Type>
queueType<Type>::~queueType()
{
	delete[] list;
}


