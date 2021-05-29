#include "Reader.h"
#include <fstream>
#include <iostream>

Reader::Reader(Base* parent, string name) : Base(parent, name) {}

void Reader::printFile() {
	file.open("field.txt");
	string str;
	getline(file, str);
	cout << str;
	while (getline(file, str)) {
		cout << endl << str;
	}
}