#include"mRunGame.h"
#include"mBuildMaze.h"
#include"mController.h"
#include"mFunctions.h"
//#include"High_Voltage.h"

void RunGame() {

    GameIntro();

    if (PlayAGame() == true) {

        InitialFillMaze();

        mController_Show();
    
        if (PlayAgain() == true) {
            do
            {
                ClearMaze();
                InitialFillMaze();
                mController_Show();
            } while (PlayAgain() == true);
        }
    }
    ExitGame();
}

void ExitGame(){
    //End
}

void GameIntro() {
    Output_A_Message("        *=================*", "nMsgBox0");
    Output_A_Message("        | High Voltage!!! |", "nMsgBox0");
    Output_A_Message("        *=================*", "nMsgBox0");
    Output_A_Message("", "nMsgBox0");
    Output_A_Message("You are within the walls of a high voltage maze.", "nMsgBox0");
    Output_A_Message("There are 15 security machines (interceptors)", "nMsgBox0");
    Output_A_Message("trying to destroy you.", "nMsgBox0");
    Output_A_Message("", "nMsgBox0");
    Output_A_Message("You are the '*', and the interceptors are the '+'.", "nMsgBox0");
    Output_A_Message("The areas marked 'x' are high voltage!", "nMsgBox0");
    Output_A_Message("Your only hope is to destroy the interceptors by", "nMsgBox0");
    Output_A_Message("running them into an 'x'.", "nMsgBox0");    
    Output_A_Message("Your moves are as follows: ", "nMsgBox0");
    Output_A_Message("", "nMsgBox0");
    Output_A_Message("      7.8.9    ^", "nMsgBox0");
    Output_A_Message("      4. .6  < + >", "nMsgBox0");
    Output_A_Message("      1.2.3    v", "nMsgBox0");
    Output_A_Message(" ", "nMsgBox0");
    Output_A_Message("5 = No move for one turn.", "nMsgBox0");
    Output_A_Message("10 = No move for the rest of the game.", "nMsgBox0");
    Output_A_Message("-1 = Give up. Situation hopeless.", "nMsgBox0");
    Output_A_Message("and of course '0' is super jump.", "nMsgBox0");
}