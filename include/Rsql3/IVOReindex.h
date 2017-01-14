#ifndef __IVO_REINDEX_H__
#define __IVO_REINDEX_H__
#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOTable.h>
// {BBCB770A-A97F-4F37-8E66-75CFDC5C8855}
DEFINE_GUID(IID_IVOReindex,
    0xbbcb770a, 0xa97f, 0x4f37, 0x8e, 0x66, 0x75, 0xcf, 0xdc, 0x5c, 0x88, 0x55);

// syntax as follows
// [collation]|[Schema.[table]|[index]]
interface IVOReindex
    : public IVOBase

{
    IFACEMETHOD_(IVOReindex&, Collation)(LPCWSTR szCollation, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
    IFACEMETHOD_(IVOReindex&, Collation)(LPCSTR szCollation, DEALLOCATOR pDealloc= STATIC_COPY) = 0;

    IFACEMETHOD_(IVOReindex&, Schema)(LPCWSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOReindex&, Schema)(LPCSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    IFACEMETHOD_(IVOReindex&, Table)(LPCWSTR szCollation, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOReindex&, Table)(LPCSTR szCollation, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    IFACEMETHOD_(IVOReindex&, Index)(LPCWSTR szIndex, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
    IFACEMETHOD_(IVOReindex&, Index)(LPCSTR szIndex, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
};

extern "C"
IVOReindex* __stdcall VOReindex();
#endif
