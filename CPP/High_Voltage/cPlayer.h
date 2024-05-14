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
    bool Alive = true;// () const { return m_bAlive; }
    int Row;// () const { return m_iRow; }
    int Column;// () const { return m_iColumn; }
};
#endif
