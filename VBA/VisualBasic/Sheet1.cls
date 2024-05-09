VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "Sheet1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Private Sub Worksheet_Change(ByVal Target As Range)
Dim nValue As Variant
Dim nAddress As String
Dim iRowOffset As Integer
Dim iColumnOffset As Integer

    If (Target.Address = "$C$3") Then
         nValue = Range("C3").Value
      If IsNumeric(nValue) Then
         nAddress = Range("C6").Value
         If nAddress = "" Then
            nAddress = "$I$12"
         End If
         iRowOffset = offsetRowBy(CInt(nValue))
         iColumnOffset = offsetColumnBy(CInt(nValue))
         'MsgBox "Offset row by " & iRowOffset & Chr(10) _
         '& "Offset column by " & iColumnOffset
         Range(nAddress).Select
         Selection.Value = sOpenAreaSymbol
         ActiveCell.Offset(iRowOffset, iColumnOffset).Select
         Selection.Value = sPlayerSymbol
         Range("C6").Value = Selection.Address
         Range("C3").Select
      End If
    End If
End Sub

Function offsetRowBy(ByVal iValue As Integer) As Integer

If 1 <= iValue And iValue <= 3 Then
   offsetRowBy = 1
ElseIf 7 <= iValue And iValue <= 9 Then
   offsetRowBy = -1
Else
   offsetRowBy = 0
End If

End Function

Function offsetColumnBy(ByVal iValue As Integer) As Integer

If iValue = 3 Or iValue = 6 Or iValue = 9 Then
   offsetColumnBy = 1
ElseIf iValue = 1 Or iValue = 4 Or iValue = 7 Then
   offsetColumnBy = -1
Else
   offsetColumnBy = 0
End If

End Function

