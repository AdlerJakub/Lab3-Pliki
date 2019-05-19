#pragma once
#include <fstream>
#include "Tester.h"
#include "Defines.h"

class CLogger : LoggerTester
{
private:
    bool binary;
    ofstream file;
public:
    CLogger(string filePath, bool binary = false); //otwiera plik 
    ~CLogger(); //zamyka plik
    //loguje jeden punkt na koniec pliku (dodaje punkt)
    result_en Log(const point_t &p); 
    result_en Log(const vector<point_t> &pointsVector); //dodaje kolekcje punktów do pliku
};