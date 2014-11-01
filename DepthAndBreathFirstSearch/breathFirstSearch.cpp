
#include <iostream>
#include "breathFirstSearch.h"

using namespace std;

BreathFirstSearch::BreathFirstSearch()
{
	head = NULL;
	cur = NULL;
}

void BreathFirstSearch::initialize(int f, int s)
{
	if(head == NULL){
		head = new List();
		head->first = f;
		head->sec = s;
	} else {
		List *ptr = new List();
		ptr->first = f;
		ptr->sec = s;
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

// Breath First Search Implementation
void BreathFirstSearch::search(int node)
{
	Queue object;
	object.enqueue(head->first);
	int value;
	while(!object.isQueueEmpty())
	{
		List *ptr = new List();
		value = object.getTop();
		for(ptr = head; ptr != NULL; ptr = ptr->next)
		{
			if(ptr->first == value && !object.isVisited(ptr->sec)){
				object.enqueue(ptr->sec);
			}
			if(value == node){
				object.visitedNode(value);
				cout << "The node value is found!" << endl;
				cout <<"The visited nodes are : ";
				object.printVisitedNode();
				return;
			}
		}
		object.visitedNode(value);
		object.pop();
		ptr = NULL;
		delete ptr;
	}
	cout << "The node value is not found." << endl;
}


void BreathFirstSearch::print()
{
	cout << "Nodes : " << endl;
	for(cur = head; cur != NULL; cur = cur->next)
	{
		cout << cur->first << "  " << cur->sec << endl;
	}
}

// Queue
Queue::Queue()
{
	head = NULL;
	cur = NULL;
	Head = NULL;
	Cur = NULL;
}

// enqueue node values into Queue
void Queue::enqueue(int val)
{
	if(head == NULL){
		head = new queueList();
		head->var = val;
	} else {
		queueList *ptr = new queueList();
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


// pop the node value from the top of the Queue
void Queue::pop()
{
	if(head == NULL)
		return;
	head = head->next;
}

// return the top of the Queue!
int Queue::getTop()
{
	return head->var;
}

// check if the Queue is empty
bool Queue::isQueueEmpty()
{
	return (head == NULL);
}

// store visited node in a list
void Queue::visitedNode(int val)
{
	if(Head == NULL){
		Head = new visited();
		Head->visit = val;
	} else {
		visited *ptr = new visited();
		ptr->visit = val;
		Cur = Head;
		bool NodeExist = false;
		while(Cur->next != NULL)
		{
			if(Cur->next->visit == val){
				NodeExist = true;
			}
			Cur = Cur->next;
		}
		if(!NodeExist)
			Cur->next = ptr;
		ptr = NULL;
		delete ptr;
	}
}

// check if the node is already visited
bool Queue::isVisited(int val)
{
	for(visited *ptr = Head; ptr != NULL; ptr = ptr->next)
	{
		if(ptr->visit == val)
			return true;
	}
	return false;
}

// print the path of the node if
// it exists
void Queue::printPath(queueList *& node)
{
	while(node != NULL)
	{
		if(node->next != NULL){
			cout << node->var << " -> ";
		} else {
			cout << node->var;
		}
		node = node->next;
	}
}

// the function to print the path
// of a node value is called
void Queue::printQueue()
{
	cur = head;
	printPath(cur);
	cout << endl;
}

// Not important ! for testing purpose only.
void Queue::printVisitedNode()
{
	Cur = Head;
	while(Cur != NULL)
	{
		if(Cur->next != NULL)
			cout << Cur->visit << " -> ";
		else
			cout << Cur->visit;
		Cur = Cur->next;
	}
	cout << endl;
}

Queue::~Queue()
{
	if(!head){
		head = NULL;
		delete head;
	}
	if(!cur){
		cur = NULL;
		delete cur;
	}
	if(!Head){
		Head = NULL;
		delete Head;
	}
	if(!Cur){
		Cur = NULL;
		delete Cur;
	}
}
