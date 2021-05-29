#ifndef READER_H
#define READER_H
#include "Base.h"

class Reader: public Base {
private:
	// объект для чтения информации из файла
	ifstream file;
public:
	Reader(Base* parent, string name);
	// Метод вывода текста файла на экран
	void printFile();
};
#endif