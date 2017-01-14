#ifndef __IVO_CREATEINDEX_H__
#define __IVO_CREATEINDEX_H__
#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOColumn.h>
#include <Rsql3/IVOConditions.h>
// {2F273231-5D82-4BBF-BB07-D8CBA02AB968}
DEFINE_GUID(IID_IVOCreateIndex,
    0x2f273231, 0x5d82, 0x4bbf, 0xbb, 0x7, 0xd8, 0xcb, 0xa0, 0x2a, 0xb9, 0x68);

interface IVOCreateIndex
    : public IVOBase
{
    IFACEMETHOD_(IVOCreateIndex&, Unique)(BOOL bValue = TRUE) = 0;

    IFACEMETHOD_(IVOCreateIndex&, IfNotExist)(BOOL bValue = TRUE) = 0;

    IFACEMETHOD_(IVOCreateIndex&, Schema)(LPCWSTR szSchema, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateIndex&, Schema)(LPCSTR szSchema, DEALLOCATOR pDealloc= STATIC_COPY) = 0;

    IFACEMETHOD_(IVOCreateIndex&, Index)(LPCWSTR szIndex, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateIndex&, Index)(LPCSTR szIndex, DEALLOCATOR pDealloc= STATIC_COPY) = 0;

    IFACEMETHOD_(IVOCreateIndex&, OnTable)(LPCWSTR szTable, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateIndex&, OnTable)(LPCSTR szTable, DEALLOCATOR pDealloc= STATIC_COPY) = 0;

    IFACEMETHOD_(IVOCreateIndex&, Column)(IVOIndexedColumn* pIndexedColumn) = 0;

    IFACEMETHOD_(IVOCreateIndex&, Where)(IVOConditions* pConditions) = 0;
};
#endif
