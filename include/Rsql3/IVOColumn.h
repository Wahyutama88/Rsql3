#ifndef __IVO_COLUMN_H__
#define __IVO_COLUMN_H__

#include <Rsql3/IValueObjects.h>
#include <Rsql3/Enums.h>
template <typename T>
interface IColumnNameT
{
    IFACEMETHOD_(T&, Name)(LPCWSTR szColumnName, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
    IFACEMETHOD_(T&, Name)(LPCSTR szColumnName, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
};

//////////////////////////////////////////////////////////////////////////
// {6850C483-7700-421D-B75B-84DB0148DE15}
DEFINE_GUID(IID_IVOColumnName,
    0x6850c483, 0x7700, 0x421d, 0xb7, 0x5b, 0x84, 0xdb, 0x1, 0x48, 0xde, 0x15);

interface IVOColumnName
    : public IVOBase
    , public IColumnNameT<IVOColumnName> {};


extern "C"
{
    IVOColumnName* __stdcall VOColumnName();
    IVOColumnName* __stdcall vo_column_name(LPCSTR szColumnName, DEALLOCATOR pDeallocator = STATIC_COPY);
    IVOColumnName* __stdcall vo_column_name16(LPCWSTR szColumnName, DEALLOCATOR pDeallocator = STATIC_COPY);

}
//////////////////////////////////////////////////////////////////////////
// {68555412-C1F6-4345-96CD-3765C7928C36}
DEFINE_GUID(IID_IVOIndexedColumn,
    0x68555412, 0xc1f6, 0x4345, 0x96, 0xcd, 0x37, 0x65, 0xc7, 0x92, 0x8c, 0x36);

interface IVOIndexedColumn
    : public IVOBase
    , public IColumnNameT<IVOIndexedColumn>
{
    IFACEMETHOD_(IVOIndexedColumn&, Sort)(SORT::ORDER eSortOrder = SORT::NONE) = 0;
    IFACEMETHOD_(IVOIndexedColumn&, Collate)(LPCWSTR szCollationName = 0, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOIndexedColumn&, Collate)(LPCSTR szCollationName = 0, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
};
extern "C"
{
    IVOIndexedColumn* __stdcall VOIndexedColumn();
    IVOIndexedColumn* __stdcall vo_index16(LPCWSTR szIndexName, DEALLOCATOR pDealloc = STATIC_COPY);
    IVOIndexedColumn* __stdcall vo_index(LPCSTR szIndexName, DEALLOCATOR pDealloc = STATIC_COPY);
}


//////////////////////////////////////////////////////////////////////////
#include <Rsql3/IVOTable.h>
// {56F7B12A-6A2E-4313-A30E-5DE2A1F5993C}
DEFINE_GUID(IID_IVOColumnNameEx,
    0x56f7b12a, 0x6a2e, 0x4313, 0xa3, 0xe, 0x5d, 0xe2, 0xa1, 0xf5, 0x99, 0x3c);

interface IVOColumnNameEx
    : public IVOBase
    , public ITableNameT<IVOColumnNameEx>
    , public IColumnNameT<IVOColumnNameEx>
{
    IFACEMETHOD_(IVOColumnNameEx&, Alias)(IVOAlias* pAlias) = 0;
};
extern "C"
IVOColumnNameEx* __stdcall VOColumnNameEx();

////////////////////////////////////////////////////////////////////////////////////
#include <Rsql3/IVOConstraint.h>
// {2F391E5B-518C-4875-8C15-D073B7D1B486}
DEFINE_GUID(IID_IVOColumn,
    0x2f391e5b, 0x518c, 0x4875, 0x8c, 0x15, 0xd0, 0x73, 0xb7, 0xd1, 0xb4, 0x86);

interface IVOColumn
    : public IVOBase
    , public IColumnNameT<IVOColumn>
{
    IFACEMETHOD_(IVOColumn&, DataType)(LPCWSTR szDataType, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOColumn&, DataType)(LPCSTR szDataType, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOColumn&, DataType)(DATA::TYPES eDatatype) = 0;
    IFACEMETHOD_(IVOColumn&, DataType)(IVOBase* pDatatype) = 0;

    IFACEMETHOD_(IVOColumn&, Constraint)(IVOBase* pConstraint) = 0;
};

extern "C"
IVOColumn* __stdcall VOColumn();
#endif