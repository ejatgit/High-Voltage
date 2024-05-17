#include"GlobalVariables.h"
#include "mFunctions.h"
//Attribute VB_Name = "mFunctions"
//Option Explicit
//
int offsetRowBy(int iValue) {
    //Function offsetRowBy(ByVal iValue As Integer) As Integer
    //
    //If 1 <= iValue And iValue <= 3 Then
    if (1 <= iValue && iValue <= 3 ){
//   offsetRowBy = 1
   return 1;
}
 //ElseIf 7 <= iValue And iValue <= 9 Then
   else if (7 <= iValue && iValue <= 9){
//   offsetRowBy = -1
   return -1;
} 
//Else
    else {
//   offsetRowBy = 0
    return 0;
//End If
    }
//
    //End Function
}
//
int offsetColumnBy(int iValue) {
    //Function offsetColumnBy(ByVal iValue As Integer) As Integer
    //
    //If iValue = 3 Or iValue = 6 Or iValue = 9 Then
    if (iValue == 3 || iValue == 6 || iValue == 9){
//   offsetColumnBy = 1
   return 1;
}
//ElseIf iValue = 1 Or iValue = 4 Or iValue = 7 Then
    else if (iValue == 1 || iValue == 4 || iValue == 7){
//   offsetColumnBy = -1
    return -1;
}
//Else
    else {
//   offsetColumnBy = 0
    return 0;
//End If
   }
//
    //End Function
}
//
int interceptorRowOffset(int iValue) {
    //Function interceptorRowOffset(ByVal iValue As Integer) As Integer
    //Dim iTest As Integer
    //
    //iTest = cActivePlayer.Row - iValue
    int iTest = cActivePlayer.Row - iValue;
//
    //If iTest > 0 Then
    if (iTest > 0){
//   interceptorRowOffset = 1
    }
//ElseIf iTest < 0 Then
    else if (iTest < 0){
//   interceptorRowOffset = -1
    return -1;
}
//Else
   else {
 //   interceptorRowOffset = 0
    return 0;
//End If
    }
//
    //End Function
}
//
int interceptorColumnOffset(Int iValue) {
    //Function interceptorColumnOffset(ByVal iValue As Integer) As Integer
    //Dim iTest As Integer
    //
    //iTest = cActivePlayer.Column - iValue
   int iTest = cActivePlayer.Column- iValue;
 //
    //If iTest > 0 Then
    if (iTest > 0) {
//   interceptorColumnOffset = 1
   return 0;
}
//ElseIf iTest < 0 Then
    else if (iTest < 0){
//   interceptorColumnOffset = -1
   return-1;
}
//Else
    else {
//   interceptorColumnOffset = 0
   return 0;
}
//End If
    //
    //End Function
}
//
bool CheckInterceptorsAlive(){
//Function CheckInterceptorsAlive() As Boolean
//Dim cNowinterceptor As cInterceptor
cIneterceptor cNowInterceptor;
//
//For Each cNowinterceptor In interceptorCollection
for (size_t i = 0; i < myVector.size(); ++i)
    for (int i = 0; i < interceptorCollection.count,++i)//left off here
    {
        cNowInterceptor = interceptorCollection[i];
//   If cNowinterceptor.Alive Then
        if (cNowInterceptor.Alive) {
            //      CheckInterceptorsAlive = True
            return true;            
            //      Exit For
            break;
        }
//   Else
        else
        {
            //      CheckInterceptorsAlive = False
            return false;
            //   End If            
        }
//Next cNowinterceptor
//   
     }
//End Function
}
