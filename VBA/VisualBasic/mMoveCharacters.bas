Attribute VB_Name = "mMoveCharacters"
Option Explicit

Sub MovePlayer(ByRef x_iRow As Integer, ByRef x_iColumn As Integer)
Dim sTargetChar As String
Dim iLastRow As Integer
Dim iLastColumn As Integer

Range("nPlayerMove").Value = Range("nPlayerMove").Value + 1

iLastRow = cActivePlayer.Row
iLastColumn = cActivePlayer.Column

cActivePlayer.Row = cActivePlayer.Row + x_iRow
cActivePlayer.Column = cActivePlayer.Column + x_iColumn
   
sTargetChar = rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value

If sTargetChar = sOpenAreaSymbol Then
   rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
   rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value = sPlayerSymbol
ElseIf sTargetChar = sinterceptorSymbol Then
   rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
   rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value = sDeadPlayerSymbol
   'MsgBox "You hit an interceptor!"
   Range("nMsgbox1").Value = "You hit an interceptor!"
   cActivePlayer.Alive = False
ElseIf sTargetChar = sHighVoltageSymbol Then
   rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
   rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value = sDeadPlayerSymbol
   'MsgBox "You hit a barrier!"
   Range("nMsgbox1").Value = "You hit a barrier!"
   cActivePlayer.Alive = False
End If
 
Range("nPlayerCell").Value = rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Address
   
End Sub

Sub MoveInterceptors()
Dim sTargetChar As String
Dim iLastRow As Integer
Dim iLastColumn As Integer
Dim cNowinterceptor As cInterceptor
Dim iDeaths As Integer
Dim iPlayerDeaths As Integer
iDeaths = 0
iPlayerDeaths = 0
For Each cNowinterceptor In interceptorCollection
   If cNowinterceptor.Alive Then
      iLastRow = cNowinterceptor.Row
      iLastColumn = cNowinterceptor.Column
      
      cNowinterceptor.Row = cNowinterceptor.Row + interceptorRowOffset(cNowinterceptor.Row)
      cNowinterceptor.Column = cNowinterceptor.Column + interceptorColumnOffset(cNowinterceptor.Column)
         
      sTargetChar = rMaze.Cells(cNowinterceptor.Row, cNowinterceptor.Column).Value
      
      If sTargetChar = sOpenAreaSymbol Then
         rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
         rMaze.Cells(cNowinterceptor.Row, cNowinterceptor.Column).Value = sinterceptorSymbol
      ElseIf sTargetChar = sPlayerSymbol Then
         rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
         rMaze.Cells(cNowinterceptor.Row, cNowinterceptor.Column).Value = sDeadPlayerSymbol
         iPlayerDeaths = iPlayerDeaths + 1
         cActivePlayer.Alive = False
      ElseIf sTargetChar = sHighVoltageSymbol Then
         rMaze.Cells(iLastRow, iLastColumn).Value = sOpenAreaSymbol
         iDeaths = iDeaths + 1
         cNowinterceptor.Alive = False
      End If
   End If
Next cNowinterceptor

If iDeaths > 0 Then
   'MsgBox "You killed " & iDeaths & " interceptor(s)!"
   Range("nMsgbox0").Value = "You killed " & iDeaths & " interceptor(s)!"
   Range("nInterAlive").Value = Range("nInterAlive").Value - iDeaths
   Range("nInterKilled").Value = Range("nInterKilled").Value + iDeaths
   Range("nTotalinterceptorsKilled").Value = Range("nTotalinterceptorsKilled").Value + iDeaths
End If

If iPlayerDeaths > 0 Then
   'MsgBox "You've been hit by " & iPlayerDeaths & " interceptor(s)!"
   Range("nMsgbox0").Value = "You've been hit by " & iPlayerDeaths & " interceptor(s)!"
End If

End Sub
