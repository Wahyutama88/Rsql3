#ifndef __IVO_PRAGMA_H__
#define __IVO_PRAGMA_H__
#include <Rsql3/IVOBase.h>

// {7239F545-EB6E-4231-A777-8C5011EB7C7B}
DEFINE_GUID(IID_IVOPragma,
    0x7239f545, 0xeb6e, 0x4231, 0xa7, 0x77, 0x8c, 0x50, 0x11, 0xeb, 0x7c, 0x7b);

namespace PRAGMA {
    enum TYPE
    {
        NO_SIGN,
        EQUALS_SIGN,
        BRACKET_SIGN
    };
}
interface IVOPragma
    : public IVOBase
{
    // optional
    IFACEMETHOD_(IVOPragma&, Schema)(LPCWSTR szDB = nullptr, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOPragma&, Schema)(LPCSTR szDB, DEALLOCATOR pDealloc = STATIC_COPY) = 0;


    IFACEMETHOD_(IVOPragma&, Pragma)(LPCWSTR szName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOPragma&, Pragma)(LPCSTR szName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    // optional
    IFACEMETHOD_(IVOPragma&, Value)(PRAGMA::TYPE eType, IVOBase* pValue) = 0;
};

extern "C"
IVOPragma* __stdcall VOPragma();
#endif
