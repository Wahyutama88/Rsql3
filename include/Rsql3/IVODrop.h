#ifndef __IVO_DROP_H__
#define __IVO_DROP_H__
#include <Rsql3/IVOBase.h>
namespace DROP {
    enum TYPE
    {
        TABLE,
        INDEX,
        TRIGGER,
        VIEW,
    };
}
// {0F577E03-D071-4AA2-BD92-BC706A0DFD08}
DEFINE_GUID(IID_IVODrop,
    0xf577e03, 0xd071, 0x4aa2, 0xbd, 0x92, 0xbc, 0x70, 0x6a, 0xd, 0xfd, 0x8);

interface IVODrop
    : public IVOBase
{
    IFACEMETHOD_(IVODrop&, IfExist)(BOOL bValue = TRUE) = 0;
    IFACEMETHOD_(IVODrop&, Schema)(LPCSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVODrop&, Schema)(LPCWSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVODrop&, Type)(DROP::TYPE eDropType) = 0;
    IFACEMETHOD_(IVODrop&, Drop)(LPCSTR szDrop, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVODrop&, Drop)(LPCWSTR szDrop, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

extern "C"
IVODrop* __stdcall VODrop();
#endif
