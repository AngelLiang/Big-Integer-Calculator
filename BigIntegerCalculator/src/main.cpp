#include "CBigInt.h"

int main(int argc, char* argv[])
{
    CBigInt a,b,res;
    a.m_nLength = 2;
    a.m_ulValue[0] = 100;
    a.m_ulValue[1] = 100;
    b.m_nLength = 2;
    b.m_ulValue[0] = 150;
    b.m_ulValue[1] = 150;
    res = a + b;
    res = b - a;

    return 0;
}