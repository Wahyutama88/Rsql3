#ifndef __IVO_JOIN_ENTRY_H__
#define __IVO_JOIN_ENTRY_H__
#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOTable.h>
#include <Rsql3/IVOColumn.h>
// Used by IVOSelect

// {2B1749E7-01CF-49FC-9976-69B8C8BA7D81}
DEFINE_GUID(IID_IVOJoinEntry,
    0x2b1749e7, 0x1cf, 0x49fc, 0x99, 0x76, 0x69, 0xb8, 0xc8, 0xba, 0x7d, 0x81);

interface IVOJoinEntry
    : public IVOBase
{
    IFACEMETHOD_(IVOJoinEntry&, Natural)() = 0;
    // if you need this then use it; won't have any effect on inner join and_ cross join...
    IFACEMETHOD_(IVOJoinEntry&, Outer)() = 0;

    // mutual exclusive
    IFACEMETHOD_(IVOJoinEntry&, Inner)() = 0;
    IFACEMETHOD_(IVOJoinEntry&, Left)() = 0;
    IFACEMETHOD_(IVOJoinEntry&, Right)() = 0;
    IFACEMETHOD_(IVOJoinEntry&, Full)() = 0;
    IFACEMETHOD_(IVOJoinEntry&, Cross)() = 0;

    // you can share ITable with another call
    // but remember to inc the refcount by calling its addref
    IFACEMETHOD_(IVOJoinEntry&, Join)(IVOTable* pJoinTable) = 0;

    // have different name
    IFACEMETHOD_(IVOJoinEntry&, On)(IVOColumnName* pColumnJoin, IVOColumnName* pColumnFrom) = 0;
    // have same name
    IFACEMETHOD_(IVOJoinEntry&, On)(IVOColumnName* pColumnJoin) = 0;

    // use vo_in for function below
    IFACEMETHOD_(IVOJoinEntry&, Using)(IVOColumnName* pUsingColumn) = 0;
};
extern "C"
IVOJoinEntry* __stdcall VOJoin();

#endif