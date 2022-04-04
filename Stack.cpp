#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()     // CONSTRUCTOR
{
	top=0;
}

Stack::~Stack()    // DESTRUCTOR
{
	StackNode *nodePtr = 0, *nextNode = 0;
	nodePtr=top;
	
	while(nodePtr != 0)    // while node is not pointing to null (at end)
	{
		nextNode=nodePtr->next;  // traverses through stack
		delete nodePtr;          // deletes each node
		nodePtr=nextNode;		//  sets nodePtr to the next node
	}
}

void Stack::push(int num)    // PUSH FUNCTION
{
	StackNode *newNode = 0;	//initializes new node pointer
	
	newNode=new StackNode;  // initializes new node
	newNode->value=num;     // sets new node equal to the value being pushed onto stack
	
	if(isEmpty())           // if the stack is empty
	{
		top=newNode;        // the new node becomes the top
		newNode->next=0;    // new node's next pointer points to null, making it the only value in the stack
	}
	else                    // if stack is NOT empty
	{
		newNode->next=top;   // inserts new node before top value
		top=newNode;         // new node becomes the top of the stack
	}
}

int Stack::pop()  // POP FUNCTION
{
	StackNode *temp=0;     // initializes a temp pointer
	int num;				// variable to hold popped value
	
	if(isEmpty())          // if stack is empty
	{
		cout << "The stack is empty.\n"<<endl;
	}
	else        // if stack is NOT empty
	{
		num=top->value;   // sets the number being popped equal to the value on top of the stack
		temp=top->next;   // temp is set equal to the second value in stack
		delete top;       // top is deleted
		top=temp;         // temp becomes the top value of the stack
	}
	return num;			// returns value being popped off stack

}

bool Stack::isEmpty()    // isEmpty FUNCTION
{
	bool status;         // initializes boolean variable
	
	if(!top)             // if there is no top
	{
		status=true;     // the stack is empty
	}
	else                 // if a top exists
	{
		status=false;    // the stack is NOT empty
	}
	return status;       // returns status of stack
}



int Stack::stackTop()        // stackTop FUNCTION
{

	if (!top)      //  if no top exists
	{
		return -1;	// returns -1 if stack is empty
	}

	return top->value;	// returns value at top of stack
}

