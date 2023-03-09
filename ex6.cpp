#include <algorithm>
#include <iostream>
#include <stdio.h>

char* Stack;
char* redoStack;
int originCnt;
int redoCnt;

void init(int limit) {
	Stack = new char[2 * limit];
	redoStack = new char[2 * limit];
	originCnt = 0;
	redoCnt = 0;
}

void display() {
	for (int i = 1; i <= originCnt; ++i) {
		std::cout << Stack[i] << " \n"[i == originCnt];
	}

	for (int i = 1; i <= redoCnt; ++i) {
		std::cout << redoStack[i] << " \n"[i == redoCnt];
	}
}

void push() {
	Stack[++originCnt] = redoStack[redoCnt];
	--redoCnt;
}

void pop() {
	redoStack[++redoCnt] = Stack[originCnt];
	--originCnt;
}

int main() {
	const int MAX_SIZE = 100;
	init(MAX_SIZE);
	display();
}