#include <stdio.h>
#include <stdlib.h> // free, malloc
#include <string.h> // memset
#include <unistd.h> // sleep
#include <time.h> 

// gcc comecome.c -o comecome -Wall -pedantic
/* This program requests chuncks of memory, until the real amount of available 
 * memory is surpased, and the OOM Killer is called*/
int main(int arc, char**argv){
    int i, counter = 1; 
    char *allocate;
    srand(time(NULL));

    /* increase request in chuncks of 1 GB each time */
    for (i = 0; i < 12; i++){
	allocate = malloc(sizeof(char) * 1024 * 1024 * 1024 * counter);
    	if (allocate){
	    printf("allocated %d GB\n", i);
	    memset(allocate, 1, sizeof(char) * 1024 * 1024 * 1024 * counter);
	    printf("Filled %d GB with 1s\n", i);
	    /* release memory. Comment this line if you want to freeze/slow down your computer. Reboot probably required */  
	    free(allocate);
	    /* Add some randomness to the failure */
	    sleep(rand()%5);
	} else { // Error Handling. Very important
	    printf("Out of memory\n");
	}
    }
    return 0;
}
