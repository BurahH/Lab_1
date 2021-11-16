#include <iostream>
using namespace std;

#include "Class.h"

List::List() {
	head = NULL;
	size = 0;
}

List::~List()
{
	while(size)
		pop_front();
}

void List::push_front(int data) //The function inserts an element at the beginning of the list
{
	if (head == NULL)           //Create a list item if it is empty
		head = new Node(data);
	else {
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
	size++;
}

void List::push_back(int data) //The function inserts an element at the end of the list
{
	if (head == NULL)          //Create a list item if it is empty
		head = new Node(data);
	else {
		Node* temp = new Node(data);
		Node* current;
		current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = temp;
	}
	size++;
}
void List::pop_back()           //Removing the last item in the list
{
	if (head != NULL)           //Checking that the list is not empty
	{
		Node* current;
		Node* previous;
		current = head;
		previous = NULL;
		while (current->next != NULL)  //The transition of the current to the last element and the previus to the penultimate element
		{
			previous = current;
			current = current->next;
		}
		delete(current);
		if (previous != NULL)
			previous->next = NULL;
		else
			head = NULL;
		size--;
	}
	else
	{
		throw out_of_range("deletion isn't possible, the list is empty");  //Exception if list is empty
	}
}
void List::pop_front()       //Removing the first item in the list
{
	if (head != NULL)
	{
		Node* current;
		current = head->next;
		delete(head);
		head = current;
		size--;
	}
	else
	{
		throw out_of_range("deletion isn't possible, the list is empty");  //Exception if list is empty
	}
}

void List::insert(int data, size_t index) //adding element by index
{
	if ((size > index) or (index < 0))    //Checking for the correctness of the index
	{
		Node* current = head;
		if (index == 0)
			push_front(data);
		else
		{
			for (size_t i = 1; i < index; i++)  //go to the element of the previous entered index
				current = current->next;
			Node* temp = new Node(data);
			temp->next = current->next;
			current->next = temp;
			size++;
		}
	}
	else
	{
		throw out_of_range("Invalid index entered");  //Invalid Index Exception
	}
}

int List::at(size_t index)    //getting an element by index
{
	if ((size > index) or (index < 0))  //Checking for the correctness of the index
	{
		Node* current = head;
		for (int i = 0; i < index; i++)
			current = current->next;
		return current->data;
	}
	else
	{
	     throw out_of_range("Invalid index entered"); //Invalid Index Exception
	}
}

void List::remove(size_t index)  //deleting an element by index
{
	if ((size > index) or (index < 0))   //Checking for the correctness of the index
	{
		Node* current = head;
		Node* previous = NULL;
		for (int i = 0; i < index; i++)
		{
			previous = current;
			current = current->next;
		}
		if (previous == NULL)
		{
			head = current->next;
			delete(current);
		}
		else
		{
			previous->next = current->next;
			delete(current);
		}
		size--;
	}
	else
	{
		throw out_of_range("Invalid index entered");     //Invalid Index Exception
	}
}

size_t List::get_size()  //getting list size
{
	return size;
}
 
void List::clear()    //removing all list items
{
	Node* current;
	while (head != NULL)
	{
		current = head;
		head = head->next;
		delete(current);
	}
	size = 0;
}

void List::set(size_t index, int data)   //replacing the element by index with the passed one element
{
	if ((size > index) or (index < 0)) //Checking for the correctness of the index
	{
		Node* temp = new Node(data);
		Node* current = head;
		Node* previous = NULL;
		for (int i = 0; i < index; i++)       //Go to the element to be replaced
		{
			previous = current;
			current = current->next;
		}
		if (previous == NULL)
		{
			temp->next = head->next;
			head = temp;
			delete(current);
		}
		else
		{
			temp->next = current->next;
			previous->next = temp;
			delete(current);
		}
	}
	else
	{
		throw out_of_range("Invalid index entered");     //Invalid Index Exception
	}
}

bool List::isEmpty()     //checking if the list is empty
{
	return head == NULL;
}

ostream& operator<<(ostream& out, const List& list)  //Overloading the inference statement <<
{
	List current;
	current.head = list.head;
	while (current.head != NULL)
	{
		out << current.head->data;
		out << " ";
		current.head = current.head->next;
	}
	current.size = 0;       //Assignment to prevent the destructor from clearing memory
	return out;
}

void List::push_back(List* anotherlist)   //inserting another list at the end
{
		Node* current;
		int data;
		current = anotherlist->head;      
		while (current != NULL)
		{
			data = current->data;   
			push_back(data);              //Creating a new item in the first list with information from an item in the second list
			current = current->next;
		}
}