#ifndef __IVO_FOREIGNKEYWORDS_H__
#define __IVO_FOREIGNKEYWORDS_H__

#include <Rsql3/IVOBase.h>
#include <Rsql3/Deallocator.h>
#include <Rsql3/Enums.h>
#include <Rsql3/IVOColumn.h>
// {1F24D639-6585-4ADF-9ACE-AE8D539C951F}
DEFINE_GUID(IID_IVOForeignKey,
    0x1f24d639, 0x6585, 0x4adf, 0x9a, 0xce, 0xae, 0x8d, 0x53, 0x9c, 0x95, 0x1f);

interface IVOForeignKey
    : public IVOBase
{
    IFACEMETHOD_(IVOForeignKey&, Table)(LPCWSTR szTableName, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOForeignKey&, Table)(LPCSTR szTableName, DEALLOCATOR pDeallocator = STATIC_COPY) = 0;
    // multiple times
    IFACEMETHOD_(IVOForeignKey&, ColumName)(IVOColumnName* pColumn) = 0;

    // only call if needed
    IFACEMETHOD_(IVOForeignKey&, OnDelete)(FOREIGN::ACTION eForeignAct) = 0;
    IFACEMETHOD_(IVOForeignKey&, OnUpdate)(FOREIGN::ACTION eForeignAct) = 0;
    IFACEMETHOD_(IVOForeignKey&, Deferable)(FOREIGN::INITIAL::ACTION eForeignInitAct) = 0;
    IFACEMETHOD_(IVOForeignKey&, NotDeferable)(FOREIGN::INITIAL::ACTION eForeignInitAct) = 0;
};

extern "C"
IVOForeignKey* __stdcall VOForeignKey();

#endif
