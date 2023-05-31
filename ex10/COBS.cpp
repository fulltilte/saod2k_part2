#include "COBS.h"
#include "stdafx.h"

unsigned COBSEncode(const unsigned char* src, unsigned  len, unsigned char* dst, unsigned char r) {
	unsigned code_index = 0;
	unsigned src_index = 0;
	unsigned dst_index = 1;
	unsigned code = 1;

	while (src_index < len) {
		if (src[src_index] == r) {
			dst[code_index] = code;
			code = 1;
			code_index = dst_index++;
			src_index++;
		}

		else {
			dst[dst_index++] = src[src_index++];
			code++;

			if (code == 0xff) {
				dst[code_index] = code;
				code = 1;
				code_index = dst_index++;
			}
		}
	}

	dst[code_index] = code;
	return dst_index;
}

unsigned COBSDecode(const unsigned char* src, unsigned len, unsigned char* dst, unsigned char r) {
	unsigned src_index = 0;
	unsigned dst_index = 0;
	
	while (src_index < len) {
		unsigned code = src[src_index];
		if (src_index + code > len && code != 1) {
			return 0; // error: invalid encoding
		}
		src_index++;
		for (unsigned i = 1; i < code; i++) {
			dst[dst_index++] = src[src_index++];
		}
		if (code < 0xff && src_index != len) {
			dst[dst_index++] = r;
		}
	}
	return dst_index;
}

bool check(const char* src, char r) {
	unsigned int i = 0;
	while (src[i] != '\0') {
		if (src[i] == r) {
			return false;
		}
		i++;
	}
	return true;
}