/**              Copyright (c) 2017 Twinecoin Developers
 * The file is licenced under the MIT software license, see LICENCE
 * or http://www.opensource.org/licenses/mit-license.php.
 */
#ifndef TWINECONSENSUS_H
#define TWINECONSENSUS_H

#include <stdint.h>

#ifndef TW_LIBEXPORT
 #ifdef _WIN32
  #define TW_LIBEXPORT __declspec(dllexport)
 #else
  #define TW_LIBEXPORT __attribute__ ((visibility ("default")))
 #endif
#endif

typedef struct _tw_context tw_context;

/**  
 * Interface version test
 *
 * Tests if the library supports an interface version
 * 
 *   version:  The library version
 *   return:  non-zero if the version is supported
 */
TW_LIBEXPORT uint32_t twlib_test_version(uint32_t version);

/**
 * Creates a Twinecoin consensus context for a particular chain
 * 0: Main chain
 * 1: Test chain
 * 2: Regression test chain
 *
 * chain_id: the id of the chain for the context
 * return: a pointer to an initialized Twinecoin consensus context, or NULL if out of memory
 */
TW_LIBEXPORT tw_context* twlib_create_context(const uint32_t chain_id);

/**
 * Frees a Twinecoin consensus context
 *
 * context: a pointer to the Twinecoin consensus context to be freed
 */
TW_LIBEXPORT void twlib_free_context(tw_context* context);

/**
 * Checks POW header's proof of work
 *
 * return: 1 if the POW Header meets the claimed POW
 */
TW_LIBEXPORT uint32_t twlib_check_pow_header_pow(tw_context* context, const uint32_t length, const uint8_t* pow_header);

#endif
