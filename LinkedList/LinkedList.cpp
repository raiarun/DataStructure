// Author: Arun Rai
// LinkedList.cpp - a simple linked list implementation

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	prev = NULL;
	cur = NULL;
	head = NULL;
	tail = NULL;
}

// Create a liked list
void LinkedList::initialize(int val)
{
	if(head == NULL){
		head = new List();
		head->var = val;
	} else {
		List *ptr = new List();
		ptr->var = val;
		cur = head;
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = ptr;
		ptr = NULL;
		delete ptr;
	}
}

// add a node at the begining of the list
void LinkedList::addToHead(int val)
{
	List *ptr = new List();
	ptr->var = val;
	ptr->next = head;
	head = ptr;
	ptr = NULL;
	delete ptr;
}

// delete a node from the list
void LinkedList::deleteNode(int val)
{
	if(head->var == val){
		head = head->next;
		return;
	}
	else {
		List *ptr = new List();
		List *temp = new List();
		ptr = head;
		while(ptr != NULL)
		{
			if(ptr->var == val){
				break;
			}
			temp = ptr;
			ptr = ptr->next;
		}
		if(ptr != NULL){
			temp->next = ptr->next;
			ptr = temp;
		}
		ptr = NULL;
		temp = NULL;
		delete ptr;
		delete temp;
	}
}

// add node to tail
void LinkedList::addToTail(int val)
{
	List *temp = new List();
	List *ptr = new List();
	temp->var = val;
	ptr = head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
	temp = NULL;
	ptr = NULL;
	delete temp;
	delete ptr;
}

// find the mid point of a linked list
void LinkedList::findMidPoint()
{
	int counter = 0;
	List *ptr = head, *temp = head, *buf;
	while(ptr != NULL)
	{
		counter ++;
		if(counter%2 == 0){
			buf = temp;
			temp = temp->next;
		}
		ptr = ptr->next;
	}
	if(counter % 2 != 0){
		cout <<"Mid pint of the list is: " << temp->var << endl;
	} else {
		cout << "Mid points of the list are : " << buf->var << " and " << temp->var << endl;
	}
}

// reverse a linked list - iteratively
void LinkedList::reverseList()
{
	if(head == NULL) return;
	List *prev = NULL, *current = head, *temp;
	while(current != NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	head = prev;
}

// print the list
void LinkedList::print()
{
	for(cur = head; cur != NULL; cur = cur->next)
	{
		cout << cur->var << " ";
	}
	cout << endl;
}

LinkedList::~LinkedList()
{
	if(head != NULL){
		head = NULL;
		delete head;
	}
	if(tail != NULL){
		tail = NULL;
		delete head;
	}
	if(cur != NULL){
		cur = NULL;
		delete head;
	}
	if(prev != NULL){
		prev = NULL;
		delete head;
	}
}

//**************************************************************
// Creating linked list in C
//**************************************************************
nextList *initList(nextList * &head, nextList * &cur, int val)
{
	if(head == NULL){
		head = new nextList();
		head->var = val;
	} else {
		nextList *ptr = new nextList();
		ptr->var = val;
		cur = head;
		while(cur->Next != NULL)
		{
			cur = cur->Next;
		}
		cur->Next = ptr;
		ptr = NULL;
		delete ptr;
	}
	return head;
}

void print(nextList *node)
{
	while(node != NULL)
	{
		cout << node->var << " ";
		node = node->Next;
	}
	cout << endl;
}

// Reverse a linked list recursively
void reverseRecursive(nextList * &node)
{
	if(node == NULL) return;
	nextList *ptr = node->Next;
	if(ptr == NULL) return;
	reverseRecursive(ptr);
	node->Next->Next = node;
	node->Next = NULL;
	node = ptr;
}
