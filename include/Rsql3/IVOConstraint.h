#ifndef __IVO_CONSTRAINT_H__
#define __IVO_CONSTRAINT_H__

#include <Rsql3/Deallocator.h>
////////////////////////////////////////////////////////////////////////////////
// {AB4FF13E-4B49-45F3-96E9-4BCD2072DA82}
DEFINE_GUID(IID_IVOConstraint,
    0xab4ff13e, 0x4b49, 0x45f3, 0x96, 0xe9, 0x4b, 0xcd, 0x20, 0x72, 0xda, 0x82);
template <typename T>
interface IVOConstraintT : public IVOBase
{
    IFACEMETHOD_(T&, Name)(LPCWSTR szName, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
    IFACEMETHOD_(T&, Name)(LPCSTR szName, DEALLOCATOR pDealloc= STATIC_COPY) = 0;
};




#endif
