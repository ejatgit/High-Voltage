
//import { cPlayer } from "./cPlayer.js";
//import { cInterceptor } from "./cInterceptor.js";

//import { cActivePlayer, sPlayerSymbol, sOpenAreaSymbol, rMaze } from "./GlobalVariables.js";

function SpawnPlayer() {

   cActivePlayer['m_bAlive'] = true;

   //srand(time(NULL));
   for (let iCount = 0; iCount < 1000; ++iCount) {
      let iRow = Math.floor((Math.random() * (iMazeRows - 1)) + 2);
      let iColumn = Math.floor((Math.random() * (iMazeCols - 1)) + 2);
      if (rMaze[iRow][iColumn] == sOpenAreaSymbol) {
         cActivePlayer['m_iRow']=iRow;
         cActivePlayer['m_iColumn']=iColumn;
         break;
      }

   }

   rMaze[cActivePlayer['m_iRow']][cActivePlayer['m_iColumn']] = sPlayerSymbol;

}

function Spawninterceptors() {

   //srand(time(NULL));

   for (let i = 0; i < iNumberOfinterceptors; ++i) {
      let cNowinterceptor = new cInterceptor;
      for (let iCount = 0; iCount < 1000; ++iCount) {
         let iRow = Math.floor((Math.random() * (iMazeRows - 2)) + 1);
         let iColumn = Math.floor((Math.random() * (iMazeCols - 2)) + 1);
         if (rMaze[iRow][iColumn] == sOpenAreaSymbol) {
            //cNowinterceptor.SetRow(iRow);
            cNowinterceptor['m_iRow']=iRow;
            //cNowinterceptor.SetColumn(iColumn);
            cNowinterceptor['m_iColumn']=iColumn;
            if (i == 0) {
               interceptorCollection[0] = cNowinterceptor;
            } else {
               interceptorCollection.push(cNowinterceptor);
            }
            break;
         }
      }
   }

   for (let iCount = 0; iCount < interceptorCollection.length; ++iCount) {
      //cInterceptor cNowInterceptor;
      let cNowInterceptor = interceptorCollection[iCount];
      rMaze[cNowInterceptor['m_iRow']][cNowInterceptor['m_iColumn']] = sInterceptorSymbol;
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
            iDice = Math.floor((Math.random() * 6) + 1);
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
   for (let iRow = 0; iRow < iMazeRows; ++iRow) {
      let MazeRow = [sOpenAreaSymbol];
      for (let iCol = 1; iCol < iMazeCols; ++iCol) {
         MazeRow.push(sOpenAreaSymbol);         
      }
      if (irow = 0) { rMaze[0] = MazeRow; }
      else { rMaze.push(MazeRow); }
            
   }
   InstallHighVoltageBarriers();
   Spawninterceptors();
   SpawnPlayer();
   DrawTheMaze();
}

function DrawTheMaze() {
   //layoutGrid(iMazeRows, iMazeCols, 'maze-container')
   const MazeGrid = document.getElementById('mazeID')

   for (let iRow = 0; iRow < iMazeRows; ++iRow) {
      for (let iCol = 0; iCol < iMazeCols; ++iCol) {
         MazeGrid.innerHTML += rMaze[iRow][iCol];
         //MazeGrid.set(iRow, iCol, rMaze[iRow][iCol]);
      }
      MazeGrid.innerHTML += "<br>"
      //std:: cout << std:: endl;
   }
}

/*const layoutGrid = (height, width, gridname) => {
   const container = document.getElementById(gridname)
   container.style.gridTemplateColumns = `repeat(${width}, 1fr)`
   container.style.gridTemplateRows = `repeat(${height}, 1fr)`
}*/


function InitialFillMaze2() {
   for (let iRow = 0; iRow < iMazeRows; ++iRow) {
      let MazeRow = [sOpenAreaSymbol];
      for (let iCol = 0; iCol < iMazeCols; ++iCol) {
         MazeRow.push(sOpenAreaSymbol);
      }
      if (iRow == 0) {
         // rMaze[0] = MazeRow; 
         rMaze.splice(0,1,MazeRow); 
       //  rMaze.push(MazeRow); 
      }
      else { rMaze.push(MazeRow); }

   }
   InstallHighVoltageBarriers();
   Spawninterceptors();
   SpawnPlayer();
   tableCreate();
}

function tableCreate() {
   //const body = document.body,
   const MazeLocation = document.getElementById("MazeTarge"),
      tbl = document.createElement('table');
   tbl.style.width = '100px';
   tbl.style.border = '1px solid black';
   tbl.id = 'TheMaze'
   for (let i = 0; i < iMazeRows; i++) {
      const tr = tbl.insertRow();
      for (let j = 0; j < iMazeCols; j++) {
        // if (i === 2 && j === 1) {
          //  break;
         //} else {
            const td = tr.insertCell();
           // td.appendChild(document.createTextNode(`Cell I${i}/J${j}`));
            td.appendChild(document.createTextNode(rMaze[i][j]));
            td.style.border = '1px solid black';
          //  td.style.border = '1px solid white';
           /* if (i === 1 && j === 1) {
               td.setAttribute('rowSpan', '2');
            }*/
         //}
      }
   }
   //body.appendChild(tbl);
   MazeLocation.appendChild(tbl);
}

function UpdateTheMaze() {
   //const body = document.body,
   tbl = document.getElementById('TheMaze');
   
   for (let i = 0, iRow; iRow = tbl.rows[i]; i++) {      
      for (let j = 0, iCol; iCol = iRow.cells[j]; j++) {
         
         iCol.innerHTML = rMaze[i][j];
         
      }
   }
  // body.appendChild(tbl);
}