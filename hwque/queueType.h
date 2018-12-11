#pragma once
#include <iostream>
#include "queueADT.h"
#include <assert.h>

using namespace std;

template<class Type>
class queueType : public queueADT<Type>
{
public:
	const queueType<Type>& operator=(const queueType<Type>&);
	// Overload the assignment operator.

	bool isEmptyQueue() const;

	bool isFullQueue() const;

	void initializeQueue();
	// Function to initialize the queue to an empty state.
	// Postcondition: The queue is empty.

	Type front() const;
	// Function to return the first element of the queue
	// Preconditoopn: the queue exists and is not empty
	// Postcondition: if the queue is empty, the program
	// terminates; otherwise, the first element of the queue
	// is returned.

	Type back() const;
	// Function to return the last element of the queue.
	// Precondtion: The queue exists and is not empty.
	// Postconditon: If the queue is empty, the program
	// terminates; otherwise, the last element of the queue
	// is returned.

	void addQueue(const Type& queueElement);
	// Function to add queueElement to the queue
	// Preconditon: the queue exists and is not full.
	// Postcondition: The queue is change and queueElement is 
	// added to the queue.

	void deleteQueue();

	void moveNthFront(int n);
	// Function to remove the first element of the queue.
	// Preconditon: The queue exists and is not empty.
	// Postcondition: The queue is changed and the first element
	// is removed from the queue.

	queueType(int queueSize = 100);
	// Constructor

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

// Empty queue
template<class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return(count == 0);
}

// Full queue
template<class Type>
bool queueType<Type>::isFullQueue() const
{
	return (count == maxQueueSize);
}

template<class Type>
void queueType<Type>::initializeQueue()
{
	queueFront = 0; // set to zero
	queueRear = maxQueueSize -1; //set to queue size minus 1
	count = 0; //set counter to 0
}

template<class Type>
Type queueType<Type>::back() const
{
	assert(!isEmptyQueue()); // make sure it is not empty
	return list[queueRear]; // returns the end from the array
}

template<class Type>
Type queueType<Type>::front() const
{
	assert(!isEmptyQueue()); // make sure it is not empty
	return list[queueFront]; // returns the end from the array
}

// Add Queue

template<class Type>
void queueType<Type>::addQueue(const Type& newELement)
{
	if (!isFullQueue())
	{
		queueRear = (queueRear + 1) % maxQueueSize;

		count++;
		list[queueRear] = newELement;
	}
	else
	{
		cout << "Cannot add to a full queue." << endl;
	}
} // puts new item at back and increments counter

template<class Type>
void queueType<Type>::deleteQueue() // takes off front element
{
	if (!isEmptyQueue())
	{
		count--; // decrements count
		queueFront = (queueFront + 1) % maxQueueSize;
		// use the mod operator to advance queueFront
		// because the array is circular
	}
	else
	{
		cout << "Cannot remove from an empty queue" << endl;
	}
}

template <class Type>
queueType<Type>::queueType(int queueSize)
{
	if (queueSize <= 0)
	{
		cout << "Size of the array to hold the queue must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxQueueSize = 100;
	}
	else
	{
		maxQueueSize = queueSize;
	}

	queueFront = 0; // sets the queue front to zero
	queueRear = maxQueueSize - 1; // sets the queue rear to maxsize minus one
	count = 0;// sets count to zer0
	list = new Type[maxQueueSize];// sets list to type of size maxQueueSize
}

template<class Type> // destructor just deletes the list
queueType<Type>::~queueType()
{
	delete[] list;
}

template<class Type>
void queueType<Type>::moveNthFront(int n)
{

	int tempInt = 0;
	tempInt = list[n];
	for (int i = n -1; i > 0; i--) // simple right shift loop which leaves the first space open
	{
		list[i + 1] = list[i];
	}
	list[0] = tempInt; // places the value at the front


}

