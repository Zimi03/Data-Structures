#include<iostream>
#include <fstream>
#include "Dynamic array.h"
#include "List(head).h"
#include "List(head, tail).h"
#include "Double Linked List.h"
#include "read_write.h"
#include "IDataStructure.h"

using namespace std;


/**
 * Metoda wyświetlająca menu
 * @param[out] zadanie  - zwracany przez parametr numer zadania wybrany przez użytkownika
 */
void menu_display(unsigned short &zadanie)
{
    cout << "\n\nMENU - "  << endl;
    cout << "0. Wyjdz z programu." << endl;
//    cout << "1. " << endl;
//    cout << "2. " << endl;
//    cout << "3. " << endl;
//    cout << "4. " << endl;
//    cout << "5. Wyświetl." << endl;
//    cout << "6. " << endl;
//    cout << "7. " << endl;
//    cout << "8. " << endl;

    cout << "Wybierz zadanie: ";
    cin >> zadanie;

    if (zadanie > 8) cout << "Bledny numer zadania" << endl;
}

void displayListH(IDataStructure* list){
    int i = 0;
    optional<int> value;
    value = list->get(i);
    while(value !=nullopt) {
        cout << value.value() << ", ";
        i++;
        value = list->get(i);
    } cout << endl;
}

void list_h_test(IDataStructure* lista){
    for(int i = 0; i < 10; i ++){
        lista->insertFront(i);
    }
    displayListH(lista);


    lista->insert(10,30);
    displayListH(lista);

    lista->insertBack(20);
    displayListH(lista);

    optional<int> removed = lista->removeFront();
    if(removed==nullopt){
        cout << "NULLOPT" << endl;
    } else {
        cout << "Removed first: " << removed.value() << endl;
    }
    displayListH(lista);

    removed = lista->remove(1);
    if(removed==nullopt){
        cout << "NULLOPT" << endl;
    } else {
        cout << "Removed index 1: " << removed.value() << endl;
    }
    displayListH(lista);

    removed = lista->removeBack();
    if(removed==nullopt){
        cout << "NULLOPT" << endl;
    } else {
        cout << "Removed back: " << removed.value() << endl;
    }
    displayListH(lista);

    int found = lista->find(30);
    cout << "Found 30 on: " << found << " index" << endl;
}


int main(){
    cout << "\tLIST HEAD" << endl;
    List_h lista;
    list_h_test(&lista);
    cout << endl << "\tLIST HEAD TAIL" << endl;
    List_h_t lista2;
    list_h_test(&lista2);



    unsigned short task = 0;
    string data_folder = "/home/grzegorz/Dokumenty/.......";


    while (true) {
        menu_display(task);
        switch (task) {
            case 0:
                exit(0);
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5: // wyświetl

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            default:
                break;
        }
    }
    return 0;
}