#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream input("records.txt");
	string record;
	while (getline(input, record))
	{
		istringstream line(record);
		string word;
		while (line >> word)
		{
			cout << word << " ";
		}
		cout << endl;
	}
	return 0;
}