#pragma once
#ifndef cPlayer_H
#define cPlayer_H
class cPlayer
{
private:
    bool m_bAlive{ true };
    int m_iRow{};
    int m_iColumn{};

public:
    bool Alive();// () const { return m_bAlive; }
    void Alive(bool bNowAlive);
    int Row();// () const { return m_iRow; }
    void Row(int iNowRow);// () const { return m_iRow; }
    int Column();// () const { return m_iColumn; }
    void Column(int iNowCol);// () const { return m_iColumn; }
};
#endif
