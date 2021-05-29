#include "Base.h"
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;

Base::Base(Base* parent, string name) {
	this->index = 1;
	this->parent = parent;
	setParent(parent);
	setName(name);
}

Base::~Base()
{
	for (int i = 0; i < this->children.size(); i++) {
		delete this->children[i];
	}
}

void Base::setName(string name) {
	this->name = name;
}

string Base::getName() {
	return this->name;
}

void Base::setParent(Base* parent) {
	if (this->parent != nullptr && (find(this->parent->children.begin(), this->parent->children.end(), this) != this->parent->children.end())) {
		this->parent->children.erase(find(this->parent->children.begin(), this->parent->children.end(), this));
		this->parent = parent;
	}
	this->parent = parent;
	if (parent) {
		parent->children.push_back(this);
	}
}

void Base::printNames() {
	if (children.empty()) return;
	cout << endl << name;
	children_iterator = children.begin();
	while (children_iterator != children.end()) {
		cout << "  " << (*children_iterator)->getName();
		children_iterator++;
	}
	children_iterator--;
	(*children_iterator)->printNames();
}

void Base::printNames2() {
	if (children.empty()) return;
	children_iterator = children.begin();
	while (children_iterator != children.end()) {
		cout << endl << "The object " << (*children_iterator)->getName() << (*children_iterator)->getStatus();
		(*children_iterator)->printNames2();
		children_iterator++;
	}
}

void Base::printNames3(int lvl) {
	string a = "";
	int tmp_lvl = lvl;
	for (int i = 0; i < tmp_lvl; i++) {
		a += "    ";
	}
	if (children.empty()) return;
	children_iterator = children.begin();
	while (children_iterator != children.end()) {
		cout << endl << a << (*children_iterator)->getName();
		tmp_lvl += 1;
		(*children_iterator)->printNames3(tmp_lvl);
		children_iterator++;
		tmp_lvl -= 1;
	}
}

Base* Base::findDaddy(string name)
{
	if (this->getName() == name) return this;
	if (children.empty()) return nullptr;
	children_iterator = children.begin();
	while (children_iterator != children.end()) {
		if (name == (*children_iterator)->getName()) {
			return *children_iterator;
		}
		Base* tmp = (*children_iterator)->findDaddy(name);
		if (tmp != nullptr && tmp->getName() == name) {
			return tmp;
		}
		children_iterator++;
	}
	return nullptr;
}

vector<string> Base::split(const string& s, char delim) {
	vector<string> elems;
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}
Base* Base::findDaddy2(string address)
{
	vector<string> keys = split(address, '/');
	keys.erase(keys.begin());
	if (keys[0] == this->getName() and keys.size() == 1) {
		return this;
	}
	else if (keys[0] != this->getName()) {
		return nullptr;
	}
	keys.erase(keys.begin());
	int size = keys.size();
	Base* tmp_daddy = this;
	for (int i = 0; i < size; i++) {
		children_iterator = tmp_daddy->children.begin();
		while (children_iterator != tmp_daddy->children.end()) {
			if (keys[i] == (*children_iterator)->getName()) {
				tmp_daddy = *children_iterator;
				break;
			}
			children_iterator++;
		}
		if (tmp_daddy->getName() != keys[i]) {
			return nullptr;
		}
	}
	if (tmp_daddy == this)
	{
		return nullptr;
	}
	else if (tmp_daddy->getName() != keys[size - 1])
	{
		return nullptr;
	}
	else
	{
		return tmp_daddy;
	}
}

void Base::connect(Base* target_object, TYPE_SIGNAL signal,
	TYPE_HANDLER handler)
{
	Connection connection = Connection();
	connection.target_object = target_object;
	connection.signal = signal;
	connection.handler = handler;
	this->connections.push_back(connection);
	return;
}
void Base::disconnect(string target_object_name) {
	for (auto connection = this->connections.begin(); connection != this->connections.end(); connection++) {
		if ((*connection).target_object->getName() == target_object_name) {
			this->connections.erase(connection);
			break;
		}
	}
	return;
}

// Вызов всех связанных с сигналом обработчиков
void Base::emit(TYPE_SIGNAL signal, string command) {
	(this->*signal) (command); // Вызов сигнала
	// Поиск всех обработчиков подключённых к данному сигналу
	for (auto connection : this->connections) {
		if (connection.signal == signal)
			(connection.target_object->*(connection.handler))
			(command); // Вызов обработчика
	}
	return;
}

void Base::signal_1(string& command)
{
	command = this->getName() + " -> " + command;
	return;
}
void Base::handler_1(string command)
{
	cout << endl << "Signal to " << this->getName() << " Text: " << command;
	return;
}

int Base::getIndex() {
	return this->index;
}

void Base::setStatus(int status) {
	this->status = status;
}
string Base::getStatus() {
	if (status <= 0) {
		return " is not ready";
	}
	else {
		return " is ready";
	}
}