//***************************************************
// Linked list implementaion
// Created by Arun Rai.
// Copyright (c) 2014 Arun Rai. All rights reserved.
//***************************************************

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList object;
	object.initialize(2);
	object.initialize(6);
	object.initialize(3);
	object.initialize(-10);
	object.initialize(1);
	object.initialize(0);
	object.initialize(-13);
	object.print();
	object.addToHead(12);
	object.print();
	object.deleteNode(12);
	object.deleteNode(2);
	object.deleteNode(0);
	object.print();
	object.addToTail(33);
	object.addToTail(36);
	object.addToTail(22);
	object.addToTail(44);
	object.addToTail(54);
	object.print();
	object.findMidPoint();
	object.reverseList();
	object.print();
	object.reverseList();
	object.print();
	
	cout <<"Creating a linked list in C: " << endl;
	struct nextList *Head = NULL, *Cur;
	initList(Head, Cur, 10);
	initList(Head, Cur, 1);
	initList(Head, Cur, 7);
	initList(Head, Cur, 91);
	initList(Head, Cur, 0);
	initList(Head, Cur, 5);
	initList(Head, Cur, 8);
	print(Head);
	reverseRecursive(Head);
	print(Head);
	return 0;
}
