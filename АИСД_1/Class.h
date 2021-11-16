#pragma once
#include <iostream>
using namespace std;

class List {
private:
	class Node {
	public:
		int data;
		class Node* next;
		Node(int initdata)
		{
			this->next = NULL;
			this->data = initdata;
		}
		~Node(){}
	};
	Node* head;
	size_t size;
public:
	List();
	~List();
	void push_front(int data);
	void push_back(int data);
	void pop_back();
	void pop_front();
	void insert(int data, size_t index);
	int at(size_t index);
	void remove(size_t index);
	size_t get_size();
	void clear();
	void set(size_t index, int data);
	bool isEmpty();
	void push_back(List* anoterlist);
	friend ostream& operator << (ostream& stream, const List& list);
};
