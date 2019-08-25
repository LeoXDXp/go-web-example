#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void) {
	char *p;
// 1 << 20 = 1024 * 1024 = 1 MB
         while (1) {
                 if ((p = malloc(1<<20)) == NULL) {
                         printf("malloc failure after %d MiB\n", n);
                         return 0;
                 }
                 memset (p, 0, (1<<20));
                 printf ("got %d MiB\n", ++n);
         }
}
