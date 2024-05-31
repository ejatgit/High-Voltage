
import { cPlayer } from "./cPlayer.js";
import { cInterceptor } from "./cInterceptor.js";

const sOpenAreaSymbol = " ";
const sPlayerSymbol = "*" ;
const sDeadPlayerSymbol ="#" ;
const sInterceptorSymbol = "+" ;
const iNumberOfinterceptors = 15 ;
const sHighVoltageSymbol = "x" ;
const iMaxHighVoltageBarriersPerRow = 15 ;

const iMazeRows = 25 ;
const iMazeCols = 30 ;


let nInterAlive;
let nInterKilled;
let nTotalinterceptorsKilled;
let rMaze = new array(iMazeRows, iMazeCols);
    /*extern HANDLE hStdout;
    extern HANDLE hStdin;
    extern CONSOLE_SCREEN_BUFFER_INFO csbiInfo;*/
let cActivePlayer = new cPlayer;    
let interceptorCollection = new array(iNumberOfinterceptors)
