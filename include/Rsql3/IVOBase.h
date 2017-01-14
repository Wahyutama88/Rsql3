#ifndef __IVALUE_OBJECT_BASE_H__
#define __IVALUE_OBJECT_BASE_H__

#ifdef WIN32
#include <Windows.h>
#endif
#include <Rsql3/Report.h>
#include <Rsql3/IException.h>
#include <Rsql3/Deallocator.h>
// {DC9E2D21-E753-49CA-91CB-9DFB95585374}
DEFINE_GUID(IID_IVOBase,
    0xdc9e2d21, 0xe753, 0x49ca, 0x91, 0xcb, 0x9d, 0xfb, 0x95, 0x58, 0x53, 0x74);

#ifndef _VOBASEDEFINED
#define _VOBASEDEFINED
enum OwnerShip
{
    System,
    OwnCount,
};

interface IVOBase : public IUnknown
{
    IFACEMETHOD_(BOOL, IsWideAvailable)() = 0;
    IFACEMETHOD_(LPCSTR, Build)() = 0;
    IFACEMETHOD_(LPCWSTR, Build16)() = 0;
    IFACEMETHOD_(VOID, Detach)() = 0;
    IFACEMETHOD_(INT, Owner)(OwnerShip owner) = 0;
    // destroy current constructed SQL query for safety
    IFACEMETHOD_(VOID, Destroy)() = 0;


    IFACEMETHOD_(BOOL, IsAvailable)() = 0;
    IFACEMETHOD_(VOID, ResetAll)() = 0;
    IFACEMETHOD_(VOID, RegisterListener)(R3_REPORT_PROC pReport, LPARAM lParam) = 0;

    IFACEMETHOD_(VOID, BreakBuild)() = 0;
    IFACEMETHOD_(VOID, EnableBuild)() = 0;
    IFACEMETHOD_(IException*, GetException)() = 0;
    IFACEMETHOD_(VOID, TerminateStatement)(BOOL bValue = TRUE) = 0;


    // internal
    IFACEMETHOD_(VOID, Reserved)() = 0;
    IFACEMETHOD_(VOID, Reserved2)() = 0;
    IFACEMETHOD_(VOID, Reserved3)() = 0;

};

#endif



extern "C"
HRESULT WINAPI CreateInterface(REFIID riid, void ** ppvObject);

#endif