#ifndef __IVO_ORDER_H__
#define __IVO_ORDER_H__

#include <Rsql3/IVOBase.h>
#include <Rsql3/Enums.h>
// {C5BC6E7D-4496-4639-A7E2-ABFB28DDEA7E}
DEFINE_GUID(IID_IVOOrderByEntry,
    0xc5bc6e7d, 0x4496, 0x4639, 0xa7, 0xe2, 0xab, 0xfb, 0x28, 0xdd, 0xea, 0x7e);

interface IVOOrderEntry
    : public IVOBase
{
    IFACEMETHOD_(IVOOrderEntry&, OrderBy)(LPCWSTR szColumnName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOOrderEntry&, OrderBy)(LPCSTR szColumnName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOOrderEntry&, Sort)(SORT::ORDER eSort = SORT::NONE) = 0;
    IFACEMETHOD_(IVOOrderEntry&, CollationName)(LPCWSTR szCollationName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOOrderEntry&, CollationName)(LPCSTR szCollationName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

extern "C"
IVOOrderEntry* __stdcall VOOrder();

#endif
