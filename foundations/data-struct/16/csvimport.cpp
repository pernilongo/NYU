#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void csv_import(string data[][10], int columns, int *records, string filename)
{
	string line;
	ifstream fin(filename);
	int i = 0;
	while (getline(fin, line))
	{
		int j = 0;
		string col;
		istringstream tokenStream(line);
		while (getline(tokenStream, col, ','))
		{
			data[i][j++] = col;
		}
		i++;
	}
	fin.close();
	*records = i;
}
