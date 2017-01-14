#ifndef __IVO_WITH_H__
#define __IVO_WITH_H__
#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOSelect.h>
#include <Rsql3/IVODelete.h>
#include <Rsql3/IVOInsert.h>
#include <Rsql3/IVOUpdate.h>
#include <Rsql3/IVOColumn.h>
// {4A6BE000-7599-46EC-B002-FE8405269068}
DEFINE_GUID(IID_IVOCTE ,
    0x4a6be000, 0x7599, 0x46ec, 0xb0, 0x2, 0xfe, 0x84, 0x5, 0x26, 0x90, 0x68);

interface IVOCTE
    : public IVOBase
{
    IFACEMETHOD_(IVOCTE&, Table)(LPCWSTR szTable, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCTE&, Table)(LPCSTR szTable, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    // multiple
    IFACEMETHOD_(IVOCTE&, Column)(IVOColumnName* pColumn) = 0;

    IFACEMETHOD_(IVOCTE&, As)(IVOSelect* pSelect) = 0;
};

// {33D2BFD0-B36E-46F7-81D3-967193617CDE}
DEFINE_GUID(IID_IVOWith,
    0x33d2bfd0, 0xb36e, 0x46f7, 0x81, 0xd3, 0x96, 0x71, 0x93, 0x61, 0x7c, 0xde);

interface IVOWith
    : public IVOBase
{
    IFACEMETHOD_(IVOWith&, Recursive)(BOOL bValue = TRUE) = 0;
    // multiple
    IFACEMETHOD_(IVOWith&, CTE)(IVOCTE* pCTE) = 0;

    IFACEMETHOD_(IVOWith&, Stmt)(IVOSelect* pSelect) = 0;
    IFACEMETHOD_(IVOWith&, Stmt)(IVODelete* pDelete) = 0;
    IFACEMETHOD_(IVOWith&, Stmt)(IVODeleteEx* pDeleteEx) = 0;
    IFACEMETHOD_(IVOWith&, Stmt)(IVOInsert* pInsert) = 0;
    IFACEMETHOD_(IVOWith&, Stmt)(IVOUpdate* pUpdate) = 0;
    IFACEMETHOD_(IVOWith&, Stmt)(IVOUpdateEx* pUpdateEx) = 0;
};
#endif
