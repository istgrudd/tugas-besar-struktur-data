#include "StackText.h"

void initStack(Stack &S) {
    S.top = NULL;
}

bool isEmptyStack(Stack &S) {
    return S.top == NULL;
}

void push(Stack &S, ListD L) {
    elemStack* newElement = new elemStack;
    newElement->listState = copyList(L);
    newElement->next = S.top;
    S.top = newElement;
}


ListD pop(Stack &S) {
    if (S.top == NULL) {
        ListD emptyList;
        initList(emptyList);
        return emptyList;
    }

    elemStack* temp = S.top;
    S.top = S.top->next;

    ListD poppedList = temp->listState;
    delete temp;
    return poppedList;
}


ListD copyList(ListD L) {
    ListD newList;
    initList(newList);

    adr temp = L.first;
    while (temp != NULL) {
        insertLast(newList, temp->text);
        temp = temp->next;
    }

    return newList;
}


