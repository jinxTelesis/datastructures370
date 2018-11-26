//////////////////////////////////////////////////////////
//	Andre Lussier
//	BCS370 Data Structures
//	Chapter 4 problem 1
//	William Myers
//  
//	Description: This program stores 5 canidates
//	Along with votes they got 
//	it displays their names their vote totals 
//	and the percentage of the total votes they got
//	it displays the winner and the winning number of votes
//	to command prompt
//////////////////////////////////////////////////////////



#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> canidate = vector<string>();
	vector<string> canidatereader = vector<string>();
	vector<int> votes = vector<int>();
	vector<double> votepercent = vector<double>();
	//vector<double> percentage = vector<double>();
	int total = 0;
	int highest = 0;
	int highestindex = 0;

	cout << "Enter five canidates on seperate lines" << endl;

	int i = 0;
	string temp = "";
	string canidatewinner = "";
	while (i < 5)
	{
		i++;
		getline(cin,temp);
		canidate.push_back(temp);
		

	}

	cout << "Enter the votes for each canidate in order on sererpate lines " << endl;

	i = 0;
	int tempint = 0;
	temp = "";
	while (i < 5)
	{
		i++;
		getline(cin, temp);
		tempint = stoi(temp);
		if (tempint > highest)
		{
			highest = tempint;
			highestindex = i;
		}
		total = total + tempint;
		votes.push_back(tempint);
		votepercent.push_back(tempint);
		
	}

	cout << "canindate \t" << "Votes recieved\t" << "% of total " << endl;
	i = 0;
	while (i < 5)
	{

	cout << canidate[i] << ' ';
	cout << votes[i] << ' ';
	cout << (double)(votepercent[i])/total << '\n';

	i++;
	}
	cout << "Winner is " << canidatewinner << "with " << highest << endl;
 

	system("pause");
	return 0;
}
