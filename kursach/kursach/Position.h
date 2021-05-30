#ifndef POSITION_H
#define POSITION_H
#include "Base.h"
#include "Writer.h"
class Position : public Base {
private:
	Writer* writer;
public:
	Position(Base* parent, string name);
	void handleFromApplication(string);
	void signalToWriter(string&);
};
#endif

