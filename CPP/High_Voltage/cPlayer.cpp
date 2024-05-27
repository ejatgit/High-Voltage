//VBA code below. New code and class definition in the header file.
#include"GlobalVariables.h"

bool cPlayer::Alive() {
    return cPlayer::m_bAlive;
}

void cPlayer::Alive(bool bNowAlive) {
    cPlayer::m_bAlive = bNowAlive;
}

int cPlayer::Row() {
   // cPlayer::m_iRow = iNowRow;
    return cPlayer::m_iRow;
}

void cPlayer::Row(int iNowRow) {
    cPlayer::m_iRow = iNowRow;
    //return cPlayer::m_iRow;
}

int cPlayer::Column() {
    //cPlayer::m_iColumn = iNowCol;
    return cPlayer::m_iColumn;
}

void cPlayer::Column(int iNowCol) {
    cPlayer::m_iColumn = iNowCol;
   // return cPlayer::m_iColumn;
}

/*Option Explicit

Private m_bAlive As Boolean
Private m_iRow As Integer
Private m_iColumn As Integer
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' Constructor
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Private Sub Class_Initialize()
m_bAlive = True
End Sub

Public Property Get Alive() As Boolean
Alive = m_bAlive
End Property
Public Property Let Alive(ByVal a_Value As Boolean)
m_bAlive = a_Value
End Property

Public Property Get Row() As Integer
Row = m_iRow
End Property
Public Property Let Row(ByVal a_Value As Integer)
m_iRow = a_Value
End Property

Public Property Get Column() As Integer
Column = m_iColumn
End Property
Public Property Let Column(ByVal a_Value As Integer)
m_iColumn = a_Value
End Property*/

