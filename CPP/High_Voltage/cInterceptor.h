#pragma once

#ifndef cInterceptor_H
#define cInterceptor_H
class cInterceptor{
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