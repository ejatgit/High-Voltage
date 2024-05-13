//Attribute VB_Name = "mFunctions"
//Option Explicit
//
//Function offsetRowBy(ByVal iValue As Integer) As Integer
//
//If 1 <= iValue And iValue <= 3 Then
//   offsetRowBy = 1
//ElseIf 7 <= iValue And iValue <= 9 Then
//   offsetRowBy = -1
//Else
//   offsetRowBy = 0
//End If
//
//End Function
//
//Function offsetColumnBy(ByVal iValue As Integer) As Integer
//
//If iValue = 3 Or iValue = 6 Or iValue = 9 Then
//   offsetColumnBy = 1
//ElseIf iValue = 1 Or iValue = 4 Or iValue = 7 Then
//   offsetColumnBy = -1
//Else
//   offsetColumnBy = 0
//End If
//
//End Function
//
//Function interceptorRowOffset(ByVal iValue As Integer) As Integer
//Dim iTest As Integer
//
//iTest = cActivePlayer.Row - iValue
//
//If iTest > 0 Then
//   interceptorRowOffset = 1
//ElseIf iTest < 0 Then
//   interceptorRowOffset = -1
//Else
//   interceptorRowOffset = 0
//End If
//
//End Function
//
//Function interceptorColumnOffset(ByVal iValue As Integer) As Integer
//Dim iTest As Integer
//
//iTest = cActivePlayer.Column - iValue
//
//If iTest > 0 Then
//   interceptorColumnOffset = 1
//ElseIf iTest < 0 Then
//   interceptorColumnOffset = -1
//Else
//   interceptorColumnOffset = 0
//End If
//
//End Function
//
//Function CheckInterceptorsAlive() As Boolean
//Dim cNowinterceptor As cInterceptor
//
//For Each cNowinterceptor In interceptorCollection
//   If cNowinterceptor.Alive Then
//      CheckInterceptorsAlive = True
//      Exit For
//   Else
//      CheckInterceptorsAlive = False
//   End If
//Next cNowinterceptor
//   
//End Function
