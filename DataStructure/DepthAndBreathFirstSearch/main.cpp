//***************************************************
// Depth first serach implementaion in C++
// Created by Arun Rai.
// Copyright (c) 2014 Arun Rai. All rights reserved.
//***************************************************

#include <iostream>
#include "depthFirstSearch.h"
#include "breathFirstSearch.h"

using namespace std;

int main()
{
	// Test DFS
	DepthFirstSearch object;
	object.initialize(2,4);
	object.initialize(4,5);
	object.initialize(5,7);
	object.initialize(5,8);
	object.initialize(4,6);
	object.initialize(4,0);
	object.initialize(8,9);
	object.initialize(9,10);
	object.initialize(9,11);
	object.initialize(10,1);
	object.initialize(11,1);
	object.initialize(1,99);
	object.initialize(99,100);
	// Graph must be defined in correct order
	// otherwise the program may assume a same node
	// as different nodes giving undesired result!
	object.print();
	cout <<"\nNon recursive search: " << endl;
	object.search(111);
	cout <<"\nRecursive search: " << endl;
	object.recursiveSearch(111);
	cout << "\n";
	
	// Test BFS
	BreathFirstSearch breath;
	breath.initialize(3,5);
	breath.initialize(3,6);
	breath.initialize(5,7);
	breath.initialize(5,9);
	breath.initialize(6,10);
	breath.initialize(6,8);
	breath.initialize(8,12);
	breath.initialize(8,13);
	breath.initialize(8,22);
	breath.initialize(6,10);
	breath.initialize(6,13);
	breath.print();
	cout << "\n";
	breath.search(22);
	cout << "\n";
	breath.search(2);
	cout << "\n";
	return 0;
}

BreathFirstSearch::~BreathFirstSearch()
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
