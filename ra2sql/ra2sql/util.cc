#include "util.h"
#include <stdint.h>
#include <iostream>
#include <random>

namespace R2S {
	void good_random(void *out, size_t out_len)
	{
		std::random_device rd;
		uint8_t *o = static_cast<uint8_t *>(out);
		for (size_t i = 0; i < out_len; i++)
			o[i] = rd();
		
	}
}