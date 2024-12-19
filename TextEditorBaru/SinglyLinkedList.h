#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

struct elemSLL {
    string text;
    elemSLL* next;
};

struct SinglyLinkedList {
    elemSLL* first;
};

void initList(SinglyLinkedList &L);
void insert(SinglyLinkedList &L, const string &text);
void autoSave(SinglyLinkedList &L, const string &text);
void display(const SinglyLinkedList &L);
int countTotalCharactersSLL(const SinglyLinkedList &L);

#endif // SINGLYLINKEDLIST_H_INCLUDED
