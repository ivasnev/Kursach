#ifndef READER_H
#define READER_H
#include "Base.h"

class Reader: public Base {
private:
	ifstream file;
public:
	Reader(Base* parent, string name);
	void printFile();
};
#endif