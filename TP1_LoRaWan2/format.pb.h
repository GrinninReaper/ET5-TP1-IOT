/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.1 */

#ifndef PB_POLYTECH_FORMAT_PB_H_INCLUDED
#define PB_POLYTECH_FORMAT_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _polytech_Uplink {
    char data[24];
    uint32_t noseq;
    char sender[10];
    uint32_t tmst;
} polytech_Uplink;


/* Initializer values for message structs */
#define polytech_Uplink_init_default             {"", 0, "", 0}
#define polytech_Uplink_init_zero                {"", 0, "", 0}

/* Field tags (for use in manual encoding/decoding) */
#define polytech_Uplink_data_tag                 1
#define polytech_Uplink_noseq_tag                2
#define polytech_Uplink_sender_tag               3
#define polytech_Uplink_tmst_tag                 4

/* Struct field encoding specification for nanopb */
#define polytech_Uplink_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   data,              1) \
X(a, STATIC,   SINGULAR, UINT32,   noseq,             2) \
X(a, STATIC,   SINGULAR, STRING,   sender,            3) \
X(a, STATIC,   SINGULAR, UINT32,   tmst,              4)
#define polytech_Uplink_CALLBACK NULL
#define polytech_Uplink_DEFAULT NULL

extern const pb_msgdesc_t polytech_Uplink_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define polytech_Uplink_fields &polytech_Uplink_msg

/* Maximum encoded size of messages (where known) */
#define polytech_Uplink_size                     48

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif