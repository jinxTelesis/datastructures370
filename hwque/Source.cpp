#include <iostream>
//#include "queueLinked.h"
#include "queue.h"

//***********************************
// File: Source.cpp
// 
// Author: Andre Lussier
// For: Bill Myers
//
// Purpose: Modifcation of queue to allow prioritizing of one element
// the addtional member function moveNthFront allows you to move
// the element at the Nth index to the from of the queue
// the value of that element is demonstrated in the driver program
// Source.cpp
//
//***********************************


using namespace std;

int main()
{
	//linkedQueueType<int> queue;
	queueType<int> queue1(150);
	queue1.initializeQueue();

	queue1.addQueue(10);
	queue1.addQueue(50);
	queue1.addQueue(100);
	queue1.addQueue(77);
	queue1.addQueue(19);
	queue1.addQueue(101);
	queue1.moveNthFront(3);

	int x = queue1.front();

	std::cout << x << std::endl;


	

	//queue.initializeQueue();
	

	//queue.addQueue(x);
	//queue.addQueue(y);

	


	system("pause");
	return 0;
}
