#include"mRunGame.h"
#include"mBuildMaze.h"
#include"mController.h"
//#include"High_Voltage.h"
//Attribute VB_Name = "mRunGame"
//Option Explicit
//
void RunGame() {
    //Sub RunGame()
    //
    //Call InitialFillMaze
    InitialFillMaze();
    //frmController.Show
    mController_Show();
    //Call ExitGame
    ExitGame();
    //
    //End Sub
}//
//
//
void ExitGame(){
    //Sub ExitGame()
    //
    //Set interceptorCollection = Nothing
    //Set cActivePlayer = Nothing
    //Set rMaze = Nothing
    //
    //End Sub
}