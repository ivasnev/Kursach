#ifndef APP_H
#define APP_H
#include "Position.h"
#include "Reader.h"
#include "Writer.h"

typedef void (Base::* TYPE_SIGNAL) (string&);
typedef void (Base::* TYPE_HANDLER) (string);

#define SIGNAL_D(signal_f) ( TYPE_SIGNAL ) (&signal_f)
#define HANDLER_D(handler_f) ( TYPE_HANDLER ) (&handler_f)

class Application : public Base {
private:
	Position* position;
	Reader* reader;
	Writer* writer;
	bool endInput;
public:
	Application(Base* parent = 0);
	int execute();
	void signalToPosition(string&);
};
#endif