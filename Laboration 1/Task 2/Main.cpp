#include "Stack.h"
#include "Queue.h"
#include <string>
#include <iostream>
#include <ctype.h>
#include <chrono>

using namespace std;

void stackOnly(string palindrome) {
	Stack frontStackOnly(palindrome.size());
	Stack backStackOnly(palindrome.size());
	int sizeOfWord = palindrome.size();

	for (int i = 0; i < palindrome.size(); i++) { // sends palindrome front first into stack
		if (isalpha(palindrome[i])) {
			palindrome[i] = tolower(palindrome[i]);
			frontStackOnly.addToStack(palindrome[i]);
		}
		if (isalpha(palindrome[palindrome.size() - i - 1])) { // sends palindrome back first into stack
			palindrome[palindrome.size() - i - 1] = tolower(palindrome[palindrome.size() - i - 1]);
			backStackOnly.addToStack(palindrome[palindrome.size() - i - 1]);
		}
		else {
			sizeOfWord--;
		}
	}

	for (int i = 0; i < sizeOfWord; i++) { // compares outcome of front and back
		if (frontStackOnly.takeFromStack() != backStackOnly.takeFromStack()) {
			cout << "Word is not a palindrome!" << endl;
			return;
		}
	}
	cout << "Word is a palindrome" << endl;
}

void queueAndStack(string palindrome) {
	Stack stack(palindrome.size());
	Queue queue(palindrome.size());
	int sizeOfWord = palindrome.size();

	for (int i = 0; i < palindrome.size(); i++) { // send palindrome front first into both queue and stack
		if (isalpha(palindrome[i])) {
			palindrome[i] = tolower(palindrome[i]);
			stack.addToStack(palindrome[i]);
			queue.addToQueue(palindrome[i]);
		}
		else {
			sizeOfWord--;
		}
	}

	for (int i = 0; i < sizeOfWord; i++) {
		if (stack.takeFromStack() != queue.takeFromQueue()) { // compare queue outcome to stack outcome
			cout << "Word is not a palindrome!" << endl;
			return;
		}
	}
	cout << "Word is a palindrome" << endl;
}

void main() {
	string palindrome = "No lemon, no melon";
	string unnecessarilyLongBoringPalindrome = "ababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";

	{// scope to time stackOnly
		auto start = chrono::high_resolution_clock().now();

		stackOnly(palindrome);

		auto stop = chrono::high_resolution_clock().now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
		cout << duration << " microseconds elapsed." << endl;
	}

	cout << endl << endl;

	{ // scope to time queueAndStack
		auto start = chrono::high_resolution_clock().now();

		queueAndStack(palindrome);

		auto stop = chrono::high_resolution_clock().now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
		cout << duration << " microseconds elapsed." << endl;
	}

	{// scope to time stackOnly
		auto start = chrono::high_resolution_clock().now();

		stackOnly(unnecessarilyLongBoringPalindrome);

		auto stop = chrono::high_resolution_clock().now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
		cout << duration << " microseconds elapsed." << endl;
	}

	cout << endl << endl;

	{ // scope to time queueAndStack
		auto start = chrono::high_resolution_clock().now();

		queueAndStack(unnecessarilyLongBoringPalindrome);

		auto stop = chrono::high_resolution_clock().now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
		cout << duration << " microseconds elapsed." << endl;
	}
}