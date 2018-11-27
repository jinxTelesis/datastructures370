//////////////////////////////////////////////
// Andre Lussier 
// Data Structures
// page 391 problem 8
// William Myers
// this program takes in a set of digits
// and reverses the order of those digits
// recursively first isn't a real conversion
// just a display and builtins
///////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void reverseDigits(int digits, string dummy);
void reverseNumericly(int number);


int main()
{
	reverseDigits(70010,"");
	reverseNumericly(213104);
	system("pause");
	return 0;

}

// hack solution that produces the reverse via library string
// minupulation 
void reverseDigits(int digits, string dummy)
{
	dummy = to_string(digits);

	int digitLength = dummy.length();

	if (digitLength == 1)
	{
		cout << dummy << endl;
	}
	else
	{
		cout << dummy[digitLength - 1];
		reverseDigits(stoi(dummy.substr(0, digitLength - 1)),dummy.substr(0, digitLength - 1));
	}
}


void reverseNumericly(int digits) {
	if (digits == 0)
	{
		return;
	}
	
	cout << digits % 10; // will print off the last number thats what mod ten does 
	reverseNumericly(digits / 10); // passes the the number will one less digit and the modulus number printed off 
	
}
