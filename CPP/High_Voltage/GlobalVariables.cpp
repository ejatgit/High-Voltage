//Attribute VB_Name = "GlobalVariables"
//Option Explicit
//Public Const sOpenAreaSymbol As String = " "
//Public Const sPlayerSymbol As String = "*"
//Public Const sDeadPlayerSymbol As String = "#"
//Public Const sinterceptorSymbol As String = "+"
//Public Const iNumberOfinterceptors As Integer = 15
//Public Const sHighVoltageSymbol As String = "x"
//Public Const iMaxHighVoltageBarriersPerRow As Integer = 15
//Public rMaze As Range
//Public interceptorCollection As Collection
//Public cActivePlayer As cPlayer
#include "GlobalVariables.h"
namespace Shared_Vars{
    extern int nInterAlive{};
    extern int nInterKilled{};
    extern int nTotalinterceptorsKilled{};
    extern std::string rMaze[iMazeRows][iMazeCols]{};
    extern HANDLE hStdout{};
    extern HANDLE hStdin{};
    extern CONSOLE_SCREEN_BUFFER_INFO csbiInfo{};
    extern cPlayer cActivePlayer{};

    //reference for below collection
// https://www.codeproject.com/Articles/6381/Creating-a-Collection-Class-in-C
  /*
    template <class TBase>
    //class CustomCollection {
    //protected:
        //The Vector container that will hold the collection of Items
      //  std::vector<TBase> m_items;
    //public:
    int CustomCollection<TBase>::Add(void)
        {
            //Create a new base item
            TBase BaseItem{};
            //Add the item to the container
            m_items.push_back(BaseItem);
            //Return the position of the item within the container. 
            //Zero Based
            return (m_items.size() - 1);
        }
        //Function to return the memory address of a specific Item
    template <class TBase>
    TBase* CustomCollection<TBase>::GetAddress(int ItemKey)
        {
            return &(m_items[ItemKey]);
        }
        //Remove a specific Item from the collection
    template <class TBase>
    void CustomCollection<TBase>::Remove(int ItemKey)
        {
            //Remove the Item using the vector’s erase function
            m_items.erase(GetAddress(ItemKey));
        }
    template <class TBase>
    void CustomCollection<TBase>::Clear(void) //Clear the collection
        {
            m_items.clear();
        }
        //Return the number of items in collection
    template <class TBase>
    int CustomCollection<TBase>::Count(void)
        {
            return m_items.size(); //One Based
        }
        //Operator Returning a reference to TBase
    template <class TBase>
    TBase& CustomCollection<TBase>::operator [](int ItemKey)
        {
            return m_items[ItemKey];
        }
    //};
    */
    //CustomCollection<cInterceptor> interceptorCollection;
   // extern CustomCollection<cInterceptor> interceptorCollection{};
    extern std::vector<cInterceptor> interceptorCollection{};
}