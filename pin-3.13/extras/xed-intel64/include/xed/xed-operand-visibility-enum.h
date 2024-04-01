/*BEGIN_LEGAL 
Copyright 2002-2019 Intel Corporation.

This software and the related documents are Intel copyrighted materials, and your
use of them is governed by the express license under which they were provided to
you ("License"). Unless the License provides otherwise, you may not use, modify,
copy, publish, distribute, disclose or transmit this software or the related
documents without Intel's prior written permission.

This software and the related documents are provided as is, with no express or
implied warranties, other than those that are expressly stated in the License.
END_LEGAL */
/// @file xed-operand-visibility-enum.h

// This file was automatically generated.
// Do not edit this file.

#if !defined(XED_OPERAND_VISIBILITY_ENUM_H)
# define XED_OPERAND_VISIBILITY_ENUM_H
#include "xed-common-hdrs.h"
typedef enum {
  XED_OPVIS_INVALID,
  XED_OPVIS_EXPLICIT, ///< Shows up in operand encoding
  XED_OPVIS_IMPLICIT, ///< Part of the opcode, but listed as an operand
  XED_OPVIS_SUPPRESSED, ///< Part of the opcode, but not typically listed as an operand
  XED_OPVIS_LAST
} xed_operand_visibility_enum_t;

/// This converts strings to #xed_operand_visibility_enum_t types.
/// @param s A C-string.
/// @return #xed_operand_visibility_enum_t
/// @ingroup ENUM
XED_DLL_EXPORT xed_operand_visibility_enum_t str2xed_operand_visibility_enum_t(const char* s);
/// This converts strings to #xed_operand_visibility_enum_t types.
/// @param p An enumeration element of type xed_operand_visibility_enum_t.
/// @return string
/// @ingroup ENUM
XED_DLL_EXPORT const char* xed_operand_visibility_enum_t2str(const xed_operand_visibility_enum_t p);

/// Returns the last element of the enumeration
/// @return xed_operand_visibility_enum_t The last element of the enumeration.
/// @ingroup ENUM
XED_DLL_EXPORT xed_operand_visibility_enum_t xed_operand_visibility_enum_t_last(void);
#endif
