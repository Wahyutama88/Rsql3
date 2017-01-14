#ifndef __IVO_COLUMNCONSTRAINT_H__
#define __IVO_COLUMNCONSTRAINT_H__

#include <Rsql3/IVOConstraint.h>
#include <Rsql3/Enums.h>

//////////////////////////////////////////////////////////////////////////////////////
// {BE5BF915-3EBA-4A9A-A1D1-A66BB397E80C}
DEFINE_GUID(IID_IVOColumnConstraint ,
    0xbe5bf915, 0x3eba, 0x4a9a, 0xa1, 0xd1, 0xa6, 0x6b, 0xb3, 0x97, 0xe8, 0xc);

//////////////////////////////////////////////////////////////////////////////////////
// {A0946C43-9B53-4AE0-A0E3-1DDB2E219999}
DEFINE_GUID(IID_IVOCPrimaryKey,
    0xa0946c43, 0x9b53, 0x4ae0, 0xa0, 0xe3, 0x1d, 0xdb, 0x2e, 0x21, 0x99, 0x99);

interface IVOCPrimaryKey : public IVOConstraintT<IVOCPrimaryKey>
{
    IFACEMETHOD_(IVOCPrimaryKey&, SortOrder)(SORT::ORDER eSort = SORT::NONE) = 0;
    IFACEMETHOD_(IVOCPrimaryKey&, OnConflict)(CONFLICT::CLAUSE eConflict = CONFLICT::DO_NOTHING) = 0;
    IFACEMETHOD_(IVOCPrimaryKey&, AutoIncrement)(BOOL bAutoInc = TRUE) = 0;
};

extern "C"
IVOCPrimaryKey* __stdcall VOCPrimaryKey();

//////////////////////////////////////////////////////////////////////////////////////
// {93DDF03E-26F1-4AD3-8A6F-076DDC8B4E1E}
DEFINE_GUID(IID_IVOCNotNull,
    0x93ddf03e, 0x26f1, 0x4ad3, 0x8a, 0x6f, 0x7, 0x6d, 0xdc, 0x8b, 0x4e, 0x1e);

interface IVOCNotNull : public IVOConstraintT<IVOCNotNull>
{
    IFACEMETHOD_(IVOCNotNull&, OnConflict)(CONFLICT::CLAUSE eConflict = CONFLICT::DO_NOTHING) = 0;
};
extern "C"
IVOCNotNull* __stdcall VOCNotNull();

//////////////////////////////////////////////////////////////////////////////////////
// {3A2B9F8F-1305-48CD-AA42-C8D9F0CF0CAC}
DEFINE_GUID(IID_IVOCUnique,
    0x3a2b9f8f, 0x1305, 0x48cd, 0xaa, 0x42, 0xc8, 0xd9, 0xf0, 0xcf, 0xc, 0xac);

interface IVOCUnique : public IVOConstraintT<IVOCUnique>
{
    IFACEMETHOD_(IVOCUnique&, OnConflict)(CONFLICT::CLAUSE eConflict = CONFLICT::DO_NOTHING) = 0;
};
extern "C"
IVOCUnique* __stdcall VOCUnique();

//////////////////////////////////////////////////////////////////////////////////////
#include <Rsql3/IVOConditions.h>
// {9BEDC177-5322-4F89-949C-45E8598FD990}
DEFINE_GUID(IID_IVOCCheck,
    0x9bedc177, 0x5322, 0x4f89, 0x94, 0x9c, 0x45, 0xe8, 0x59, 0x8f, 0xd9, 0x90);

interface IVOCCheck : public IVOConstraintT<IVOCCheck>
{
    IFACEMETHOD_(IVOCCheck&, Check)(IVOConditions* pConditions) = 0;
};

extern "C"
IVOCCheck* __stdcall VOCCheck();

//////////////////////////////////////////////////////////////////////////////////////
// {3C3F7CAC-DEC8-48B0-8722-3A6F944F73E9}
DEFINE_GUID(IID_IVOCDefault,
    0x3c3f7cac, 0xdec8, 0x48b0, 0x87, 0x22, 0x3a, 0x6f, 0x94, 0x4f, 0x73, 0xe9);

interface IVOCDefault : public IVOConstraintT<IVOCDefault>
{
    IFACEMETHOD_(IVOCDefault&, Default)(IVOBase* pDefault) = 0;
};

extern "C"
IVOCDefault* __stdcall VOCDefault();

//////////////////////////////////////////////////////////////////////////////////////
// {C6AD3380-8F1C-4A1A-9F98-6BF1C25345BD}
DEFINE_GUID(IID_IVOCCollate,
    0xc6ad3380, 0x8f1c, 0x4a1a, 0x9f, 0x98, 0x6b, 0xf1, 0xc2, 0x53, 0x45, 0xbd);

interface IVOCCollate : public IVOConstraintT<IVOCCollate>
{
    IFACEMETHOD_(IVOCCollate&, Collate)(LPCWSTR szCollationName, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCCollate&, Collate)(LPCSTR  szCollationName, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
};

extern "C"
IVOCCollate* __stdcall VOCCollate();

//////////////////////////////////////////////////////////////////////////////////////
interface IVOForeignKey;
// {F7E31553-6BD3-40A3-BE2A-D534C793C013}
DEFINE_GUID(IID_IVOCForeignKey,
    0xf7e31553, 0x6bd3, 0x40a3, 0xbe, 0x2a, 0xd5, 0x34, 0xc7, 0x93, 0xc0, 0x13);

interface IVOCForeignKey : public IVOConstraintT<IVOCForeignKey>
{
    IFACEMETHOD_(IVOCForeignKey&, ForeignKey)(IVOForeignKey* pForeignKey) = 0;
};

extern "C"
IVOCForeignKey* __stdcall VOCForeignKey();
#endif // !__IVO_COLUMNCONSTRAINT_H__

