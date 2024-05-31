//#include<string>
//#include "mFunctions.h"
import { cActivePlayer, interceptorCollection } from "./GlobalVariables.js";
//#include"High_Voltage.h"



function offsetRowBy(iValue) {
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

function offsetColumnBy(iValue) {
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

function interceptorRowOffset(iValue) {
   let iTest = cActivePlayer.Row() - iValue;
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

function interceptorColumnOffset(iValue) {
    let iTest = cActivePlayer.Column() - iValue;
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

function CheckInterceptorsAlive() {
   let bTemp = false;

   for (let i = 0; i < interceptorCollection.length(); ++i) {
      let cNowInterceptor = interceptorCollection[i];
      if (cNowInterceptor.Alive() == true) {
         bTemp = true;
         break;
      }
      else {
         bTemp = false;
      }
   }
   return bTemp;
}

function Output_A_Message(sNowMessage, rLocation) {
   if (rLocation == "nMsgBox0") {
      NowTarget = document.getElementById("nMsgBox0");
      //std:: cout << sNowMessage << std:: endl;
      NowTarget.innerHtml = sNowMessage;
   }
   else if (rLocation == "nMsgBox1") {
      NowTarget = document.getElementById("nMsgBox1");
      NowTarget.innerHtml = sNowMessage;
   }
   else if (rLocation == "nMsgBox2") {
      NowTarget = document.getElementById("nMsgBox2");
      NowTarget.innerHtml = sNowMessage;
   }
   else if (rLocation == "nInterAlive") {
      NowTarget = document.getElementById("nInterAlive");
      NowTarget.innerHtml = sNowMessage;
   }
   else if (rLocation == "nInterKilled") {
      NowTarget = document.getElementById("nInterKilled");
      NowTarget.innerHtml = sNowMessage;
   }
   else if (rLocation == "nTotalinterceptorsKilled") {
      NowTarget = document.getElementById("nTotalinterceptorsKilled");
      NowTarget.innerHtml = sNowMessage;
   }
   else if (rLocation == "nQuestion0") {
      NowTarget = document.getElementById("nMsgBox0");
      NowTarget.innerHtml = sNowMessage;
   }
}
function PlayAGame() {
   //sResponse;
   Output_A_Message("", "nMsgBox0");
   Output_A_Message("Do you want to enter the maze (Y or N)? ", "nQuestion0");
   let sResponse = Event.key;
   let sLeftChar = sResponse[0];
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

function PlayAgain() {
   Output_A_Message("", "nMsgBox0");
   Output_A_Message("Do you want to play again (Y or N)? ", "nQuestion0");
   let sResponse = Event.key;
   let sLeftChar = sResponse[0];
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


