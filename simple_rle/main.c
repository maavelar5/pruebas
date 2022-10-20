#include <stdlib.h>
#include <stdio.h>
#include <string.h>





// A very simple Run-Length decoder

size_t rle_decode(unsigned char* in, size_t len, unsigned char* out) {
	// len is the length of the compressed input, in bytes
	// out is guaranteed to be big enough to contain the decoded output
	// returns the length of the decoded output
	
	
	
	return 0;
}







int main(int argc, char* argv[]) {
	
	// format: a sequence of codes, as follows:
	// {0, n, [n bytes of literal text]} -> n bytes of literal text
	// {n = 1-255, k} -> n + 2 copies of k
	
	unsigned char* test = (unsigned char*)"\x00\x08zyxwvuts\x04i\x06j\x00\x03klm\x09n";
	unsigned char* answer = (unsigned char*)"zyxwvutsiiiiiijjjjjjjjklmnnnnnnnnnnn";
	
	unsigned char out[128];
	size_t olen = rle_decode(test, 21, out);
	out[olen] = 0;
		
	if(olen == 36 && 0 == memcmp(out, answer, 36)) {
		printf("\e[32mOK  \e[0m\n");
	}
	else {
		printf("\e[31mFAIL\e[0m out == \"%s\"\n", out);
	}

	return 0;
}



