
#include <iostream>
#include "depthFirstSearch.h"

using namespace std;

// Depth first search ****************************************************
DepthFirstSearch::DepthFirstSearch()
{
	head = NULL;
	cur = NULL;
}

// Create a list of nodes - grapth or tree of nodes
// Description : a node consists of two values.
// if the second value of a node equals the first value of the next
// node then the nodes are linked or connected.
// Example: nodeA - 2 5
// 			nodeB - 5 7 = nodeA and nodeB are connected
// 			nodeC - 9 0
// 			nodeD - 7 8 = nodeC and nodeD are not connected
//						  but nodeA, B, and D are connected.
void DepthFirstSearch::initialize(int f, int s)
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

// implementation of depth first search - Non recursive version
void DepthFirstSearch::search(int node)
{
	stack obj;
	obj.push(head->first);
	int value;
	while(!obj.isStackEmpty())
	{
		List *ptr = new List();
		value = obj.getTop();
		for(ptr = head; ptr != NULL; ptr = ptr->next)
		{
			if(ptr->first == value && !obj.isVisited(ptr->sec)){
				obj.push(ptr->sec);
				value = ptr->sec;
			}
			if(value == node){
				cout << "The node value is found!" << endl;
				cout << "The path is : ";
				obj.printStack();
				return;
			}
		}
		obj.visitedNode(value);
		obj.pop();
		ptr = NULL;
		delete ptr;
	}
	cout << "The node value is not found." << endl;
}

// Recursive function
void DepthFirstSearch::recursion(int node, stack & obj)
{
	List *ptr = new List();
	if(obj.isStackEmpty()){
		ptr = NULL;
		delete ptr;
		cout << "The node value is not found." << endl;
		return;
	}
	int value = obj.getTop();
	for(ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if(ptr->first == value && !obj.isVisited(ptr->sec)){
			obj.push(ptr->sec);
			value = ptr->sec;
		}
		if(value == node){
			cout << "The node value is found!" << endl;
			cout << "The path is : ";
			obj.printStack();
			return;
		}
	}
	obj.visitedNode(value);
	obj.pop();
	recursion(node, obj);
}

// implementation of depth first search - Recursive version
void DepthFirstSearch::recursiveSearch(int node)
{
	// create an instance of stack class
	stack obj;
	// push the first root value to the stack
	obj.push(head->first);
	// Recursive function call
	recursion(node, obj);
}

// Print the node values
void DepthFirstSearch::print()
{
	cout << "Nodes : " << endl;
	for(cur = head; cur != NULL; cur = cur->next)
	{
		cout << cur->first << "  " << cur->sec << endl;
	}
}

// End of Depth first search **********************************************

// Stack *******************************************************************
stack::stack()
{
	head = NULL;
	cur = NULL;
	Head = NULL;
	Cur = NULL;
}

// Push node values into stack
void stack::push(int val)
{
	if(head == NULL){
		head = new stackList();
		head->var = val;
	} else {
		stackList *ptr = new stackList();
		ptr->var = val;
		ptr->next = head;
		head = ptr;
		ptr = NULL;
		delete ptr;
	}
}

// pop the node value from the top of the stack
void stack::pop()
{
	if(head == NULL)
		return;
	head = head->next;
}

// return the top of the stack!
int stack::getTop()
{
	return head->var;
}

// check if the stack is empty
bool stack::isStackEmpty()
{
	return (head == NULL);
}

// store visited node in a list
void stack::visitedNode(int val)
{
	if(Head == NULL){
		Head = new visited();
		Head->visit = val;
	} else {
		visited *ptr = new visited();
		ptr->visit = val;
		Cur = Head;
		while(Cur->next != NULL)
		{
			Cur = Cur->next;
		}
		Cur->next = ptr;
		ptr = NULL;
		delete ptr;
	}
}

// check if the node is already visited
bool stack::isVisited(int val)
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
void stack::printPath(stackList *& node)
{
	if(node != NULL){
		printPath(node->next);
	}
	else{
		return;
	}
	if(node->var != head->var){
		cout << node->var << " -> ";
	}
	else{
		cout << node->var;
	}
}

// the function to print the path
// of a node value is called
void stack::printStack()
{
	cur = head;
	printPath(cur);
	cout << endl;
}

// Not important ! for testing purpose only.
void stack::printVisitedNode()
{
	for(Cur = Head; Cur != NULL; Cur = Cur->next)
	{
		cout << Cur->visit << "  ";
	}
	cout << endl;
}

// End of stack ************************************************************
// Destructors
DepthFirstSearch::~DepthFirstSearch()
{
	if(!head){
		head = NULL;
		delete head;
	}  
	if(!cur){
		cur = NULL;
		delete cur;
	}
}

stack::~stack()
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

