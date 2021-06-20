// Copyright 2019 E.

#ifndef MEMELANG_CONSTANTS_H
#define MEMELANG_CONSTANTS_H

#include <map>
#include <string>

namespace memelang {

inline const char* BOOL = "bool";
inline const char* I8 = "i8";
inline const char* I16 = "i16";
inline const char* I32 = "i32";
inline const char* I64 = "i64";
inline const char* U8 = "u8";
inline const char* U16 = "u16";
inline const char* U32 = "u32";
inline const char* U64 = "u64";
inline const char* F32 = "f32";
inline const char* F64 = "f64";

inline const char* BUILTIN_FNS[] = {"printf", "readf", "_malloc", "sizeof"};
inline const char* BUILTIN_TYPES[] = {BOOL, I8, I16, I32, I64, U8, U16, U32, U64, F32, F64};
const std::map<std::string, int> BUILTIN_SIZE = {{BOOL, 1}, {I8, 1}, {I16, 2}, {I32, 4}, {I64, 8},
    {U8, 1}, {U16, 2}, {U32, 4}, {U64, 8}, {F32, 4}, {F64, 8}};

}  // namespace memelang

#endif  // MEMELANG_CONSTANTS_H
