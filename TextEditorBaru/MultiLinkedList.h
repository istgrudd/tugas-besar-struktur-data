#ifndef MULTILINKEDLIST_H_INCLUDED
#define MULTILINKEDLIST_H_INCLUDED

#include <string>
using namespace std;

struct elemAnnotation {
    string annotation;
    elemAnnotation* next;
};

struct elemMulti {
    string text;
    elemAnnotation* annotations;
    elemMulti* next;
};

struct MultiLinkedList {
    elemMulti* first;
};

void initMultiList(MultiLinkedList &L);
void addText(MultiLinkedList &L, const string &text);
elemMulti* findTextNode(MultiLinkedList &L, const string &text);
void addAnnotation(elemMulti* textNode, const string &annotation);
void displayAnnotations(elemMulti* textNode);

bool isTextExist(MultiLinkedList &L, const string &text);

#endif // MULTILINKEDLIST_H_INCLUDED
