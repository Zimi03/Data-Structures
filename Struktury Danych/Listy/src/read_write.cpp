//
// Created by grzegorz on 25.03.24.
//

#include "read_write.h"


int readTxt(IDataStructure* list, int n, const string &txt_read_path) {
    if (n <= 0) return 2;

    fstream plik{txt_read_path};
    if (!plik.is_open()) {
        cout << "not opened" << endl;
        return 1;
    } else {
        string line;
        int number;

        for (int i = 0; i < n; i++) {
            if(getline(plik, line)) {
                try {
                    number = std::stoi(line);
                    std::cout << "Parsed integer: " << number << std::endl;
                    list->insertFront(number);
                } catch (const std::invalid_argument &ia) {
                    std::cerr << "Invalid argument: " << ia.what() << std::endl;
                } catch (const std::out_of_range &oor) {
                    std::cerr << "Out of range: " << oor.what() << std::endl;
                }
            }
        }
        plik.close();
        return 0;
    }
}

/**
 * zapisuje do pliku csv
 * @param folderpath
 * @param filename
 * @param data
 * @return 0 - ok
 * @return 1 - błąd tworzenia/otwierania folderu
 * @return 2 - błąd tworzenia/otwierania pliku
 */
int writeCSV(const string& folderpath, const string& filename, const string& header, const string& data)
{
    struct stat info;
    if (stat(folderpath.c_str(), &info) != 0) {
        // Jeśli folder nie istnieje -> tworzymy go
        if (mkdir(folderpath.c_str(), 0777) != 0) {
            std::cerr << "Nie można utworzyć folderu." << std::endl;
            return 1;
        }
    }

    ofstream file (folderpath + "/" + filename, std::ios::app);
    if (file.is_open()) {
        file.seekp(0, std::ios::end);
        if (!file.tellp()) {
            file << header << std::endl;
        }
        file << data << endl;
        file.close();
        return 0;
    } else {
        std::cerr << "Nie można otworzyć pliku do zapisu." << std::endl;
        return 2;
    }
}