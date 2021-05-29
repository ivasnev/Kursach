#ifndef POSITION_H
#define POSITION_H
#include "Base.h"
#include "Writer.h"
class Position : public Base {
private:
	// Указатель на объект для записи в файл
	Writer* writer;
public:
	// Конструктор класса
	Position(Base* parent, string name);
	// Метод-обработчик сигнала
	void handleFromApplication(string);
	// Метод-сигнал
	void signalToWriter(string&);
};
#endif

