/*
Implement in file buffer.c your specification from Exercise
7.3 of the LIFO queue using an array (as part of a struct) as the basic underlying data structure. Test it using your unit test from Exercise 7.4. The implementation is simpler than than of the circular buffer, so if you’re introducing head and tail indices and trying to apply modulo addition, retreat
and regroup.
*/

#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>

struct _lifo {

    int filled;
    int capacity;
    void** data;
    
};

lifo* lifoCreate (int size) {

    //Checking for malformed input.
    if (size < 1) return NULL; 
    
    //Creating space on the heap for the new lifo struct and checking to see if the allocation failed. 
    lifo* p = (lifo*) malloc (sizeof (lifo));
    if (!p) return NULL;
    
    //Allocating space for the array of void*'s that is pointed to by "data", a member of the new lifo struct. Also checks for if the memory allocation fails.
    p->data = (void**) malloc (sizeof (void*) * size);
    if (!p->data) {
    
        free (p);
        return NULL;
    }
    
    //Setting initial values for the other members of the struct.
    p->filled = 0;
    p->capacity = size;
    
    //Returning a pointer to the struct.
    return p;
}

int lifoDelete (lifo* lifo) {

    //Checking for malformed input.
    if (!lifo) return 1;
    
    //Freeing the memory allocated to the struct and its member "data". 
    free (lifo->data);
    free (lifo);
    
    //A return of 0 for successful execution.
    return 0;
}
 
int lifoPush (lifo* lifo, void* data) {

    //Checking for malformed input.
    if (!lifo || lifoIsFull (lifo)) return 1;
    
    //Setting the correct element of the array "data" to the inputted information stored in the variable "data", and incrementing the counter for the number of in use or "filled" elements by 1. 
    int i = lifo->filled;
    lifo->data[i] = data;
    lifo->filled++;
    
    //A return of 0 for successful execution. 
    return 0;
}

int lifoPop (lifo* lifo, void** rv) {

    //Checking for malformed input. The capture variable "*rv" is set to 0 on malformed input.
    if (!lifo || !rv || lifoIsEmpty (lifo)) 
    {
        *rv = 0;
        return 1;
    }
    
    //Setting the capture varialbe "*rv" to the correct data from the lifo. The counter for the in use or "filled" elements is reduced by 1. 
    int i = lifo->filled - 1;
    *rv = lifo->data[i];
    lifo->filled = i;
    
    return 0;
}

int lifoIsEmpty (lifo const* lifo) {

    //Checking for malformed input.
    if (!lifo) return -1;
    
    //Checking to see if the lifo is empty. Return 1 if it is and 0 if it isn't. 
    if (lifo->filled == 0) return 1;
    else return 0;
}

int lifoIsFull (lifo const* lifo) {

    //Checking for malformed input.
    if (!lifo) return -1;
    
    //Checking to see if the lifo is completely filled. Return 1 if it is full and 0 if it isn't.
    if (lifo->filled == lifo->capacity) return 1;
    else return 0;
}

int lifoInUse (lifo const* lifo) {

    //Checking for malformed input.
    if (!lifo) return -1;
    
    //Return the number of in use or "filled" elements.
    return lifo->filled;
}

int lifoSize (lifo const* lifo) {

    //Checking for malformed input.
    if (!lifo) return -1;
    
    //Returns the maximum number of elements in the lifo. 
    return lifo->capacity;
}

int lifoState (lifo const* lifo) {

    //Checking for malformed input.
    if (!lifo) return 1;
    
    //Prints to the terminal the ratio of the elements in use to the total number of elements. 
    printf ("\n%d/%d\n\n", lifo->filled, lifo->capacity);
    
    return 0;
}

int lifoPrint (lifo const* lifo, void (*fp) (void const *)) {

    //Checking for malformed input.
    if (!lifo || !fp) return 1;
    
    //Transverses the elements of the lifo. The function pointed to by the function pointer "fp" allows the data to be printed to the terminal with the correct casting. 
    for (int i = 0; i < lifo->filled; i++) {
    
        fp (lifo->data[i]);
        putchar (' ');
    }
    
    //A line for formatting and world peace.
    putchar ('\n');
    
    //A return of 0 for successful execution. 
    return 0;
}