#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


/* 


Requirements and Scope:

Fill in the data in the Bitmap struct; nothing else is required.
Input images will always be left-to right, top-to-bottom.
Decode RGBA data with 8 bits per channel. Other formats are not required.
Run-Length Encoding is not used in the test file and support is not required.
Reading metadata is not required.
No 3rd-party libraries. (eg, libtga)


Documentation:
https://en.wikipedia.org/wiki/Truevision_TGA
https://www.dca.fee.unicamp.br/~martino/disciplinas/ea978/tgaffs.pdf

Useful CLI Tools:
hexedit
man ascii

Reminders: 
The escaped numbers in the image data string colornoise.c are in octal

This is not school. It is perfectly allowed, and even recommended, to
look at colornoise.c as well as the hex dump of colornoise.tga. You can
search for and examine other code that does the same thing on the 
internet, although you cannot copy-and-paste it due to copyrights. The 
point is to fulfill the specifications, not to do it "without cheating".
Use all resources available.

*/


typedef struct {
	long w, h; // width and height
	           // ignore multi-layer/animated files for now
	
	uint8_t* data; // packed bitmap data; 
	               // 1-byte R,G,B,A values for each pixel from left to right then top to bottom 
} Bitmap;




// returns 0 on success, a positive value on error
int decode_tga(Bitmap* b, uint8_t* contents, long fsz) {
	
	// read header
	
	// allocate data buffer in b
	
	// decode image data

	return 0;
}




int main(int argc, char* argv[]) {
	
	if(argc < 2) {
		fprintf(stderr, "Missing argument: tga file\n");
		return 1;
	}
	
	FILE* f = fopen(argv[1], "rb");
	if(!f) {
		fprintf(stderr, "Could not open file '%s'\n", argv[1]);
		return 2;
	}
	
	// get the file size using the traditional method. fstat() is more reliable.
	fseek(f, 0, SEEK_END);
	long fsz = ftell(f);
	rewind(f);
	
	uint8_t* contents = malloc(fsz);
	// On linux, malloc never returns NULL.
	
	// read the entire file 
	long bytes_read = 0;
	do {
		bytes_read += fread(contents + bytes_read, 1, fsz, f);
	} while(bytes_read < fsz);
	
	fclose(f);
	
	
	
	Bitmap b = {0};
	
	if(decode_tga(&b, contents, fsz)) {
		fprintf(stderr, "Error decoding tga file '%s'\n", argv[1]);
		return 3;
	}
	
	
	// check the results
	#include "colornoise.c"
	
	if(gimp_image.width != b.w || gimp_image.height != b.h) {
		printf("\e[31mFAIL\e[0m incorrect image size\n");
		return 4;
	}
	
	if(0 != memcmp(b.data, gimp_image.pixel_data, 64*64*4)) {
		printf("\e[31mFAIL\e[0m incorrect image data\n");
		return 5;
	}
	
	printf("\e[32mOK\e[0m\n");

	return 0;
}



