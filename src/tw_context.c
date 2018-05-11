/**              Copyright (c) 2017 Twinecoin Developers
 * The file is licenced under the MIT software license, see LICENCE
 * or http://www.opensource.org/licenses/mit-license.php.
 */
#include <assert.h>
#include <stdlib.h>
#include "tw_context.h"

struct _tw_context {
  tw_u32 chain_id;
};

#include "twineconsensus.h"

tw_context* tw_create_context(const tw_u32 chain_id) {
  if (chain_id > 2) {
    return NULL;
  }
  tw_context* context = (tw_context*) malloc(sizeof(*context));
  if (context == NULL) {
    return NULL;
  }
  context->chain_id = chain_id;
  return context;
}

void tw_free_context(tw_context* context) {
  free(context);
}
