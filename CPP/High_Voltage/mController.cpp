#include"mController.h"
#include"mFunctions.h"
#include"mMoveCharacters.h"
#include"mBuildMaze.h"
//#include"High_Voltage.h"
#include"GlobalVariables.h"
bool UnLoadMe{};

void mController_Show() {    
    UnLoadMe = false;
    std::string sNowInput{ "" };
    bool bSkipInput{ false };
    do
    {
        
        if (bSkipInput == false) {
            Output_A_Message("Player row: " + std::to_string(Shared_Vars::cActivePlayer.Row()), "nMsgBox0");
            Output_A_Message("Player column: " + std::to_string(Shared_Vars::cActivePlayer.Column()), "nMsgBox0");
            Output_A_Message("Make your move: ", "nQuestion0");
            std::cin >> sNowInput;
        }
        if (sNowInput=="0")
        {
            CommandButton0_Click();
        }
        else if (sNowInput == "1")
        {
            CommandButton1_Click();
        }
        else if (sNowInput == "2")
        {
            CommandButton2_Click();
        }
        else if (sNowInput == "3")
        {
            CommandButton3_Click();
        }
        else if (sNowInput == "4")
        {
            CommandButton4_Click();
        }
        else if (sNowInput == "5")
        {
            CommandButton5_Click();
        }
        else if (sNowInput == "6")
        {
            CommandButton6_Click();
        }
        else if (sNowInput == "7")
        {
            CommandButton7_Click();
        }
        else if (sNowInput == "8")
        {
            CommandButton8_Click();
        }
        else if (sNowInput == "9")
        {
            CommandButton9_Click();
        }
        else if (sNowInput == "10")
        {
            CommandButton10_Click();
            bSkipInput = true ;
            sNowInput = "loop_to_the_end";
        }
        else if (sNowInput == "-1")
        {
            CommandButtonNeg1_Click();
        }
        else if (sNowInput == "loop_to_the_end")
        {
            LoopToTheEnd();
        }
        else if (sNowInput == "q" || sNowInput == "x")
        {
            CommandButtonExit_Click();
        }
        else
        {
            //do nothing
            Output_A_Message("I don't understand.", "nMsgBox0");
        }
    } while (UnLoadMe == false);
}



void CommandButton0_Click() {
    srand(time(NULL));
    int iRow{ ((rand() % iMazeRows) + 1) - Shared_Vars::cActivePlayer.Row()};
    int iColumn{ ((rand() % iMazeCols) + 1) - Shared_Vars::cActivePlayer.Column()};
    Output_A_Message("Super Jump!!!", "nMsgBox0");
    MovePlayer(iRow, iColumn);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton1_Click(){
    MovePlayer(1, -1);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton2_Click() {
    MovePlayer(1, 0);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton3_Click() {
    MovePlayer(1, 1);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton4_Click() {
    MovePlayer(0, -1);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton5_Click() {
    MovePlayer(0, 0);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton6_Click() {
    MovePlayer(0, 1);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton7_Click() {
    MovePlayer(-1, -1);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton8_Click() {
    MovePlayer(-1, 0);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton9_Click() {
    MovePlayer(-1, 1);
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButton10_Click() {
    std::string sResponse;
    Output_A_Message("You've chosen to not to move for the rest of the game.", "nMsgBox0");
    Output_A_Message("We'll see if that was a wise choice or not.", "nMsgBox0");
    system("pause");
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButtonNeg1_Click() {
    Output_A_Message("You've chosen to give up.", "nMsgBox0");
    Shared_Vars::cActivePlayer.Alive(false);
    Shared_Vars::rMaze[Shared_Vars::cActivePlayer.Row()][Shared_Vars::cActivePlayer.Column()] = sDeadPlayerSymbol;
    system("pause");
    WhoIsAlive();
}

void LoopToTheEnd() {
    MoveInterceptors();
    WhoIsAlive();
}

void CommandButtonExit_Click(){
    UnLoadMe = true;
}

void WhoIsAlive(){
    DrawTheMaze();
    if (Shared_Vars::cActivePlayer.Alive() == false) {
        Output_A_Message("You are dead.  You lose!", "nMsgBox2");
        UnLoadMe = true;
    }
    else if (CheckInterceptorsAlive() == false) {
        Output_A_Message("All the interceptors are dead.  You win!", "nMsgBox2");            
        UnLoadMe = true;
    }

}

