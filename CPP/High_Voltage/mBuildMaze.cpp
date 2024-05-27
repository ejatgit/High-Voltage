#include "mBuildMaze.h"
//#include"High_Voltage.h"
#include"cPlayer.h"
#include"cInterceptor.h"
#include"GlobalVariables.h"
//Attribute VB_Name = "mBuildMaze"
//Option Explicit
//
using namespace Shared_Vars;
void SpawnPlayer(){
    //Sub SpawnPlayer()
    //Dim iCount As Integer
    //Dim iRow As Integer
    //Dim iColumn As Integer
    //
    //Set cActivePlayer = New cPlayer
   // cPlayer cActivePlayer;
    //
    //iCount = 1
    //
    //Do
    for (int iCount = 0; iCount < 1000; ++iCount) {
        //   iRow = Int(((rMaze.Rows.Count - 1) * Rnd) + 2)
        int iRow = ((rand() % (iMazeRows - 1)) + 2);
        //   iColumn = Int(((rMaze.Columns.Count - 1) * Rnd) + 2)
        int iColumn = ((rand() % (iMazeCols - 1)) + 2);
        //   If rMaze.Cells(iRow, iColumn).Value = sOpenAreaSymbol Then
        if (rMaze[iRow][iColumn] == sOpenAreaSymbol)
        {
            //      cActivePlayer.Row = iRow
            cActivePlayer.Row(iRow);
            //      cActivePlayer.Column = iColumn
            cActivePlayer.Column(iColumn);
            //      Exit Do
            break;
        }

        //   End If
        //   iCount = iCount + 1
        //Loop While iCount < 1000
    }//
    //rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value = sPlayerSymbol
    rMaze[cActivePlayer.Row()][cActivePlayer.Column()] = sPlayerSymbol;
    //Range("nPlayerCell").Value = rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Address
    //
    //End Sub
}

void Spawninterceptors() {
    //Sub Spawninterceptors()
    //Dim i As Integer
    //Dim iCount As Integer
    //Dim iRow As Integer
    //Dim iColumn As Integer
    //Dim cNowinterceptor As cInterceptor
    //
    
    //For i = 1 To iNumberOfinterceptors
    for (int i = 0; i < iNumberOfinterceptors; ++i) {
        //   iCount = 1
        //   Set cNowinterceptor = New cInterceptor
        cInterceptor cNowinterceptor;
        //   Do
        for (int iCount = 0; iCount < 1000; ++iCount) {
            //      iRow = Int(((rMaze.Rows.Count - 1) * Rnd) + 2)
            int iRow = ((rand() % (iMazeRows - 1)) + 2);
            //      iColumn = Int(((rMaze.Columns.Count - 1) * Rnd) + 2)
            int iColumn = ((rand() % (iMazeCols - 1)) + 2);
            //      If rMaze.Cells(iRow, iColumn).Value = sOpenAreaSymbol Then
            if (rMaze[iRow][iColumn] == sOpenAreaSymbol){
                //         cNowinterceptor.Row = iRow
                cNowinterceptor.Row(iRow);
                //         cNowinterceptor.Column = iColumn
                cNowinterceptor.Column(iColumn);
                //         Call interceptorCollection.Add(cNowinterceptor)
                //int iCount = interceptorCollection.Add();
                //interceptorCollection[iCount] = cNowinterceptor;
                interceptorCollection.push_back(cNowinterceptor);                
                //         Exit Do
                break;
                //      End If
            }//      iCount = iCount + 1
            //   Loop While iCount < 1000
        }
        //Next i
    }//
    //For Each cNowinterceptor In interceptorCollection
    //   rMaze.Cells(cNowinterceptor.Row, cNowinterceptor.Column).Value = sinterceptorSymbol
    //Next cNowinterceptor
    for (int i = 0; i < interceptorCollection.size(); ++i) {
        cInterceptor cNowInterceptor;
        cNowInterceptor = interceptorCollection[i];
                //         rMaze.Cells(cNowinterceptor.Row, cNowinterceptor.Column).Value = sinterceptorSymbol
                rMaze[cNowInterceptor.Row()][cNowInterceptor.Column()] = sInterceptorSymbol;
        
     }
    nInterAlive = interceptorCollection.size() + 1;
    //
    //End Sub
}

