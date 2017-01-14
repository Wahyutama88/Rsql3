#ifndef __IEXCEPTION_H__
#define __IEXCEPTION_H__
#include <Windows.h>
interface IException
{
    IFACEMETHOD_(INT, Code)() = 0;
    IFACEMETHOD_(LPCSTR, CodeAsString)() = 0;
    IFACEMETHOD_(LPCWSTR, CodeAsString16)() = 0;
    IFACEMETHOD_(LPCSTR, CodeMsg)() = 0;
    IFACEMETHOD_(LPCWSTR, CodeMsg16)() = 0;
};

#endif

