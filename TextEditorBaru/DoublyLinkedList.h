#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

#include <string>
#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

typedef struct element *adr;
typedef struct ListD {
    adr first;
    adr last;
} ListD;

struct element {
    string text;
    adr next;
    adr prev;
};

void initList(ListD &L);
void insertFirst(ListD &L, string text);
void insertLast(ListD &L, string text);
void deleteFirst(ListD &L);
void deleteLast(ListD &L);
void deleteAt(ListD &L, adr P);
void displayList(ListD L);

#endif // DOUBLYLINKEDLIST_H_INCLUDED
