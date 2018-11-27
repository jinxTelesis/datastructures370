#include <iostream>
#include <string>

using namespace std;

int fact(int num); // proto
int largest(const int list[], int lowerIndex, int upperIndex);
int rFibNum(int a, int b, int n);

int main()
{

	int mylist[] = { 5,10,12,8 };


	//cout << fact(3) << endl;
	//cout << largest(mylist, 0, 3) << endl;
	cout << rFibNum(2, 3, 7) << endl;


	system("pause");
	return 0;

}

int rFibNum(int a, int b, int n)
{
	if (n == 1)
	{
		return a;
	}
	else if( n ==2)
	{
		return b;
	}
	else
	{
		return rFibNum(a, b, n - 1) + rFibNum(a, b, n - 2);
	}


}

int largest(const int list[], int lowerIndex, int upperIndex)
{
	int max;

	if (lowerIndex == upperIndex)
	{
		return list[lowerIndex];
	}
	else
	{
		max = largest(list, lowerIndex + 1, upperIndex);

		if (list[lowerIndex] >= max)
		{
			return list[lowerIndex];
		}
		else
		{
			return max;
		}

	}

}

int fact(int num)
{
	if (num == 0)
	{
		return 1;
	}
	else
	{
		return num * fact(num - 1);
	}
}
