#ifndef __IVO_CREATE_TRIGGER_H__
#define __IVO_CREATE_TRIGGER_H__

#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOColumn.h>
#include <Rsql3/IVOConditions.h>
#include <Rsql3/IVOUpdate.h>
#include <Rsql3/IVOInsert.h>
#include <Rsql3/IVODelete.h>
#include <Rsql3/IVOSelect.h>

// {2D23CD16-E3F8-42C6-8C7F-EA4AA318AEFA}
DEFINE_GUID(IID_IVOCreateTrigger,
    0x2d23cd16, 0xe3f8, 0x42c6, 0x8c, 0x7f, 0xea, 0x4a, 0xa3, 0x18, 0xae, 0xfa);

interface IVOCreateTrigger
    : public IVOBase
{
    IFACEMETHOD_(IVOCreateTrigger&, Temporary)(BOOL bValue = TRUE) = 0;
    IFACEMETHOD_(IVOCreateTrigger&, IfNotExist)(BOOL bValue = TRUE) = 0;

    IFACEMETHOD_(IVOCreateTrigger&, Schema)(LPCWSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateTrigger&, Schema)(LPCSTR szSchema, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    IFACEMETHOD_(IVOCreateTrigger&, Trigger)(LPCWSTR szTrigger, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateTrigger&, Trigger)(LPCSTR szTrigger, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    IFACEMETHOD_(IVOCreateTrigger&, NoPreCondition)() = 0; /*default*/
    IFACEMETHOD_(IVOCreateTrigger&, Before)() = 0;
    IFACEMETHOD_(IVOCreateTrigger&, After)() = 0;
    IFACEMETHOD_(IVOCreateTrigger&, InsteadOf)() = 0;

    IFACEMETHOD_(IVOCreateTrigger&, Delete)() = 0;
    IFACEMETHOD_(IVOCreateTrigger&, Insert)() = 0;
    IFACEMETHOD_(IVOCreateTrigger&, Update)() = 0;
    IFACEMETHOD_(IVOCreateTrigger&, OfColumn)(IVOColumnName* pColumn) = 0;

    IFACEMETHOD_(IVOCreateTrigger&, OnTable)(LPCWSTR szTable, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
    IFACEMETHOD_(IVOCreateTrigger&, OnTable)(LPCSTR szTable, DEALLOCATOR pDealloc = STATIC_COPY) = 0;

    IFACEMETHOD_(IVOCreateTrigger&, ForEachRow)(BOOL bValue = TRUE) = 0;

    IFACEMETHOD_(IVOCreateTrigger&, When)(IVOConditions* pConditions) = 0;

    IFACEMETHOD_(IVOCreateTrigger&, Stmt)(IVOUpdate* pUpdate) = 0;
    IFACEMETHOD_(IVOCreateTrigger&, Stmt)(IVOUpdateEx* pUpdateEx) = 0;
    IFACEMETHOD_(IVOCreateTrigger&, Stmt)(IVOInsert* pInsert) = 0;
    IFACEMETHOD_(IVOCreateTrigger&, Stmt)(IVODelete* pDelete) = 0;
    IFACEMETHOD_(IVOCreateTrigger&, Stmt)(IVODeleteEx* pDeleteEx) = 0;
    IFACEMETHOD_(IVOCreateTrigger&, Stmt)(IVOSelect* pSelect) = 0;

    IFACEMETHOD_(VOID, ResetStmt)() = 0;
};
#endif
