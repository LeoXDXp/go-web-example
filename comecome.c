#include <stdio.h>
#include <stdlib.h> // free, malloc
#include <string.h> // memset
#include <unistd.h> // sleep
#include <time.h> 

// gcc comecome.c -o comecome -Wall -pedantic
/* This program requests chuncks of memory, until the real amount of available 
 * memory is surpased, and the OOM Killer is called*/
int main(int arc, char**argv){
    int i, j, counter = 1, size = 1024 * 1024 * 1024; 
    char *allocate;
    srand(time(NULL));

    /* increase request in chuncks of 1 GB each time */
    for (i = 1; i < 20; i++){
	allocate = malloc(sizeof(char) * size * counter);
    	if (allocate){
	    printf("allocated %d GB\n", i);
	    for (j = 0; j < strlen(allocate)-1; j++)
		allocate[j] = 'a';
	    //memset(allocate, 5, sizeof(int) * size * counter);
	    printf("Filled %d GB with 5s\n", i);
	    /* release memory. Comment this line if you want to freeze/slow down your computer. Reboot probably required */  
	    free(allocate);
	    printf("Freed %d GB\n", i);
	} else { // Error Handling. Very important
	    printf("Out of memory\n");
	}
	/* Add some randomness to the failure */
	//sleep(rand()%5);
    }
    return 0;
}
