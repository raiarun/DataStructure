
// Simple program to reverse a string
// both recursively and non-recursively
// Created by Arun Rai, 11/01/2014
#include <iostream>
#include <string>

using namespace std;

void reverseString(string &st)
{
	int i = 0;
	while(st[++i] != '\0');
	char c;
	for(int j = 0; j < i/2; j++){
		c = st[j];
		st[j] = st[(i - 1) - j];
		st[(i - 1) - j] = c;
	}
}

void reverseRecursively(string &st, int i)
{
	if(i == st.length()/2) return;
	if(i < st.length()/2){
		char c = st[st.length() - 1 - i];
		st[st.length() - 1 - i] = st[i];
		st[i] = c;
	}
	i += 1;
	reverseRecursively(st, i);
}

int main()
{
	string st = "iaR nurA si eman yM";
	cout << st << endl;
	reverseString(st);
	cout << st << endl;
	int counter = 0;
	reverseRecursively(st, counter);
	reverseRecursively(st, counter);
	cout << st << endl;
	return 0;
}
