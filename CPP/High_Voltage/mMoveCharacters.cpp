
#include"mMoveCharacters.h"
//#include"High_Voltage.h"
#include "GlobalVariables.h"
#include "mFunctions.h"
//Attribute VB_Name = "mMoveCharacters"
//Option Explicit
//
using namespace Shared_Vars;
void MovePlayer(int x_iRow, int x_iColumn) {
    //Sub MovePlayer(ByRef x_iRow As Integer, ByRef x_iColumn As Integer)
    //Dim sTargetChar As String
    //Dim iLastRow As Integer
    //Dim iLastColumn As Integer
    //
    //Range("nPlayerMove").Value = Range("nPlayerMove").Value + 1
    //
    //iLastRow = cActivePlayer.Row
    int iLastRow = cActivePlayer.Row;
    //iLastColumn = cActivePlayer.Column
    int iLastColumn = cActivePlayer.Column;
    //
    //cActivePlayer.Row = cActivePlayer.Row + x_iRow
    cActivePlayer.Row = cActivePlayer.Row + x_iRow;
    //cActivePlayer.Column = cActivePlayer.Column + x_iColumn
    cActivePlayer.Column = cActivePlayer.Column + x_iColumn;
    //   
    //sTargetChar = rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value
    std::string sTargetChar = rMaze[cActivePlayer.Row][cActivePlayer.Column];
    //
    //If sTargetChar = sOpenAreaSymbol Then
    if (sTargetChar == sOpenAreaSymbol)
    {
        //   rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
        rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
        //   rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value = sPlayerSymbol
        rMaze[cActivePlayer.Row][cActivePlayer.Column] = sPlayerSymbol;
    }
    //ElseIf sTargetChar = sinterceptorSymbol Then
    else if (sTargetChar == sInterceptorSymbol) {
        //   rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
        rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
        //   rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value = sDeadPlayerSymbol
        rMaze[cActivePlayer.Row][cActivePlayer.Column] = sDeadPlayerSymbol;
        //   'MsgBox "You hit an interceptor!"
        //   Range("nMsgbox1").Value = "You hit an interceptor!"
        MsgBox("You hit an interceptor!","MsgBox0");
        //   
        cActivePlayer.Alive = false;
    }
    //ElseIf sTargetChar = sHighVoltageSymbol Then
        else if (sTargetChar == sHighVoltageSymbol){
    //   rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
        rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
    //   rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value = sDeadPlayerSymbol
        rMaze[cActivePlayer.Row][cActivePlayer.Column] = sDeadPlayerSymbol;
    //   'MsgBox "You hit a barrier!"
    //   Range("nMsgbox1").Value = "You hit a barrier!"
        MsgBox("You hit a barrier!","MsgBox0");
    //   cActivePlayer.Alive = False
        cActivePlayer.Alive = false;
    //End If    
    }
    //Range("nPlayerCell").Value = rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Address
    //   
    //End Sub
}
//
void MoveInterceptors(){
    //Sub MoveInterceptors()
    //Dim sTargetChar As String
    std::string sTargetChar;
    //Dim iLastRow As Integer
    int iLastRow;
    //Dim iLastColumn As Integer
    int iLastColumn;
    //Dim cNowinterceptor As cInterceptor
    cInterceptor cNowInterceptor;
    //Dim iDeaths As Integer
    //Dim iPlayerDeaths As Integer
    //iDeaths = 0
    int iDeaths = 0;
    //iPlayerDeaths = 0
    int iPlayerDeaths = 0;
    //For Each cNowinterceptor In interceptorCollection
    for (int i = 0; i < interceptorCollection.Count(); ++i) {
        cNowInterceptor=interceptorCollection[i];
        //   If cNowinterceptor.Alive Then
        if (cNowInterceptor.Alive) {
            //      iLastRow = cNowinterceptor.Row
            iLastRow = cNowInterceptor.Row;
            //      iLastColumn = cNowinterceptor.Column
            iLastColumn = cNowInterceptor.Column;
            //      
            //      cNowinterceptor.Row = cNowinterceptor.Row + interceptorRowOffset(cNowinterceptor.Row)
            cNowInterceptor.Row = cNowInterceptor.Row + interceptorRowOffset(cNowInterceptor.Row);
            //      cNowinterceptor.Column = cNowinterceptor.Column + interceptorColumnOffset(cNowinterceptor.Column)
            cNowInterceptor.Column = cNowInterceptor.Column + interceptorColumnOffset(cNowInterceptor.Column);
            //         
            //      sTargetChar = rMaze.Cells(cNowinterceptor.Row, cNowinterceptor.Column).Value
            sTargetChar = rMaze[cNowInterceptor.Row][cNowInterceptor.Column];
            //      
            //      If sTargetChar = sOpenAreaSymbol Then
            if (sTargetChar == sOpenAreaSymbol) {
                //         rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
                rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
                //         rMaze.Cells(cNowinterceptor.Row, cNowinterceptor.Column).Value = sinterceptorSymbol
                rMaze[cNowInterceptor.Row][cNowInterceptor.Column] = sInterceptorSymbol;
            }
            //      ElseIf sTargetChar = sPlayerSymbol Then
            else if (sTargetChar == sPlayerSymbol) {
                //         rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
                rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
                //         rMaze.Cells(cNowinterceptor.Row, cNowinterceptor.Column).Value = sDeadPlayerSymbol
                rMaze[cNowInterceptor.Row][cNowInterceptor.Column] = sDeadPlayerSymbol;
                //         iPlayerDeaths = iPlayerDeaths + 1
                iPlayerDeaths = iPlayerDeaths + 1;
                //         cActivePlayer.Alive = False
                cActivePlayer.Alive = false;
            }//      ElseIf sTargetChar = sHighVoltageSymbol Then
            else if (sTargetChar == sHighVoltageSymbol) {
                //         rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
                rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
                //         iDeaths = iDeaths + 1
                iDeaths = iDeaths + 1;
                //         cNowinterceptor.Alive = False
                cNowInterceptor.Alive = false;
                //      End If
            }
            //   End If
        }
        //Next cNowinterceptor
    }
    //
    //If iDeaths > 0 Then
    if (iDeaths > 0) {
        //   'MsgBox "You killed " & iDeaths & " interceptor(s)!"
        //   Range("nMsgbox0").Value = "You killed " & iDeaths & " interceptor(s)!"
        MsgBox("You killed " + std::to_string(iDeaths) + " interceptor(s)!", "nMsgbox0");
        //   Range("nInterAlive").Value = Range("nInterAlive").Value - iDeaths
        nInterAlive = nInterAlive - iDeaths;
        MsgBox("Alive Interceptor(s): " + std::to_string(nInterAlive), "nInterAlive");
        //   Range("nInterKilled").Value = Range("nInterKilled").Value + iDeaths
        nInterKilled = nInterKilled + iDeaths;
        MsgBox("Dead Interceptor(s): " + std::to_string(nInterKilled), "nInterKilled");
        //   Range("nTotalinterceptorsKilled").Value = Range("nTotalinterceptorsKilled").Value + iDeaths
        nTotalinterceptorsKilled = nTotalinterceptorsKilled + iDeaths;
        MsgBox("Total Dead Interceptor(s): " + nTotalinterceptorsKilled, "nTotalinterceptorsKilled");
        //End If
    }
    //
        //If iPlayerDeaths > 0 Then
    if (iPlayerDeaths > 0) {
        //   'MsgBox "You've been hit by " & iPlayerDeaths & " interceptor(s)!"
        //   Range("nMsgbox0").Value = "You've been hit by " & iPlayerDeaths & " interceptor(s)!"
        MsgBox("You've been hit by " + std::to_string(iPlayerDeaths) + " interceptor(s)!", "nMsgbox0");
        //End If
    } //
        //End Sub       
       

    
}