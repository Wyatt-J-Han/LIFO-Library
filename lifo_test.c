#include <assert.h>
#include <stdio.h>

#include "lifo.h"

static void printLong(void const * e) {
  printf("%ld", (long) e);
}

static void printString(void const * e) {
  printf("%s", (char *) e);
}

int main(void) {
  lifo * longq, * stringq;
  void * e;
  int err;

  /* test with longs */
  longq = lifoCreate(3);

  assert(lifoIsEmpty(longq));

  printf("longq (empty): ");
  lifoPrint(longq, printLong);

  err = lifoPush(longq, (void *) 1); assert(!err);
  err = lifoPush(longq, (void *) 2); assert(!err);
  err = lifoPush(longq, (void *) 3); assert(!err);

  err = lifoPush(longq, (void *) 4); assert(err);

  printf("longq (3 elements): ");
  lifoPrint(longq, printLong);

  err = lifoPop(longq, &e); assert(!err);
  printf("from longq (3): %ld\n", (long) e);

  err = lifoPush(longq, (void *) 4); assert(!err);

  printf("longq (3 elements): ");
  lifoPrint(longq, printLong);

  err = lifoPop(longq, &e); assert(!err);
  printf("from longq (4): %ld\n", (long) e);
  err = lifoPop(longq, &e); assert(!err);
  printf("from longq (2): %ld\n", (long) e);
  err = lifoPop(longq, &e); assert(!err);
  printf("from longq (1): %ld\n", (long) e);

  assert(lifoIsEmpty(longq));
  err = lifoPop(longq, &e); assert(err);
  assert(!e);

  lifoDelete(longq);

  /* test with strings */

  stringq = lifoCreate(3);
  assert(lifoIsEmpty(stringq));

  printf("stringq (empty): ");
  lifoPrint(stringq, printString);

  err = lifoPush(stringq, "Hello"); assert(!err);
  err = lifoPush(stringq, "there"); assert(!err);
  err = lifoPush(stringq, "universe"); assert(!err);

  err = lifoPush(stringq, "!"); assert(err);

  printf("stringq (3 elements): ");
  lifoPrint(stringq, printString);

  err = lifoPop(stringq, &e); assert(!err);
  printf("from stringq (universe): %s\n", (char *) e);

  err = lifoPush(stringq, "!"); assert(!err);

  printf("stringq (3 elements): ");
  lifoPrint(stringq, printString);

  err = lifoPop(stringq, &e); assert(!err);
  printf("from stringq (!): %s\n", (char *) e);
  err = lifoPop(stringq, &e); assert(!err);
  printf("from stringq (there): %s\n", (char *) e);
  err = lifoPop(stringq, &e); assert(!err);
  printf("from stringq (Hello): %s\n", (char *) e);

  assert(lifoIsEmpty(stringq));
  err = lifoPop(stringq, &e); assert(err);
  assert(!e);

  lifoDelete(stringq);
    
    //Further testing for my extra variables.This first block is just creating and initializing the lifo.
    lifo* A = lifoCreate (4);
    err = lifoPush (A, (void*) 1); assert (!err);
    err = lifoPush (A, (void*) 2); assert (!err);
    err = lifoPush (A, (void*) 3); assert (!err);
    err = lifoPush (A, (void*) 4); assert (!err);
    
    assert (lifoIsFull (A));            //Testing whether these functions work correctly. 
    assert (lifoInUse (A) == 4);
    assert (lifoSize (A) == 4);
    err = lifoState (A); assert (!err);
    
    //Testing whether these function recognise malformed inputs correcty. 
    err = lifoIsFull (NULL); assert (err = -1);
    err = lifoInUse (NULL); assert (err = -1);
    err = lifoSize (NULL); assert (err = -1);
    err = lifoState (NULL); assert (err);
    
    //Actually testing the delete function. 
    err = lifoDelete (A); assert (!err);
    
  return 0;
}
