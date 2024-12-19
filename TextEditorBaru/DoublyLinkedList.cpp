#include "DoublyLinkedList.h"
#include "SinglyLinkedList.h"

using namespace std;

void initList(ListD &L) {
    L.first = NULL;
    L.last = NULL;
}

void insertFirst(ListD &L, string text) {
    adr newElem = new element;
    newElem->text = text;
    newElem->next = L.first;
    newElem->prev = NULL;

    if (L.first == NULL) {
        L.last = newElem;
    } else {
        L.first->prev = newElem;
    }
    L.first = newElem;
}

void insertLast(ListD &L, string text) {
    adr newElem = new element;
    newElem->text = text;
    newElem->next = NULL;

    if (L.last == NULL) {
        L.first = L.last = newElem;
        newElem->prev = NULL;
    } else {
        newElem->prev = L.last;
        L.last->next = newElem;
        L.last = newElem;
    }
}

void deleteFirst(ListD &L) {
    if (L.first != NULL) {
        adr temp = L.first;
        if (L.first == L.last) {
            L.first = L.last = NULL;
        } else {
            L.first = L.first->next;
            L.first->prev = NULL;
        }
        delete temp;
    }
}

void deleteLast(ListD &L) {
    if (L.last != NULL) {
        adr temp = L.last;
        if (L.first == L.last) {
            L.first = L.last = NULL;
        } else {
            L.last = L.last->prev;
            L.last->next = NULL;
        }
        delete temp;
    }
}

void deleteAt(ListD &L, adr P) {
    if (P == L.first) {
        deleteFirst(L);
    } else if (P == L.last) {
        deleteLast(L);
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        delete P;
    }
}

void displayList(ListD L) {
    adr temp = L.first;
    while (temp != NULL) {
        cout << temp->text << endl;
        temp = temp->next;
    }
}
