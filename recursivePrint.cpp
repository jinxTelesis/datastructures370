//////////////////////////////////////////////
// Andre Lussier 
// Data Structures
// page 391 problem 1
// William Myers
// this program takes in a number n
// and recursively prints stars 
// both on the calls and the tails of the call
///////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void printLine(int n); // prototype for the recursive print line function
void recursivePrint(int n); // prototype for the recursive function 
// calls print line twice and has the general base case

int main()
{
	recursivePrint(5);



	system("pause");
	return 0;
}

void printLine(int n) // the fuction that actually prints the dots
{

	if (n == 1)
	{
		return;
	}
  
	cout << "* ";
	printLine(n - 1);
}

void recursivePrint(int n) // the forward and tail recursion that calls printline 
{
	if (n == 1)
	{
		return;
	}
    
	printLine(n);

	cout << endl;

	recursivePrint(n - 1);

	cout << endl;

	printLine(n);

}


