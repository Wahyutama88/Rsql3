#ifndef __REPORT_H__
#define __REPORT_H__

interface IVOBase;

struct R3_REPORT
{
    DWORD           cbSize;     // current size
    DWORD           dwErrorCode;
    LPCWSTR         szErrorcode16;
    LPCSTR          szErrorcode;
    GUID            guid;       // of element

    LPCWSTR         szMsg16;
    LPCSTR          szMsg;
    IVOBase*        pVOBase;
};

// for Callback
typedef VOID(*R3_REPORT_PROC)(R3_REPORT* pVOReport, LPARAM lParam);

// if the error callback is registered, then it will be responsible for error reporting to the user
// while the value object is still stand alone; not yet attached.
// for example if user call a methods but that method failed then it will reported immediately supplying necessary field
// but if the full interface failed to deliver then, the responsible ones will be the interface error handler

#endif