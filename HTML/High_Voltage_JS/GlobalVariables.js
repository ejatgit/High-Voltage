

const sOpenAreaSymbol = " ";
const sPlayerSymbol = "*" ;
const sDeadPlayerSymbol ="#" ;
const sInterceptorSymbol = "+" ;
const iNumberOfinterceptors = 15 ;
const sHighVoltageSymbol = "X" ;
const iMaxHighVoltageBarriersPerRow = 15 ;

const iMazeRows = 25 ;
const iMazeCols = 30 ;


let nInterAlive;
let nInterKilled;
let nTotalinterceptorsKilled;
let rMaze = [sHighVoltageSymbol];
let cActivePlayer = new cPlayer;    
let interceptorCollection = [sInterceptorSymbol];
