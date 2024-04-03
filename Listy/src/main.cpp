#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <limits>
#include <iomanip>
#include <sstream>
#include <optional>

#include "Dynamic array.h"
#include "List(head).h"
#include "List(head, tail).h"
#include "Double Linked List.h"
#include "read_write.h"
#include "IDataStructure.h"
#include "test.h"

using namespace std;

unsigned int typeNumberU(){
    unsigned int i = 0;
        cin >> i;
        while (cin.fail()) {
            cout << "Błąd! Wprowadzono nieprawidłowe dane. Spróbuj ponownie." << std::endl;
            cin.clear(); // Wyczyść flagi błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Usuń błędne dane z bufora
            cout << "Podaj liczbę całkowitą nieujemną: ";
            cin >> i;
        }
    return i;
}

int typeNumber(){
    int i = 0;
    cin >> i;
    while (cin.fail()) {
        cout << "Błąd! Wprowadzono nieprawidłowe dane. Spróbuj ponownie." << std::endl;
        cin.clear(); // Wyczyść flagi błędu
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Usuń błędne dane z bufora
        cout << "Podaj liczbę całkowitą: ";
        cin >> i;
    }
    return i;
}


void typeNumber(int &n1, string s1, int &n2, string s2){
    cout << s1;
    n1 = typeNumber();
    cout << s2;
    n2 = typeNumber();
}


/**
 * Metoda wyświetlająca menu
 * @param[out] zadanie  - zwracany przez parametr numer zadania wybrany przez użytkownika
 */
void menu(unsigned int &first)
{
    cout << "\n\nMENU - "  << endl;
    cout << "0. EXIT." << endl;
    cout << "1. List(head)" << endl;
    cout << "2. List(head, tail)" << endl;
    cout << "3. Double linked list" << endl;
    cout << "4. Dynamic array" << endl;

    cout << "Choose task: ";
    first = typeNumberU();
}

void menuSecondLevel(unsigned int firstLevelChoice, unsigned int &second, int size){
    string structure = " ";
    if(firstLevelChoice == 1) structure = "List(head)";
    else if(firstLevelChoice == 2)  structure = "List(head, tail)";
    else if(firstLevelChoice == 3)  structure = "Double linked list";
    else if(firstLevelChoice == 4)  structure = "Dynamic array";

    cout << "\n\nMENU - " << structure << " - " << size << endl;
    cout << "0. Back to main menu." << endl;
    cout << "1. test insertFront" << endl;
    cout << "2. test insert" << endl;
    cout << "3. test insertBack" << endl;
    cout << "4. test removeFront" << endl;
    cout << "5. test remove" << endl;
    cout << "6. test removeBack" << endl;
    cout << "7. test find" << endl;
    cout << "8. display" << endl;


    cout << "Choose task: ";
    second = typeNumberU();
}

void display(IDataStructure* list){
    int i = 0;
    optional<int> value;
    value = list->get(i);
    while(value != nullopt) {
        cout << value.value() << ", ";
        i++;
        value = list->get(i);
    } cout << endl;
}

void structure_test(IDataStructure* lista){
    for(int i = 0; i < 10; i ++){
        lista->insertFront(i);
    }
    display(lista);


    lista->insert(10,30);
    display(lista);

    lista->insertBack(20);
    display(lista);

    optional<int> removed = lista->removeFront();
    if(removed==nullopt){
        cout << "NULLOPT" << endl;
    } else {
        cout << "Removed first: " << removed.value() << endl;
    }
    display(lista);

    removed = lista->remove(1);
    if(removed==nullopt){
        cout << "NULLOPT" << endl;
    } else {
        cout << "Removed index 1: " << removed.value() << endl;
    }
    display(lista);

    removed = lista->removeBack();
    if(removed==nullopt){
        cout << "NULLOPT" << endl;
    } else {
        cout << "Removed back: " << removed.value() << endl;
    }
    display(lista);

    int found = lista->find(30);
    cout << "Found 30 on: " << found << " index" << endl;
}



