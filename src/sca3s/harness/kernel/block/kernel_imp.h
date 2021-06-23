/* Copyright (C) 2018 SCARV project <info@scarv.org>
 *
 * Use of this source code is restricted per the MIT license, a copy of which 
 * can be found at https://opensource.org/licenses/MIT (or should be included 
 * as LICENSE.txt within the associated archive or repository).
 */

#ifndef __KERNEL_IMP_H
#define __KERNEL_IMP_H

// ============================================================================

/** @brief      The kernel name, e.g., 
  *             1) KERNEL_NAMEOF_GENERIC, for generic block cipher,
  *             2) KERNEL_NAMEOF_AES,     for AES     block cipher,
  *             3) ...
  */

#if !defined( KERNEL_NAMEOF     )
#define KERNEL_NAMEOF     ( KERNEL_NAMEOF_GENERIC )
#endif

/** @brief      The kernel mode, i.e., either
  *             1) KERNEL_MODEOF_ENC for encryption operation,
  *                or
  *             2) KERNEL_MODEOF_DEC for decryption operation.
  */

#if !defined( KERNEL_MODEOF     )
#define KERNEL_MODEOF   ( KERNEL_MODEOF_ENC )
#endif

/** @brief      Number of allocated bytes in register that contains (externally supplied) randomness.
  */

#if !defined( KERNEL_SIZEOF_R )
#define KERNEL_SIZEOF_R (  0 )
#endif

/** @brief      Number of allocated bytes in register that contains cipher key.
  */

#if !defined( KERNEL_SIZEOF_K )
#define KERNEL_SIZEOF_K ( 16 )
#endif

/** @brief      Number of allocated bytes in register that contains  plaintext block.
  */

#if !defined( KERNEL_SIZEOF_M )
#define KERNEL_SIZEOF_M ( 16 )
#endif

/** @brief      Number of allocated bytes in register that contains ciphertext block.
  */

#if !defined( KERNEL_SIZEOF_C )
#define KERNEL_SIZEOF_C ( 16 )
#endif

// ============================================================================

#endif
