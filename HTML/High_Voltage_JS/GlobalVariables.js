
//import { cPlayer } from "./cPlayer.js";
//import { cInterceptor } from "./cInterceptor.js";

const sOpenAreaSymbol = " " //String.fromCharCode(176); //"O";
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
let rMaze = [sHighVoltageSymbol]//[sOpenAreaSymbol];
    /*extern HANDLE hStdout;
    extern HANDLE hStdin;
    extern CONSOLE_SCREEN_BUFFER_INFO csbiInfo;*/
let cActivePlayer = new cPlayer;    
let interceptorCollection = [sInterceptorSymbol];// = new array(iNumberOfinterceptors)
