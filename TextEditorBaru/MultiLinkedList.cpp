#include "MultiLinkedList.h"
#include <iostream>
using namespace std;

void initMultiList(MultiLinkedList &L) {
    L.first = NULL;
}

void addText(MultiLinkedList &L, const string &text) {
    elemMulti* newElem = new elemMulti;
    newElem->text = text;
    newElem->annotations = NULL;
    newElem->next = NULL;

    if (L.first == NULL) {
        L.first = newElem;
    } else {
        elemMulti* temp = L.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newElem;
    }
}

// Fungsi untuk mengecek apakah teks sudah ada dalam daftar
bool isTextExist(MultiLinkedList &L, const string &text) {
    elemMulti* temp = L.first;
    while (temp != NULL) {
        if (temp->text == text) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Menambahkan anotasi pada elemen MultiLinkedList
void addAnnotation(elemMulti* textNode, const string &annotation) {
    elemAnnotation* newAnnot = new elemAnnotation;
    newAnnot->annotation = annotation;
    newAnnot->next = textNode->annotations;
    textNode->annotations = newAnnot;
}


// Menampilkan anotasi untuk sebuah elemen
void displayAnnotations(elemMulti* textNode) {
    elemAnnotation* annot = textNode->annotations;
    if (annot == NULL) {
        cout << "No annotations available.\n";
    }
    while (annot != NULL) {
        cout << "Annotation: " << annot->annotation << endl;
        annot = annot->next;
    }
}



// Mencari teks dalam MultiLinkedList dan mengembalikan node teks
elemMulti* findTextNode(MultiLinkedList &L, const string &text) {
    elemMulti* temp = L.first;
    while (temp != NULL) {
        if (temp->text == text) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
