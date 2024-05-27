//VBA code below. New code and class definition in the header file.
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
/*VERSION 1.0 CLASS
BEGIN
MultiUse = -1  'True
END
Attribute VB_Name = "cInterceptor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

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

