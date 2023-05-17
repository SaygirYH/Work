#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	char* filename = argv[1];
	ifstream fin(filename);
	ofstream data;
	data.open("data.dzn");
    long long V, i, j, k = 0;
	fin >> V;
	data << "V = " << V << ';' << endl;
	data << "E_n = " << V * (V - 1) << ';' << endl;
	data << "E = array2d(1..E_n, 1..2,[" << endl;
	for (i = 0; i < V; i++)
        {
		for (j = 0; j < V; j++)
		{
			if (i != j)
			{
				data << i + 1 << ',' << j + 1 << ',' << endl;
			}
		}
	}
	data << "]);" << endl;
	data << endl;
	double x_i, y_i;// dist;
	vector <double> x (V);
	vector <double> y (V);
	for (i = 0; i < V; i++)
	{
		fin >> x_i >> y_i;
		x[i] = x_i;
		y[i] = y_i;
	}
	data << "c = [" << endl;
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			if (i != j)
			{
				data << round(sqrt((x[i] - x[j]) *
                       (x[i] - x[j]) + (y[i] - y[j]) *
                       (y[i] - y[j])) * 1000) << ',' << endl;
			}
		}
	}
	data << "];";
	data.close();
	fin.close();
	system("minizinc --solver Gecode minizinc_TSP.mzn data.dzn");
	return 0; //
}
