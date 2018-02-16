#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif


#include <iostream>
#include "Vector.h"

using namespace std;

void check() {
	Vector vec3(3);

	Vector vecl(2);
	vecl[0] = 1;
	vecl[1] = 2;

	Vector vecr(3, 5);
	vecr[3] = 5;
	vecr[4] = 7;
	// vecr[5] = 5; // out of range

	cout << "vecl: "; vecl.print();
	cout << "vecr: "; vecr.print();
	cout << "vecl len: "<< vecl.getLen() << endl;

	Vector sum = vecl + vecr;
	//sum = vecl + vec3; // different length
	cout << "sum: "; sum.print();

	Vector subtraction = vecr - vecl;
	cout << "subtraction: "; subtraction.print();

	Vector multipl = vecr * 4;
	cout << "multipl: "; multipl.print();

	Vector division = multipl / 2;
	cout << "division: "; division.print();
}

int main() {
	check();

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}