#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <exception>

struct studentas {
	std::string vardas;
	std::string pavarde;
	std::vector<int> pazymiai;
	int egzas;
	double rezultatas;
	double sum = 0;
};

unsigned int countWordsInString(std::string const& str);
std::vector<int> vedimas_ranka(std::vector<int>duom);
std::vector<int> auto_generavimas(std::vector<int>duom);
double count_mediana(std::vector<int>pazymiai);
double count_galutinis(std::vector<int> pazymiai, int sum, int egzas);
std::vector<studentas> read_from_file(std::vector<studentas>stud);
void write_to_file(std::vector<studentas> duom);
studentas stud();
