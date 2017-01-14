#ifndef __IVO_CREATEVIEW_H__
#define __IVO_CREATEVIEW_H__

#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOSelect.h>
// {38E74E36-6EEA-4EFA-A95D-1B053D19753A}
DEFINE_GUID(IID_IVOCreateView,
    0x38e74e36, 0x6eea, 0x4efa, 0xa9, 0x5d, 0x1b, 0x5, 0x3d, 0x19, 0x75, 0x3a);

interface IVOCreateView
    : public IVOBase
{
    IFACEMETHOD_(IVOCreateView&, Temporary)(BOOL bValue = TRUE) = 0;
    IFACEMETHOD_(IVOCreateView&, IfNotExist)(BOOL bValue = TRUE) = 0;
    IFACEMETHOD_(IVOCreateView&, Schema)(LPCWSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateView&, Schema)(LPCSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateView&, View)(LPCWSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateView&, View)(LPCSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateView&, As)(IVOSelect* pSelect) = 0;
};
#endif
