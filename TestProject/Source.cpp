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

int main()
{
	setlocale(LC_ALL, "RUSSIAN");//Чтобы русский текст поддерживался

	//Создаем файловый поток и связываем его с файлом
	ifstream file("Ea_Nasdaq_Full.txt");

	if (file.is_open())//Если открытие файла прошло успешно
	{
		cout << "Файл открыт." << endl;

		string line;//Строчка текста

		//Будем считывать информацию построчно до тех пор,
		//пока не закончится файл

		vector<double> close;
		vector<double> high;
		vector<double> low;

		while (getline(file, line))
		{
			//cout << line << endl;//Можно посмотреть, что в строчке считалось

			//Теперь в line хранится содержимое строчки из файла.
			//Будем её разбирать на составные части.

			//В нашем файле идут две строчки, а потом два числа
			double close, high, low;

			//Создадим поток для считывания данных из строчки
			istringstream iss(line);

			//Теперь через стандартный оператор >> считаем данные
			//Программа сама поймет что в качестве разделителя надо
			//использовать знак табуляции \t

			//За раз всё считаем
			iss >> close >> high >> low;

			//Выведем наши данные
			cout << "Данные из строчки:" << endl;
			cout << "\tClose: " << close << endl;
			cout << "\tHigh: " << high << endl;
			cout << "\tLow: " << low << endl;
		}
	}
	else
	{
		cout << "Не удалось открыть файл." << endl;
	}

	system("pause");
	return 0;
}