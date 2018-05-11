/**              Copyright (c) 2017 Twinecoin Developers
 * The file is licenced under the MIT software license, see LICENCE
 * or http://www.opensource.org/licenses/mit-license.php.
 */
#include "twineconsensus.h"
#include "config.h"
#include "tw_context.h"

uint32_t twlib_test_version(const uint32_t version) {
  return version <= (uint32_t) TWCON_IF_VER;
}

tw_context* twlib_create_context(const uint32_t chain_id) {
  return tw_create_context(chain_id);
}

void twlib_free_context(tw_context* context) {
  tw_free_context(context);
}

uint32_t twlib_check_pow_header_pow(tw_context* context, const uint32_t length, const uint8_t* pow_header) {
  return tw_check_pow_header_pow(context, length, pow_header);
}
