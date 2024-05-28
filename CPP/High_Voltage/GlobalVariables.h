#pragma once

//using namespace std;

#ifndef GlobalVariables_H
#define GlobalVariables_H

#include<iostream>
#include<string>
#include<vector>
#include<windows.h>

//#include"mFunctions.h"
#include"cPlayer.h"
#include"cInterceptor.h"
//#include"mRunGame.h"
//#include"mMoveCharacters.h"
//#include"mBuildMaze.h"
//#include"mController.h"


const std::string sOpenAreaSymbol{ " " };
const std::string sPlayerSymbol{ "*" };
const std::string sDeadPlayerSymbol{ "#" };
const std::string sInterceptorSymbol{ "+" };
const int iNumberOfinterceptors{ 15 };
const std::string sHighVoltageSymbol{ "x" };
const int iMaxHighVoltageBarriersPerRow{ 15 };

const int iMazeRows{ 25 };
const int iMazeCols{ 30 };

namespace Shared_Vars {
    extern int nInterAlive;
    extern int nInterKilled;
    extern int nTotalinterceptorsKilled;
    extern std::string rMaze[iMazeRows][iMazeCols];
    extern HANDLE hStdout;
    extern HANDLE hStdin;
    extern CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    extern cPlayer cActivePlayer;
    extern std::vector<cInterceptor> interceptorCollection;
}

#endif