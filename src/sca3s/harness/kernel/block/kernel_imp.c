/* Copyright (C) 2018 SCARV project <info@scarv.org>
 *
 * Use of this source code is restricted per the MIT license, a copy of which 
 * can be found at https://opensource.org/licenses/MIT (or should be included 
 * as LICENSE.txt within the associated archive or repository).
 */

#include "kernel_imp.h"

#include "kernel_imp.h_harness"
#include "kernel_imp.c_harness"

// ============================================================================

   keyInstance    key_state;
cipherInstance cipher_state;

// ----------------------------------------------------------------------------

/** @brief      Execute the kernel prologue,
  *             e.g., any  pre-execution steps such as   allocation of memory.
  *
  * @return     an instance of \c kernel_fec_t, 
  *             e.g.,
  *             \c KERNEL_FEC_FAILURE to indicate failure
  *             or 
  *             \c KERNEL_FEC_SUCCESS to indicate success;
  *             this is captured in \c fec, the function exit code register.
  *
  * @note       Execution of this function is excluded from the trigger period.
  */

kernel_fec_t kernel_prologue() {
  char t[ 2 * KERNEL_SIZEOF_K + 1 ];

  for( int i = 0; i < KERNEL_SIZEOF_K; i++ ) {
    t[ 2 * i + 0 ] = itox( ( k[ i ] >> 0 ) & 0xF );
    t[ 2 * i + 1 ] = itox( ( k[ i ] >> 4 ) & 0xF );
  }

  t[ 2 * KERNEL_SIZEOF_K ] = '\x00';

     key_state.blockLen = 8 * KERNEL_SIZEOF_K;
  cipher_state.blockLen = 8 * KERNEL_SIZEOF_M;

  if( 0 >= makeKey( &key_state, DIR_ENCRYPT, 8 * KERNEL_SIZEOF_K, t ) ) {
    return KERNEL_FEC_FAILURE;
  }

  if( 0 >= cipherInit( &cipher_state, MODE_ECB, NULL ) ) {
    return KERNEL_FEC_FAILURE;
  }

  return KERNEL_FEC_SUCCESS;
}

/** @brief      Execute the kernel itself.
  *
  * @return     an instance of \c kernel_fec_t, 
  *             e.g.,
  *             \c KERNEL_FEC_FAILURE to indicate failure
  *             or 
  *             \c KERNEL_FEC_SUCCESS to indicate success;
  *             this is captured in \c fec, the function exit code register.
  *
  * @note       Execution of this function is included in   the trigger period.
  *
  * @note       The kernel  input is:
  *             \c k of length \c KERNEL_SIZEOF_K bytes,
  *             and
  *             either
  *             \c m of length \c KERNEL_SIZEOF_M bytes
  *             or 
  *             \c c of length \c KERNEL_SIZEOF_C bytes
  *             depending on the kernel mode.
  *
  * @note       The kernel output is:
  *             either
  *             \c c of length \c KERNEL_SIZEOF_C bytes
  *             or 
  *             \c m of length \c KERNEL_SIZEOF_M bytes
  *             depending on the kernel mode.
  */

kernel_fec_t kernel() {
  if( 0 >= blockEncrypt( &cipher_state, &key_state, m, 8 * KERNEL_SIZEOF_M, c ) ) {
    return KERNEL_FEC_FAILURE;
  }
  else {
    return KERNEL_FEC_SUCCESS;
  }
}

/** @brief      Execute the kernel epilogue,
  *             e.g., any post-execution steps such as deallocation of memory.
  *
  * @return     an instance of \c kernel_fec_t, 
  *             e.g.,
  *             \c KERNEL_FEC_FAILURE to indicate failure
  *             or 
  *             \c KERNEL_FEC_SUCCESS to indicate success;
  *             this is captured in \c fec, the function exit code register.
  *
  * @note       Execution of this function is excluded from the trigger period.
  */

kernel_fec_t kernel_epilogue() {
  return KERNEL_FEC_SUCCESS;
}

// ============================================================================
