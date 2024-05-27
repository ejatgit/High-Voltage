#pragma once
#include<string>

#ifndef mFunctions_H
#define mFunctions_H
//#include"GlobalVariables.h"

int offsetRowBy(int iValue);
int offsetColumnBy(int iValue);
int interceptorRowOffset(int iValue);
int interceptorColumnOffset(int iValue);
bool CheckInterceptorsAlive();
void Output_A_Message(std::string sNowMessage, std::string rLocation);
bool PlayAGame();
bool PlayAgain();
#endif

