
class cInterceptor {
   //Private
   #m_bAlive = true;
   #m_iRow;
   #m_iColumn;

   //Public
   Alive() {
      return cInterceptor.#m_bAlive;
   }

   Alive(bNowAlive) {
      cInterceptor.#m_bAlive = bNowAlive;
   }

   Row() {
      return cInterceptor.#m_iRow;
   }

   Row(iNowRow) {
      cInterceptor.#m_iRow = iNowRow;
   }

   Column() {
      return cInterceptor.#m_iColumn;
   }

   Column(iNowCol) {
      cInterceptor.#m_iColumn = iNowCol;
   }

}