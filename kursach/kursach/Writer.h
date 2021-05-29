#ifndef WRITER_H
#define WRITER_H
#include "Base.h"

class Writer : public Base {
private:
	// ������ ��� ������ � ����
	fstream fout;
public:
	Writer(Base*, string);
	// ����� �������� � ���������� �����
	void createFile();
	// �����-����������
	void handleFromPosition(string);
	// ����� ������ ������ � ����
	void writeError(string);
	// ����� ������ ������� � �������� �������
	void writeSymbol(int, int, char);
};
#endif