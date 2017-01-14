#ifndef __IVO_ANALYZE_H__
#define __IVO_ANALYZE_H__
#include <Rsql3/IVOBase.h>
// {75785A17-133A-4C8B-9353-6027C46B3AA5}
DEFINE_GUID(IID_IVOAnalyze,
    0x75785a17, 0x133a, 0x4c8b, 0x93, 0x53, 0x60, 0x27, 0xc4, 0x6b, 0x3a, 0xa5);

interface IVOAnalyze
    : public IVOBase
{
    IFACEMETHOD_(IVOAnalyze&, Schema)(LPCWSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOAnalyze&, Schema)(LPCSTR szSchema, DEALLOCATOR pDealloc= STATIC_COPY) = 0;

    // mutual exclusive
    IFACEMETHOD_(IVOAnalyze&, Index)(LPCWSTR szSchema, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
    IFACEMETHOD_(IVOAnalyze&, Index)(LPCSTR szSchema, DEALLOCATOR pDealloc= STATIC_COPY) = 0;

    IFACEMETHOD_(IVOAnalyze&, Table)(LPCWSTR szSchema, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
    IFACEMETHOD_(IVOAnalyze&, Table)(LPCSTR szSchema, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
};

extern "C"
IVOAnalyze* __stdcall VOAnalyze();
#endif
