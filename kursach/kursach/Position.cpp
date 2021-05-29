#include "Position.h"

Position::Position(Base* parent, string name) : Base(parent, name) {
	this->writer = new Writer(this,"writer");
	connect(this->writer,SIGNAL_D(Position::signalToWriter),HANDLER_D(Writer::handleFromPosition));
}
void Position::handleFromApplication(string command) {
	vector<string> keys = split(command,32);
	if (keys[0] == "NULL") {
		return;
	}
	emit(SIGNAL_D(Position::signalToWriter), command);
}
void Position::signalToWriter(string& command) {
	vector<string> keys = split(command, 32);
	string xStr = keys[0];
	string yStr = keys[1];
	int x = stoi(xStr);
	int y = stoi(yStr);
	string symbol = keys[2];
	if (x < 1 || y < 1 || x > 10 || y > 10) {
		command = "Coordinate is wrong ( " + xStr + ", " + yStr +
			" )";
	}
	else if (!(symbol[0] >= 'A' && symbol[0] <= 'Z' || symbol[0] >= 'a' &&
		symbol[0] <= 'z')) {
		command = "Not a letter of the Latin alphabet: " + symbol;
	}
}