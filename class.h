#ifndef CLASS_H
#define CLASS_H
#endif
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
#include <time.h>
#include <istream>


class zmogus {
protected:
	std::string vardas;
	std::string pavarde;

public:
	zmogus() {}; //def konstruktorius

	//getteriai
	inline std::string getVardas() const { return vardas; }
	inline std::string getPavarde() const { return pavarde; }

	//setteriai
	inline void setVardas(std::string _vardas) { vardas = _vardas; }
	inline void setPavarde(std::string _pavarde) { pavarde = _pavarde; }

	~zmogus() {}; //destruktorius
};

class studentas : public zmogus {
	std::vector<int> pazymiai;
	int paz_sk;
	int sum;
	double egzas;
	double galutinis;

public:
	studentas() : galutinis(0) { } //default konstruktorius
	studentas(std::string vardas, std::string pavarde);

	//getteriai
	inline std::vector<int> getPazymiai() const { return pazymiai; }
	inline int getEgzas() const { return egzas; }
	inline int getSum() const { return sum; }
	inline double getRezultatas() const { return galutinis; }

	//setteriai
	inline void setPazymiai(std::vector<int>pazymiai) { studentas::pazymiai = pazymiai; }
	inline void setSum(int sum) { studentas::sum = sum; }
	inline void setEgzas(int egzas) { studentas::egzas = egzas; }
	inline void setRezultatas(double galutinis) { studentas::galutinis = galutinis; }

	//copy constructor
	studentas(const studentas& other) :
		pazymiai(other.pazymiai),
		egzas(other.egzas),
		paz_sk(other.paz_sk),
		sum(other.sum),
		galutinis(other.galutinis) {
			
			vardas = other.getVardas();
			pavarde = other.getPavarde();
	};

	//copy assignment operator
	studentas& operator = (const studentas& other) {
		vardas = other.vardas;
		pavarde = other.pavarde;
		pazymiai = other.pazymiai;
		paz_sk = other.paz_sk;
		sum = other.sum;
		galutinis = other.galutinis;
		return *this;
	}

	~studentas() { }; //destruktorius
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
double count_galutinis(std::vector<int> pazymiai, int sum, int egzas);
double count_mediana(std::vector<int>pazymiai, int egzas);
std::string egzo_rezultatas();
std::string pazGeneravimas();
bool palyginimas(const studentas& a, const studentas& b);
std::vector<int> vedimas_ranka(std::vector<int>duom);
std::vector<int> auto_generavimas(std::vector<int>duom);
studentas stud();
unsigned int countWordsInString(std::string const& str);
std::vector<studentas> read_from_file(std::string name, std::vector<studentas>stud, std::string metodas);
void write_to_file(std::vector<studentas>duom);
void stud_gen(int a);
std::vector<studentas> gen_nuskaitymas(std::vector<studentas> duom, int a, std::string metodas);
void gen_irasymas(std::vector<studentas> duom, std::string a);
double list1(int a, std::string metodas);
double list2(int a, std::string metodas);
double vector1(int a, std::string metodas);
double vector2(int a, std::string metodas);
double st_part(int a, std::string metodas);
double partition(int a, std::string metodas);