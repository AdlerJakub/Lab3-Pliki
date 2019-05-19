#include "Logger.h"
#include "Defines.h"

using namespace std;

CLogger::CLogger(string filePath, bool binary)
{
	this->binary = binary;
	if (binary)
	{
		file.open(filePath, ios::binary | ios::out);
	}
	else
	{
		file.open(filePath, ios::out);
	}
		
	
}

CLogger::~CLogger()
{
	if(file.is_open() == true)
	file.close(); /// zamykamy plik
}


result_en CLogger::Log(const point_t &p)
{
	if (file.is_open() == false)
	{
		return res_file_not_open;
	}
	if (binary == true)
	{
		int fBytes = sizeof(point_t);
		file.write((char *)&p, fBytes);
		return res_ok;
	}
	if(binary== false)
	{
		file << p.x << ";" << p.y << ";" << p.z << endl;
		return res_ok;
	}
	
}

result_en CLogger::Log(const vector<point_t> &pointsVector)
{
	int i, fBytes;
	if (file.is_open() == false)
	{
		return res_file_not_open;
	}
	if (binary == true)
	{
		fBytes = sizeof(point_t) * pointsVector.size();
		
			file.write((const char*)&pointsVector, fBytes);
		
			return res_ok;
	}
	else
	{
		for (i = 0; i < pointsVector.size(); i++)
		{
			file << pointsVector[i].x << ";" << pointsVector[i].y << ";" << pointsVector[i].z << endl;
		}
		return res_ok;
	}



}