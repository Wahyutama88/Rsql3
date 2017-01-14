#ifndef __IVO_ALTER_TABLE_H__
#define __IVO_ALTER_TABLE_H__

#include <Rsql3/Deallocator.h>
#include <Rsql3/IVOTable.h>
#include <Rsql3/IVOColumn.h>

// {FB00BBB2-3129-44B7-91B7-AF0A499DAFF6}
DEFINE_GUID(IID_IVOAlterTable,
    0xfb00bbb2, 0x3129, 0x44b7, 0x91, 0xb7, 0xaf, 0xa, 0x49, 0x9d, 0xaf, 0xf6);

interface IVOAlterTable
    : public IVOBase
{
    IFACEMETHOD_(IVOAlterTable&, Table)(IVOTableName* pTable) = 0;

    IFACEMETHOD_(IVOAlterTable&, RenameTable)(LPCWSTR szTableName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOAlterTable&, RenameTable)(LPCSTR szTableName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    IFACEMETHOD_(IVOAlterTable&, AddColumn)(IVOColumn* pColumn) = 0;
};

extern "C"
IVOAlterTable* __stdcall VOAlterTable();
#endif
