#pragma once
#include <Rsql3/IVOBase.h>
#include <Rsql3/Deallocator.h>
#include <Rsql3/Enums.h>

template <typename T>
interface ITableNameT
{
    IFACEMETHOD_(T&, Schema)(LPCWSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(T&, Schema)(LPCSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    IFACEMETHOD_(T&, Table)(LPCWSTR szTable, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(T&, Table)(LPCSTR szTable, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

///////////////////////////////////////////////////////////////////////////////////////
// {93965726-0DA8-4268-8C20-4A173D129EF2}
DEFINE_GUID(IID_IVOTableName,
    0x93965726, 0xda8, 0x4268, 0x8c, 0x20, 0x4a, 0x17, 0x3d, 0x12, 0x9e, 0xf2);

interface IVOTableName
    : public IVOBase
    , public ITableNameT<IVOTableName> {};

extern "C"
IVOTableName* __stdcall VOTableName();
///////////////////////////////////////////////////////////////////////////////////////
namespace PARAM {
    enum EXTRA
    {
        UNUSED,
        INDEXED_BY,
        NOT_INDEXED
    };
}
template <typename T>
interface IQuaTableNameT
    : public ITableNameT<T>
{
    IFACEMETHOD_(T&, ExtraParam16)(PARAM::EXTRA eParam = PARAM::UNUSED, LPCWSTR szIndexName = 0, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(T&, ExtraParam)(PARAM::EXTRA eParam = PARAM::UNUSED, LPCSTR szIndexName = 0, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

///////////////////////////////////////////////////////////////////////////////////////
// {637A5D0A-1812-4B25-B8BB-911BA460C25B}
DEFINE_GUID(IID_IVOQuaTableName,
    0x637a5d0a, 0x1812, 0x4b25, 0xb8, 0xbb, 0x91, 0x1b, 0xa4, 0x60, 0xc2, 0x5b);

interface IVOQuaTableName
    : public IVOBase
    , public IQuaTableNameT<IVOQuaTableName> {};
extern "C"
IVOQuaTableName* __stdcall VOQuaTableName();

///////////////////////////////////////////////////////////////////////////////////////
#include <Rsql3/IValueObjects.h>
// {2580C205-9524-4E1E-9757-510EB847FCEE}
DEFINE_GUID(IID_IVOTable,
    0x2580c205, 0x9524, 0x4e1e, 0x97, 0x57, 0x51, 0xe, 0xb8, 0x47, 0xfc, 0xee);

interface IVOTable
    : public IVOBase
    , public IQuaTableNameT<IVOTable>
{
    IFACEMETHOD_(IVOTable&, Alias)(IVOAlias* pAlias) = 0;
    IFACEMETHOD_(IVOTable&, Alias)(LPCWSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOTable&, Alias)(LPCSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

extern "C"
IVOTable* __stdcall VOTable();

extern "C"
{
    IVOTable* __stdcall vo_table_name(LPCSTR szTableName, DEALLOCATOR pDealloc = STATIC_COPY);
    IVOTable* __stdcall vo_table_name16(LPCWSTR szTableName, DEALLOCATOR pDealloc = STATIC_COPY);
}

