// C++ program to print all
// possible strings of length k
#include <bits/stdc++.h>
using namespace std;
	

// The main recursive method
// to print all possible
// strings of length k
void printAllKLengthRec(char set[], string prefix,
									int n, int k)
{
	
	// Base case: k is 0,
	// print prefix
	if (k == 0)
	{
		cout << (prefix) << endl;
		return;
	}

	// One by one add all characters
	// from set and recursively
	// call for k equals to k-1
	for (int i = 0; i < n; i++)
	{
		string newPrefix;
		
		// Next character of input added
		newPrefix = prefix + set[i] + " ";
		
		// k is decreased, because
		// we have added a new character
		printAllKLengthRec(set, newPrefix, n, k - 1);
	}

}

void printAllKLength(char set[], int k, int n)
{
	printAllKLengthRec(set, "", n, k);
}

// Driver Code
int main()
{
	//cout << "First Test" << endl;
	char set[] = {'1', '2'};
	int k = 5;
	printAllKLength(set, k, sizeof(set)/sizeof(set[0]));
	return 0;
}