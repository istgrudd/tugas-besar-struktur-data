#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;

void initList(SinglyLinkedList &L) {
    L.first = NULL;
}

void insert(SinglyLinkedList &L, const string &text) {
    elemSLL* newElem = new elemSLL;
    newElem->text = text;
    newElem->next = NULL;

    if (L.first == NULL) {
        L.first = newElem;
    } else {
        elemSLL* temp = L.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newElem;
    }
}

void autoSave(SinglyLinkedList &L, const string &text) {
    insert(L, text);
    cout << "Auto-saved: " << text << endl;
}

void display(const SinglyLinkedList &L) {
    elemSLL* temp = L.first;
    while (temp != NULL) {
        cout << temp->text << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int countTotalCharactersSLL(const SinglyLinkedList &L) {
    int totalCount = 0;
    elemSLL* temp = L.first;

    while (temp != NULL) {
        totalCount += temp->text.length();
        temp = temp->next;
    }

    return totalCount;
}
