#include <iostream>
#include <cmath>
#include <memory>
#include <string>
#include <vector>

using namespace std;

void Hanoi(int count, int tower1, int tower3, int tower2);


int main()
{


	Hanoi(5, 1, 2, 3);


	system("pause");
	return 0;

}

void Hanoi(int count, int tower1, int tower3, int tower2)
{

	if (count > 0)
	{
		Hanoi(count - 1, tower1, tower2, tower3);

		cout << "Move disk " << count << " from " << tower1
			<< " to " << tower3 << "." << endl;

		Hanoi(count - 1, tower2, tower3, tower1);
	}

}
