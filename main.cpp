//	ASSIGNMENT 3 - CSC-328 - DATA STRUCTURES
//	GROUP MEMBERS:  Hailey Maimone, Ricky Peddicord, Kelli Huff, Michael Mickey
//
//  PROGRAM SYNOPSIS:  Program reads postfix expressions from input file,
//  	"input.txt".  The values in the expression are read into a 
//		stack implemented by a linked list.  The values are popped off the
//      the stack when an operator is reached and the calculated result
//		is then pushed back onto the stack.  The program then continues
//		to read expressions line by line.  An error is given and the expression
//		is not calculated if a space is found, or if the expression is found
//		to be invalid.  Invalid expressions are expressions that contain alphabetical
//		characters, too many numbers in comparison to operators, or if there are 
//		too many operators in the expression.  


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Stack.h"


using namespace std;



int main() 
{
	
	ifstream inputFile;
	

	int catchVar;   //variable to hold values being popped from stack
	string expression;   // holds expression read from file
	int stackvalue;  // value entered in each node
	int n;    // number of values to enter on stack
	int i;   // index for loop
	Stack stack;   // initializes an instance of Stack class
	int a, b;	// holds values popped off stack for +, -, *, / calculations
	int sum=0;			// int to hodl sum
	int ans=0;			// int to hold value of multiplication
	int quotient=0;		// int to hold quotient
	int diff=0;			// int to hold difference
	bool name;			// boolean for printing out valid expressions (i ran out of name ideas)
	int numDig = 0;		// int value to count number of digits in an expression
	int numOp = 0;		// int value to count number of operators in an expression

	
	
	
	cout << "Opening file...\n" << endl;
	inputFile.open("input.txt");		// opens input file input.txt


	if(inputFile.is_open())				// if file is opened
	{
		while(!inputFile.eof())			// while not at end of file
		{
			getline(inputFile, expression);		// read line from file and save it into expression variable
			if(expression.length()==0)			// if the line is empty
			{
				getline(inputFile, expression);	// move to next line
			}
			cout << "\nThe expression is:  " << expression << endl;		// prints expression read from file onto screen
			if(expression[0]=='+' || expression[0]=='-' || expression[0]=='*' || expression[0]=='/')	// if the first value of the expression is an operator
			{
				cout << "INVALID EXPRESSION:  Must be a postfix expression." << endl;
				name=true;			// boolean set to true to prevent stack top from being printed at end
				getline(inputFile, expression);		// moves to next line in file
			}
			else if(expression[1]=='+' || expression[1]=='-' || expression[1]=='*' || expression[1]=='/')	// if the second value of the expression is an operator
			{
				cout << "INVALID EXPRESSION:  Must be a postfix expression." << endl;
				name=true;			// boolean set to true to prevent stack top from being printed at end
				getline(inputFile, expression);		// moves to next line in file
			}
			else
			{
				for(i=0; i<expression.length(); i++)	//  for loop to move through each character in expression
				{
					if(isdigit(expression[i]))		// if character is a digit
					{
						numDig++;
						stackvalue=expression[i] - 48;	// stackvalue is set to the character's value minus 48 to convert from ASCII code
						stack.push(stackvalue);			// value is pushed on to stack
					}
					else if(isalpha(expression[i]))		// if character is a letter
					{
						cout << "INVALID EXPRESSION:  Expression contains alphabetical data" << endl;
						name=true;						// boolean is set to true to prevent stack top from printing at end
						numOp=0;
						numDig=1;
						getline(inputFile, expression);	// moves to next line
					}
					else if(expression[i] == ' ')		// if the expression contains a space
					{
						cout << "INVALID EXPRESSION:  Expression contains spaces." << endl;
						name=true;					// invalid expression, moves to next line
						getline(inputFile, expression);
					}
					else		// if character is a value other than a letter or digit
					{
						if(expression[i] == '+')	// if character is a +
						{
							numOp++;
							a=stack.pop();			// value is popped from stack and held in variable a
							b=stack.pop();			// value is popped from stack and held in variable b
							sum=b+a;				// sum of b+a is calculated
							stack.push(sum);		// sum is pushed onto stack
						}
						else if(expression[i] == '-')	// if character is a -
						{
							numOp++;
							a=stack.pop();			// value is popped from stack and held in variable a
							b=stack.pop();			// value is popped from stack and held in variable b
							diff=b-a;				// difference of b-a is calculated
							stack.push(diff);		// diff is pushed onto stack
						}
						else if(expression[i] == '*')	// if character is a *
						{
							numOp++;
							a=stack.pop();			// value is popped from stack and held in variable a
							b=stack.pop();			// value is popped from stack and held in variable b
							ans=b*a;				// value of b*a is calculated
							stack.push(ans);		// value is pushed onto stack
						}
						else if(expression[i]=='/')		// if character is a /
						{
							numOp++;
							a=stack.pop();			// value is popped from stack and held in variable a
							b=stack.pop();			// value is popped from stack and held in variable b
							quotient=b/a;			// quotient of b/a is calculated
							stack.push(quotient);	// quotient is pushed onto stack
						}
						
					}
					if(numDig <= numOp)   // checks if the number of operators is equal to or greater than the number of digits
					{
						cout << "INVALID EXPRESSION." << endl;
						name=true;				// if so, the expression is invalid
						getline(inputFile, expression);	// moves to next line
					}

			
				}


			}
			if(numDig > (numOp+1))	// if there are too many numbers compared to operators
			{
				cout << "INVALID EXPRESSION." << endl;
				name=true;			// expression is invalid, moves to next line
				getline(inputFile, expression);
			}
			if(name==false)		// if statement to print out a valid expression's result
			{
				cout << "-------------------------" << endl;
				cout << "Result of Expression:  " << stack.stackTop() << endl;		// prints out top of stack, which is the current expression's result
				cout << "-------------------------" << endl;
			}
			name=false;		// sets boolean back to false
			numOp=0;		// resets number of operators for counting
			numDig=0;		// resets number of digits for counting
		}
	}



	
	inputFile.close();		// closes input file
	

	
	return 0;
}
