#ifndef __IVO_SELECT_H__
#define __IVO_SELECT_H__

#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOColumn.h>
#include <Rsql3/IVOJoin.h>
#include <Rsql3/IVOOrder.h>
#include <Rsql3/IVOConditions.h>
#include <Rsql3/IVOSubQuery.h>
// {44F4228C-F682-48C2-9C05-14EAFAFE7DC3}
DEFINE_GUID(IID_IVOSelect,
    0x44f4228c, 0xf682, 0x48c2, 0x9c, 0x5, 0x14, 0xea, 0xfa, 0xfe, 0x7d, 0xc3);


interface IVOSelect
    : public IVOBase
{
    // compound select
    IFACEMETHOD_(IVOSelect&, Union)() = 0;
    IFACEMETHOD_(IVOSelect&, UnionAll)() = 0;
    IFACEMETHOD_(IVOSelect&, Intersect)() = 0;
    IFACEMETHOD_(IVOSelect&, Except)() = 0;

    // select
    // call these only ONE time
    // mutual exclusive
    IFACEMETHOD_(IVOSelect&, Distinct)() = 0;
    IFACEMETHOD_(IVOSelect&, All)() = 0;

    // select
    // call this multiple times
    IFACEMETHOD_(IVOSelect&, Select)(IVOColumnNameEx* pColumn) = 0;
    IFACEMETHOD_(IVOSelect&, Select)(IVOBase* pSelect) = 0;

    // from
    // call this multiple times
    IFACEMETHOD_(IVOSelect&, From)(IVOTable* pTableFrom) = 0;
    IFACEMETHOD_(IVOSelect&, From)(IVOSubQuery* pFrom) = 0;

    // join
    // call this multiple times
    IFACEMETHOD_(IVOSelect&, Join)(IVOJoinEntry* pJoin) = 0;

    // where
    // call this only ONE time
    IFACEMETHOD_(IVOSelect&, Where)(IVOConditions* pCondition) = 0;

    // group by
    // call this multiple times
    IFACEMETHOD_(IVOSelect&, GroupBy)(IVOColumnName* pColumnName) = 0;
    IFACEMETHOD_(IVOSelect&, GroupBy)(IVOColumnNameEx* pColumnName) = 0;


    // having
    // call this only ONE time
    IFACEMETHOD_(IVOSelect&, Having)(IVOConditions* pCondition) = 0;


    // mutual exclusive with select --> having above.
    IFACEMETHOD_(IVOSelect&, Values)(IVOBase* pVO) = 0;
    // use for replace any prev values
    IFACEMETHOD_(IVOSelect&, Values)(ULONG_PTR idx, IVOBase* pVO) = 0;

    // multiple times
    IFACEMETHOD_(IVOSelect&, OrderBy)(IVOOrderEntry* pOrder) = 0;

    // single
    IFACEMETHOD_(IVOSelect&, Limit)(UINT64 iLimit) = 0;
    IFACEMETHOD_(IVOSelect&, Offset)(UINT64 iOffset) = 0;

    IFACEMETHOD_(VOID, ResetCurrent)() = 0;
    IFACEMETHOD_(VOID, ResetOrder)() = 0;
    IFACEMETHOD_(VOID, ResetLimitOffset)() = 0;
};
extern "C"
IVOSelect* __stdcall VOSelect();

#endif
