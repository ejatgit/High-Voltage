//#include"mRunGame.h"
//#include"mBuildMaze.h"
//import { InitialFillMaze, ClearMaze } from "./mBuildMaze.js";
//#include"mController.h"
//import { mController_Show } from "./mController.js";
//#include"mFunctions.h"
//import { Output_A_Message, PlayAGame, PlayAgain } from "./mFunctions.js";
//#include"High_Voltage.h"

function RunGame() {

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

function ExitGame(){
    //End
}

function GameIntro() {
    Output_A_Message("        *=================*", "nIntroBox0");
   Output_A_Message("        | High Voltage!!! |", "nIntroBox0");
   Output_A_Message("        *=================*", "nIntroBox0");
   Output_A_Message("", "nIntroBox0");
   Output_A_Message("You are within the walls of a high voltage maze.", "nIntroBox0");
   Output_A_Message("There are 15 security machines (interceptors)", "nIntroBox0");
   Output_A_Message("trying to destroy you.", "nIntroBox0");
   Output_A_Message("", "nIntroBox0");
   Output_A_Message("You are the '*', and the interceptors are the '+'.", "nIntroBox0");
   Output_A_Message("The areas marked 'x' are high voltage!", "nIntroBox0");
   Output_A_Message("Your only hope is to destroy the interceptors by", "nIntroBox0");
   Output_A_Message("running them into an 'x'.", "nIntroBox0");    
   Output_A_Message("Your moves are as follows: ", "nIntroBox0");
   Output_A_Message("", "nIntroBox0");
   Output_A_Message("      7.8.9    ^", "nIntroBox0");
   Output_A_Message("      4. .6  < + >", "nIntroBox0");
   Output_A_Message("      1.2.3    v", "nIntroBox0");
   Output_A_Message(" ", "nIntroBox0");
   Output_A_Message("5 = No move for one turn.", "nIntroBox0");
   Output_A_Message("10 = No move for the rest of the game.", "nIntroBox0");
   Output_A_Message("-1 = Give up. Situation hopeless.", "nIntroBox0");
   Output_A_Message("and of course '0' is super jump.", "nIntroBox0");
}
//export { RunGame };