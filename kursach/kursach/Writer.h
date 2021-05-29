#ifndef WRITER_H
#define WRITER_H
#include "Base.h"

class Writer : public Base {
private:
	// Объект для записи в файл
	fstream fout;
public:
	Writer(Base*, string);
	// Метод создания и заполнения файла
	void createFile();
	// Метод-обработчик
	void handleFromPosition(string);
	// Метод записи ошибки в файл
	void writeError(string);
	// Метод записи символа в заданную позицию
	void writeSymbol(int, int, char);
};
#endif