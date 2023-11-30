/*
Write a specification for a lifo module in file lifo.h. Run
gcc -Wall -Wextra -c lifo.h to check for syntax errors.
*/

#ifndef _lifo_H
#define _lifo_H

typedef struct _lifo lifo;

//T means that the function was tested. 

//Creates a lifo with specified number of elements (this is the lifo's size). The parameters are an integer "size". The return is a pointer to the new lifo struct. It returns NULL when "size" is inputed as a number less than 1 or if the function fails to assign memory. T
lifo* lifoCreate (int size);

//Deletes the specified lifo struct. The parameters are a pointer to a lifo struct called "lifo". The function returns a 0 for successful execution and 1 for malformed input. T 
int lifoDelete (lifo* lifo);

//Puts an element into the specified lifo. The parameters are a pointer to a lifo struct called "lifo" and a generic pointer "in". The data you want to enter must first be casted to a void pointer and must also fit within the size of a pointer so that it can be used as the parameter "data". The function returns 0 on successful execution, and 1 on malformed input or if the lifo is full. T  
int lifoPush (lifo* lifo, void* data);

//Retrieves one piece of data from the specified lifo. This piece of data will be the most recently inputed piece of data. The parameters are a pointer to a lifo struct called "lifo" and "rv", the address of a void*. This void* that "rv" points to will have the retrieved data assigned to them. The retrieved data is in the form of a void*. As such, this data must be casted to the desired data type after it is extracted and placed into the variable pointed to by "rv". The function returns 0 on successful execution, and 1 on malformed input or if the lifo is empty. When the return value is 1, the variable pointed to by "rv" is set to 0. T
int lifoPop (lifo* lifo, void** rv);

//Checks to see if the specified lifo is empty. The parameters are a pointer to a lifo struct called "lifo". The function returns 1 if the lifo is empty, 0 if it isn't, and -1 for malformed input. T
int lifoIsEmpty (lifo const* lifo);

//Checks to see if the specified lifo is full. The parameters are a pointer to a lifo struct called "lifo". The function returns 1 if the lifo is full, 0 if it isn't, and -1 for malformed input.  T
int lifoIsFull (lifo const* lifo);

//Reports the number of elements currently in use by the specified lifo. The parameters are a pointer to a lifo struct called "lifo". The return is the number of elements currently in use by the specified lifo on successful execution and -1 for malformed input. T
int lifoInUse (lifo const* lifo);

//Informs the user of the total number of elements in the specified lifo. The parameters are a pointer to a lifo struct called "lifo". The function returns the total number of elements in the specified lifo on successful execution and -1 for malformed input. T
int lifoSize (lifo const* lifo);

//Checks to see exactly how full the specified lifo is. It will print this information to the stdout in the form of a fraction of the number of elements currently in use and the total number of elemetns of the lifo. The parameters are a pointer to a lifo struct called "lifo". The function returns 0 on successful execution and 1 for malformed input. T
int lifoState (lifo const* lifo);

//Prints the lifo to the terminal. The parameters are a pointer to a lifo struct called "lifo" and a function pointer. This function pointer describes a function that returns nothing (void), takes a constant void* as a parameter, and that prints the inputed void* to stdin as the desired data type (Ex: "printf("%ld", (long) e);"). The function returns 0 on successful execution and 1 for malformed input. T
int lifoPrint (lifo const* lifo, void (*fp) (void const *));

#endif