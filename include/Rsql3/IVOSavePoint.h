#ifndef __IVO_SAVEPOINT_H__
#define __IVO_SAVEPOINT_H__

#include <Rsql3/IVOBase.h>
// {5C67A5C2-0A77-4858-AD43-D2888035048B}
DEFINE_GUID(IID_IVOSavePoint,
    0x5c67a5c2, 0xa77, 0x4858, 0xad, 0x43, 0xd2, 0x88, 0x80, 0x35, 0x4, 0x8b);

interface IVOSavePoint
    : public IVOBase
{
    IFACEMETHOD_(IVOSavePoint&, Name)(LPCWSTR szName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOSavePoint&, Name)(LPCSTR szName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOSavePoint&, SavePoint)() = 0;
    IFACEMETHOD_(IVOSavePoint&, ReleaseSP)() = 0;
    IFACEMETHOD_(IVOSavePoint&, Rollback)() = 0;
};

extern "C"
{
    IVOSavePoint* __stdcall vo_savepoint(LPCSTR szSavePoint, DEALLOCATOR pDealloc = STATIC_COPY);
    IVOSavePoint* __stdcall vo_savepoint16(LPCWSTR szSavePoint, DEALLOCATOR pDealloc = STATIC_COPY);

    IVOSavePoint* __stdcall vo_release_savepoint(LPCSTR szSavePoint, DEALLOCATOR pDealloc = STATIC_COPY);
    IVOSavePoint* __stdcall vo_release_savepoint16(LPCWSTR szSavePoint, DEALLOCATOR pDealloc = STATIC_COPY);

    IVOSavePoint* __stdcall vo_rollback_savepoint(LPCSTR szSavePoint, DEALLOCATOR pDealloc = STATIC_COPY);
    IVOSavePoint* __stdcall vo_rollback_savepoint16(LPCWSTR szSavePoint, DEALLOCATOR pDealloc = STATIC_COPY);


}


extern "C"
IVOSavePoint* __stdcall VOSavePoint();
#endif