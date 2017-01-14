#ifndef __IVOSUBQUERY_H__
#define __IVOSUBQUERY_H__
#include <Rsql3/IVOSelect.h>
#include <Rsql3/IValueObjects.h>
// {49076926-573B-4827-B4C4-CF118C374CD5}
DEFINE_GUID(IID_IVOSubQuery,
    0x49076926, 0x573b, 0x4827, 0xb4, 0xc4, 0xcf, 0x11, 0x8c, 0x37, 0x4c, 0xd5);

interface IVOSubQuery
    : public IVOBase
{
    IFACEMETHOD_(IVOSubQuery&, Query)(IVOSelect* pSelect) = 0;
    IFACEMETHOD_(IVOSubQuery&, Alias)(IVOAlias* pAlias) = 0;
    IFACEMETHOD_(IVOSubQuery&, Alias)(LPCWSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOSubQuery&, Alias)(LPCSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

extern "C"
IVOSubQuery* __stdcall VOSubQuery();
#endif
