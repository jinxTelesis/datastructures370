#pragma once

#include "queueADT.h"
#include <assert.h>

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class linkedQueueType : public queueADT<Type>
{
public:
	const linkedQueueType<Type>& operator=
		(const linkedQueueType<Type>&);
	// Overload the assignment operator
	bool isEmptyQueue() const;
	// Function to determine whetherthe queue is empty.
	bool isFullQueue() const;

	void initializeQueue();

	Type front() const;

	Type back() const;

	void addQueue(const Type& queueElement);

	void deleteQueue();

	linkedQueueType();

	linkedQueueType(const linkedQueueType<Type>& otherQueue);

	~linkedQueueType();
	// Destructor

private:
	nodeType<Type> *queueFront;
	nodeType<Type> *queueRear;
};

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
	return(queueFront == NULL);
}

template <class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
	return false;
}

template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
	nodeType<Type> *temp; // makes a pointer

	while (queueFront != NULL) // while front is not null
	{
		temp = queueFront; // set temp to front
		queueFront = queueFront->link; // move front to next

		delete temp; // delete temp
	}

	queueRear = NULL; // set rear to null
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
	nodeType<Type> *newNode; // pointer

	newNode = new nodeType<Type>; // make a new node

	newNode->info = newElement; // copy info
	newNode->link = NULL; // set link null

	if (queueFront == NULL) // if no front
	{
		queueFront = newNode; // front equals node just made
		queueRear = newNode; // back equals node just made
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
	assert(queueFront != NULL); // checks if front isnull
	return queueFront->info; //then passes back the info of that type
}

template<class Type>
Type linkedQueueType<Type>::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
}

// delete queue aka delete frirst item

template<class Type>
void linkedQueueType<Type>::deleteQueue()
{
	nodeType<Type> *temp; // temp pointer

	if (!isEmptyQueue()) //checks if queue is empty
	{
		temp = queueFront; // set temp pointer to front
		queueFront = queueFront->link; // set queue front to next link

		delete temp; // delete that node

		if (queueFront == NULL) // if queueFront is null
		{
			queueRear = NULL; // set rear to null also
		}

	}
	else // what it dones if the queue is empty 
	{
		std::cout << "Cannot remove from an empty queue" << std::endl;
	}
}

template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
	queueFront = NULL;
	queueRear = NULL;
}

// we never wrote these 
template<class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue)
{

}

template<class Type>
linkedQueueType<Type>::~linkedQueueType()
{

}


