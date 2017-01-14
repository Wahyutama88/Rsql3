#ifndef __ICONDITION_H__
#define __ICONDITION_H__

#include <Rsql3/IVOBase.h>
#include <Rsql3/Enums.h>

// {689F55DA-7F24-453D-B27D-B73451F510A7}
DEFINE_GUID(IID_IVOConditions,
    0x689f55da, 0x7f24, 0x453d, 0xb2, 0x7d, 0xb7, 0x34, 0x51, 0xf5, 0x10, 0xa7);

interface IVOConditions : public IVOBase
{
    // on single level; inside single ()
    IFACEMETHOD_(IVOConditions&, Check)(LPCWSTR szCondition, OPERATOR::TYPE eOperator, IVOBase* pValueObject, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Check)(LPCSTR szCondition, OPERATOR::TYPE eOperator, IVOBase* pValueObject, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Check)(IVOBase* pCondition, OPERATOR::TYPE eOperator, IVOBase* pValueObject) = 0;

    // same as above for special operator
    IFACEMETHOD_(IVOConditions&, Check)(LPCWSTR szCondition, IVOBase* pVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Check)(LPCSTR szCondition, IVOBase* pVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Check)(IVOBase* pCondition, IVOBase* pVO) = 0;

    // on single level; inside single ()
    IFACEMETHOD_(IVOConditions&, Where)(LPCWSTR szCondition, OPERATOR::TYPE eOperator, IVOBase* pVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Where)(LPCSTR szCondition, OPERATOR::TYPE eOperator, IVOBase* pVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Where)(IVOBase* pCondition, OPERATOR::TYPE eOperator, IVOBase* pVO) = 0;

    // same as above for special operator
    IFACEMETHOD_(IVOConditions&, Where)(LPCWSTR szCondition, IVOBase* pVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Where)(LPCSTR szCondition, IVOBase* pVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Where)(IVOBase* pCondition, IVOBase* pVO) = 0;


    // use previously defined szCondition
    IFACEMETHOD_(IVOConditions&, Or)(OPERATOR::TYPE eOperator, IVOBase* pValueObject) = 0;
    IFACEMETHOD_(IVOConditions&, And)(OPERATOR::TYPE eOperator, IVOBase* pValueObject) = 0;
    // same as above for special operator
    IFACEMETHOD_(IVOConditions&, Or)(IVOBase* pVO) = 0;
    IFACEMETHOD_(IVOConditions&, And)(IVOBase* pVO) = 0;

    // on the same level as previous call
    IFACEMETHOD_(IVOConditions&, Or)(LPCWSTR szCondition, OPERATOR::TYPE eOperator, IVOBase* pValueObject, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, And)(LPCWSTR szCondition, OPERATOR::TYPE eOperator, IVOBase* pValueObject, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    // same as above for special operator
    IFACEMETHOD_(IVOConditions&, Or)(LPCWSTR szCondition, IVOBase* pVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, And)(LPCWSTR szCondition, IVOBase* pVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    // simple check; users wrote the condition
    IFACEMETHOD_(IVOConditions&, Check)(LPCWSTR szCondition, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Check)(LPCSTR szCondition, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Check)(IVOBase* pCondition) = 0;

    IFACEMETHOD_(IVOConditions&, Where)(LPCWSTR szCondition, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Where)(LPCSTR szCondition, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOConditions&, Where)(IVOBase* pCondition) = 0;

    // next level; next (); then use above function
    IFACEMETHOD_(IVOConditions&, Or)() = 0;
    IFACEMETHOD_(IVOConditions&, And)() = 0;
};
extern "C"
IVOConditions* __stdcall VOConditions();
#endif