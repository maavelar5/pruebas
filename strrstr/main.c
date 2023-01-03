#include <stdlib.h>
#include <stdio.h>
#include <string.h>






// reverse strstr()
// Seaches for the last complete copy of needle inside haystack
// Does not need to handle NULL inputs; garbage in, segfault out.
// Does need to handle empty strings.
char* strrstr (char* haystack, char* needle)
{

    // this function should only scan through haystack once.
    // do not use any library functions

    int i = 0, answer = -1;

    while (*(haystack + i))
    {
        if (*(haystack + i) == *needle)
        {
            int j = 0, result = 0;

            while (*(needle + j))
            {
                if (*(haystack + i + j) == *(needle + j))
                {
                    j++;
                    continue;
                }
                else
                {
                    result = 1;
                    break;
                }
            }

            if (result == 0)
            {
                answer = i;
            }

            i += j;
        }
        else
        {
            i++;
        }
    }

    return (haystack + answer);
}

int main(int argc, char* argv[]) {
	
	
	char* test[] = {
		"abc def abc",
		"abc def abc def",
		"abc def abc def abc",
		"def abc abc",
		"abc abc",
		"",
	};	
	
	
	long answers[] = {
		4,
		12,
		12,
		0,
		-1,
		-1,
	};
	
	for(int i = 0; i < 6; i++) {
		int fail = 0;
		
		char* out = strrstr(test[i], "def");
		
		int pos = out == NULL ? -1 : out - test[i];
		
		fail = (answers[i] != pos); 
		
		if(fail) {
			if(pos == -1) {
				printf("%d: \e[31mFAIL\e[0m out == NULL (\"%s\")\n", i, test[i]);
			}
			else if(pos > strlen(test[i])) {
				printf("%d: \e[31mFAIL\e[0m out - haystack > strlen(haystack) (\"%s\")\n", i, test[i]);
			}
			else {
				printf("%d: \e[31mFAIL\e[0m \"%.*s\e[31m*\e[0m%s\"\n", i, pos, test[i], test[i] + pos);
			}
		}
		else {
			printf("%d: \e[32mOK  \e[0m\n", i);
		}
	}

	return 0;
}



