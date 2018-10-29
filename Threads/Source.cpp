#include <thread>
#include <iostream>
#include <string>
using namespace std;

void senderFunc(string **msg) {
	this_thread::sleep_for(chrono::seconds(1));
	*msg = new string("Hello");
	cout << **msg << " from sender.\n" << endl;
}

void receiverFunc(string **msg) {
	this_thread::sleep_for(chrono::seconds(3));
	while (*msg == nullptr);
	cout << **msg << " from receiver.\n" << endl;
}

//int main() {
//	string *msg = nullptr;
//
//	thread sender (senderFunc, &msg);
//	thread receiver (receiverFunc, &msg);
//
//	sender.join();
//	receiver.join();
//
//	cout << "Done.\n" << endl;
//	getchar();
//	return 0;
//}