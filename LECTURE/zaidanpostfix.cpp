#include <iostream>
#include <conio.h>
#include <ctype.h>

using namespace std;

class Evaluate {
	public:
		int digit[50];
		int top;
		char formula[50];

		Evaluate () {
			top = -1;
		}

		void push(int number) {
			top++;
			digit[top] = number;
		}

		int pop() {
			int number = formula[top];
			top--;
			return number;
		}

		int operation(int a, int b, char oper) {
			switch (oper) {
				case '+': return a + b;
				case '-': return a - b;
				case '*': return a * b;
				case '/': return a / b;
				default: return 0;
			}
		}

		int calculatePostfix();
};



int Evaluate::calculatePostfix() {
	int i = 0;
	while(formula[i] != '#') {
		if (isdigit(formula[i])) {
			push(formula[i] - '0');
		}
		
		else {
			int x = pop();
			int y = pop();
			int result = operation(x, y, formula[i]);
			push(result);
		}
		
		i++;
	}
	return pop();
}

int main () {
	void clrscr();
	Evaluate e;
	cout << "Enter the postfix expression: ";
	cin >> e.formula;
	int result = e.calculatePostfix();
	cout << "The result is " << result;
	getch();
}