int main(){
    // TO CI ZOSTAWIAM JAKO SZKIC DO TESTOWANIA STRUKTUR NA MAŁYCH STAŁYCH DANYCH

    cout << "\tLIST HEAD" << endl;
    DynamicArray arr;
    structure_test(&arr);


    string data_folder = "/home/grzegorz/Dokumenty/Struktury danych/projekt1/Data-Structures/Struktury Danych/Listy/Dane/";
    string path = " ";

    IDataStructure** structure = nullptr;
    List_h* list_h = nullptr;
    List_h_t* list_h_t = nullptr;
    DLL* list_d = nullptr;
    DynamicArray* dynArr = nullptr;

    int* tab_index = nullptr;
    int precision = 12;
    ostringstream time_oss;

    string header = " ";
    string commit = " ";
    long double time = 0;
    int number = 0, size = 0, value = 0;
    unsigned int firstChocie = 0, secondChoice = 0;

    do {
        menu(firstChocie);
        switch (firstChocie) {
            case 0:
                cout << "EXITING";
                break;



    /*  LIST - HEAD   */
            case 1: // List(head)
                cout << "Podaj liczbę danych dla list(head)" << endl;
                size = typeNumber();
                path = data_folder + to_string(size) + ".txt";

                // sprawdza czy jest juz taka lista o takim rozmiarze czy nie
                if(list_h!= nullptr && list_h->getSize() != size) {
                    delete list_h;
                    list_h = new List_h;
                    if(readTxt(list_h, size, path) != 0){
                        cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                        break;
                    }
                } else {
                    list_h = new List_h;
                    if(readTxt(list_h, size, path) != 0){
                        cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                        break;
                    }
                }

                do{
                    menuSecondLevel(firstChocie, secondChoice, size);
                    switch (secondChoice) {
                        case 0:
                            cout << "Quiting from List(head)" << endl;
                            break;
        /* INSERT FRONT */
                        case 1:
                            cout << "\t# INSERT FRONT #" << endl;
                            typeNumber(number, "Liczba testów: ", value, "Liczba do dodania: ");
                            if (number <= 0) break;
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_insertFront(structure, value, number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV
                            commit = time_oss.str() + "," + to_string(size) + "," + to_string(number);
                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* INSERT */
                        case 2:
                            cout << "\t# INSERT #" << endl;
                            typeNumber(number, "Liczba testów: ", value, "Liczba do dodania: ");
                            if (number <= 0) break;
                            // odczyt danych losowych z pliku txt jesli istnieje
                            tab_index = new int [number];
                            if(readTxt(tab_index, number, data_folder + "random_" + to_string(number)) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_insert(structure, value, tab_index, number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            delete[] tab_index; tab_index = nullptr;
                            break;
        /* INSERT BACK */
                        case 3:
                            cout << "\t# INSERT BACK #" << endl;
                            typeNumber(number, "Liczba testów: ", value, "Liczba do dodania: ");
                            if (number <= 0) break;
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_insertBack(structure, value, number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* REMOVE FRONT */
                        case 4:
                            cout << "\t# REMOVE FRONT #" << endl;
                            cout << "Liczba testów: " << endl;
                            number = typeNumber();
                            if (number <= 0) break;
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_removeFront(structure, number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* REMOVE */
                        case 5:
                            cout << "\t# REMOVE #" << endl;
                            cout << "Liczba testów: " << endl;
                            number = typeNumber();
                            if (number <= 0) break;
                            // odczyt danych losowych z pliku txt jesli istnieje
                            tab_index = new int [number];
                            if(readTxt(tab_index, number, data_folder + "random_" + to_string(number)) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_remove(structure, tab_index, number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            delete[] tab_index; tab_index = nullptr;
                            break;
        /* REMOVE BACK */
                        case 6:
                            cout << "\t# REMOVE BACK #" << endl;
                            cout << "Liczba testów: " << endl;
                            number = typeNumber();
                            if (number <= 0) break;
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_removeBack(structure,number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* FIND */
                        case 7:
                            cout << "\t# FIND #" << endl;
                            cout << "Liczba testów: " << endl;
                            number = typeNumber();
                            if (number <= 0) break;
                            // odczyt danych losowych z pliku txt jesli istnieje
                            tab_index = new int [number];
                            if(readTxt(tab_index, number, data_folder + "find_" + to_string(number)) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_find(structure, tab_index, number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* DISPLAY */
                        case 8:
                            display(list_h);
                            break;
                        default:
                            cout << "Nieprawidłowy wybór. Wybierz ponownie." << endl;
                            break;
                    }
                }while(secondChoice != 0);
                break;


    /*  LIST - HEAD TAIL   */
            case 2:
                cout << "Podaj liczbę danych dla list(head, tail)" << endl;
                size = typeNumber();
                path = data_folder + to_string(size) + ".txt";

                // sprawdza czy jest juz taka lista o takim rozmiarze czy nie
                if(list_h_t != nullptr && list_h_t->getSize() != size) {
                    delete list_h_t;
                    list_h_t = new List_h_t;
                    if(readTxt(list_h_t, size, path) != 0){
                        cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                        break;
                    }
                } else {
                    list_h_t = new List_h_t;
                    if(readTxt(list_h_t, size, path) != 0){
                        cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                        break;
                    }
                }

                do{
                    menuSecondLevel(firstChocie, secondChoice, size);
                    switch (secondChoice) {
                        case 0:
                            cout << "Quiting from List(head, tail)" << endl;
                            break;
        /* INSERT FRONT */
                        case 1:
                            cout << "\t# INSERT FRONT #" << endl;
                            typeNumber(number, "Liczba testów: ", value, "Liczba do dodania: ");
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h_t(list_h_t); // przygotuj odpowiednią ilość struktur
                            // test
                            time = test_insertFront(structure, value, number); // test
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* INSERT */
                        case 2:
                            cout << "\t# INSERT #" << endl;
                            typeNumber(number, "Liczba testów: ", value, "Liczba do dodania: ");
                            if (number <= 0) break;
                            // odczyt danych losowych z pliku txt jesli istnieje
                            tab_index = new int [number];
                            if(readTxt(tab_index, number, data_folder + "random_" + to_string(number)) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h_t(list_h_t);
                            // test
                            time = test_insert(structure, value, tab_index, number); // test
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            delete[] tab_index; tab_index = nullptr;
                            break;

        /* INSERT BACK */
                        case 3:
                            cout << "\t# INSERT BACK #" << endl;
                            typeNumber(number, "Liczba testów: ", value, "Liczba do dodania: ");
                            if (number <= 0) break;
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h_t(list_h_t);
                            // test
                            time = test_insertBack(structure, value, number); // test
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* REMOVE FRONT */
                        case 4:
                            cout << "\t# REMOVE FRONT #" << endl;
                            cout << "Liczba testów: " << endl;
                            number = typeNumber();
                            if (number <= 0) break;
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h_t(list_h_t);
                            // test
                            time = test_removeFront(structure, number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* REMOVE */
                        case 5:
                            cout << "\t# REMOVE #" << endl;
                            cout << "Liczba testów: " << endl;
                            number = typeNumber();
                            if (number <= 0) break;
                            // odczyt danych losowych z pliku txt jesli istnieje
                            tab_index = new int [number];
                            if(readTxt(tab_index, number, data_folder + "random_" + to_string(number)) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h_t(list_h_t);
                            // test
                            time = test_remove(structure, tab_index, number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            delete[] tab_index; tab_index = nullptr;
                            break;
        /* REMOVE BACK */
                        case 6:
                            cout << "\t# REMOVE BACK #" << endl;
                            cout << "Liczba testów: " << endl;
                            number = typeNumber();
                            if (number <= 0) break;
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h_t(list_h_t);
                            // test
                            time = test_removeBack(structure,number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* FIND */
                        case 7:
                            cout << "\t# FIND #" << endl;
                            cout << "Liczba testów: " << endl;
                            number = typeNumber();
                            if (number <= 0) break;
                            // odczyt danych losowych z pliku txt jesli istnieje
                            tab_index = new int [number];
                            if(readTxt(tab_index, number, data_folder + "/find_" + to_string(number)) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number];
                            for(int i = 0; i < number; i++) structure[i] = new List_h_t(list_h_t);
                            // test
                            time = test_find(structure,tab_index,number); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            break;
        /* DISPLAY */
                        case 8:
                            display(list_h_t);
                            break;
                        default:
                            cout << "Nieprawidłowy wybór. Wybierz ponownie." << endl;
                            break;
                    }
                }while(secondChoice != 0);
                break;


    /*  DOUBLE LINKED LIST   */
            case 3:
                cout << "Podaj liczbę danych dla double linked list" << endl;
                size = typeNumber();
                path = data_folder + "/" + to_string(size) + ".txt";

                // sprawdza czy jest juz taka lista o takim rozmiarze czy nie
                if(list_d!= nullptr && list_h->getSize() != size) {
                    delete list_h;
                    list_h = new List_h;
                    if(readTxt(list_h, size, path) != 0){
                        cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                        break;
                    }
                } else {
                    list_h = new List_h;
                    if(readTxt(list_h, size, path) != 0){
                        cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                        break;
                    }
                }
                break;


    /*  DYNAMIC ARRAY */
            case 4:
                cout << "Podaj liczbę danych dla dynamic array" << endl;
                size = typeNumber();
                path = data_folder + "/" + to_string(size) + ".txt";
                // sprawdza czy jest juz taka lista o takim rozmiarze czy nie
                if(list_h!= nullptr && list_h->getSize() != size) {
                    delete list_h;
                    list_h = new List_h;
                    if(readTxt(list_h, size, path) != 0){
                        cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                        break;
                    }
                } else {
                    list_h = new List_h;
                    if(readTxt(list_h, size, path) != 0){
                        cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                        break;
                    }
                }
                break;
            default:
                cout << "Nieprawidłowy wybór. Wybierz ponownie." << endl;
                break;
        }
    } while( firstChocie!=0);
    exit(0);
}