

function MovePlayer(x_iRow, x_iColumn) {

   let iLastRow = cActivePlayer['m_iRow'];
   let iLastColumn = cActivePlayer['m_iColumn'];

   cActivePlayer['m_iRow'] = (cActivePlayer['m_iRow'] + x_iRow);
   cActivePlayer['m_iColumn'] = (cActivePlayer['m_iColumn'] + x_iColumn);

   let sTargetChar = rMaze[cActivePlayer['m_iRow']][cActivePlayer['m_iColumn']];

   if (sTargetChar == sOpenAreaSymbol) {
      rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
      rMaze[cActivePlayer['m_iRow']][cActivePlayer['m_iColumn']] = sPlayerSymbol;
      Output_A_Message("You are at row " + cActivePlayer['m_iRow'] + " column " + cActivePlayer['m_iColumn'], "nMsgBox1");
      Output_A_Message("", "nMsgBox2");
   }
   else if (sTargetChar == sInterceptorSymbol) {
      rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
      rMaze[cActivePlayer['m_iRow']][cActivePlayer['m_iColumn']] = sDeadPlayerSymbol;
      Output_A_Message("You hit an interceptor!", "nMsgBox0");
      Output_A_Message("You are at row " + cActivePlayer['m_iRow'] + " column " + cActivePlayer['m_iColumn'], "nMsgBox1");
      Output_A_Message("", "nMsgBox2");
      cActivePlayer['m_bAlive']=false;
   }
   else if (sTargetChar == sHighVoltageSymbol) {
      rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
      rMaze[cActivePlayer['m_iRow']][cActivePlayer['m_iColumn']] = sDeadPlayerSymbol;
      Output_A_Message("You hit a barrier!", "nMsgBox0");
      Output_A_Message("You are at row " + cActivePlayer['m_iRow'] + " column " + cActivePlayer['m_iColumn'], "nMsgBox1");
      Output_A_Message("", "nMsgBox2");
      cActivePlayer['m_bAlive'] = false;
   }
}

function MoveInterceptors() {

   let sTargetChar;
   let iLastRow;
   let iLastColumn;
   let iDeaths = 0;
   let iPlayerDeaths = 0;
   for (let i = 0; i < iNumberOfinterceptors; ++i) {
      let nowInterceptor = interceptorCollection[i];
      if (nowInterceptor['m_bAlive'] == true) {
         iLastRow = nowInterceptor['m_iRow'];
         iLastColumn = nowInterceptor['m_iColumn'];
         nowInterceptor['m_iRow']=(nowInterceptor['m_iRow'] + interceptorRowOffset(nowInterceptor['m_iRow']));
         nowInterceptor['m_iColumn']=(nowInterceptor['m_iColumn'] + interceptorColumnOffset(nowInterceptor['m_iColumn']));
         sTargetChar = rMaze[nowInterceptor['m_iRow']][nowInterceptor['m_iColumn']];
         if (sTargetChar == sOpenAreaSymbol) {
            rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
            rMaze[nowInterceptor['m_iRow']][nowInterceptor['m_iColumn']] = sInterceptorSymbol;
         }
         else if (sTargetChar == sPlayerSymbol || sTargetChar == sDeadPlayerSymbol) {
            rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
            rMaze[nowInterceptor['m_iRow']][nowInterceptor['m_iColumn']] = sDeadPlayerSymbol;
            iPlayerDeaths = iPlayerDeaths + 1;
            cActivePlayer['m_bAlive']=false;
         }
         else if (sTargetChar == sHighVoltageSymbol) {
            rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
            iDeaths = iDeaths + 1;
            nowInterceptor['m_bAlive']=false;
         }
         else {
            rMaze[iLastRow][iLastColumn] = sOpenAreaSymbol;
            rMaze[nowInterceptor['m_iRow']][nowInterceptor['m_iColumn']] = sInterceptorSymbol;
         }
      }
   }
   if (iDeaths > 0) {
      Output_A_Message("You killed " + iDeaths + " interceptor(s)!", "nMsgBox0");
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
