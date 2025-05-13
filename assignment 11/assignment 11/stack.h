//*****************************************************************************************************
//
//		File:					stack.h
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #11
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					April 27th, 2023
//
//
//		This program uses a templated Stack and a templated Queue to determine if a character array
//      string is a valid palindrome.
// 	
//		Other files required: N/A
//			
//*****************************************************************************************************

#ifndef STACK_H
#define STACK_H

//*****************************************************************************************************

template <typename TYPE>
class Stack
{
private:
	TYPE* stack;
	int top;
	int capacity;

public:
	Stack(int cap = 100);
	~Stack();
	bool push(const TYPE& dataIn);
	bool pop(TYPE& dataOut);
	bool peek(TYPE& dataOut) const;
	int getNumValues() const;
	bool isFull() const;
	bool isEmpty() const;
};

//*****************************************************************************************************

template<typename TYPE>
Stack<TYPE>::Stack(int cap)
{
	capacity = cap;
	top = -1;
	stack = new TYPE[capacity];
}

//*****************************************************************************************************

template<typename TYPE>
Stack<TYPE>::~Stack()
{
	capacity = 0;
	delete[]stack;
	top = 0;
	stack = nullptr;
}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::push(const TYPE& dataIn)
{
	bool success = false;

	if ((top + 1) < capacity)
	{
		top += 1;
		stack[top] = dataIn;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::pop(TYPE& dataOut)
{
	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top];
		top -= 1;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::peek(TYPE& dataOut) const
{
	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top];
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename TYPE>
int Stack<TYPE>::getNumValues() const
{
	return (top + 1);
}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::isFull() const
{
	return ((top + 1) == capacity);
}

//*****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::isEmpty() const
{
	return (top == -1);
}

//*****************************************************************************************************

#endif