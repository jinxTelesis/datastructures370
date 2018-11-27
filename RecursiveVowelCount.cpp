

//////////////////////////////////////////////
// Andre Lussier 
// Data Structures
// page 391 problem 4
// William Myers
// Purpose this program takes a string as input 
// and recursively counts vowels in the string
// then reports them back to command prompt
///////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

// prototypes
int vowels(string word, int pos); 
int vowelCount(char ch);

// driver or main
int main()
{
	int vowelNum = 0;
	string str = "FaaArk";

	vowelNum = vowels(str, 4);
	cout << vowelNum << endl;

	system("pause");
	return 0;

}

int vowels(string word, int pos) 
{
	if (pos == 1) // base case to go back up the call stack
	{
		return vowelCount(word[pos - 1]);
	}

	// if it is not the base case add the vowles and call one more time
	return (int)vowels(word, pos - 1) + (int)vowelCount(word[pos - 1]);
}
// decoupled code for the vowel count, ternary operator to produce values
int vowelCount(char ch) // fuction that checks vowles value then adds one 
{
	return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' ||
		ch == 'e' || ch == 'i' || ch == 'O' || ch == 'U') ? (1) : (0);
}
