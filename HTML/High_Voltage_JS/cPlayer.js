class cPlayer {
   //Private:
   #m_bAlive = true;
   #m_iRow;
   #m_iColumn;

   //Public:
   Alive() {
      return cPlayer.#m_bAlive;
   }

   Alive(bNowAlive) {
      cPlayer.#m_bAlive = bNowAlive;
   }

   Row() {
      return cPlayer.#m_iRow;
   }

   Row(iNowRow) {
      cPlayer.#m_iRow = iNowRow;
   }

   Column() {
      return cPlayer.#m_iColumn;
   }

   Column(iNowCol) {
      cPlayer.#m_iColumn = iNowCol;
   }
}