void InstallHighVoltageBarriers(){
    //Sub InstallHighVoltageBarriers()
    //Dim iRow As Integer
    //Dim iCol As Integer
    //Dim iBarrierCount As Integer
    int iBarrierCount;
    //Dim iDice As Integer
    int iDice;
    //
    //For iRow = 1 To rMaze.Rows.Count
    for (int iRow = 0; iRow < iMazeRows; ++iRow) {
        //   iBarrierCount = 0
        iBarrierCount = 0;
        //   For iCol = 1 To rMaze.Columns.Count
        for (int iCol = 0; iCol < iMazeCols; ++iCol) {
            //      If iRow = 1 Or iRow = rMaze.Rows.Count Then
            if ((iRow == 0) || (iRow == iMazeRows - 1))
            {
                //         rMaze.Cells(iRow, iCol).Value = sHighVoltageSymbol
                rMaze[iRow][iCol] = sHighVoltageSymbol;
            }

            //      ElseIf iCol = 1 Or iCol = rMaze.Columns.Count Then
            else if ((iCol == 0) || (iCol == iMazeCols - 1)) {
                //         rMaze.Cells(iRow, iCol).Value = sHighVoltageSymbol
                rMaze[iRow][iCol] = sHighVoltageSymbol;
            }
            //      Else
            else {
                //         iDice = Int((6 * Rnd) + 1)
                iDice = ((rand() % 6) + 1);
                //         If iDice > 4 Then
                if (iDice == 4) {
                    //            If iBarrierCount >= iMaxHighVoltageBarriersPerRow Then
                    if (iBarrierCount >= iMaxHighVoltageBarriersPerRow) {
                        //               Exit For
                        break;
                    }
                    //            Else
                    else {
                        //               rMaze.Cells(iRow, iCol).Value = sHighVoltageSymbol
                        rMaze[iRow][iCol] = sHighVoltageSymbol;
                        //               iBarrierCount = iBarrierCount + 1
                        ++iBarrierCount;// = iBarrierCount + 1;
                        //            End If
                    }
                }
                //         Else
                else {
                    //            rMaze.Cells(iRow, iCol).Value = sOpenAreaSymbol
                    rMaze[iRow][iCol] = sOpenAreaSymbol;
                    //         End If
                }
                //      End If
            }
            //   Next iCol
        }
        //   
        //Next iRow
    }
    //End Sub
}

void ClearMaze(){
    //Sub ClearMaze()
    //Dim iRow As Integer
    //Dim iCol As Integer
    //
    //For iRow = 1 To rMaze.Rows.Count
    for (int iRow = 0; iRow < iMazeRows; ++iRow) {
        //   For iCol = 1 To rMaze.Columns.Count
        for (int iCol = 0; iCol < iMazeCols; ++iCol) {
            //      rMaze.Cells(iRow, iCol).Value = sOpenAreaSymbol
            rMaze[iRow][iCol] = sOpenAreaSymbol;
            //   Next iCol
        }
        //Next iRow
    }
//
    //End Sub
}

//Sub InitialFillMaze()
void InitialFillMaze(){
    //Application.Calculation = xlCalculationManual
    //Randomize
    //ThisWorkbook.Activate
    //Worksheets("Maze").Activate
    //Set rMaze = Range("tblHVMaze")
    //Set interceptorCollection = New Collection
    //
    //Range("nMsgbox0").Value = ""
    //Range("nMsgbox1").Value = ""
    //Range("nMsgbox2").Value = ""
    //
    //Range("nInterAlive").Value = iNumberOfinterceptors
    //Range("nInterKilled").Value = 0
    //
    //Call ClearMaze
    //ClearMaze();
//Call InstallHighVoltageBarriers
    InstallHighVoltageBarriers();
//Call Spawninterceptors
    Spawninterceptors();
//Call SpawnPlayer
//SpawnPlayer();
    SpawnPlayer();
//Application.Calculation = xlCalculationAutomatic
//End Sub
    DrawTheMaze();
}

void DrawTheMaze()
{
    for (int iRow = 0; iRow < iMazeRows; ++iRow) {        
        for (int iCol = 0; iCol < iMazeCols; ++iCol) {            
            //rMaze[iRow][iCol] = sOpenAreaSymbol;
            std::cout << rMaze[iRow][iCol];             
        }
        std::cout << std::endl;        
    }
}