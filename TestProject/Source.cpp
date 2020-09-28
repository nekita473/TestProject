//Содержимое файла input.txt
/*
Aslapova	Nastya	29	5
Nikolaev	Dima	12	9
Tokmin	Lev	96	75
*/

//#include "stdafx.h"//Visual Studio может попросить

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<double> ema(vector<double> close, double n) {
	double alpha = 2 / (n + 1);
	vector<double> ema_values;
	ema_values.push_back(close[0]);
	for (int i = 1; i < close.size(); i++) {
		ema_values.push_back(alpha * close[i] + (1 - alpha) * ema_values[i - 1]);
	}
	return ema_values;
}

struct vector3d {
	vector3d() {
	}
	vector<double> firstvector;
	vector<double> secondvector;
	vector<double> thirdvector;
};

vector3d read_file(string filename) {
	setlocale(LC_ALL, "RUSSIAN");
	ifstream file(filename);
	vector<double> close;
	vector<double> high;
	vector<double> low;
	if (file.is_open())
	{
		cout << "Файл открыт." << endl;

		string line;

		while (getline(file, line))
		{
			double close_now, high_now, low_now;
			istringstream iss(line);

			iss >> close_now >> high_now >> low_now;

			close.push_back(close_now);
			high.push_back(high_now);
			low.push_back(low_now);
		}
	}
	else
	{
		cout << "Не удалось открыть файл." << endl;
	}
	vector3d res;
	res.firstvector = close;
	res.secondvector = high;
	res.thirdvector = low;

	return res;
}

int main()
{
	vector<double> close, high, low;
	vector3d res = read_file("Ea_Nasdaq_Full.txt");
	close = res.firstvector;
	vector<double> ema_values_final = ema(close, 9);
	cout << ema_values_final[2514] << endl;
	system("pause");
	return 0;
}