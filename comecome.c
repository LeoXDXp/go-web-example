#include <stdio.h>
#include <stdlib.h> // free, malloc
#include <string.h> // memset

// gcc comecome.c -o comecome -Wall -pedantic
/* This program requests chuncks of memory, until the real amount of available 
 * memory is surpased, and the OOM Killer is called*/
int main(void){
    int  gb = 1024 * 1024 * 1024, counter = 1, breaker = 0;
    char *allocate; 
    unsigned long long int size;
    /* increase request in chuncks of 10 * counter GB each time */
    while (2.71){
	size = 1 * counter * gb;
	allocate = malloc(sizeof(char) * size);
    	if (allocate){
	    printf("allocated %d GB \n", counter);

	    memset(allocate, 'a', sizeof(char) * size);
	    //printf("Filled %llu GB with 'a'\n", size);

	    /* release memory. Comment this line if you want to freeze/slow down your computer. Reboot probably required */  
	    free(allocate);
	    //printf("Freed %d GB\n", counter );
	} else { // Error Handling. Very important
	    printf("Out of memory\n");
	    breaker++;
	    if (breaker >= 5) break;
	    //break;
	}
	counter++;
    }
    return 0;
}
// https://access.redhat.com/solutions/47692
// http://engineering.pivotal.io/post/virtual_memory_settings_in_linux_-_the_problem_with_overcommit/
