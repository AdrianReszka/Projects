#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <unordered_map>
#include <vector>
#include <string>


struct krawedz
{
    int wierz_koncowy;
};


struct wierzcholek
{
    std::vector<krawedz> krawedzie;
};

typedef
std::unordered_map<int, wierzcholek> Graf;

   
#endif
