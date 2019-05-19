#pragma once
#include <fstream>
#include "Tester.h"
#include "Defines.h"

class CBinaryReader : ReaderTester
{
private:
    ifstream file;
public:
    CBinaryReader(string filePath); //otwieramy plik
    ~CBinaryReader(); //zamykamy plik
    result_en ReadFile(vector<point_t> &pointsVector); //odczyt wszystkich punktów z pliku
    result_en ReadIndex(size_t index, point_t &p); //odczyt jednego punktu z pliku
};

