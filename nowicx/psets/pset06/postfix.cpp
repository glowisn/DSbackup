// postfix.cpp :
//
// The program evaluates a given postfix expression and produces a fully
// parenthesized infix expression. If the postfix expression may be 
// evaluated to a numeric value if it is expressed using numerically.
// For simplicity of coding, however, the postfix expression consists
// of single character operands and operators only and may have spaces.
//
// Author: idebtor@gmail.com
// 2020.04.05	Creation
// 2020.10.03	evaluation of numerical postfix expressions
//

/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: Á¤¿¹Âù*/


#include <iostream>
#include <stack>
#include <cassert>
#include <cstdlib>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// change the printStack to use template once you finish part 1 in step 1.
// prints the stack contents from the bottom.
template<typename T>
void printStack(stack<T> orig) {
	stack<T> temp;
	while (!orig.empty()) {
		cout << orig.top() << "";
		temp.push(orig.top());
		orig.pop();
	}
	while (!temp.empty()) {
		orig.push(temp.top());
		temp.pop();
	}
	// brute version of printStack
}


// returns a fully parenthesized infix expression in string after postfix evaluation.
string evaluate(string tokens) {
	stack<string> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// current token is a value(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			string val2 = st.top();
			st.pop();
			string val1 = st.top();
			st.pop();
			string valE = "(" + val1 + " " + token + " " + val2 + ")";
			st.push(valE);
			
		}
		else {  // push the operand
			DPRINT(cout << "  push: " << token << endl;);
			// convert token(char type) to a string type and push it to the stack
			string operand = string(1, token);
			st.push(operand);
			
		}
	}

	DPRINT(cout << "token exhausted: \n";);
	DPRINT(printStack(st););
	DPRINT(cout << "stack size() should be 1.\n";);

	assert(st.size() == 1); // stack size should be 1

	DPRINT(cout << "<evaluate() returns " << st.top() << endl;);
	return st.top();
}

// returns true if the tokens consist of '+', '-', '*', '/', spaces, and 
// digits (0 ~ 9), false otherwise.

// if there is at least one alphabet value, it is not numeric.
bool is_numeric(string tokens) {

	for (char token : tokens) {
		if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z'))
			return false;
	}

	return true;
}

// returns a numeric value after evaluating the postfix evaluation.
double evaluate_numeric(string tokens) {
	stack<double> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// if token is a operator, evaluate; if a digit(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			// checking the stack top() for right operand 
			// checking the stack top() for left oprand 
			// compute the expression and push the result
			double val2 = st.top();
			//assert(typeid(val2).name() == "double");
			st.pop();
			double val1 = st.top();
			//assert(typeid(val1).name() == "double");
			st.pop();
			double valC = 0;
			switch (token)
			{
			case '+':
				valC = val1 + val2;
				break;

			case '-':
				valC = val1 - val2;
				break;

			case '*':
				valC = val1 * val2;
				break;

			case '/':
				valC = val1 / val2;
				break;

			default:
				break;
			}


			st.push(valC);
		}
		else { // push the operand (digit) in a value to the stack
			// convert token to a numeric data type and push it the stack

			double val0 = atoi(&token);
			st.push(val0);
		}
	}

	DPRINT(cout << "token exhausted: check the stack, its size() should be 1.\n";);
	DPRINT(printStack(st););

	assert(st.size() == 1);

	DPRINT(cout << "<evaluate() returns " << st.top() << endl;);
	return st.top();
}
