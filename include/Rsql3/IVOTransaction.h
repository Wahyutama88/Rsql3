#ifndef __IVO_TRANSACTION_H__
#define __IVO_TRANSACTION_H__

#include <Rsql3/IVOBase.h>

// {F39DF6BD-558C-4A2C-9441-01A4C7B13102}
DEFINE_GUID(IID_IVOTransaction,
    0xf39df6bd, 0x558c, 0x4a2c, 0x94, 0x41, 0x1, 0xa4, 0xc7, 0xb1, 0x31, 0x2);
namespace TRANSACTION {
    namespace BEGIN {
        enum TYPE
        {
            Ordinary,
            Deferred,
            Immediate,
            Exclusive
        };
    }
}
interface IVOTransaction
    : public IVOBase
{
    // will call function below
    IFACEMETHOD_(IVOTransaction&, Begin)(TRANSACTION::BEGIN::TYPE etype = TRANSACTION::BEGIN::Ordinary) = 0;
    IFACEMETHOD_(IVOTransaction&, Commit)() = 0;
    IFACEMETHOD_(IVOTransaction&, Rollback)() = 0;

    IFACEMETHOD_(IVOTransaction&, Rollback)(LPCWSTR szSavePoint, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
    IFACEMETHOD_(IVOTransaction&, Rollback)(LPCSTR szSavePoint, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
};

extern "C"
{
    IVOTransaction* __stdcall VOTransaction();
    LPCWSTR __stdcall vof_begin16(TRANSACTION::BEGIN::TYPE etype = TRANSACTION::BEGIN::Ordinary);
    LPCSTR __stdcall vof_begin(TRANSACTION::BEGIN::TYPE etype = TRANSACTION::BEGIN::Ordinary);

    LPCWSTR __stdcall vof_commit16();
    LPCSTR __stdcall vof_commit();

    LPCWSTR __stdcall vof_rollback16();
    LPCSTR __stdcall vof_rollback();
}
#endif
