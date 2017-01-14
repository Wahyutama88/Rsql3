#ifndef __IVALUE_OBJECTS_H__
#define __IVALUE_OBJECTS_H__

#include <Rsql3/Deallocator.h>

namespace VOType {
	enum INPUT
	{
		TEXT_LITERAL = 1,
		TEXT,         // with single quote
		INT64,
		INT,
		FLOAT,
		DOUBLE,
		NULL_,
		TEXT_LITERAL_UTF8,  // UTF8
		TEXT_UTF8,          // UTF8
		UINT,
		UINT64,
		COUNT,
	};
}
// {7A1F9404-7524-4C5E-9994-CFDF40B1F2CE}
DEFINE_GUID(IID_IVOBasic,
	0x7a1f9404, 0x7524, 0x4c5e, 0x99, 0x94, 0xcf, 0xdf, 0x40, 0xb1, 0xf2, 0xce);

#define NO_PRECISION -1
#define DEFAULT_PRECISION 3
interface IVOBasic
	: public IVOBase
{
	IFACEMETHOD_(VOType::INPUT, GetType)() = 0;
	IFACEMETHOD_(VOID, Replace)() = 0;
	IFACEMETHOD_(VOID, Replace)(DOUBLE _ddValue, DWORD dwPrecision) = 0;
	IFACEMETHOD_(VOID, Replace)(FLOAT ffValue, DWORD dwPrecision) = 0;
	IFACEMETHOD_(VOID, Replace)(INT iValue) = 0;
	IFACEMETHOD_(VOID, Replace)(INT64 i64Value) = 0;
	IFACEMETHOD_(VOID, Replace)(LPCWSTR szValue, BOOL bLiteral, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(VOID, Replace)(LPWSTR szValue, BOOL bLiteral, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(VOID, Replace)(LPCSTR szValue, BOOL bLiteral, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(VOID, Replace)(LPSTR szValue, BOOL bLiteral, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

extern "C"
{
	IVOBasic* __stdcall vo_dd(DOUBLE ddValue, UINT uPrecision = NO_PRECISION);
	IVOBasic* __stdcall vo_ff(FLOAT ffValue, UINT uPrecision = NO_PRECISION);
	IVOBasic* __stdcall vo_i(INT iValue);
	IVOBasic* __stdcall vo_ui(UINT uiValue);
	IVOBasic* __stdcall vo_i64(INT64 i64Value);
	IVOBasic* __stdcall vo_ui64(UINT64 ui64Value);
	IVOBasic* __stdcall vo(); // NULL
	IVOBasic* __stdcall vo_tl16(LPCWSTR szValue, DEALLOCATOR pDealloc = STATIC_COPY); // LITERAL UTF16
	IVOBasic* __stdcall vo_t16(LPCWSTR szValue, DEALLOCATOR pDealloc = STATIC_COPY);  // SINGLE QUOTED UTF16
	IVOBasic* __stdcall vo_tl(LPCSTR szValue, DEALLOCATOR pDealloc = STATIC_COPY); // LITERAL UTF8
	IVOBasic* __stdcall vo_t(LPCSTR szValue, DEALLOCATOR pDealloc = STATIC_COPY);  // SINGLE QUOTED UTF8

	// long name equivalent
	IVOBasic* __stdcall vo_double(DOUBLE ddValue, DWORD dwPrecision = NO_PRECISION);
	IVOBasic* __stdcall vo_float(FLOAT ffValue, DWORD dwPrecision = NO_PRECISION);
	IVOBasic* __stdcall vo_int(INT iValue);
	IVOBasic* __stdcall vo_uint(UINT uiValue);
	IVOBasic* __stdcall vo_int64(INT64 i64Value);
	IVOBasic* __stdcall vo_uint64(UINT64 ui64Value);
	IVOBasic* __stdcall vo_null(); // NULL
	IVOBasic* __stdcall vo_text_literal16(LPCWSTR szValue, DEALLOCATOR pDealloc = STATIC_COPY); // LITERAL UTF16
	IVOBasic* __stdcall vo_text16(LPCWSTR szValue, DEALLOCATOR pDealloc = STATIC_COPY);  // QUOTED UTF16
	IVOBasic* __stdcall vo_text_literal(LPCSTR szValue, DEALLOCATOR pDealloc = STATIC_COPY); // LITERAL UTF8
	IVOBasic* __stdcall vo_text(LPCSTR szValue, DEALLOCATOR pDealloc = STATIC_COPY);  // QUOTED UTF8

	IVOBase* __stdcall vo_varchar(UINT64 uiValue);
	IVOBase* __cdecl vo_function(const char* functionName, INT iParamCount, ...);
	IVOBase* __cdecl vo_function16(const wchar_t* functionName, INT iParamCount, ...);

	IVOBase* __stdcall vo_count(IVOBase* pVO = vo_tl("*"));
	IVOBase* __stdcall vo_count_distinct(IVOBase* pVO);


	//IVOBasic * __stdcall vo_date(INT iYear, INT iMonth, INT iDay);
	//IVOBasic * __stdcall vo_time24(INT iHour, INT iMinutes, INT iSeconds);
	//IVOBasic * __stdcall vo_datetime(INT iYear, INT iMonth, INT iDay, INT iHour = 0, INT iMinutes = 0, INT iSeconds = 0);
}

///////////////////////////////////////////////////////////////////////////////////
// {F63B1C06-9D20-4957-B6F0-1542774B9647}
DEFINE_GUID(IID_IVOCollection,
	0xf63b1c06, 0x9d20, 0x4957, 0xb6, 0xf0, 0x15, 0x42, 0x77, 0x4b, 0x96, 0x47);
// structure as follows
// [name][space][bracket][member1][separator]...[separator][memberN][bracket]
// separator default : , (comma with trailing space)
// Extract means the member is given to the caller it's no longer in collection
interface IVOCollection
	: public IVOBase
{
	IFACEMETHOD_(IVOCollection&, Add)(IVOBase* pValueObject, REFIID RefiidValidate = IID_IVOBase) = 0;
	IFACEMETHOD_(IVOCollection&, UseBracket)(BOOL bValue) = 0;
	IFACEMETHOD_(IVOCollection&, Separator)(IVOBase* pSeparator) = 0;
	IFACEMETHOD_(IVOCollection&, Name)(IVOBase* pName, BOOL bSpace = TRUE) = 0;

	IFACEMETHOD_(IVOBase*, GetVO)(ULONG_PTR UlID) = 0;
	IFACEMETHOD_(IVOBase*, Extract)(ULONG_PTR idx) = 0;
	IFACEMETHOD_(BOOL, Replace)(ULONG_PTR idx, IVOBase* pValueObject) = 0; // 0 based
	IFACEMETHOD_(SIZE_T, Size)() = 0;
	IFACEMETHOD_(BOOL, ResetName)() = 0;
	IFACEMETHOD_(BOOL, ResetSeparator)() = 0;
	IFACEMETHOD_(BOOL, ResetContent)() = 0;

};

///////////////////////////////////////////////////////////////////////////////////
// {12659FF9-CFF0-4406-B745-7827302BCA47}
DEFINE_GUID(IID_IVOLiteral,
	0x12659ff9, 0xcff0, 0x4406, 0xb7, 0x45, 0x78, 0x27, 0x30, 0x2b, 0xca, 0x47);

interface IVOLiteral
	: public IVOBase
{
	IFACEMETHOD_(IVOLiteral&, Literal)(LPCWSTR szVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(IVOLiteral&, Literal)(LPCSTR szVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

extern "C"
IVOLiteral* __stdcall VOLiteral();
///////////////////////////////////////////////////////////////////////////////////
// {9F6A7A9B-D78C-4CA4-9830-21D221468728}
DEFINE_GUID(IID_IVOText,
	0x9f6a7a9b, 0xd78c, 0x4ca4, 0x98, 0x30, 0x21, 0xd2, 0x21, 0x46, 0x87, 0x28);

interface IVOText
	: public IVOBase
{
	// might return VOType::INPUT_NULL after reset
	IFACEMETHOD_(VOType::INPUT, GetType)() = 0;
	IFACEMETHOD_(IVOText&, Text)(LPCWSTR szVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(IVOText&, Text)(LPCSTR szVO, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(IVOText&, AsLiteral)(BOOL bValue) = 0;
};

extern "C"
IVOText* __stdcall VOText();

///////////////////////////////////////////////////////////////////////////////////
// {EF819B94-2A9F-46BD-B445-A34ADA4ED136}
DEFINE_GUID(IID_IVOFunction,
	0xef819b94, 0x2a9f, 0x46bd, 0xb4, 0x45, 0xa3, 0x4a, 0xda, 0x4e, 0xd1, 0x36);

interface IVOFunction
	: public IVOBase
{
	IFACEMETHOD_(IVOFunction&, Distinct)(BOOL bValue = TRUE) = 0;
	IFACEMETHOD_(IVOFunction&, Name)(LPCWSTR szName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(IVOFunction&, Name)(LPCSTR szName, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(IVOFunction&, Param)(IVOBase* pVOParam) = 0;
	IFACEMETHOD_(VOID, ResetParams)() = 0;
};

extern "C"
IVOFunction* __stdcall VOFunction();

//////////////////////////////////////////////////////////////////////////
// special operator section
//////////////////////////////////////////////////////////////////////////
// {B88ABCEE-59CE-4484-ABC9-56C919CEBD53}
DEFINE_GUID(IID_IVOBetween,
	0xb88abcee, 0x59ce, 0x4484, 0xab, 0xc9, 0x56, 0xc9, 0x19, 0xce, 0xbd, 0x53);

interface IVOBetween
	: public IVOBase
{
	// any prev value will be replaced if any
	IFACEMETHOD_(IVOBetween&, Between)(IVOBase* pValueObject1, IVOBase* pValueObject2) = 0;
	IFACEMETHOD_(IVOBetween&, Not)(BOOL bValue = TRUE) = 0;
};

extern "C"
IVOBetween* __stdcall VOBetween();


//////////////////////////////////////////////////////////////////////////
// {06B2A5A4-6DA7-4ADB-9E3D-B9C7D5F29E6E}
DEFINE_GUID(IID_IVOIn,
	0x6b2a5a4, 0x6da7, 0x4adb, 0x9e, 0x3d, 0xb9, 0xc7, 0xd5, 0xf2, 0x9e, 0x6e);


interface IVOSelect;
interface IVOTableName;
interface IVOIn
	: public IVOBase
{
	IFACEMETHOD_(IVOIn&, Not)(BOOL bValue = TRUE) = 0;

	// mutual exclusive
	IFACEMETHOD_(IVOIn&, In)(IVOCollection* pRaidVO) = 0;
	IFACEMETHOD_(IVOIn&, In)(IVOTableName* pTable) = 0;
	IFACEMETHOD_(IVOIn&, In)(IVOSelect* pSelect) = 0;
};

extern "C"
IVOIn* __stdcall VOIn();

//////////////////////////////////////////////////////////////////////////
// {F2ED1D70-63C5-4BB6-9C9B-1DCCEA879671}
DEFINE_GUID(IID_IVOLike,
	0xf2ed1d70, 0x63c5, 0x4bb6, 0x9c, 0x9b, 0x1d, 0xcc, 0xea, 0x87, 0x96, 0x71);

interface IVOLike
	: public IVOBase
{
	IFACEMETHOD_(IVOLike&, Not)(BOOL bValue = TRUE) = 0;
	IFACEMETHOD_(IVOLike&, Like)(LPCWSTR szLike, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(IVOLike&, Like)(LPCSTR szLike, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

extern "C"
IVOLike* __stdcall VOLike();
//////////////////////////////////////////////////////////////////////////
// {C29E2D07-3D73-4DE3-9061-A871A7A898D1}
DEFINE_GUID(IID_IVOGlob,
	0xc29e2d07, 0x3d73, 0x4de3, 0x90, 0x61, 0xa8, 0x71, 0xa7, 0xa8, 0x98, 0xd1);

interface IVOGlob
	: public IVOBase
{
	IFACEMETHOD_(IVOGlob&, Not)(BOOL bValue = TRUE) = 0;
	IFACEMETHOD_(IVOGlob&, Glob)(LPCWSTR szGlob, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(IVOGlob&, Glob)(LPCSTR szGlob, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

extern "C"
IVOGlob* __stdcall VOGlob();
//////////////////////////////////////////////////////////////////////////
// {68D1F5B3-4F56-4FCD-A993-8D21423DD954}
DEFINE_GUID(IID_IVOAlias,
	0x68d1f5b3, 0x4f56, 0x4fcd, 0xa9, 0x93, 0x8d, 0x21, 0x42, 0x3d, 0xd9, 0x54);

interface IVOAlias
	: public IVOBase
{
	IFACEMETHOD_(IVOAlias&, AS)(LPCWSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(IVOAlias&, AS)(LPCSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(const IVOLiteral*, GetAlias)() = 0;
};

extern "C"
IVOAlias* __stdcall VOAlias();
extern "C"
{
	IVOAlias* __stdcall vo_as(LPCSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY);
	IVOAlias* __stdcall vo_as16(LPCWSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY);
}
//////////////////////////////////////////////////////////////////////////
// {52989AAE-9592-4B50-82D8-96DD3B8820EF}
DEFINE_GUID(IID_IVOAliasEx,
	0x52989aae, 0x9592, 0x4b50, 0x82, 0xd8, 0x96, 0xdd, 0x3b, 0x88, 0x20, 0xef);


interface IVOAliasEx
	: public IVOBase
{
	IFACEMETHOD_(IVOAliasEx&, IVO)(IVOBase* pVO) = 0;
	IFACEMETHOD_(IVOAliasEx&, Alias)(IVOAlias* pAlias) = 0;
	IFACEMETHOD_(IVOAliasEx&, Alias)(LPCWSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
	IFACEMETHOD_(IVOAliasEx&, Alias)(LPCSTR szAlias, DEALLOCATOR pDealloc = STATIC_COPY) = 0;
};

extern "C"
IVOAliasEx* __stdcall VOAliasEx();

//////////////////////////////////////////////////////////////////////////
// {A6870AD3-B8E3-44D5-B80A-A4E96541914B}
DEFINE_GUID(IID_IVOImplode,
	0xa6870ad3, 0xb8e3, 0x44d5, 0xb8, 0xa, 0xa4, 0xe9, 0x65, 0x41, 0x91, 0x4b);

interface IVOImplode
	: public IVOCollection
{
	// single
	IFACEMETHOD_(IVOImplode&, Delimiter)(IVOBasic* pDelim) = 0;
	// multiple times
	IFACEMETHOD_(IVOImplode&, IVO)(IVOBase* pVO) = 0;
};

extern "C"
IVOImplode* __stdcall VOImplode();

//////////////////////////////////////////////////////////////////////////
// {CB8A714B-DB10-486C-BAED-92AEA01214CD}
DEFINE_GUID(IID_IVOPair,
	0xcb8a714b, 0xdb10, 0x486c, 0xba, 0xed, 0x92, 0xae, 0xa0, 0x12, 0x14, 0xcd);

interface IVOPair
	: public IVOBase
{
	IFACEMETHOD_(IVOPair&, IVO1)(IVOBase* pVO1) = 0;
	IFACEMETHOD_(IVOPair&, IVO2)(IVOBase* pVO2) = 0;
	IFACEMETHOD_(IVOPair&, Delimiter)(IVOBase* pDelim) = 0;
};

extern "C"
{
	IVOPair* __stdcall VOPair();
	IVOPair* __stdcall vo_pair(IVOBase* pVO1, IVOBase* pVO2);
}

#include <Rsql3/Enums.h>
//////////////////////////////////////////////////////////////////////////
// {1C69F6BA-C68A-43C9-A2B6-4BF3D73E575D}
DEFINE_GUID(IID_IVOOperator,
	0x1c69f6ba, 0xc68a, 0x43c9, 0xa2, 0xb6, 0x4b, 0xf3, 0xd7, 0x3e, 0x57, 0x5d);

interface IVOOperator
	: public IVOBase
{
	IFACEMETHOD_(IVOOperator&, Operator)(OPERATOR::TYPE eOperator) = 0;
};

extern "C"
{
	IVOOperator* __stdcall VOOperator();

	IVOOperator* __stdcall vo_operator(OPERATOR::TYPE eOperator);
}

//////////////////////////////////////////////////////////////////////////
// {7203F2CD-E61D-41FF-A083-6E0EDCD57852}
DEFINE_GUID(IID_IVOBracket,
	0x7203f2cd, 0xe61d, 0x41ff, 0xa0, 0x83, 0x6e, 0xe, 0xdc, 0xd5, 0x78, 0x52);

interface IVOBracket
	: public IVOBase
{
	IFACEMETHOD_(IVOBracket&, IVO)(IVOBase* pVO) = 0;
	IFACEMETHOD_(IVOBase*, GetVO)() = 0;

};

extern "C"
{
	IVOBracket* __stdcall VOBracket();
	IVOBracket* __stdcall vo_bracket(IVOBase* pVO);
}

//////////////////////////////////////////////////////////////////////////
// {53CDFA7E-64D6-420B-8133-DEC72A8526CF}
DEFINE_GUID(IID_IVOIs,
	0x53cdfa7e, 0x64d6, 0x420b, 0x81, 0x33, 0xde, 0xc7, 0x2a, 0x85, 0x26, 0xcf);

interface IVOIs
	: public IVOBase
{
	IFACEMETHOD_(IVOIs&, Is)(BOOL bValue = TRUE) = 0;
	IFACEMETHOD_(IVOIs&, Not)(BOOL bValue = TRUE) = 0;

	// mutual exclusive
	IFACEMETHOD_(IVOIs&, Null)(BOOL bValue = TRUE) = 0;
	IFACEMETHOD_(IVOIs&, Expr)(IVOBase* pVO) = 0;
};
extern "C"
{
	IVOIs* __stdcall VOIs();
	IVOIs* __stdcall vo_is_null();
	IVOIs* __stdcall vo_is_not_null();
	IVOIs* __stdcall vo_is(IVOBase* pVO);
}

//////////////////////////////////////////////////////////////////////////
// {B8949077-C339-4D58-B432-B19810F20222}
DEFINE_GUID(IID_IVOEXISTS,
	0xb8949077, 0xc339, 0x4d58, 0xb4, 0x32, 0xb1, 0x98, 0x10, 0xf2, 0x2, 0x22);

interface IVOExists
	: public IVOBase
{
	IFACEMETHOD_(IVOExists&, Not)(BOOL value = TRUE) = 0;
};

extern "C"
{
	IVOExists* __stdcall VOExists();
	IVOExists* __stdcall vo_exists();
	IVOExists* __stdcall vo_not_exists();
}

#endif

