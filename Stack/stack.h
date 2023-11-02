/*  My Stack Specification  */

#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack MyStack;

/*  INITIALIZE STACK OBJECT  */
MyStack* s_newStack(void);

/*  PUSH elem TO TOP */
MyStack* s_push(MyStack* q, int elem);

/*  POP TOP ELEM  */
void s_pop(MyStack* q);

/*  RETURNS THE TOP  */
int s_top(MyStack* q);

/*  RETURNS SIZE OF STACK  */
int s_size(MyStack* q);

/*  RETURNS 1 IF STACK IS EMPTY, 0 otherwise  */
int s_isEmpty(MyStack* q);

/*  FREE ALL SPACE USED BY STACK  */
void s_free(MyStack* q);

/*  PRINT STACK TO stdout  */
void s_print(MyStack* q);


#endif /* STACK_HEADER */