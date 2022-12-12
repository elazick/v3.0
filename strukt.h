#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <exception>
#include <chrono>
#include <cstdlib>
#include <list>

struct studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int egzas;
    double rezultatas;
    double sum = 0;
};

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{ std::chrono::high_resolution_clock::now() } {}

    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }

    double elapsed() const {
        return std::chrono::duration<double>
            (std::chrono::high_resolution_clock::now() - start).count();
    }
};

studentas stud();
unsigned int countWordsInString(std::string const& str);
double count_mediana(std::vector<int>pazymiai, int egzas);
double count_galutinis(std::vector<int> pazymiai, int sum, int egzas);
std::string pazGeneravimas();
void stud_gen(int a);
std::vector<studentas> gen_nuskaitymas(int a);
void gen_irasymas(std::vector<studentas> duom, std::string a);
std::vector<int> vedimas_ranka(std::vector<int>duom);
std::vector<int> auto_generavimas(std::vector<int>duom);
std::vector<studentas> read_from_file(std::vector<studentas>stud);
void write_to_file(std::vector<studentas> duom);
double vektoriaus_laikas(int a, std::string metodas);
double list_laikas(int a, std::string metodas);
std::string egzo_rezultatas();
bool palyginimas(const studentas& a, const studentas& b);
double list1(int a, std::string metodas);
double list2(int a, std::string metodas);
double vector1(int a, std::string metodas);
double vector2(int a, std::string metodas);
double st_part(int a, std::string metodas);
double partition(int a, std::string metodas);