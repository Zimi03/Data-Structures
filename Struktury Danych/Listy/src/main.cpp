#include<iostream>
#include "Dynamic array.h"
#include "List(head).h"
#include "List(head, tail).h"
#include "Double Linked List.h"


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




int main(){
    List_h lista;
    for(int i = 0; i < 10; i ++){
        lista.insertFront(i);
    }
    for(int i = 0; i < 10; i ++){
        cout << lista.get(i) << ", ";
    }
    cout << endl;

    lista.insert(1,20);
    for(int i = 0; i < 11; i ++){
        cout << lista.get(i) << ", ";
    }
    cout << endl;

    lista.insertBack(20);
    for(int i = 0; i < 12; i ++){
        cout << lista.get(i) << ", ";
    }



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