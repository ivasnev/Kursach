#include "Writer.h"

Writer::Writer(Base* parent, string name) : Base(parent, name) {}

void Writer::createFile() {
	this->fout.open("field.txt", ios::out);
	for (int i = 0; i < 10; i++) {
		fout << 8888888888;
		if (i != 9) {
			fout << endl;
		}
	}
	this->fout.close();
}
void Writer::handleFromPosition(string command) {
	if (command.find("Coordinate is wrong ( ", 0) != string::npos ||
		command.find("Not a letter of the Latin alphabet: ", 0) != string::npos) {
		this->writeError(command);
	}
	else {
		vector<string> keys = split(command, 32);
		int x = stoi(keys[0]);
		int y = stoi(keys[1]);
		this->writeSymbol(x, y, keys[2][0]);
	}
}
void Writer::writeError(string error) {
	this->fout.open("field.txt", ofstream::app);
	fout << endl << error;
	this->fout.close();
}
void Writer::writeSymbol(int x, int y, char symbol) {
	fout.open("field.txt", ios::in);
	vector<string> data;
	string str;
	while (getline(fout, str)) {
		data.push_back(str);
	}
	fout.close();
	fout.open("field.txt", ios::out);
	if (x - 1 == 0) {
		data[0][y - 1] = symbol;
	}
	fout << data[0];
	for (int i = 1; i < data.size(); i++) {
		if (i == x - 1) {
			data[i][y - 1] = symbol;
		}
		fout << endl << data[i];
	}
	fout.close();
}