#ifndef __IVO_EXTENDED_H__
#define __IVO_EXTENDED_H__
#include <Rsql3/IVOOrder.h>
template <typename T>
interface IVOExtendedT
{
    IFACEMETHOD_(T&, OrderBy)(IVOOrderEntry* pOrderEntry) = 0;
    IFACEMETHOD_(T&, Limit)(UINT64 limit) = 0;
    IFACEMETHOD_(T&, Offset)(UINT64 offset) = 0;
};

#endif
