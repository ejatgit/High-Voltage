Attribute VB_Name = "mBuildMaze"
Option Explicit

Sub InitialFillMaze()
Application.Calculation = xlCalculationManual
Randomize
ThisWorkbook.Activate
Worksheets("Maze").Activate
Set rMaze = Range("tblHVMaze")
Set interceptorCollection = New Collection

Range("nMsgbox0").Value = ""
Range("nMsgbox1").Value = ""
Range("nMsgbox2").Value = ""

Range("nInterAlive").Value = iNumberOfinterceptors
Range("nInterKilled").Value = 0

Call ClearMaze
Call InstallHighVoltageBarriers
Call Spawninterceptors
Call SpawnPlayer
Application.Calculation = xlCalculationAutomatic
End Sub
Sub SpawnPlayer()
Dim iCount As Integer
Dim iRow As Integer
Dim iColumn As Integer

Set cActivePlayer = New cPlayer

iCount = 1

Do
   iRow = Int(((rMaze.Rows.Count - 1) * Rnd) + 2)
   iColumn = Int(((rMaze.Columns.Count - 1) * Rnd) + 2)
   If rMaze.Cells(iRow, iColumn).Value = sOpenAreaSymbol Then
      cActivePlayer.Row = iRow
      cActivePlayer.Column = iColumn
      Exit Do
   End If
   iCount = iCount + 1
Loop While iCount < 1000

rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Value = sPlayerSymbol
Range("nPlayerCell").Value = rMaze.Cells(cActivePlayer.Row, cActivePlayer.Column).Address

End Sub
Sub Spawninterceptors()
Dim i As Integer
Dim iCount As Integer
Dim iRow As Integer
Dim iColumn As Integer
Dim cNowinterceptor As cInterceptor

For i = 1 To iNumberOfinterceptors
   iCount = 1
   Set cNowinterceptor = New cInterceptor
   Do
      iRow = Int(((rMaze.Rows.Count - 1) * Rnd) + 2)
      iColumn = Int(((rMaze.Columns.Count - 1) * Rnd) + 2)
      If rMaze.Cells(iRow, iColumn).Value = sOpenAreaSymbol Then
         cNowinterceptor.Row = iRow
         cNowinterceptor.Column = iColumn
         Call interceptorCollection.Add(cNowinterceptor)
         Exit Do
      End If
      iCount = iCount + 1
   Loop While iCount < 1000
Next i

For Each cNowinterceptor In interceptorCollection
   rMaze.Cells(cNowinterceptor.Row, cNowinterceptor.Column).Value = sinterceptorSymbol
Next cNowinterceptor

End Sub
Sub InstallHighVoltageBarriers()
Dim iRow As Integer
Dim iCol As Integer
Dim iBarrierCount As Integer
Dim iDice As Integer

For iRow = 1 To rMaze.Rows.Count
   iBarrierCount = 0
   For iCol = 1 To rMaze.Columns.Count
      If iRow = 1 Or iRow = rMaze.Rows.Count Then
         rMaze.Cells(iRow, iCol).Value = sHighVoltageSymbol
      ElseIf iCol = 1 Or iCol = rMaze.Columns.Count Then
         rMaze.Cells(iRow, iCol).Value = sHighVoltageSymbol
      Else
         iDice = Int((6 * Rnd) + 1)
         If iDice > 4 Then
            If iBarrierCount >= iMaxHighVoltageBarriersPerRow Then
               Exit For
            Else
               rMaze.Cells(iRow, iCol).Value = sHighVoltageSymbol
               iBarrierCount = iBarrierCount + 1
            End If
         Else
            rMaze.Cells(iRow, iCol).Value = sOpenAreaSymbol
         End If
      End If
   Next iCol
   
Next iRow

End Sub
Sub ClearMaze()
Dim iRow As Integer
Dim iCol As Integer

For iRow = 1 To rMaze.Rows.Count
   For iCol = 1 To rMaze.Columns.Count
      rMaze.Cells(iRow, iCol).Value = sOpenAreaSymbol
   Next iCol
Next iRow

End Sub
