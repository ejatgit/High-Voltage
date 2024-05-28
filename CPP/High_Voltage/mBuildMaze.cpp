#include "mBuildMaze.h"
//#include"High_Voltage.h"
#include"cPlayer.h"
#include"cInterceptor.h"
#include"GlobalVariables.h"

using namespace Shared_Vars;
void SpawnPlayer(){

    cActivePlayer.Alive(true);

    srand(time(NULL));
    for (int iCount = 0; iCount < 1000; ++iCount) {
        int iRow = ((rand() % (iMazeRows - 1)) + 2);
        int iColumn = ((rand() % (iMazeCols - 1)) + 2);
        if (rMaze[iRow][iColumn] == sOpenAreaSymbol)
        {
            cActivePlayer.Row(iRow);
            cActivePlayer.Column(iColumn);
            break;
        }

    }
    
    rMaze[cActivePlayer.Row()][cActivePlayer.Column()] = sPlayerSymbol;
    
}

void Spawninterceptors() {
    
    srand(time(NULL));
    
    for (int i = 0; i < iNumberOfinterceptors; ++i) {
        cInterceptor cNowinterceptor;
        for (int iCount = 0; iCount < 1000; ++iCount) {
            int iRow = ((rand() % (iMazeRows - 1)) + 2);
            int iColumn = ((rand() % (iMazeCols - 1)) + 2);
            if (rMaze[iRow][iColumn] == sOpenAreaSymbol){
                cNowinterceptor.Row(iRow);
                cNowinterceptor.Column(iColumn);
                interceptorCollection.push_back(cNowinterceptor);                
                break;
            }
        }
    }
    
    for (size_t iCount = 0; iCount < interceptorCollection.size(); ++iCount) {
        cInterceptor cNowInterceptor;
        cNowInterceptor = interceptorCollection[iCount];
        rMaze[cNowInterceptor.Row()][cNowInterceptor.Column()] = sInterceptorSymbol;
     }
    
    nInterAlive = interceptorCollection.size() + 1;
    
}

void InstallHighVoltageBarriers(){
    int iBarrierCount;
    int iDice;
  
    srand(time(NULL));
    
    for (int iRow = 0; iRow < iMazeRows; ++iRow) {
        iBarrierCount = 0;
        for (int iCol = 0; iCol < iMazeCols; ++iCol) {
            if ((iRow == 0) || (iRow == iMazeRows - 1))
            {
                rMaze[iRow][iCol] = sHighVoltageSymbol;
            }
            else if ((iCol == 0) || (iCol == iMazeCols - 1)) {
                rMaze[iRow][iCol] = sHighVoltageSymbol;
            }
            else {
                iDice = ((rand() % 6) + 1);
                if (iDice == 4) {
                    if (iBarrierCount >= iMaxHighVoltageBarriersPerRow) {
                        break;
                    }
                    else {
                        rMaze[iRow][iCol] = sHighVoltageSymbol;
                        ++iBarrierCount;
                    }
                }
                else {
                    rMaze[iRow][iCol] = sOpenAreaSymbol;
                }                
            }
        }
    }    
}

void ClearMaze(){
    for (int iRow = 0; iRow < iMazeRows; ++iRow) {
        for (int iCol = 0; iCol < iMazeCols; ++iCol) {
            rMaze[iRow][iCol] = sOpenAreaSymbol;
        }
    }    
}

void InitialFillMaze(){
    InstallHighVoltageBarriers();
    Spawninterceptors();
    SpawnPlayer();
    DrawTheMaze();
}

void DrawTheMaze()
{
    for (int iRow = 0; iRow < iMazeRows; ++iRow) {        
        for (int iCol = 0; iCol < iMazeCols; ++iCol) {            
            std::cout << rMaze[iRow][iCol];             
        }
        std::cout << std::endl;        
    }
}