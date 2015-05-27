#include <stddef.h>
#ifdef __AVX2__
#include <immintrin.h>
#endif

#include "../include/libbase64.h"
#include "codec_choose.h"

extern const char base64_table_enc[];
extern const unsigned char base64_table_dec[];

void
base64_stream_encode_avx2 BASE64_ENC_PARAMS
{
#ifdef __AVX2__
	#include "enc/head.c"
	#include "enc/avx2.c"
	#include "enc/tail.c"
#else
	(void)state;
	(void)src;
	(void)srclen;
	(void)out;

	*outlen = 0;
#endif
}

int
base64_stream_decode_avx2 BASE64_DEC_PARAMS
{
#ifdef __AVX2__
	#include "dec/head.c"
	#include "dec/avx2.c"
	#include "dec/tail.c"
#else
	(void)state;
	(void)src;
	(void)srclen;
	(void)out;
	(void)outlen;

	return -1;
#endif
}
