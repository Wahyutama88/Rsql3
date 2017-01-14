#ifndef __IVO_UPDATE_H__
#define __IVO_UPDATE_H__
#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOColumn.h>
#include <Rsql3/IVOConditions.h>
#include <Rsql3/IVOExtended.h>

template <typename T>
interface IVOUpdateBase
    : public IVOBase
{
    IFACEMETHOD_(T&, Update)(IVOQuaTableName* pTable) = 0;
    // can be called multiple times
    IFACEMETHOD_(T&, Set)(IVOColumnName* pColumn, IVOBase* pValue) = 0;
    // can be ommited
    IFACEMETHOD_(T&, Where)(IVOConditions* pConditions) = 0;

    // only when needed
    IFACEMETHOD_(T&, OrRollback)() = 0;
    IFACEMETHOD_(T&, OrAbort)() = 0;
    IFACEMETHOD_(T&, OrReplace)() = 0;
    IFACEMETHOD_(T&, OrFail)() = 0;
    IFACEMETHOD_(T&, OrIgnore)() = 0;
    // to reset methods above
    IFACEMETHOD_(T&, Only)() = 0;
};

// {0B805E36-7696-450C-A307-EE01A84818AC}
DEFINE_GUID(IID_IVOUpdate,
    0xb805e36, 0x7696, 0x450c, 0xa3, 0x7, 0xee, 0x1, 0xa8, 0x48, 0x18, 0xac);

interface IVOUpdate
    : public IVOUpdateBase<IVOUpdate> {};

extern "C"
IVOUpdate* __stdcall VOUpdate();

// {BBDED656-8EF1-4A53-B7B0-D42DF7FED2CC}
DEFINE_GUID(IID_IVOUpdateEx,
    0xbbded656, 0x8ef1, 0x4a53, 0xb7, 0xb0, 0xd4, 0x2d, 0xf7, 0xfe, 0xd2, 0xcc);


interface IVOUpdateEx
    : public IVOUpdateBase<IVOUpdateEx>
    , public IVOExtendedT<IVOUpdateEx> {};

extern "C"
IVOUpdateEx* __stdcall VOUpdateEx();
#endif


