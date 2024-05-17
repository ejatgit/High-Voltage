// High_Voltage.cpp : Defines the entry point for the application.
//

#include "High_Voltage.h"
#include"mRunGame.h"
using namespace std;

int main()
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "Hello CMake." << endl;
	RunGame();
	return 0;
}
