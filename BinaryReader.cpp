#include <iostream>
#include <fstream>
#include <cstdio>

#include "BinaryReader.h"
#include "Defines.h"

using namespace std;

CBinaryReader::CBinaryReader(string filePath)
{
	
	file.open(filePath, ios::in | ios::binary);

}

CBinaryReader::~CBinaryReader()
{
	
		file.close();
}


result_en CBinaryReader::ReadFile(vector<point_t> &pointsVector)
{

	int i, el_count=0;
	if (file.is_open() == false)
	{
		return res_file_not_open;
	}
	else
	{
		file.seekg(0, file.end);		///ustawienie pozycji w pliku na jego koniec
		uint32_t bytes = file.tellg();	///pobranie d³ugoœci pliku
		file.seekg(0, file.beg);	/// przesuniêcie pozycji w pliku na pocz¹tek

		el_count = bytes / sizeof(point_t); ///liczy ilosc elementow w pliku
		point_t *buff = new point_t[el_count]; ///tworzy bufor

		file.read((char *)buff, bytes);

		for (i = 0; i < el_count; i++)
		{
			pointsVector.push_back(buff[i]);
		}

		delete buff;
		return res_ok;
	}
}

result_en CBinaryReader::ReadIndex(size_t index, point_t &p)
{
	int el_count;
	if (file.is_open() == false)
	{
		return res_file_not_open;
	}

	file.seekg(0, file.end);		///ustawienie pozycji w pliku na jego koniec
	uint32_t bytes = file.tellg();	///pobranie d³ugoœci pliku
	file.seekg(0, file.beg);	/// przesuniêcie pozycji w pliku na pocz¹tek
	el_count = bytes / sizeof(point_t); ///liczy ilosc elementow w pliku

	if (index > el_count)
	{
		return res_out_of_range;
	}

	int przesun = sizeof(point_t)  * index;

	file.seekg(0, przesun);
	file.read((char *)&p, sizeof(point_t));

	return res_ok;

}
