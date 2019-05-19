#pragma once
#define USER_NAME    "Imiê"         //Proszê wpisaæ swoje Imiê
#define USER_SURNAME "Nazwisko"     //Proszê wpisaæ swoje Nazwizko
#define USER_GROUP   0 				//Proszê wpisac numer grupy

struct point_t
{
    double x, y, z;
};

enum result_en {
    res_ok,             
    res_file_not_open,          /*!< Plik nie zosta³ poprawnie otwarty      */
    res_out_of_range,           /*!< Podany indeks przekracza rozmiar pliku */
    res_error,                  /*!< Inny b³¹d                              */
};
