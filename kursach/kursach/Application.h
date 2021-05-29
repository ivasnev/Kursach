#ifndef APP_H
#define APP_H
#include "Position.h"
#include "Reader.h"
#include "Writer.h"

// Введём новые типы данных - указатели на методы сигналов и обработчиков
typedef void (Base::* TYPE_SIGNAL) (string&);
typedef void (Base::* TYPE_HANDLER) (string);
// Макроопределения для приведения метода к типам TYPE_SIGNAL, TYPE_HANDLER

#define SIGNAL_D(signal_f) ( TYPE_SIGNAL ) (&signal_f)
#define HANDLER_D(handler_f) ( TYPE_HANDLER ) (&handler_f)

class Application : public Base {
private:
	// Объект для определения позиции
	Position* position;
	// Объект для чтения из файла
	Reader* reader;
	// Объект для записи в файл
	Writer* writer;
	// Переменная для сигнализации выхода из цикла
	bool endInput;
public:
	// Конструктор класса
	Application(Base* parent = 0);
	// Метод, реализующий основной алгоритм программы
	int execute();
	// Метод-сигнал для определения позиции
	void signalToPosition(string&);
};
#endif