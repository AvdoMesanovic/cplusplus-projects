//*****************************************************************************************************
//
//		File:					qDriver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #8
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					April 5th, 2023
//
//
//		This program explores the Queue data structure and utilizes several functions to employ it.
//	
//		Other files required:
//			1. Queue.h - the class definition for a linked implementation of a queue
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "queue.h"

//*****************************************************************************************************

int main()
{
	int front,
		rear,
		dequeued;

	Queue<int> intQueue;

	cout << "empty queue tests" << endl;
	cout << "--------------------" << endl;

	if (intQueue.viewFront(front))
	{
		cout << "the front value is " << front << endl;
	}
	else
	{
		cout << "unable to view the front value" << endl;
	}

	if (intQueue.viewRear(rear))
	{
		cout << "the rear value is " << rear;
		cout << endl;
	}
	else
	{
		cout << "unable to view the rear value" << endl;
	}

	if (intQueue.isEmpty())
	{
		cout << "queue is empty" << endl;
	}
	else
	{
		cout << "queue is not empty" << endl;
	}

	if (intQueue.isFull())
	{
		cout << "queue is full" << endl;
	}
	else
	{
		cout << "queue is not full" << endl;
	}

	cout << "numValues is " << intQueue.getNumValues() << endl;

	if (intQueue.dequeue(dequeued))
	{
		cout << "dequeued value is " << dequeued << " and numValues is "
			<< intQueue.getNumValues() << endl;
	}
	else
	{
		cout << "unable to dequeue the front value" << endl;
	}

	cout << endl;

	cout << "enqueue tests" << endl;
	cout << "--------------------" << endl;

	if (intQueue.enqueue(5))
	{
		cout << "5 has been enqueued and numValues is " << intQueue.getNumValues() << endl;
	}
	else
	{
		cout << "unable to enqueue the value 5" << endl;
	}


	if (intQueue.enqueue(9))
	{
		cout << "9 has been enqueued and numValues is " << intQueue.getNumValues() << endl;
	}
	else
	{
		cout << "unable to enqueue the value 9" << endl;
	}


	if (intQueue.enqueue(20))
	{
		cout << "20 has been enqueued and numValues is " << intQueue.getNumValues() << endl;
	}
	else
	{
		cout << "unable to enqueue the value 20" << endl;
	}

	if (intQueue.enqueue(16))
	{
		cout << "16 has been enqueued and numValues is " << intQueue.getNumValues() << endl;
	}
	else
	{
		cout << "unable to enqueue the value 16" << endl;
	}

	if (intQueue.viewFront(front))
	{
		cout << "the front value is " << front << endl;
	}
	else
	{
		cout << "unable to view the front value" << endl;
	}

	if (intQueue.viewRear(rear))
	{
		cout << "the rear value is " << rear;
		cout << endl;
	}
	else
	{
		cout << "unable to view the rear value" << endl;
	}

	if (intQueue.isEmpty())
	{
		cout << "queue is empty" << endl;
	}
	else
	{
		cout << "queue is not empty" << endl;
	}

	if (intQueue.isFull())
	{
		cout << "queue is full" << endl;
	}
	else
	{
		cout << "queue is not full" << endl;
	}

	cout << endl;

	cout << "dequeue tests" << endl;
	cout << "--------------------" << endl;

	if (intQueue.dequeue(dequeued))
	{
		cout << "dequeued value is " << dequeued << " and numValues is "
			<< intQueue.getNumValues() << endl;
	}
	else
	{
		cout << "unable to dequeue the front value" << endl;
	}

	if (intQueue.dequeue(dequeued))
	{
		cout << "dequeued value is " << dequeued << " and numValues is "
			<< intQueue.getNumValues() << endl;
	}
	else
	{
		cout << "unable to dequeue the front value" << endl;
	}

	if (intQueue.viewFront(front))
	{
		cout << "the front value is " << front << endl;
	}
	else
	{
		cout << "unable to view the front value" << endl;
	}

	if (intQueue.viewRear(rear))
	{
		cout << "the rear value is " << rear;
		cout << endl;
	}
	else
	{
		cout << "unable to view the last value" << endl;
	}

	cout << endl;

	return 0;
}

//*****************************************************************************************************

//empty queue tests
//--------------------
//unable to view the front value
//unable to view the rear value
//queue is empty
//queue is not full
//numValues is 0
//unable to dequeue the front value
//
//enqueue tests
//--------------------
//5 has been enqueued and numValues is 1
//9 has been enqueued and numValues is 2
//20 has been enqueued and numValues is 3
//16 has been enqueued and numValues is 4
//the front value is 5
//the rear value is 16
//queue is not empty
//queue is not full
//
//dequeue tests
//--------------------
//dequeued value is 5 and numValues is 3
//dequeued value is 9 and numValues is 2
//the front value is 20
//the rear value is 16



