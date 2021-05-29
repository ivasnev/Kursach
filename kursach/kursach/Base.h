#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
using namespace std;

class Base;

// Введём новые типы данных - указатели на методы сигналов и обработчиков
typedef void (Base::* TYPE_SIGNAL) (string&);
typedef void (Base::* TYPE_HANDLER) (string);
// Макроопределения для приведения метода к типам TYPE_SIGNAL, TYPE_HANDLER

#define SIGNAL_D(signal_f) ( TYPE_SIGNAL ) (&signal_f)
#define HANDLER_D(handler_f) ( TYPE_HANDLER ) (&handler_f)

struct Connection
{
	Base* target_object;
	TYPE_SIGNAL signal;
	TYPE_HANDLER handler;
};

class Base {
protected:
	int index;
	string name;
	int status;
	Base* parent;
	vector<Base*> children;
	vector<Base*>::iterator children_iterator;
	list<Connection> connections;
public:
	Base(Base*, string = "base");
	~Base();
	void setName(string);
	void setStatus(int status);
	string getName();
	string getStatus();
	void setParent(Base*);
	Base* getParent();
	void printNames();
	void printNames2();
	void printNames3(int lvl = 1);
	Base* findDaddy(string name);
	vector<string> split(const string& s, char delim);
	Base* findDaddy2(string address);
	int getIndex();
	void connect(Base* target_object, TYPE_SIGNAL signal,
		TYPE_HANDLER handler);
	void disconnect(string target_object_name);
	void emit(TYPE_SIGNAL signal, string command);
	void signal_1(string& text);
	void handler_1(string text);
};
#endif