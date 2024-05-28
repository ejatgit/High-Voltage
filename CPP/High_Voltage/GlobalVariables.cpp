#include "GlobalVariables.h"

namespace Shared_Vars{
    extern int nInterAlive{};
    extern int nInterKilled{};
    extern int nTotalinterceptorsKilled{};
    extern std::string rMaze[iMazeRows][iMazeCols]{};
    extern HANDLE hStdout{};
    extern HANDLE hStdin{};
    extern CONSOLE_SCREEN_BUFFER_INFO csbiInfo{};
    extern cPlayer cActivePlayer{};
    extern std::vector<cInterceptor> interceptorCollection{};
}