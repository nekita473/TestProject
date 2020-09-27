//���������� ����� input.txt
/*
Aslapova	Nastya	29	5
Nikolaev	Dima	12	9
Tokmin	Lev	96	75
*/

//#include "stdafx.h"//Visual Studio ����� ���������

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

int main()
{
	setlocale(LC_ALL, "RUSSIAN");//����� ������� ����� �������������

	//������� �������� ����� � ��������� ��� � ������
	ifstream file("Ea_Nasdaq_Full.txt");

	if (file.is_open())//���� �������� ����� ������ �������
	{
		cout << "���� ������." << endl;

		string line;//������� ������

		//����� ��������� ���������� ��������� �� ��� ���,
		//���� �� ���������� ����

		vector<double> close;
		vector<double> high;
		vector<double> low;

		int i = 1;
		while (getline(file, line))
		{
			if (i == 0) {
				cout << line << endl;//����� ����������, ��� � ������� ���������
				i++;
			}

			//������ � line �������� ���������� ������� �� �����.
			//����� � ��������� �� ��������� �����.

			//� ����� ����� ���� ��� �������, � ����� ��� �����
			double close_now, high_now, low_now;

			//�������� ����� ��� ���������� ������ �� �������
			istringstream iss(line);

			//������ ����� ����������� �������� >> ������� ������
			//��������� ���� ������ ��� � �������� ����������� ����
			//������������ ���� ��������� \t

			//�� ��� �� �������
			iss >> close_now >> high_now >> low_now;

			//������� ���� ������
			//cout << "������ �� �������:" << endl;
			//cout << "\tClose: " << close << endl;
			//cout << "\tHigh: " << high << endl;
			//cout << "\tLow: " << low << endl;

			close.push_back(close_now);
			high.push_back(high_now);
			low.push_back(low_now);
		}
		vector<double> ema_values_final = ema(close, 9);
		cout << ema_values_final[2514] << endl;
	}
	else
	{
		cout << "�� ������� ������� ����." << endl;
	}

	system("pause");
	return 0;
}