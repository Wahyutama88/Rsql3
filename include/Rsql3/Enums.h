#ifndef __RSQL3_ENUMS_H__
#define __RSQL3_ENUMS_H__

namespace OPERATOR {
    enum TYPE
    {
        NULLS,
        // Comparison
        EQUALS = 1,
        NOT_EQUALS,
        GREATER_THAN,
        GREATER_OR_EQUALS,
        NOT_GREATER_THAN,
        LESS_THAN,
        LESS_OR_EQUALS,
        NOT_LESS_THAN,

        // Logical
        AND,
        OR
    };
};

namespace DATA {
    enum TYPES : CHAR
    {
        NULL_,
        INTEGER,
        TEXT,
        BLOB,
        REAL
    };
}
namespace CONFLICT {
    enum CLAUSE : CHAR
    {
        DO_NOTHING,
        ROLLBACK,
        ABORT,
        FAIL,
        IGNORE_,
        REPLACE
    };
}
namespace SORT {
    enum ORDER : CHAR
    {
        NONE,
        ASC,
        DESC
    };
}

namespace FOREIGN {
    enum ACTION : CHAR
    {
        SET_NULL,
        SET_DEFAULT,
        CASCADE,
        RESTRICT,
        NO_ACTION
    };
    namespace INITIAL {
        enum ACTION : CHAR
        {
            NOTHING,
            DEFERRED,
            IMMEDIATE
        };
    }
}
namespace UNION {
    enum TYPE : CHAR
    {
        NOTHING,
        UNION,
        ALL,
        INTERSECT,
        EXCEPT,
    };
}
#endif