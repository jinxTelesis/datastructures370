//////////////////////////////
// Andre Lussier 
// problem 3 page 259
// Data Structures
// William myers
// Purpose: this program takes in a number of grades
// determined by the user
// then reports the smallest highest average
// and the people below that average to the command prompt
// 
///////////////////////////////


#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	vector<double> *doubvec = new vector<double>();
	string temp = "";
	double total = 0;
	int count = 0;
	double smallest = INT_MAX;
	double largest = INT_MIN;

	while (true)
	{

		cout << "enter real numbers till you get sick of it" << endl;
		cout << "enter x to stop" << endl;
		
		getline(cin, temp);

		if (temp == "x")
		{
			break;
		}

		if (stoi(temp) < smallest)
		{
			smallest = stoi(temp);
		}

		if (stoi(temp) > largest)
		{
			largest = stoi(temp);
		}

		total += stoi(temp);
		doubvec->push_back(stoi(temp));
		count++;
	}

	cout << "The smallest number is " << smallest << endl;
	cout << "The largest number is " << largest << endl;
	cout << "The average number is " << (double)total / (double)count << endl;




	system("pause");
	return 0;

}

