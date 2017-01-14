#ifndef __IVO_TABLE_CONSTRAINT_H__
#define __IVO_TABLE_CONSTRAINT_H__

#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOConstraint.h>
#include <Rsql3/Enums.h>
#include <Rsql3/IVOColumn.h>

///////////////////////////////////////////////////////////////////////////////////////
// {63E25A36-BD62-4C80-8E6A-F6A04DB22C11}
DEFINE_GUID(IID_IVOTableConstraint,
    0x63e25a36, 0xbd62, 0x4c80, 0x8e, 0x6a, 0xf6, 0xa0, 0x4d, 0xb2, 0x2c, 0x11);

///////////////////////////////////////////////////////////////////////////////////////
// {5D29F141-16AB-478E-9FBA-CFFFD4ABF2F6}
DEFINE_GUID(IID_IVOTPrimaryKey,
    0x5d29f141, 0x16ab, 0x478e, 0x9f, 0xba, 0xcf, 0xff, 0xd4, 0xab, 0xf2, 0xf6);

interface IVOTPrimaryKey
    : public IVOConstraintT<IVOTPrimaryKey>
{
    // multiple calls
    IFACEMETHOD_(IVOTPrimaryKey&, Index)(IVOIndexedColumn* pIndexedColumn) = 0;
    IFACEMETHOD_(IVOTPrimaryKey&, OnConflict)(CONFLICT::CLAUSE eConflict) = 0;
};

extern "C"
IVOTPrimaryKey* __stdcall VOTPrimaryKey();

/////////////////////////////////////////////////////////////////////////////////////
// {C17D06B8-0A68-4083-8560-60E85A11CB46}
DEFINE_GUID(IID_IVOTUnique,
    0xc17d06b8, 0xa68, 0x4083, 0x85, 0x60, 0x60, 0xe8, 0x5a, 0x11, 0xcb, 0x46);

interface IVOTUnique
    : public IVOConstraintT<IVOTUnique>
{
    // multiple calls
    IFACEMETHOD_(IVOTUnique&, Index)(IVOIndexedColumn* pIndexedColumn) = 0;
    IFACEMETHOD_(IVOTUnique&, OnConflict)(CONFLICT::CLAUSE eConflict) = 0;
};

extern "C"
IVOTUnique* __stdcall VOTUnique();

///////////////////////////////////////////////////////////////////////////////////////
#include <Rsql3/IVOConditions.h>
// {5F62A775-AE2C-436B-8A1E-F269898F26E6}
DEFINE_GUID(IID_IVOTCheck,
    0x5f62a775, 0xae2c, 0x436b, 0x8a, 0x1e, 0xf2, 0x69, 0x89, 0x8f, 0x26, 0xe6);
interface IVOTCheck
    : public IVOConstraintT<IVOTCheck>
{
    IFACEMETHOD_(IVOTCheck&, Check)(IVOConditions* pCheck) = 0;
};
extern "C"
IVOTCheck* __stdcall VOTCheck();

///////////////////////////////////////////////////////////////////////////////////////
#include <Rsql3/IVOForeignKey.h>
// {51289EC9-D640-4C87-8065-0EEC0A16AFF6}
DEFINE_GUID(IID_IVOTForeignKey,
    0x51289ec9, 0xd640, 0x4c87, 0x80, 0x65, 0xe, 0xec, 0xa, 0x16, 0xaf, 0xf6);

interface IVOTForeignKey
    : public IVOConstraintT<IVOTForeignKey>
{
    // accept multiple calls
    IFACEMETHOD_(IVOTForeignKey&, ColumnSrc)(IVOColumnName* pColumnName) = 0;
    IFACEMETHOD_(IVOTForeignKey&, ForeignKey)(IVOForeignKey* pForeignKey) = 0;
};

extern "C"
IVOTForeignKey* __stdcall VOTForeignKey();
#endif
