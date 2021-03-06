#ifndef SPX_UTILSX4_H
#define SPX_UTILSX4_H

#include <stdint.h>
#include "params.h"

/**
 * For a given leaf index, computes the authentication path and the resulting
 * root node using Merkle's TreeHash algorithm.
 * Expects the layer and tree parts of the tree_addr to be set, as well as the
 * tree type (i.e. SPX_ADDR_TYPE_HASHTREE or SPX_ADDR_TYPE_FORSTREE).
 * Applies the offset idx_offset to indices before building addresses, so that
 * it is possible to continue counting indices across trees.
 */
void treehashx4(unsigned char *rootx4, unsigned char *auth_pathx4,
                const unsigned char *sk_seed, const unsigned char *pub_seed,
                uint32_t leaf_idx[4], uint32_t idx_offset[4],
                uint32_t tree_height,
                void (*gen_leafx4)(
                   unsigned char* /* leaf0 */,
                   unsigned char* /* leaf1 */,
                   unsigned char* /* leaf2 */,
                   unsigned char* /* leaf3 */,
                   const unsigned char* /* sk_seed */,
                   const unsigned char* /* pub_seed */,
                   uint32_t /* addr_idx0 */,
                   uint32_t /* addr_idx1 */,
                   uint32_t /* addr_idx2 */,
                   uint32_t /* addr_idx3 */,
                   const uint32_t[8] /* tree_addr */),
                uint32_t tree_addrx4[4*8]);

#endif
