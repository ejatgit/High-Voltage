// High_Voltage.cpp : Defines the entry point for the application.
//

#include "High_Voltage.h"
#include"mRunGame.h"
//using namespace std;
//using namespace Shared_Vars;
#include"GlobalVariables.h"
int main()
{
	Shared_Vars::hStdin = GetStdHandle(STD_INPUT_HANDLE);
	Shared_Vars::hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	RunGame();

	return 0;
}
