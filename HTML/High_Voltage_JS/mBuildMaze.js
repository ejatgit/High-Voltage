
function SpawnPlayer() {

   cActivePlayer['m_bAlive'] = true;

   //srand(time(NULL));
   for (let iCount = 0; iCount < 1000; ++iCount) {
      let iRow = Math.floor((Math.random() * (iMazeRows - 1)) + 2);
      let iColumn = Math.floor((Math.random() * (iMazeCols - 1)) + 2);
      if (rMaze[iRow][iColumn] == sOpenAreaSymbol) {
         cActivePlayer['m_iRow']=iRow;
         cActivePlayer['m_iColumn'] = iColumn;
         Output_A_Message("You are at row " + iRow + " column " + iColumn, "nMsgBox1");
         break;
      }

   }

   rMaze[cActivePlayer['m_iRow']][cActivePlayer['m_iColumn']] = sPlayerSymbol;

}

function Spawninterceptors() {
   for (let i = 0; i < iNumberOfinterceptors; ++i) {
      let cNowinterceptor = new cInterceptor;
      for (let iCount = 0; iCount < 1000; ++iCount) {
         let iRow = Math.floor((Math.random() * (iMazeRows - 2)) + 1);
         let iColumn = Math.floor((Math.random() * (iMazeCols - 2)) + 1);
         if (rMaze[iRow][iColumn] == sOpenAreaSymbol) {            
            cNowinterceptor['m_iRow']=iRow;            
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


function DrawTheMaze() {
   const MazeGrid = document.getElementById('mazeID')

   for (let iRow = 0; iRow < iMazeRows; ++iRow) {
      for (let iCol = 0; iCol < iMazeCols; ++iCol) {
         MazeGrid.innerHTML += rMaze[iRow][iCol];      
      }
      MazeGrid.innerHTML += "<br>";
   }
}


function InitialFillMaze() {
   for (let iRow = 0; iRow < iMazeRows; ++iRow) {
      let MazeRow = [sOpenAreaSymbol];
      for (let iCol = 0; iCol < iMazeCols; ++iCol) {
         MazeRow.push(sOpenAreaSymbol);
      }
      if (iRow == 0) {
          rMaze.splice(0,1,MazeRow);         
      }
      else { rMaze.push(MazeRow); }
   }
   InstallHighVoltageBarriers();
   Spawninterceptors();
   SpawnPlayer();
   tableCreate();
}

function tableCreate() {
   const MazeLocation = document.getElementById("MazeTarge"),
   tbl = document.createElement('table');
   tbl.style.width = '100px';
   tbl.style.border = '1px solid black';
   tbl.id = 'TheMaze'
   for (let i = 0; i < iMazeRows; i++) {
      const tr = tbl.insertRow();
      for (let j = 0; j < iMazeCols; j++) {
            const td = tr.insertCell();
            td.appendChild(document.createTextNode(rMaze[i][j]));
            td.style.border = '1px solid black';
          
      }
   }   
   MazeLocation.appendChild(tbl);
}

function UpdateTheMaze() {
   tbl = document.getElementById('TheMaze');
   
   for (let i = 0, iRow; iRow = tbl.rows[i]; i++) {      
      for (let j = 0, iCol; iCol = iRow.cells[j]; j++) {         
         iCol.innerHTML = rMaze[i][j];         
      }
   }  
}