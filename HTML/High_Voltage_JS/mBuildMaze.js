
//import { cPlayer } from "./cPlayer.js";
import { cInterceptor } from "./cInterceptor.js";

import { cActivePlayer, sPlayerSymbol, sOpenAreaSymbol, rMaze } from "./GlobalVariables.js";

function SpawnPlayer() {

   cActivePlayer.Alive(true);

   //srand(time(NULL));
   for (let iCount = 0; iCount < 1000; ++iCount) {
      let iRow = ((Math.random() % (iMazeRows - 1)) + 2);
      let iColumn = ((Math.random() % (iMazeCols - 1)) + 2);
      if (rMaze[iRow][iColumn] == sOpenAreaSymbol) {
         cActivePlayer.Row(iRow);
         cActivePlayer.Column(iColumn);
         break;
      }

   }

   rMaze[cActivePlayer.Row()][cActivePlayer.Column()] = sPlayerSymbol;

}

function Spawninterceptors() {

   //srand(time(NULL));

   for (let i = 0; i < iNumberOfinterceptors; ++i) {
      let cNowinterceptor = new cInterceptor;
      for (let iCount = 0; iCount < 1000; ++iCount) {
         let iRow = ((Math.random() % (iMazeRows - 1)) + 2);
         let iColumn = ((Math.random() % (iMazeCols - 1)) + 2);
         if (rMaze[iRow][iColumn] == sOpenAreaSymbol) {
            cNowinterceptor.Row(iRow);
            cNowinterceptor.Column(iColumn);
            interceptorCollection[i] = cNowinterceptor;
            break;
         }
      }
   }

   for (let iCount = 0; iCount < interceptorCollection.size(); ++iCount) {
      //cInterceptor cNowInterceptor;
      let cNowInterceptor = interceptorCollection[iCount];
      rMaze[cNowInterceptor.Row()][cNowInterceptor.Column()] = sInterceptorSymbol;
   }

   nInterAlive = interceptorCollection.length + 1;

}

function InstallHighVoltageBarriers() {
   let iBarrierCount;
   let iDice;

   //srand(time(NULL));

   for (let iRow = 0; iRow < iMazeRows; ++iRow) {
      iBarrierCount = 0;
      for (let iCol = 0; iCol < iMazeCols; ++iCol) {
         if ((iRow == 0) || (iRow == iMazeRows - 1)) {
            rMaze[iRow][iCol] = sHighVoltageSymbol;
         }
         else if ((iCol == 0) || (iCol == iMazeCols - 1)) {
            rMaze[iRow][iCol] = sHighVoltageSymbol;
         }
         else {
            iDice = ((Math.random() % 6) + 1);
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

function ClearMaze() {
   for (let iRow = 0; iRow < iMazeRows; ++iRow) {
      for (let iCol = 0; iCol < iMazeCols; ++iCol) {
         rMaze[iRow][iCol] = sOpenAreaSymbol;
      }
   }
}

function InitialFillMaze() {
   InstallHighVoltageBarriers();
   Spawninterceptors();
   SpawnPlayer();
   DrawTheMaze();
}

function DrawTheMaze() {
   layoutGrid(iMazeRows, iMazeCols, 'maze-container')
   const MazeGrid = document.getElementById('maze-container')

   for (let iRow = 0; iRow < iMazeRows; ++iRow) {
      for (let iCol = 0; iCol < iMazeCols; ++iCol) {
         //MazeGrid.innerHTML = rMaze[iRow][iCol];
         MazeGrid.set(iRow, iCol, rMaze[iRow][iCol]);
      }
      //std:: cout << std:: endl;
   }
}

const layoutGrid = (height, width, gridname) => {
   const container = document.getElementById(gridname)
   container.style.gridTemplateColumns = `repeat(${width}, 1fr)`
   container.style.gridTemplateRows = `repeat(${height}, 1fr)`
}