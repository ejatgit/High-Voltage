#include"GlobalVariables.h"

bool cPlayer::Alive() {
    return cPlayer::m_bAlive;
}

void cPlayer::Alive(bool bNowAlive) {
    cPlayer::m_bAlive = bNowAlive;
}

int cPlayer::Row() {
    return cPlayer::m_iRow;
}

void cPlayer::Row(int iNowRow) {
    cPlayer::m_iRow = iNowRow;   
}

int cPlayer::Column() {    
    return cPlayer::m_iColumn;
}

void cPlayer::Column(int iNowCol) {
    cPlayer::m_iColumn = iNowCol;   
}

