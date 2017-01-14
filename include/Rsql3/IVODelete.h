#ifndef __IVO_DELETE_H__
#define __IVO_DELETE_H__
#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOConditions.h>
#include <Rsql3/IVOTable.h>
// {69D7C382-DA6B-4137-8F16-A0E0184D598F}

template <typename T>
interface IVODeleteT
    : public IVOBase
{
    IFACEMETHOD_(T&, Delete)(IVOQuaTableName* pTable) = 0;
    IFACEMETHOD_(T&, Where)(IVOConditions* pConditions) = 0;
};

DEFINE_GUID(IID_IVODelete,
    0x69d7c382, 0xda6b, 0x4137, 0x8f, 0x16, 0xa0, 0xe0, 0x18, 0x4d, 0x59, 0x8f);

interface IVODelete
    : public IVODeleteT<IVODelete>
{};

extern "C"
IVODelete* __stdcall VODelete();

#include <Rsql3/IVOExtended.h>
// {C4D360B3-B76D-4D88-8896-445B58C3A56C}
DEFINE_GUID(IID_IVODeleteEx,
    0xc4d360b3, 0xb76d, 0x4d88, 0x88, 0x96, 0x44, 0x5b, 0x58, 0xc3, 0xa5, 0x6c);

interface IVODeleteEx
    : public IVODeleteT<IVODeleteEx>
    , public IVOExtendedT<IVODeleteEx>
{};

extern "C"
IVODeleteEx* __stdcall VODeleteEx();
#endif
