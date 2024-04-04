#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <limits>
#include <iomanip>
#include <sstream>
#include <optional>
#include <random>

#include "Dynamic array.h"
#include "List(head).h"
#include "List(head, tail).h"
#include "Double Linked List.h"
#include "read_write.h"
#include "IDataStructure.h"
#include "test.h"

using namespace std;



void clearInputStream() {
    std::cin.clear(); // Czyszczenie flag błędów
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorowanie wszystkich pozostałych znaków w buforze
}


unsigned int typeNumberU(){
    unsigned int i = 0;
        cin >> i;
        while (cin.fail()) {
            cout << "Błąd! Wprowadzono nieprawidłowe dane. Spróbuj ponownie." << std::endl;
            clearInputStream();
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
        clearInputStream();
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

void random_int(int* & tab, int n, int dolnyZakres, int gornyZakres) {
    random_device rd; // Inicjalizacja generatora
    mt19937 gen(rd());

    // Określenie rozkładu jednorodnego w podanym zakresie
    std::uniform_int_distribution<int> rozklad(dolnyZakres, gornyZakres);

    // Inicjalizacja tablicy liczb
    if(tab != nullptr) delete[] tab;
    tab = new int[n];

    // Generowanie i dodawanie liczb do tablicy
    int liczba = 0;
    for (int i = 0; i < n; ++i) {
        liczba = rozklad(gen);
        tab[i] = liczba;
    }

}

void reverse_array(int* &tab, int &n){
    if(n <= 0 ) return;
    int* tmp = new int[n];
    for(int i = n - 1, j = 0; i >= 0; i--, j++){
        tmp[j] = tab[i];
    }
    delete[] tab;
    tab = tmp;
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
    cout << "5. Random numbers" << endl;

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
   //TO CI ZOSTAWIAM JAKO SZKIC DO TESTOWANIA STRUKTUR NA MAŁYCH STAŁYCH DANYCH

    cout << "\tDYNAMIC ARRAY " << endl;
    DynamicArray arr;
    structure_test(&arr);


    string data_folder = "/home/grzegorz/Dokumenty/Struktury danych/projekt1/Data-Structures/Listy/Dane/";
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
    int number = 0; // liczba testów
    int size = 0; // rozmiar struktury
    int value = 0; // wartość do wpisania/usunięcia itp
    int number_of_values = 0; // zmienna pomocnicza funkcji find oznaczająca ile danych ma być znajdowanych
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
                path = data_folder + "rev_" + to_string(size) + ".txt";

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
                cout << "Wczytano dane z pliku: " << path << endl;

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
                            structure = new IDataStructure *[number];
                            for (int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_insertFront(structure, value, number); // test
                            for (int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV
                            commit = time_oss.str() + "," + to_string(size) + "," + to_string(number);
                            // usuwanie struktur
                            for (int i = 0; i < number; i++) delete structure[i];
                            delete[] structure;
                            structure = nullptr;
                            break;
        /* INSERT */
                        case 2:
                            cout << "\t# INSERT #" << endl;
                            typeNumber(number, "Liczba testów: ", value, "Liczba do dodania: ");
                            if (number <= 0) break;
                            // ile wartosci testowych z pliku wykorzystac do pojedynczeho testu
                            path = data_folder + to_string(size) + ".txt";
                            do {
                                cout << "Liczba wartosci testowych z pliku " + path + ": ";
                                number_of_values = typeNumber();
                                if(number_of_values > size){
                                    cout << "Liczba wartości testowych z pliku musi być mniejsza/równa od rozmiaru struktury."<< endl;
                                }
                            } while (number_of_values > size);
                            tab_index = new int[number_of_values];
                            // odczyt danych losowych z pliku txt jesli istnieje
                            if(readTxt(tab_index, number_of_values, path) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number*number_of_values];
                            for(int i = 0; i < number*number_of_values; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_insert(structure, value, tab_index, number, number_of_values); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for (int i = 0; i < number; i++) delete structure[i];
                            delete[] structure; structure = nullptr;
                            delete[] tab_index; tab_index = nullptr;
                            break;
        /* INSERT BACK */
                        case 3:
                            cout << "\t# INSERT BACK #" << endl;
                            typeNumber(number, "Liczba testów: ", value, "Liczba do dodania: ");
                            if (number <= 0) break;
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure *[number];
                            for (int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_insertBack(structure, value, number); // test
                            for (int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for (int i = 0; i < number; i++) delete structure[i];
                            delete[] structure;
                            structure = nullptr;
                            break;
        /* REMOVE FRONT */
                        case 4:
                            cout << "\t# REMOVE FRONT #" << endl;
                            cout << "Liczba testów: " << endl;
                            number = typeNumber();
                            if (number <= 0) break;
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure *[number];
                            for (int i = 0; i < number; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_removeFront(structure, number); // test
                            for (int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for (int i = 0; i < number; i++) delete structure[i];
                            delete[] structure;
                            structure = nullptr;
                            break;
        /* REMOVE */
                        case 5:
                            cout << "\t# REMOVE #" << endl;
                            cout << "Liczba testów: ";
                            number = typeNumber();
                            if (number <= 0) break;
                            // ile wartosci testowych z pliku wykorzystac do pojedynczeho testu
                            path = data_folder + "rev_" + to_string(size) + ".txt";
                            do {
                                cout << "Liczba wartosci testowych z pliku " + path + ": ";
                                number_of_values = typeNumber();
                                if(number_of_values > size){
                                    cout << "Liczba wartości testowych z pliku musi być mniejsza/równa od rozmiaru struktury."<< endl;
                                }
                            } while (number_of_values > size);
                            tab_index = new int[number_of_values];
                            // odczyt danych losowych z pliku txt jesli istnieje
                            if(readTxt(tab_index, number_of_values, path) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number*number_of_values];
                            for(int i = 0; i < number*number_of_values; i++) structure[i] = new List_h(list_h);
                            // test
                            time = test_remove(structure, tab_index, number, number_of_values); // test
                            for(int i = 0; i < number; i++) display(structure[i]); // wyswietl czy git
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV

                            // usuwanie struktur
                            for(int i = 0; i < number*number_of_values; i++) delete structure[i];
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
                            // ile wartosci testowych z pliku find wykorzystac do pojedynczeho testu
                            cout << "Liczba wartosci testowych bbb w pliku find_aaa_bbb.txt: " << endl;
                            number_of_values = typeNumber();
                            path = data_folder + "find_" + to_string(size) + "_" + to_string(number_of_values)+ ".txt";
                            // odczyt danych losowych z pliku txt jesli istnieje
                            tab_index = new int [number_of_values];
                            if(readTxt(tab_index, number_of_values, path) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            } else cout << "Odczyatno dane z pliku: " << path << endl;

                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [1];
                            structure[0] = new List_h(list_h);
                            // test
                            time = test_find(structure,tab_index,number,number_of_values); // test
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV
                            header = "liczba danych, czas [s], liczba testów, liczba wartości szukanych w każdym teście";
                            commit = to_string(size) + "," + time_oss.str() + "," + to_string(number) + "," + to_string(number_of_values);
                            writeCSV(data_folder + "testy", "List_h_find.csv", header, commit);
                            // usuwanie struktur
                            delete structure[0];
                            delete[] structure; structure = nullptr;
                            delete[] tab_index; tab_index = nullptr;
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
                cout << "Wczytano dane z pliku: " << path << endl;

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
                            // ile wartosci testowych z pliku wykorzystac do pojedynczeho testu
                            path = data_folder + to_string(size) + ".txt";
                            do {
                                cout << "Liczba wartosci testowych z pliku " + path + ": ";
                                number_of_values = typeNumber();
                                if(number_of_values > size){
                                    cout << "Liczba wartości testowych z pliku musi być mniejsza/równa od rozmiaru struktury."<< endl;
                                }
                            } while (number_of_values > size);
                            tab_index = new int[number_of_values];
                            // odczyt danych losowych z pliku txt jesli istnieje
                            if(readTxt(tab_index, number_of_values, path) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number*number_of_values];
                            for(int i = 0; i < number*number_of_values; i++) structure[i] = new List_h_t(list_h_t);
                            // test
                            time = test_insert(structure, value, tab_index, number, number_of_values); // test
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
                            cout << "Liczba testów: ";
                            number = typeNumber();
                            if (number <= 0) break;
                            // ile wartosci testowych z pliku wykorzystac do pojedynczeho testu
                            path = data_folder + to_string(size) + ".txt";
                            do {
                                cout << "Liczba wartosci testowych z pliku " + path + ": ";
                                number_of_values = typeNumber();
                                if(number_of_values > size){
                                    cout << "Liczba wartości testowych z pliku musi być mniejsza/równa od rozmiaru struktury."<< endl;
                                }
                            } while (number_of_values > size);
                            tab_index = new int[number_of_values];
                            // odczyt danych losowych z pliku txt jesli istnieje
                            if(readTxt(tab_index, number_of_values, path) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            }
                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [number*number_of_values];
                            for(int i = 0; i < number*number_of_values; i++) structure[i] = new List_h_t(list_h_t);
                            // test
                            time = test_remove(structure, tab_index, number, number_of_values); // test
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
                            cout << "Liczba wartosci testowych bbb w pliku find_aaa_bbb.txt: " << endl;
                            number_of_values = typeNumber();
                            path = data_folder + "find_" + to_string(size) + "_" + to_string(number_of_values)+ ".txt";
                            // odczyt danych losowych z pliku txt jesli istnieje
                            tab_index = new int [number_of_values];
                            if(readTxt(tab_index, number_of_values, path) != 0){
                                cout << "Nie ma takiego pliku: " << path <<  " w katalogu: " << data_folder << endl;
                                break;
                            } else cout << "Odczyatno dane z pliku: " << path << endl;


                            // przygotuj odpowiednią ilość struktur
                            structure = new IDataStructure* [1];
                            structure[0] = new List_h_t(list_h_t);
                            // test
                            time = test_find(structure,tab_index,number,number_of_values); // test
                            time_oss.str("");
                            time_oss << std::fixed << std::setprecision(precision) << time; // oss czasu do zapisu
                            cout << "TIME: " << time_oss.str() << endl;
                            // TU ZAPIS DO PLIKU CSV
                            header = "liczba danych, czas [s], liczba testów, liczba wartości szukanych w każdym teście";
                            commit = to_string(size) + "," + time_oss.str() + "," + to_string(number) + "," + to_string(number_of_values);
                            writeCSV(data_folder + "testy", "List_h_t_find.csv", header, commit);
                            // usuwanie struktur
                            delete structure[0];
                            delete[] structure; structure = nullptr;
                            delete[] tab_index; tab_index = nullptr;
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
                cout << "Wczytano dane z pliku: " << path << endl;

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
                cout << "Wczytano dane z pliku: " << path << endl;

                break;
            case 5:
    /* LOSOWANIE DANYCH I ZAPIS DO PLIKU */
                cout << "LOSOWANIE DANYCH" << endl;
                typeNumber(size, "Wprowadz liczbę danych do wylosowania: ", value, "Górny zakres: ");

                do {
                    cout << "Czy plik ma służyć funkcji find(): [t/n]? ";
                    clearInputStream();
                    cin >> commit;
                    if(commit == "t"){
                        path = "find_" + to_string(value) + "_" + to_string(size) + ".txt";
                        cout << "Nazwa pliku: " << data_folder << path << endl;
                        break;
                    } else if (commit == "n"){
                        path = to_string(size) + ".txt";
                        cout << "Nazwa pliku: " << data_folder << path << endl;
                    }else {
                            cout << "Błedny wybór" << endl;
                    }
                } while(commit != "n");


                random_int(tab_index, size, 0, value);

                writeTXT(data_folder, path, tab_index, size);
                cout << "Zapisano " << size << " wylosowanych danych do pliku " << data_folder << path << endl;
                do {
                    cout << "Zapisać plik z odwrotną kolejnością danych: [t/n]? ";
                    clearInputStream();
                    cin >> commit;
                    if(commit == "t"){
                        reverse_array(tab_index, size);
                        path.insert(0, "rev_");
                        writeTXT(data_folder, path, tab_index, size);
                        cout << "Zapisano " << size << " wylosowanych danych do pliku " << data_folder << path << endl;
                        break;
                    } else if( commit != "n"){
                        cout << "Błedny wybór" << endl;
                    }
                } while(commit != "n");

                break;
            default:
                cout << "Nieprawidłowy wybór. Wybierz ponownie." << endl;
                break;
        }
    } while( firstChocie!=0);
    exit(0);
}