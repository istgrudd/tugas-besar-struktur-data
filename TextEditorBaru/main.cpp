#include <iostream>
#include <fstream>
#include <string>
#include "DoublyLinkedList.h"
#include "StackText.h"
#include "SinglyLinkedList.h"
#include "MultiLinkedList.h"
#include <cstdlib> // Untuk system("cls") atau system("clear")

using namespace std;

// Fungsi untuk membersihkan tampilan cmd
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");  // Untuk Linux/MacOS
    #endif
}

void printMenu() {
    cout << "\nText Editor Menu: \n";
    cout << "1. Insert Text (Doubly Linked List)\n";
    cout << "2. Delete Text (Doubly Linked List)\n";
    cout << "3. Display Text (Doubly Linked List)\n";
    cout << "4. Undo (Stack)\n";
    cout << "5. Redo (Stack)\n";
    cout << "6. Add Annotation (Multi Linked List)\n";
    cout << "7. Display Annotations (Multi Linked List)\n";
    cout << "8. Count Total Characters (Singly Linked List)\n";  // Mengganti fitur auto-save
    cout << "9. Export Text\n";
    cout << "10. Import Text\n";
    cout << "11. Exit\n";
    cout << "Enter your choice: ";
}

void exportText(const ListD &L, const string &filename) {
    ofstream outFile(filename.c_str());
    if (!outFile) {
        cout << "Error opening file for export!" << endl;
        return;
    }

    adr temp = L.first;
    while (temp != NULL) {
        outFile << temp->text << endl;
        temp = temp->next;
    }

    outFile.close();
    cout << "Text successfully exported to " << filename << endl;
}

void importText(ListD &L, const string &filename) {
    ifstream inFile(filename.c_str());
    if (!inFile) {
        cout << "Error opening file for import!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        insertLast(L, line);
    }

    inFile.close();
    cout << "Text successfully imported from " << filename << endl;
}

bool askToContinue() {
    char choice;
    cout << "\nDo you want to return to the main menu? (y/n): ";
    cin >> choice;
    cin.ignore();  // Menghapus buffer input
    return (choice == 'y' || choice == 'Y');
}



int main() {
    ListD L;
    initList(L);

    Stack undoStack, redoStack;
    initStack(undoStack);
    initStack(redoStack);

    SinglyLinkedList sll;
    initList(sll);

    MultiLinkedList annList;
    initMultiList(annList);

    int choice;
    string text;
    bool running = true;

    adr temp;
    elemMulti* tempMulti;
    bool found;

    while (running) {
        printMenu();
        cin >> choice;
        cin.ignore();  // Untuk membersihkan input buffer

        switch (choice) {
            case 1:
                {
                    bool stayInFeature = true;
                    while (stayInFeature) {
                        cout << "Enter text to insert: ";
                        getline(cin, text);
                        insertLast(L, text);
                        insert(sll, text);
                        push(undoStack, L);
                        cout << "Text inserted.\n";
                        stayInFeature = !askToContinue();
                    }
                    clearScreen();
                }
                break;


            case 2:
                {
                    bool stayInFeature = true;
                    while (stayInFeature) {
                        cout << "Enter text to delete (must match the exact text): ";
                        getline(cin, text);
                        temp = L.first;
                        found = false;

                        while (temp != NULL) {
                            if (temp->text == text) {
                                deleteAt(L, temp);
                                push(undoStack, L);
                                cout << "Text deleted.\n";
                                found = true;
                                break;
                            }
                            temp = temp->next;
                        }

                        if (!found) {
                            cout << "Text not found.\n";
                        }

                        stayInFeature = !askToContinue();
                    }
                    clearScreen();
                }
                break;

            case 3:
                {
                    cout << "Current text:\n";
                    displayList(L);
                    askToContinue();
                    clearScreen();
                }
                break;

            case 4:
                {
                    if (!isEmptyStack(undoStack)) {
                        ListD previousState = pop(undoStack);
                        push(redoStack, L);
                        L = previousState;
                        cout << "Undo performed.\n";
                    } else {
                        cout << "Nothing to undo.\n";
                    }
                    clearScreen();
                }
                break;

            case 5:
                {
                    if (!isEmptyStack(redoStack)) {
                        ListD nextState = pop(redoStack);
                        push(undoStack, L);
                        L = nextState;
                        cout << "Redo performed.\n";
                    } else {
                        cout << "Nothing to redo.\n";
                    }
                    clearScreen();
                }
                break;

            case 6:
                {
                    bool stayInFeature = true;
                    while (stayInFeature) {
                        cout << "Enter text to annotate: ";
                        getline(cin, text);

                        elemMulti* textNode = findTextNode(annList, text);

                        if (textNode == NULL) {
                            cout << "Would you like to add it? (y/n): ";
                            char choice;
                            cin >> choice;
                            cin.ignore();
                            if (choice == 'y' || choice == 'Y') {
                                addText(annList, text);
                                cout << "Text added to the list.\n";
                                textNode = findTextNode(annList, text);
                            } else {
                                cout << "Annotation cannot be added without text.\n";
                                break;
                            }
                        }

                        cout << "Enter annotation: ";
                        string annotation;
                        getline(cin, annotation);

                        addAnnotation(textNode, annotation);
                        cout << "Annotation added.\n";

                        stayInFeature = !askToContinue();
                    }
                    clearScreen();
                }
                break;

            case 7:
                {
                    cout << "Enter text to display annotations: ";
                    getline(cin, text);
                    tempMulti = annList.first;
                    found = false;

                    while (tempMulti != NULL) {
                        if (tempMulti->text == text) {
                            cout << "Annotations for: " << tempMulti->text << endl;
                            displayAnnotations(tempMulti);
                            found = true;
                            break;
                        }
                        tempMulti = tempMulti->next;
                    }

                    if (!found) {
                        cout << "Text not found.\n";
                    }

                    askToContinue();
                    clearScreen();
                }
                break;

            case 8:
                {
                    int totalChars = countTotalCharactersSLL(sll);
                    cout << "Total characters in Singly Linked List: " << totalChars << endl;
                    askToContinue();
                    clearScreen();
                }
                break;

            case 9:
                {
                    string filename;
                    cout << "Enter filename to export (e.g., text.txt): ";
                    getline(cin, filename);
                    exportText(L, filename);
                    clearScreen();
                }
                break;

            case 10:
                {
                    string filename;
                    cout << "Enter filename to import from (e.g., text.txt): ";
                    getline(cin, filename);
                    importText(L, filename);
                    clearScreen();
                }
                break;

            case 11:
                running = false;
                cout << "Exiting text editor...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
