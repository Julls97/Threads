#include <thread>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void readerFunc(stack<string> *stack) {
	while (true) {
		if (!stack->empty()) {
			this_thread::sleep_for(chrono::milliseconds(700));
			cout << stack->top() << ". Stack size is " << stack->size() << endl;
			stack->pop();
		}
	}
}

void writer1Func(stack<string> *stack) {
	while (true) { 
		if (stack->size() < 10) {
			this_thread::sleep_for(chrono::seconds(1));
			string res = "writer1 pushed " + to_string(rand() % 10);
			stack->push(res);
		}
	}
}

void writer2Func(stack<string> *stack) {
	while (true) {
		if (stack->size() < 10) {
			this_thread::sleep_for(chrono::seconds(2));
			string res = "writer2 pushed " + to_string(rand() % 10);
			stack->push(res);
		}
	}
}

int main() {
	srand(time(NULL));
	stack<string> stack;

	thread writer1(writer1Func, &stack);
	thread writer2(writer2Func, &stack);
	thread reader(readerFunc, &stack);

	reader.join();
	writer1.join();
	writer2.join();

	cout << "Done.\n" << endl;
	getchar();
	return 0;
}