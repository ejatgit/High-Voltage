VERSION 5.00
Begin {C62A69F0-16DC-11CE-9E98-00AA00574A4F} frmController 
   Caption         =   "Control Pad"
   ClientHeight    =   3480
   ClientLeft      =   -24
   ClientTop       =   144
   ClientWidth     =   3852
   OleObjectBlob   =   "frmController.frx":0000
   StartUpPosition =   1  'CenterOwner
End
Attribute VB_Name = "frmController"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub CommandButton0_Click()
Dim iRow As Integer
Dim iColumn As Integer
   iRow = Int(((rMaze.Rows.Count) * Rnd) + 1) - cActivePlayer.Row
   iColumn = Int(((rMaze.Columns.Count) * Rnd) + 1) - cActivePlayer.Column
   'MsgBox "Super Jump!!!"
   Range("nMsgbox2").Value = "Super Jump!!!"
   Call MovePlayer(iRow, iColumn)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButton1_Click()
   Call MovePlayer(1, -1)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButton2_Click()
   Call MovePlayer(1, 0)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButton3_Click()
   Call MovePlayer(1, 1)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButton4_Click()
   Call MovePlayer(0, -1)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButton5_Click()
   Call MovePlayer(0, 0)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButton6_Click()
   Call MovePlayer(0, 1)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButton7_Click()
   Call MovePlayer(-1, -1)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButton8_Click()
   Call MovePlayer(-1, 0)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButton9_Click()
   Call MovePlayer(-1, 1)
   Call MoveInterceptors
   Call WhoIsAlive
End Sub

Private Sub CommandButtonExit_Click()
   Call Unload(Me)
End Sub

Sub WhoIsAlive()

If Not cActivePlayer.Alive Then
   'MsgBox "You are dead.  You lose."
   Range("nMsgbox2").Value = "You are dead.  You lose."
   Range("nLoses").Value = Range("nLoses").Value + 1
   Call Unload(Me)
ElseIf Not CheckInterceptorsAlive Then
   'MsgBox "All the interceptors are dead.  You win."
   Range("nMsgbox2").Value = "All the interceptors are dead.  You win."
   Range("nWins").Value = Range("nWins").Value + 1
   Call Unload(Me)
End If

End Sub

Private Sub UserForm_Activate()
   Me.Height = 200
   Me.Width = 200
End Sub


