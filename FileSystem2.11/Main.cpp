#include <iostream>
#include <string>
#include <fstream>	// file stream (файловый поток). Библиотека, содержащая в себе классы для работы с файловой системой устройства
using namespace std;

bool statistic(string word);



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	
	// способы указания пути к файлу:
	// 1. Полный путь к файлу(C:\users)
	// 2. file.txt(он находится в папке с проектом)	
	// ofstream - запись данных в файл
	// ifstream - чтение данных из файла
	// fstream - запись данных в файл и чтение из файла

	string path = "file.txt";	// путь к файлу

	// Запись в файл
	/* // std::
	ofstream out(path); // 2 способ

	out.open(path, ios::app);	// открытие файла. 1 способ

	if (out.is_open()) {	// true, если файл открыт успешно
		cout << "Файл открыт для записи.\n";
		string tmp;
		cout << "Введите строку: ";
		getline(cin, tmp);
		out << tmp + '\n'; // добавление записи в файл
	}
	else
		cout << "Ошибка открытия файла.\n";
	
	out.close();	// закрытие файла
	*/

	// Чтение из файла (используется ios::in по умолчанию)
	/*ifstream in;
	in.open(path);

	if (in.is_open()) {
		cout << "Файл открыт для чтения.\nСодержимое файла:\n";
		// Первый способ. Посимвольное считывание
		// char sym;\
		while (in.get(sym))\
			cout << sym;\
		// Второй способ. Пословное считывание
		// while (!in.eof()) {			// End of file. Цикл: пока мы не в конце файла, мы считываем слово за слово\
			string tmp;\
			in >> tmp;\
			cout << tmp << ' ';\
		}\
		// Третий способ. Построчное считывание
		string str;
		while (getline(in, str))
			cout << str << '\n';
	}
	else
		cout << "Ошибка открытия файла.\n";
	in.close();*/

	// Удаление файла
	/*if (!remove(path.c_str()))	// c_str - метод строк, возращает С-ишный символьный массив
		cout << "Файл удален.\n";
	else
		cout << "Ошибка удаления файла.\n";*/

	// Задача 1. Статистика в файл
	cout << "Задача 1.\nВведите первое слово -> ";
	string str;
	cin >> str;
	if (statistic(str))
		cout << "Первое слово успешно записано.\n";
	else
		cout << "Ошибка записи.\n";

	cout << "Введите второе слово -> ";	
	cin >> str;
	if (statistic(str))
		cout << "Второе слово успешно записано.\n\n";
	else
		cout << "Ошибка записи.\n\n";


	return 0;
}
// Задача 1
bool statistic(string word) {
	string path = "file.txt";
	ofstream out;
	out.open(path, ios::app);

	if (out.is_open()) {
		out << word + ' ' << word.length() << '\n';
		out.close();
		return true;
	}

	out.close();
	return false;	
}