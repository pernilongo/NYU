#include <fstream>
using namespace std;

void csv_export(string data[][10], int records, int columns, string filename)
{
	ofstream fout(filename);
	for (int i = 0; i < records; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (j != 0)
				fout << ',';
			fout << data[i][j];
		}
		fout << endl;
	}
	fout.close();
}
