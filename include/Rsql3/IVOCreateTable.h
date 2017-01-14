#ifndef __IVO_CREATETABLE_H__
#define __IVO_CREATETABLE_H__
#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOTable.h>
#include <Rsql3/IVOTableConstraint.h>
#include <Rsql3/IVOColumn.h>
#include <Rsql3/IVOSelect.h>
// {08CE13FC-D1D9-441B-8E7A-B1A41BA73352}
DEFINE_GUID(IID_IVOCreateTable,
    0x8ce13fc, 0xd1d9, 0x441b, 0x8e, 0x7a, 0xb1, 0xa4, 0x1b, 0xa7, 0x33, 0x52);

interface IVOCreateTable
    : public IVOBase
{
    IFACEMETHOD_(IVOCreateTable&, Temporary)(BOOL bValue = TRUE) = 0;
    IFACEMETHOD_(IVOCreateTable&, IfNotexist)(BOOL bValue = TRUE) = 0;
    IFACEMETHOD_(IVOCreateTable&, Table)(IVOTableName* pTable) = 0;

    IFACEMETHOD_(IVOCreateTable&, Column)(IVOColumn* pColumn) = 0;
    // Table constraint
    IFACEMETHOD_(IVOCreateTable&, Constraint)(IVOBase* pConstraint) = 0;
    IFACEMETHOD_(IVOCreateTable&, WithoutRowID)(BOOL bValue = TRUE) = 0;

    IFACEMETHOD_(IVOCreateTable&, As)(IVOSelect* pSelect) = 0;
};

extern "C"
IVOCreateTable* __stdcall VOCreateTable();
#endif
