
//#include"mFunctions.h"
//import { Output_A_Message } from "./mFunctions.js";
//#include"mMoveCharacters.h"
//import { MovePlayer, MoveInterceptors } from "./mMoveCharacters.js";
//#include"mBuildMaze.h"
//import { cInterceptor } from "./mBuildMaze.js";
//#include"High_Voltage.h"
//#include"GlobalVariables.h"
//import { cActivePlayer, rMaze, iMazeRows, iMazeCols, sDeadPlayerSymbol } from "./GlobalVariables.js";
let UnLoadMe = false;
/*
function mController_Show() {
   //UnLoadMe = false;
   let sNowInput = "";
   let bSkipInput = false;
   do {

      if (bSkipInput == false) {
         Output_A_Message("Player row: " + cActivePlayer.Row(), "nMsgBox0");
         Output_A_Message("Player column: " + cActivePlayer['m_iColumn'], "nMsgBox0");
         Output_A_Message("Make your move: ", "nQuestion0");
         //std:: cin >> sNowInput;
         let key = Event.key;
         sNowInput = key;//[0];
      }
      if (sNowInput == "0") {
         CommandButton0_Click();
      }
      else if (sNowInput == "1") {
         CommandButton1_Click();
      }
      else if (sNowInput == "2") {
         CommandButton2_Click();
      }
      else if (sNowInput == "3") {
         CommandButton3_Click();
      }
      else if (sNowInput == "4") {
         CommandButton4_Click();
      }
      else if (sNowInput == "5") {
         CommandButton5_Click();
      }
      else if (sNowInput == "6") {
         CommandButton6_Click();
      }
      else if (sNowInput == "7") {
         CommandButton7_Click();
      }
      else if (sNowInput == "8") {
         CommandButton8_Click();
      }
      else if (sNowInput == "9") {
         CommandButton9_Click();
      }
      else if (sNowInput == "10") {
         CommandButton10_Click();
         bSkipInput = true;
         sNowInput = "loop_to_the_end";
      }
      else if (sNowInput == "-1") {
         CommandButtonNeg1_Click();
      }
      else if (sNowInput == "loop_to_the_end") {
         LoopToTheEnd();
      }
      else if (sNowInput == "q" || sNowInput == "x") {
         CommandButtonExit_Click();
      }
      else {
         //do nothing
         Output_A_Message("I don't understand.", "nMsgBox0");
      }
   } while (UnLoadMe == false);
}
*/


function CommandButton0_Click() {
   srand(time(NULL));
   let iRow = ((Math.random() % iMazeRows) + 1) - cActivePlayer.Row();
   let iColumn = ((Math.random() % iMazeCols) + 1) - cActivePlayer['m_iColumn'];
   Output_A_Message("Super Jump!!!", "nMsgBox0");
   MovePlayer(iRow, iColumn);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton1_Click() {
   MovePlayer(1, -1);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton2_Click() {
   MovePlayer(1, 0);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton3_Click() {
   MovePlayer(1, 1);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton4_Click() {
   MovePlayer(0, -1);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton5_Click() {
   MovePlayer(0, 0);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton6_Click() {
   MovePlayer(0, 1);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton7_Click() {
   MovePlayer(-1, -1);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton8_Click() {
   MovePlayer(-1, 0);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton9_Click() {
   MovePlayer(-1, 1);
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButton10_Click() {
   let sResponse;
   Output_A_Message("You've chosen to not to move for the rest of the game.", "nMsgBox0");
   Output_A_Message("We'll see if that was a wise choice or not.", "nMsgBox0");
   system("pause");
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButtonNeg1_Click() {
   Output_A_Message("You've chosen to give up.", "nMsgBox0");
   cActivePlayer['m_bAlive']=false;
   rMaze[cActivePlayer.Row()][cActivePlayer['m_iColumn']] = sDeadPlayerSymbol;
   system("pause");
   WhoIsAlive();
}

function LoopToTheEnd() {
   MoveInterceptors();
   WhoIsAlive();
}

function CommandButtonExit_Click() {
   UnLoadMe = true;
}

function WhoIsAlive() {
   //tableCreate();
   UpdateTheMaze();
   if (cActivePlayer['m_bAlive'] == false) {
      Output_A_Message("You are dead.  You lose!", "nMsgBox2");
      UnLoadMe = true;
   }
   else if (CheckInterceptorsAlive() == false) {
      Output_A_Message("All the interceptors are dead.  You win!", "nMsgBox2");
      UnLoadMe = true;
   }

}

