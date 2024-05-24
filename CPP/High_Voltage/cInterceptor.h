#pragma once

#ifndef cInterceptor_H
#define cInterceptor_H
class cInterceptor{
private:
    bool m_bAlive{ true };
    int m_iRow{};
    int m_iColumn{};

public:
    bool Alive{ true };// () const { return m_bAlive; }
    int Row{0};// () const { return m_iRow; }
    int Column{0};// () const { return m_iColumn; }
};


#endif