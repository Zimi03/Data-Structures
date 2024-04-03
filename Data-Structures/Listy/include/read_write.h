//
// Created by grzegorz on 25.03.24.
//

#ifndef LISTY_READ_WRITE_H
#define LISTY_READ_WRITE_H
#include "List(head).h"
#include "List(head, tail).h"
#include "Double Linked List.h"
#include "Dynamic array.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;

int readTxt(int* tab, int n, const string &txt_read_path);
int readTxt(IDataStructure* list, int n, const string &txt_read_path);

int writeCSV(const string& folderpath, const string& filename, const string& header, const string& data);
int writeTXT(const string& folderpath, const string& filename, int* &tab, int &n);


#endif //LISTY_READ_WRITE_H
