#include "Application.h"
#include "Base.h"
#include <iostream>
using namespace std;

Application::Application(Base* parent) : Base(parent) {
	this->position = new Position(this, "writer");
	this->reader = new Reader(this, "writer");
	this->writer = new Writer(this,"writer");
	this->endInput = false;
	connect(this->position, SIGNAL_D( Application::signalToPosition),HANDLER_D(Position::handleFromApplication));
}
int Application::execute()
{
	this->writer->createFile();
	string command;
	while (true) {
		if (this->endInput) {
			break;
		}
		emit(SIGNAL_D(Application::signalToPosition), command);
	}
	this->reader->printFile();
	return 0;
}
void Application::signalToPosition(string& command) {
	string x, y;
	char symbol = ' ';
	cin >> x >> y;
	if (x == "0" && y == "0") {
		this->endInput = true;
	}
	else {
		cin >> symbol;
	}
	command = x + ' ' + y + ' ' + symbol;
}
