//#include<string>
#include "mFunctions.h"
#include "GlobalVariables.h"
//#include"High_Voltage.h"

using namespace Shared_Vars;

int offsetRowBy(int iValue) {
    if (1 <= iValue && iValue <= 3) {
        return 1;
    }
    else if (7 <= iValue && iValue <= 9) {
        return -1;
    }
    else {
        return 0;
    }
}

int offsetColumnBy(int iValue) {
    if (iValue == 3 || iValue == 6 || iValue == 9) {
        return 1;
    }
    else if (iValue == 1 || iValue == 4 || iValue == 7) {
        return -1;
    }
    else {
        return 0;
    }
}

int interceptorRowOffset(int iValue) {
    int iTest = cActivePlayer.Row() - iValue;
    if (iTest > 0) {
        return 1;
    }
    else if (iTest < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

int interceptorColumnOffset(int iValue) {
    int iTest = cActivePlayer.Column() - iValue;
    if (iTest > 0) {
        return 1;
    }
    else if (iTest < 0) {
        return-1;
    }
    else {
        return 0;
    }
}

bool CheckInterceptorsAlive() {
    bool bTemp{ false };

    for (int i = 0; i < interceptorCollection.size(); ++i)
    {
        cInterceptor cNowInterceptor = interceptorCollection[i];
        if (cNowInterceptor.Alive() == true) {
            bTemp = true;
            break;
        }
        else
        {
            bTemp = false;
        }
    }
    return bTemp;
}

void Output_A_Message(std::string sNowMessage,std::string rLocation) {
    if (rLocation == "nMsgBox0")
    {
       // csbiInfo.dwCursorPosition.X = 0;
       // csbiInfo.dwCursorPosition.Y = iMazeRows + 2;
       // SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
        std::cout << sNowMessage << std::endl;
    }
    else if (rLocation == "nMsgBox1")
    {
      //  csbiInfo.dwCursorPosition.X = 0;
       // csbiInfo.dwCursorPosition.Y = iMazeRows + 3;
        //SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
        std::cout << sNowMessage << std::endl;
    }
    else if (rLocation == "nMsgBox2")
    {
        //  csbiInfo.dwCursorPosition.X = 0;
         // csbiInfo.dwCursorPosition.Y = iMazeRows + 4;
          //SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
        std::cout << sNowMessage << std::endl;
    }
    else if (rLocation == "nInterAlive")
    {
        //csbiInfo.dwCursorPosition.X = 0;
        //csbiInfo.dwCursorPosition.Y = iMazeRows + 5;
        //SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
        std::cout << sNowMessage << std::endl;
    }
    else if (rLocation == "nInterKilled")
    {
        //csbiInfo.dwCursorPosition.X = 0;
        //csbiInfo.dwCursorPosition.Y = iMazeRows + 6;
        //SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
        std::cout << sNowMessage << std::endl;
    }
    else if (rLocation == "nTotalinterceptorsKilled")
    {
        //csbiInfo.dwCursorPosition.X = 0;
        //csbiInfo.dwCursorPosition.Y = iMazeRows + 7;
        //SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
        std::cout << sNowMessage << std::endl;
    }
    else if (rLocation == "nQuestion0")
    {
        //csbiInfo.dwCursorPosition.X = 0;
        //csbiInfo.dwCursorPosition.Y = iMazeRows + 7;
        //SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
        std::cout << sNowMessage; //<< std::endl;
    }
}
bool PlayAGame() {
    std::string sResponse;
    Output_A_Message("", "nMsgBox0");
    Output_A_Message("Do you want to enter the maze (Y or N)? ", "nQuestion0");
    std::cin >> sResponse;
    std::string sLeftChar = sResponse.substr(0,1);
    if (sLeftChar == "Y" || sLeftChar == "y") {        
        Output_A_Message("", "nMsgBox0");
        Output_A_Message("----So Long Turkey!!!----", "nMsgBox0");
        return true;
    }
    else if (sLeftChar == "N" || sLeftChar == "n") {
        Output_A_Message("", "nMsgBox0");
        Output_A_Message("---- Chicken!!!----", "nMsgBox0");
        return false;
    }
    else {
        Output_A_Message("", "nMsgBox0");
        Output_A_Message("That was not one of your choices! Whatever... goodbye!", "nMsgBox0");
        return false;
    }
}
bool PlayAgain() {
    std::string sResponse;
    Output_A_Message("", "nMsgBox0");
    Output_A_Message("Do you want to play again (Y or N)? ", "nQuestion0");
    std::cin >> sResponse;
    std::string sLeftChar = sResponse.substr(0, 1);
    if (sLeftChar == "Y" || sLeftChar == "y") {
        return true;
    }
    else if (sLeftChar == "N" || sLeftChar == "n") {
        return false;
    }
    else {
        Output_A_Message("", "nMsgBox0");
        Output_A_Message("I don't understand, exiting...", "nMsgBox0");
        return false;
    }
}


