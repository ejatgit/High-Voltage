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
    bool Alive();
    void Alive(bool bNowAlive);
    int Row();
    void Row(int iNowRow);
    int Column();
    void Column(int iNowCol);
};
#endif
