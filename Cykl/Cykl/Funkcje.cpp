#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Funkcje.h"
#include "Struktury.h"


std::string oczytanie_z_pliku(const std::string& plik_z_cyklami) {

    std::ifstream file(plik_z_cyklami);

    char znak;
    std::string graf = "";



    while (!file.eof())
    {
        while (!file.eof()) {
            znak = file.get();

            if (znak != ' ' && znak != '\n')
            {
                graf += znak;
            }

            for (int i = 0; i < graf.size(); i++)
            {
                if (graf[i] == ',' || graf[i] == '-' || graf[i] == '>')
                {
                    graf[i] = ' ';
                }
            }
        }

    }

    file.close();

    return graf;
}

int int_ze_stringa(std::string& str) {

    int wynik = 0;

    bool znajdz_pierwszy_int = false;

    int i = 0;
    for (; i < str.size(); i++) {

        if (str[i] <= '9' && str[i] >= '0')
        {
            wynik *= 10;
            wynik += str[i] - '0';
            znajdz_pierwszy_int = true;
        }
        else
        {
            if (znajdz_pierwszy_int)
            {
                break;
            }
        }

    }

    std::string reszta = str.substr(i + 1, str.size());
    str = reszta;

    return wynik;
}

void wypisz_vector(std::vector<int>& vector) {
    for (int i : vector)
    {
        std::cout << i << " ";
    }
}

bool zawartosc_vectora(std::vector<int>& vector, int value) {

    for (int i : vector)
    {
        if (i == value) {
            return true;
        }
    }

    return false;
}

void szukanie_cykli(Graf& graf, std::vector<int>& cykl, int wierz_poczatkowy, int sasiad, std::ofstream* zapis) {


    if (graf.find(sasiad) == graf.end() || graf.at(sasiad).krawedzie.size() == 0) {
        *zapis << "Nie znaleziono cyklu: " << wierz_poczatkowy << std::endl << std::endl;
        return;
    }

    for (krawedz kr : graf.at(sasiad).krawedzie) {

        if (kr.wierz_koncowy == wierz_poczatkowy)
        {
            *zapis << "Znaleziono cykl dla liczby: " << wierz_poczatkowy << "|| ";
            for (int i : cykl)
            {
                *zapis << i << " ";
            }
            *zapis << std::endl << std::endl;
            continue;
        }

        if (!zawartosc_vectora(cykl, kr.wierz_koncowy))
        {
            cykl.push_back(kr.wierz_koncowy);
            szukanie_cykli(graf, cykl, wierz_poczatkowy, kr.wierz_koncowy, zapis);
            cykl.pop_back();
        }

    }

}


void stworz_graf(std::string& wynik, Graf& graf) {


    while (wynik.size() > 1)
    {
        int wierz_poczatkowy = int_ze_stringa(wynik);
        krawedz krawedz;
        krawedz.wierz_koncowy = int_ze_stringa(wynik);

        graf[wierz_poczatkowy].krawedzie.push_back(krawedz);
    }


}




void drukuj_graf(Graf& graf) {

    for (std::pair<int, wierzcholek> num_wierzcholka : graf) {

        std::cout << num_wierzcholka.first << ':';

        for (krawedz krawedz : num_wierzcholka.second.krawedzie) {
            std::cout << krawedz.wierz_koncowy << ',';
        }

        std::cout << '\n';

    }

}


void zapisz_cykle(Graf& graf, const std::string& plik_z_cyklami) {
    
    std::ofstream zapis(plik_z_cyklami, std::ios::out);

    for (std::pair<int, wierzcholek> wierzcholek : graf)
    {

        std::vector<int> cycle;
        cycle.push_back(wierzcholek.first);

        szukanie_cykli(graf, cycle, wierzcholek.first, wierzcholek.first, &zapis);
    }

    zapis.close();
}