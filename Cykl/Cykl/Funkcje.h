#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "Struktury.h"

std::string oczytanie_z_pliku(const std::string& plik_z_cyklami);


int int_ze_stringa(std::string& str);


void wypisz_vector(std::vector<int>& vector);


bool zawartosc_vectora(std::vector<int>& vector, int value);


void szukanie_cykli(Graf& graf, std::vector<int>& cykl, int w_poczatkowy, int sasiad, std::ofstream* zapis);


void stworz_graf(std::string& wynik, Graf& graf);


void drukuj_graf(Graf& graf);


void zapisz_cykle (Graf& graf, const std::string& plik_z_cyklami);


#endif