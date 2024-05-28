#include"GlobalVariables.h"

bool cInterceptor::Alive() {
    return cInterceptor::m_bAlive;
}

void cInterceptor::Alive(bool bNowAlive) {
    cInterceptor::m_bAlive = bNowAlive;
}

int cInterceptor::Row() {    
    return cInterceptor::m_iRow;
}

void cInterceptor::Row(int iNowRow) {
    cInterceptor::m_iRow = iNowRow;    
}

int cInterceptor::Column() {
    return cInterceptor::m_iColumn;
}

void cInterceptor::Column(int iNowCol) {
    cInterceptor::m_iColumn = iNowCol;    
}
