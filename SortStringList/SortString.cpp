
// Sort an array of string in C++ (not best solution)
// copyright (c) 2014 Arun Rai. All rights reserved.

#include <iostream>
#include <string>

using namespace std;

void sort(string list[], int N)
{
	int smallest;
	for(int i = 0; i < N; i++)
	{
		if(list[i].length() < smallest){
			smallest = list[i].length();
		}
	}
	string st, temp;
	for(int j = 0; j < N - 1 ; j++)
	{
		for(int k = 0; k < N - 1 ; k++)
		{
			smallest = (list[k].length() < list[k+1].length()) ? list[k].length() : list[k+1].length();
			for(int i = 0; i < smallest; i++)
			{
				if(list[k][i] > list[k+1][i]){
					st = list[k];
					list[k] = list[k+1];
					list[k+1] = st;
					break;
				}
				else if(list[k][i] < list[k+1][i]){
					break;
				}
			}
		}
	}
}

void print(string list[], int N)
{
	for(int i = 0; i < N; i++)
	{
		cout << list[i] << "	";
	}
	cout << "\n\n";
}

int main()
{
	const int N = 10;
	string list[N] = {"Aruna", "Roshan", "Bibek", "Mani", "Roshi", "Arunima", "Binod","Manoj", "Binay","Binit"};
	cout <<"	Printing the unsorted Array: " << endl;
	print(list, N);
	sort(list, N);
	cout <<"	Printing the sorted Array: " << endl;
	print(list, N);
	cout << endl;
	return 0;
}
