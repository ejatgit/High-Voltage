#pragma once
#include<string>
#include<vector>
//using namespace std;

#include "cPlayer.h"
#include "cInterceptor.h"
#ifndef GlobalVariables_H
#define GlobalVariables_H

//Public Const sOpenAreaSymbol As String = " "
const std::string sOpenAreaSymbol = " ";
//Public Const sPlayerSymbol As String = "*"
const std::string sPlayerSymbol = "*";
//Public Const sDeadPlayerSymbol As String = "#"
const std::string sDeadPlayerSymbol = "#";
//Public Const sinterceptorSymbol As String = "+"
const std::string sinterceptorSymbol = "+";
//Public Const iNumberOfinterceptors As Integer = 15
const int iNumberOfinterceptors = 15;
//Public Const sHighVoltageSymbol As String = "x"
const std::string sHighVoltageSymbol = "x";
//Public Const iMaxHighVoltageBarriersPerRow As Integer = 15
const int iMaxHighVoltageBarriersPerRow = 15;
//Public rMaze As Range
const int iMazeRows = 25;
const int iMazeCols = 30;
std::string rMaze[iMazeRows][iMazeCols];
// not needed since output goes to the terminal not an excel range
//Public interceptorCollection As Collection

//reference for below collection
// https://www.codeproject.com/Articles/6381/Creating-a-Collection-Class-in-C
template <class TBase>
class CustomCollection {
    protected:
        //The Vector container that will hold the collection of Items
        std::vector<TBase> m_items;
    public:
        int Add(void)
        {
            //Create a new base item
            TBase BaseItem;
            //Add the item to the container
            m_items.push_back(BaseItem);
            //Return the position of the item within the container. 
            //Zero Based
            return (m_items.size() - 1);
        }
        //Function to return the memory address of a specific Item
        TBase* GetAddress(int ItemKey)
        {
            return &(m_items[ItemKey]);
        }
        //Remove a specific Item from the collection
        void Remove(int ItemKey)
        {
            //Remove the Item using the vector’s erase function
            m_items.erase(GetAddress(ItemKey));
        }
        void Clear(void) //Clear the collection
        {
            m_items.clear();
        }
        //Return the number of items in collection
        int Count(void)
        {
            return m_items.size(); //One Based
        }
        //Operator Returning a reference to TBase
        TBase& operator [](int ItemKey)
        {
            return m_items[ItemKey];
        }
};
CustomCollection<cInterceptor> interceptorCollection;
//Public cActivePlayer As cPlayer
cPlayer cActivePlayer{};


#endif