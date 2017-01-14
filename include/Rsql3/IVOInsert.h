#ifndef __IVO_INSERT_H__
#define __IVO_INSERT_H__
#include <Rsql3/IVOBase.h>
#include <Rsql3/IVOColumn.h>
// {3A7336D8-74ED-460E-B9AA-92E5DE2BE891}
DEFINE_GUID(IID_IVOInsert,
    0x3a7336d8, 0x74ed, 0x460e, 0xb9, 0xaa, 0x92, 0xe5, 0xde, 0x2b, 0xe8, 0x91);

namespace INSERT {
    enum TYPE
    {
        Only,        /* default ones */
        ReplaceInstead,
        OrReplace,
        OrAbort,
        OrFail,
        OrIgnore
    };

    enum WHAT
    {
        Value,       /* default ones; single value only, */
                           /* any call with the same IColumnName* will replace any previous value*/
        Values,      /* Multiple Values */
                           /* any call with the same IColumnName* will add more value*/
                           /* IColumnName* in the second call and later will be ignored */
                           /* User is advised to use any previous IColumnName* */
        Select,
        Default
    };
}
#define CONTINUE_PREV_ID (ULONG_PTR)-1
interface IVOInsert
    : public IVOBase
{
    IFACEMETHOD_(IVOInsert&, Insert)(INSERT::TYPE eType = INSERT::Only) = 0;
    IFACEMETHOD_(IVOInsert&, Insert)(INSERT::WHAT eWhat = INSERT::Value) = 0;

    // must be called first after settings above
    IFACEMETHOD_(IVOInsert&, ColumnLess)(BOOL bValue = TRUE) = 0;

    IFACEMETHOD_(IVOInsert&, Table)(IVOTableName* pTable) = 0;


    // only available on InsertWhat::InsertDefault
    IFACEMETHOD_(IVOInsert&, Column)(IVOColumnName* pColumName) = 0;

    // depend on the InsertWhat
    // on InsertWhat::InsertValue calling on the same ColumnName/index associated Values will be replaced
    // on InsertWhat::InsertValues calling on the same ColumnName/index associated Values will be added
    IFACEMETHOD_(IVOInsert&, Value)(IVOColumnName* pColumnName, IVOBase* pVO) = 0;
    IFACEMETHOD_(IVOInsert&, Value)(IVOBase* pValueObject, ULONG_PTR idx = CONTINUE_PREV_ID) = 0;

    // inserting a collection
    // only available on InsertWhat::InsertValues
    // the container will be emptied
    IFACEMETHOD_(IVOInsert&, Values)(IVOColumnName* pColumnName, IVOCollection* pCollection) = 0;

    IFACEMETHOD_(IVOInsert&, Select)(IVOSelect* pSelect) = 0;
};

extern "C"
IVOInsert* __stdcall VOInsert();
#endif
