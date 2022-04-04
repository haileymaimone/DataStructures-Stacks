// *************************
//  CLASS PROVIDED:  Stack
// *************************
//
// CONSTRUCTOR:  Stack()
//  - DESCRIPTION:  initializes stack
//  - PRECONDITIONS:  N/A
//  - POSTCONDITIONS:  initializes the top to zero so the stack is empty
//
// DESTRUCTOR:  ~Set()
//  - DESCRIPTION:  deletes all nodes from the stack
//  - PRECONDITIONS:  N/A
//  - POSTCONDITIONS:  traverses through stack and all nodes are removed
//
// CONSTANT MEMBER FUNCTIONS FOR THE SET CLASS
//   void push(int)
//       - DESCRIPTION:  pushes a value onto the stack
//       - PRECONDITION:  N/A
//       - POSTCONDITION:  value is pushed onto the stack
//
//   int pop()
//       - DESCRIPTION:  pops top value off of stack and returns the value
//       - PRECONDITIONS:  stack is checked, and if empty, nothing is popped
//       - POSTCONDITIONS:  value is popped off stack and returned
//
//   bool isEmpty()
//       - DESCRIPTION:  checks if stack is empty
//       - PRECONDITIONS:  N/A
//       - POSTCONDITIONS:  if stack is empty, true is returned, and if it is not empty, false is returned
//
//   int stackTop()
//		 - DESCRIPTION:  returns value at top of stack 
//       - PRECONDITIONS:  tests if stack is empty first, and if so, there is no top and -1 is returned
//       - POSTCONDITIONS:  stack top is displayed to screen
//
//
//

#ifndef STACK_H
#define STACK_H


using namespace std;
class Stack
{
	public:
		void push(int);          // function prototype for push
		int pop();         // function prototype for pop
		bool isEmpty();          // function prototype to test if stack is empty
		void displayStack();     // function prototype to display stack
		int stackTop();			// function to return top of stack
		Stack();                 // constructor
		~Stack();                // destructor
	private:
		struct StackNode         // Stack node structure
		{
			int value;           // value in node
			StackNode *next;     //pointer to next node
		};
		StackNode *top;          //pointer to the stack top
};

#endif
