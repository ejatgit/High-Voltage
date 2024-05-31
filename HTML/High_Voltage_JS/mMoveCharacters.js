
//#include"mMoveCharacters.h"
//#include"High_Voltage.h"
//#include "GlobalVariables.h"
import { cActivePlayer, sPlayerSymbol, sOpenAreaSymbol, rMaze } from "./GlobalVariables.js";
//#include "mFunctions.h"
import { Output_A_Message } from "./mFunctions.js";

function MovePlayer(x_iRow, x_iColumn) {

   let iLastRow = cActivePlayer.Row();
   let iLastColumn = cActivePlayer.Column();

   cActivePlayer.Row(cActivePlayer.Row() + x_iRow);
   cActivePlayer.Column(cActivePlayer.Column() + x_iColumn);

   let sTargetChar = rMaze[cActivePlayer.Row()][cActivePlayer.Column()];

   if (sTargetChar == sOpenAreaSymbol) {
      rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
      rMaze[cActivePlayer.Row()][cActivePlayer.Column()] = sPlayerSymbol;
   }
   else if (sTargetChar == sInterceptorSymbol) {
      rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
      rMaze[cActivePlayer.Row()][cActivePlayer.Column()] = sDeadPlayerSymbol;
      Output_A_Message("You hit an interceptor!", "nMsgBox0");
      cActivePlayer.Alive(false);
   }
   else if (sTargetChar == sHighVoltageSymbol) {
      rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
      rMaze[cActivePlayer.Row()][cActivePlayer.Column()] = sDeadPlayerSymbol;
      Output_A_Message("You hit a barrier!", "nMsgBox0");
      cActivePlayer.Alive(false);
   }
}

function MoveInterceptors() {

   let sTargetChar;
   let iLastRow;
   let iLastColumn;
   let iDeaths = 0;
   let iPlayerDeaths = 0;
   for (let i = 0; i < interceptorCollection.size(); ++i) {

      if (interceptorCollection[i].Alive() == true) {
         iLastRow = interceptorCollection[i].Row();
         iLastColumn = interceptorCollection[i].Column();
         interceptorCollection[i].Row(interceptorCollection[i].Row() + interceptorRowOffset(interceptorCollection[i].Row()));
         interceptorCollection[i].Column(interceptorCollection[i].Column() + interceptorColumnOffset(interceptorCollection[i].Column()));
         sTargetChar = rMaze[interceptorCollection[i].Row()][interceptorCollection[i].Column()];
         if (sTargetChar == sOpenAreaSymbol) {
            rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
            rMaze[interceptorCollection[i].Row()][interceptorCollection[i].Column()] = sInterceptorSymbol;
         }
         else if (sTargetChar == sPlayerSymbol || sTargetChar == sDeadPlayerSymbol) {
            rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
            rMaze[interceptorCollection[i].Row()][interceptorCollection[i].Column()] = sDeadPlayerSymbol;
            iPlayerDeaths = iPlayerDeaths + 1;
            cActivePlayer.Alive(false);
         }
         else if (sTargetChar == sHighVoltageSymbol) {
            rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
            iDeaths = iDeaths + 1;
            interceptorCollection[i].Alive(false);
         }
         else {
            rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
            rMaze[interceptorCollection[i].Row()][interceptorCollection[i].Column()] = sInterceptorSymbol;
         }
      }
   }
   if (iDeaths > 0) {
      Output_A_Message("You killed " + iDeaths + " interceptor(s)!", "nMsgbox0");
      nInterAlive = nInterAlive - iDeaths;
      Output_A_Message("Alive Interceptor(s): " + nInterAlive, "nInterAlive");
      nInterKilled = nInterKilled + iDeaths;
      Output_A_Message("Dead Interceptor(s): " + nInterKilled, "nInterKilled");
      nTotalinterceptorsKilled = nTotalinterceptorsKilled + iDeaths;
      Output_A_Message("Total Dead Interceptor(s): " + nTotalinterceptorsKilled, "nTotalinterceptorsKilled");
   }
   if (iPlayerDeaths > 0) {
      Output_A_Message("You've been hit by " + iPlayerDeaths + " interceptor(s)!", "nMsgBox0");
   }

}
