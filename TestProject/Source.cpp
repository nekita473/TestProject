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

		while (getline(file, line))
		{
			//cout << line << endl;//����� ����������, ��� � ������� ���������

			//������ � line �������� ���������� ������� �� �����.
			//����� � ��������� �� ��������� �����.

			//� ����� ����� ���� ��� �������, � ����� ��� �����
			double close, high, low;

			//�������� ����� ��� ���������� ������ �� �������
			istringstream iss(line);

			//������ ����� ����������� �������� >> ������� ������
			//��������� ���� ������ ��� � �������� ����������� ����
			//������������ ���� ��������� \t

			//�� ��� �� �������
			iss >> close >> high >> low;

			//������� ���� ������
			cout << "������ �� �������:" << endl;
			cout << "\tClose: " << close << endl;
			cout << "\tHigh: " << high << endl;
			cout << "\tLow: " << low << endl;
		}
	}
	else
	{
		cout << "�� ������� ������� ����." << endl;
	}

	system("pause");
	return 0;
}