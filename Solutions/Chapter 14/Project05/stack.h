#ifndef STACK_H
#define STACK_H

void stack_make_empty();
bool stack_is_empty();
bool stack_is_full();
void stack_push(int i);
int stack_pop();
void stack_overflow();
void stack_underflow();


#endif
