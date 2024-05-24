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


//Public Const sOpenAreaSymbol As String = " "
const std::string sOpenAreaSymbol{ " " };
//Public Const sPlayerSymbol As String = "*"
const std::string sPlayerSymbol{ "*" };
//Public Const sDeadPlayerSymbol As String = "#"
const std::string sDeadPlayerSymbol{ "#" };
//Public Const sinterceptorSymbol As String = "+"
const std::string sInterceptorSymbol{ "+" };
//Public Const iNumberOfinterceptors As Integer = 15
const int iNumberOfinterceptors{ 15 };
//Public Const sHighVoltageSymbol As String = "x"
const std::string sHighVoltageSymbol{ "x" };
//Public Const iMaxHighVoltageBarriersPerRow As Integer = 15
const int iMaxHighVoltageBarriersPerRow{ 15 };
//Public rMaze As Range
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

    // not needed since output goes to the terminal not an excel range
    //Public interceptorCollection As Collection

    //reference for below collection
    // https://www.codeproject.com/Articles/6381/Creating-a-Collection-Class-in-C
    template <class TBase>
    class CustomCollection 
    {
    protected:
        //The Vector container that will hold the collection of Items
        std::vector<TBase> m_items;
    public:
        int Add(void); //{ return (m_items.size() - 1); }

        //Function to return the memory address of a specific Item
        TBase* GetAddress(int ItemKey);

        //Remove a specific Item from the collection
        void Remove(int ItemKey);

        void Clear(void); //{ return m_items; }//Clear the collection

        //Return the number of items in collection
        int Count(void);

        //Operator Returning a reference to TBase
        TBase& operator[](int ItemKey);

    };
    //template <class TBase>
    //CustomCollection<TBase> interceptorCollection;
    extern CustomCollection<cInterceptor> interceptorCollection;
    //CustomCollection interceptorCollection;
    //Public cActivePlayer As cPlayer
    //cPlayer cActivePlayer{};
}

#endif