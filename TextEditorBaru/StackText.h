#ifndef STACKTEXT_H_INCLUDED
#define STACKTEXT_H_INCLUDED

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

struct elemStack {
    ListD listState;
    struct elemStack* next;
};

struct Stack {
    elemStack* top;
};

void initStack(Stack &S);
bool isEmptyStack(Stack &S);
void push(Stack &S, ListD L);
ListD pop(Stack &S);
void printStack(Stack &S);
ListD copyList(ListD L);
#endif // STACKTEXT_H_INCLUDED
