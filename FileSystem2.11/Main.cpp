#include <iostream>
#include <string>
#include <fstream>	// file stream (�������� �����). ����������, ���������� � ���� ������ ��� ������ � �������� �������� ����������
using namespace std;

bool statistic(string word);



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	
	// ������� �������� ���� � �����:
	// 1. ������ ���� � �����(C:\users)
	// 2. file.txt(�� ��������� � ����� � ��������)	
	// ofstream - ������ ������ � ����
	// ifstream - ������ ������ �� �����
	// fstream - ������ ������ � ���� � ������ �� �����

	string path = "file.txt";	// ���� � �����

	// ������ � ����
	/* // std::
	ofstream out(path); // 2 ������

	out.open(path, ios::app);	// �������� �����. 1 ������

	if (out.is_open()) {	// true, ���� ���� ������ �������
		cout << "���� ������ ��� ������.\n";
		string tmp;
		cout << "������� ������: ";
		getline(cin, tmp);
		out << tmp + '\n'; // ���������� ������ � ����
	}
	else
		cout << "������ �������� �����.\n";
	
	out.close();	// �������� �����
	*/

	// ������ �� ����� (������������ ios::in �� ���������)
	/*ifstream in;
	in.open(path);

	if (in.is_open()) {
		cout << "���� ������ ��� ������.\n���������� �����:\n";
		// ������ ������. ������������ ����������
		// char sym;\
		while (in.get(sym))\
			cout << sym;\
		// ������ ������. ��������� ����������
		// while (!in.eof()) {			// End of file. ����: ���� �� �� � ����� �����, �� ��������� ����� �� �����\
			string tmp;\
			in >> tmp;\
			cout << tmp << ' ';\
		}\
		// ������ ������. ���������� ����������
		string str;
		while (getline(in, str))
			cout << str << '\n';
	}
	else
		cout << "������ �������� �����.\n";
	in.close();*/

	// �������� �����
	/*if (!remove(path.c_str()))	// c_str - ����� �����, ��������� �-����� ���������� ������
		cout << "���� ������.\n";
	else
		cout << "������ �������� �����.\n";*/

	// ������ 1. ���������� � ����
	cout << "������ 1.\n������� ������ ����� -> ";
	string str;
	cin >> str;
	if (statistic(str))
		cout << "������ ����� ������� ��������.\n";
	else
		cout << "������ ������.\n";

	cout << "������� ������ ����� -> ";	
	cin >> str;
	if (statistic(str))
		cout << "������ ����� ������� ��������.\n\n";
	else
		cout << "������ ������.\n\n";


	return 0;
}
// ������ 1
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