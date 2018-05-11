/*               Copyright (c) 2017 Twinecoin Developers
 * The file is licenced under the MIT software license, see LICENCE
 * or http://www.opensource.org/licenses/mit-license.php.
 */
#ifndef TW_CONTEXT_H
#define TW_CONTEXT_H

#include "twineconsensus.h"
#include "tw_u256.h"

/* Get initialized twine consensus context
 * Returns an initialized twine consensus context
 */
tw_context* tw_create_context(const tw_u32 chain_id);

/* Frees a twine consensus context
 * free(context)
 */
void tw_free_context(tw_context* context);

#endif
