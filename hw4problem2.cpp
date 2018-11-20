//////////////////////////////////////////////
// Andre Lussier 
// Data Structures
// page 259 problem 2
// William myers
// This program takes a number of students determined by the user
// names and scores 
// it reports the smallest largest and average scores 
// the names of people who got below average are reported 
// by the program to console 
///////////////////////////////////////////////


#include <iostream>
#include <string>
#include <cmath>


using namespace std;

int main()
{
	double* scores;
	string *names;
	int buffersize = 5;
	int tempbuff = 0;
	double average = 0;
	double total = 0;
	double highest = 0;



	cout << "enter the number of students you want to average" << endl;
	cin >> tempbuff;

	if (tempbuff > 0)
	{
		buffersize = tempbuff;
	}
	scores = new double[buffersize];
	names = new string[buffersize];

	
	int i = 0;
	while (i < buffersize)
	{
		cout << "enter a name " << endl;
		cin >> names[i];
		cout << "enter a score " << endl;
		cin >> scores[i];
		total += scores[i];
		if (scores[i] > highest)
		{
			highest = scores[i];
		}
		i++;
	}

	// i forget the details of c++ precedence so might as well go overboard
	average = (double)total / (double)buffersize;
	cout << "the class average is " << average << endl;

	i = 0;
	while (i < buffersize)
	{
		if (scores[i] < average)
		{
			cout << names[i] << " grade is below average consider studying harder " << endl;
		}
		i++;
	}

	i = 0;
	while (i < buffersize)
	{

		if (scores[i] == highest)
		{
			cout << names[i] << " was the highest in the class at " << scores[i] << endl;
		}
		i++;
	}

	system("pause");
	return 0;
}
