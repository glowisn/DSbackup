// infix.cpp :
//
// The program evaluates a given infix expression which is fully parenthesized.
// It uses Dijkstra's two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized.
// For example:
//   ((3 - 1 ) * 5) + 4
//   2 * ((34 - 4) * 2)
//   1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com
// 2020.04.05	created and assert() added
//

/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: ������*/

#include <iostream>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 0    //////////////////////////////////////////////////////////////////////
// set #if 1, if you want to use this stack using vector instead of STL stack.
// a basic stack functinality only provided for pedagogical purpose only.
#include <vector>
template <typename T>
struct stack {
	vector<T> item;

	bool empty() const {
		return item.empty();
	}
	auto size() const {
		return item.size();
	}
	void push(T const& data) {
		item.push_back(data);
	}
	void pop() {
		if (item.empty())
			throw out_of_range("stack<>::pop(): pop stack");
		item.pop_back();
	}
	T top() const {
		if (item.empty())
			throw out_of_range("stack<>::top(): top stack");
		return item.back();
	}
};
#else  /////////////////////////// using STL stack //////////////////////////
#include <stack>
#endif ///////////////////////////////////////////////////////////////////////

template <typename T>
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
	//cout << "Step 2: your code here: copy printStack() template version from postfix.cpp\n";
	//cout << "Step 3: rewrite printStack() using recursion. refer to PDF file\n";

	cout << endl;
}

// performs arithmetic operations.
double apply_op(double a, double b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
}

// there is a bug...
double compute(stack<double>& va_stack, stack<char>& op_stack) {
	double right  = va_stack.top(); va_stack.pop();     
	double left = va_stack.top(); va_stack.pop();
	char op = op_stack.top(); op_stack.pop();
	double value = apply_op(left, right, op);

	DPRINT(cout << " va/op_stack.pop: " << value << endl;);
	return value;
}

// returns value of expression after evaluation.
double evaluate(string tokens) {
	DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
	stack<double>  va_stack;              // stack to store operands or values
	stack<char> op_stack;                 // stack to store operators.
	double value = 0;

	for (int i = 0; i < tokens.length(); i++) {
		// token is a whitespace or an opening brace, skip it.
		if (isspace(tokens[i]) || tokens[i] == '(') continue;
		DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

		// current token is a value(or operand), push it to va_stack.
		if (isdigit(tokens[i])) {
			int ivalue = tokens[i] - '0';

			while(isdigit(tokens[i + 1])) {
				ivalue = ivalue * 10 + tokens[++i] - '0';
			}
			
			va_stack.push(ivalue);
			//va_stack.push(tokens[i] - '0');
		} 
		else if (tokens[i] == ')') { // compute it, push the result to va_stack
			//va_stack.push(compute(va_stack, op_stack));
			double valA = 0;
			valA = compute(va_stack, op_stack);

			va_stack.push(valA);
			
		}
		else { // token is an operator; push it to op_stack.
			op_stack.push(tokens[i]);
		}
	}
	while (!op_stack.empty()) {
		va_stack.push(compute(va_stack, op_stack));
	}

	DPRINT(cout << "tokens exhausted: now, check two stacks:" << endl;);
	DPRINT(printStack(va_stack);  cout << endl;);
	DPRINT(printStack(op_stack);  cout << endl;);

	//cout << "your code here: process if !op_stack.empty() \n";
	assert(op_stack.empty());
	//cout << "your code here: post-conditions\n";
	
	//cout << "your code here: return & clean-up\n";
	value = va_stack.top();
	while (!va_stack.empty())va_stack.pop();

	return value;
}
