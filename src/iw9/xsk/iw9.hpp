// Copyright 2022 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "utils/xsk/utils.hpp"

#include "disassembler.hpp"
#include "decompiler.hpp"
#include "resolver.hpp"
#include "context.hpp"

namespace xsk::gsc::iw9
{

constexpr std::uint32_t max_string_id = 0;

enum class opcode : std::uint8_t
{
    OP_CastFieldObject = 0x00,
    OP_SetLocalVariableFieldCached = 0x01,
    OP_plus = 0x02,
    OP_RemoveLocalVariables = 0x03,
    OP_EvalSelfFieldVariableRef = 0x04,
    OP_ScriptFarMethodChildThreadCall = 0x05,
    OP_GetGameRef = 0x06,
    OP_EvalAnimFieldVariable = 0x07,
    OP_EvalLevelFieldVariableRef = 0x08,
    OP_GetThisthread = 0x09,
    OP_greater = 0x0A,
    OP_waittillmatch = 0x0B,
    OP_shift_right = 0x0C,
    OP_dec = 0x0D,
    OP_JumpOnTrue = 0x0E,
    OP_bit_or = 0x0F,
    OP_equality = 0x10,
    OP_ClearLocalVariableFieldCached0 = 0x11,
    OP_notify = 0x12,
    OP_GetVector = 0x13,
    OP_ScriptMethodChildThreadCallPointer = 0x14,
    OP_PreScriptCall = 0x15,
    OP_GetByte = 0x16,
    OP_ScriptFarThreadCall = 0x17,
    OP_SetSelfFieldVariableField = 0x18,
    OP_JumpOnFalseExpr = 0x19,
    OP_GetUndefined = 0x1A,
    OP_jumpback = 0x1B,
    OP_JumpOnTrueExpr = 0x1C,
    OP_CallBuiltin = 0x1D,
    OP_SetLocalVariableFieldCached0 = 0x1E,
    OP_ClearFieldVariable = 0x1F,
    OP_GetLevel = 0x20,
    OP_size = 0x21,
    OP_SafeSetWaittillVariableFieldCached = 0x22,
    OP_AddArray = 0x23,
    OP_endon = 0x24,
    OP_EvalFieldVariable = 0x25,
    OP_shift_left = 0x26,
    OP_EvalLocalArrayRefCached0 = 0x27,
    OP_Return = 0x28,
    OP_CreateLocalVariable = 0x29,
    OP_SafeSetVariableFieldCached0 = 0x2A,
    OP_GetBuiltinFunction = 0x2B,
    OP_CallBuiltinMethodPointer = 0x2C,
    OP_GetSelfObject = 0x2D,
    OP_GetGame = 0x2E,
    OP_SetLevelFieldVariableField = 0x2F,
    OP_EvalArray = 0x30,
    OP_GetSelf = 0x31,
    OP_End = 0x32,
    OP_EvalSelfFieldVariable = 0x33,
    OP_less_equal = 0x34,
    OP_EvalLocalVariableCached0 = 0x35,
    OP_EvalLocalVariableCached1 = 0x36,
    OP_EvalLocalVariableCached2 = 0x37,
    OP_EvalLocalVariableCached3 = 0x38,
    OP_EvalLocalVariableCached4 = 0x39,
    OP_EvalLocalVariableCached5 = 0x3A,
    OP_EvalLocalVariableCached = 0x3B,
    OP_EvalNewLocalArrayRefCached0 = 0x3C,
    OP_ScriptChildThreadCallPointer = 0x3D,
    OP_EvalLocalVariableObjectCached = 0x3E,
    OP_GetInteger = 0x3F,
    OP_ScriptMethodCallPointer = 0x40,
    OP_checkclearparams = 0x41,
    OP_SetAnimFieldVariableField = 0x42,
    OP_waittillmatch2 = 0x43,
    OP_minus = 0x44,
    OP_GetNegUnsignedShort = 0x45,
    OP_GetNegByte = 0x46,
    OP_SafeCreateVariableFieldCached = 0x47,
    OP_greater_equal = 0x48,
    OP_vector = 0x49,
    OP_GetBuiltinMethod = 0x4A,
    OP_endswitch = 0x4B,
    OP_ClearArray = 0x4C,
    OP_DecTop = 0x4D,
    OP_CastBool = 0x4E,
    OP_EvalArrayRef = 0x4F,
    OP_SetNewLocalVariableFieldCached0 = 0x50,
    OP_GetZero = 0x51,
    OP_wait = 0x52,
    OP_waittill = 0x53,
    OP_GetIString = 0x54,
    OP_ScriptFarFunctionCall = 0x55,
    OP_GetAnimObject = 0x56,
    OP_GetAnimTree = 0x57,
    OP_EvalLocalArrayCached = 0x58,
    OP_mod = 0x59,
    OP_ScriptFarMethodThreadCall = 0x5A,
    OP_GetUnsignedShort = 0x5B,
    OP_clearparams = 0x5C,
    OP_ScriptMethodThreadCallPointer = 0x5D,
    OP_ScriptFunctionCallPointer = 0x5E,
    OP_EmptyArray = 0x5F,
    OP_SafeSetVariableFieldCached = 0x60,
    OP_ClearVariableField = 0x61,
    OP_EvalFieldVariableRef = 0x62,
    OP_EvalNewLocalVariableRefCached0 = 0x63,
    OP_GetFloat = 0x64,
    OP_EvalLocalVariableRefCached = 0x65,
    OP_JumpOnFalse = 0x66,
    OP_BoolComplement = 0x67,
    OP_ScriptThreadCallPointer = 0x68,
    OP_less = 0x69,
    OP_BoolNot = 0x6A,
    OP_waittillFrameEnd = 0x6B,
    OP_waitframe = 0x6C,
    OP_GetString = 0x6D,
    OP_EvalLevelFieldVariable = 0x6E,
    OP_GetLevelObject = 0x6F,
    OP_inc = 0x70,
    OP_CallBuiltinMethod = 0x71,
    OP_GetAnim = 0x72,
    OP_switch = 0x73,
    OP_SetVariableField = 0x74,
    OP_divide = 0x75,
    OP_ScriptFarChildThreadCall = 0x76,
    OP_multiply = 0x77,
    OP_ClearLocalVariableFieldCached = 0x78,
    OP_EvalAnimFieldVariableRef = 0x79,
    OP_EvalLocalArrayRefCached = 0x7A,
    OP_EvalLocalVariableRefCached0 = 0x7B,
    OP_bit_and = 0x7C,
    OP_GetAnimation = 0x7D,
    OP_GetFarFunction = 0x7E,
    OP_CallBuiltinPointer = 0x7F,
    OP_jump = 0x80,
    OP_voidCodepos = 0x81,
    OP_ScriptFarMethodCall = 0x82,
    OP_inequality = 0x83,
    OP_bit_ex_or = 0x84,
    OP_unk_133 = 0x85, // size 9
    OP_unk_134 = 0x86, // size 5
    OP_unk_135 = 0x87, // size 9
    OP_unk_136 = 0x88, // size 9
    OP_unk_137 = 0x89, // size 5
    OP_unk_138 = 0x8A, // size 9
    OP_unk_139 = 0x8B,
    OP_unk_140 = 0x8C,
    OP_unk_141 = 0x8D,
    OP_unk_142 = 0x8E,
    OP_unk_143 = 0x8F,
    OP_unk_144 = 0x90,
    OP_prof_begin = 0x91,
    OP_prof_end = 0x92,
    OP_breakpoint = 0x93,
    OP_assignmentBreakpoint = 0x94,
    OP_manualAndAssignmentBreakpoint = 0x95,
    OP_BoolNotAfterAnd = 0x96,
    OP_FormalParams = 0x97,
    OP_IsDefined = 0x98,
    OP_IsTrue = 0x99,
    OP_NativeGetFarFunction = 0x9A,
    OP_NativeFarFunctionCall = 0x9B,
    OP_NativeFarMethodCall = 0x9C,
    OP_NativeFarFunctionThreadCall = 0x9D,
    OP_NativeFarMethodThreadCall = 0x9E,
    OP_NativeFarFunctionChildThreadCall = 0x9F,
    OP_NativeFarMethodChildThreadCall = 0xA0,
    OP_EvalNewLocalArrayRefCached0_Precompiled = 0xA1,
    OP_SetNewLocalVariableFieldCached0_Precompiled = 0xA2,
    OP_CreateLocalVariable_Precompiled = 0xA3,
    OP_SafeCreateVariableFieldCached_Precompiled = 0xA4,
    OP_FormalParams_Precompiled = 0xA5,
    OP_unk_166 = 0xA6, // size 9, stack 8
    OP_count = 0xA7,
};

auto opcode_size(std::uint8_t op) -> std::uint32_t;

} // namespace xsk::gsc::iw9