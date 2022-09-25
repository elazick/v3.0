//neveikia -- vedant antra studenta programa sustoja, nes ties antru/treciu pazymiu neberanta atminties

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>



struct studentai {
	std::string vardas;
	std::string pavarde;
	int egzas;
	int n = 1;
	int *pazymiai = new int[n];
	double sum = 0;
	int nd_sk=0;
	double mediana;
	double galutinis;
};



int main() {		
	studentai duom;
	int n = 1;
	studentai* stud = new studentai[n];
	std::string renkuosi;
	bool pasirinkimas1 = true;
	std::cout << "Veskite duomenis." << std::endl;
	int count = 0;
	while (pasirinkimas1) {		
		stud[count] = duom;
								
		srand(time(0));
		
		std::cout << "Veskite varda: ";
		std::cin >> stud[count].vardas;
		std::cout << "Veskite pavarde: ";
		std::cin >> stud[count].pavarde;
		std::cout << "Veskite egzamino rezultata: ";
		std::cin >> stud[count].egzas;
		
		std::cout << "Ar pazymius vesite patys, ar generuoti atsitiktinai?(P/A)";
		std::cin >> renkuosi;
		if (renkuosi == "P" || renkuosi == "p") {
			std::cout << "Veskite pazymius; 0 baigs vedima." << std::endl;
			while (pasirinkimas1) {
				int paz;
				std::cout << "Veskite pazymi: ";
				std::cin >> paz;
				if (paz != 0) {
					if (stud[count].n != 1) {
						int* newPaz = new int[stud[count].n];
						std::copy(stud[count].pazymiai, stud[count].pazymiai + std::min(stud[count].n - 1, stud[count].n), newPaz);
						delete[] stud[count].pazymiai;
						stud[count].pazymiai = newPaz;
					}
					stud[count].pazymiai[stud[count].n-1] = paz;
					stud[count].n++;
					stud[count].sum += paz;
					stud[count].nd_sk++;
				}
				else if (paz == 0) {
					stud[count].n--;
					pasirinkimas1 = false;
				}
				else {
					std::cout << "KLAIDA" << std::endl;
					return 0;
				}
			}

		}
		else if (renkuosi == "A" || renkuosi == "a") {
			int paz_sk = ((rand() % 10) + 1);
			int paz;
			for (int i = 0; i < paz_sk; i++) {				
				paz = (rand() % 10) + 1;
				stud[count].pazymiai[stud[count].n - 1] = paz;
				stud[count].n++;
				int* newPaz = new int[stud[count].n];
				std::copy(stud[count].pazymiai, stud[count].pazymiai + std::min(stud[count].n - 1, stud[count].n), newPaz);
				delete[] stud[count].pazymiai;
				stud[count].pazymiai = newPaz;
				stud[count].sum += paz;
				stud[count].nd_sk++;
			}
			
			//savikontrole
			for (int j = 0; j < stud[count].n - 1; j++) {
				std::cout << stud[count].pazymiai[j] << std::endl;
			}

		}
		else {
			std::cout << "KLAIDA" << std::endl;
			return 0;
		}
		
		//savikontrole
		for (int j = 0; j < stud[count].n; j++) {
			std::cout << stud[count].pazymiai[j] << std::endl;
		}									
		
		std::cout << "Ar vesite dar duomenu?(T/N): ";
		std::cin >> renkuosi;
		if (renkuosi == "T" || renkuosi == "t") {
			count++;
			n++;
			studentai* naujas = new studentai[n];
			std::copy(stud, stud + std::min(n - 1, n), naujas);
			delete[] stud;
			stud = naujas;
			//duom.pazymiai.clear();
			pasirinkimas1 = true;			
		}
		else if (renkuosi == "N" || renkuosi == "n") {
			pasirinkimas1 = false;
		}
		else {
			std::cout << "KLAIDA" << std::endl;
			return 0;
		}
	}

	std::cout << "Mediana ar vidurkis?(M/V)";
	std::cin >> renkuosi;
	if (renkuosi == "M" || renkuosi == "m") {	
		//stud.push_back(duom);
		for (int i = 0; i < n; i++) {
			std::sort(stud[i].pazymiai, stud[i].pazymiai + (sizeof(stud[i].pazymiai) / sizeof(stud[i].pazymiai[0])));
			if (stud[i].n % 2 != 0) {
				stud[i].mediana = (double)stud[i].pazymiai[stud[i].n / 2];
			}
			else {
				stud[i].mediana = (double)(stud[i].pazymiai[(stud[i].n - 1) / 2] + stud[i].pazymiai[stud[i].n / 2]) / 2;;
			}

			std::cout << "Vardas\t" << "Pavarde\t" << "Mediana\t" << std::endl;
			std::cout << stud[i].vardas << "\t" << stud[i].pavarde << "\t" << stud[i].mediana << std::endl << std::endl;
		};
	}
	else if (renkuosi == "V" || renkuosi == "v") {
		for (int i = 0; i < n; i++) {
			stud[i].galutinis = double(stud[i].sum) / stud[i].n * 0.4 + stud[i].egzas * 0.6;
		}
		

		for (int i = 0; i < n; i++) {

			std::cout << "Vardas\t" << "Pavarde\t" << "Galutinis\t" << std::endl;
			std::cout << stud[i].vardas << "\t" << stud[i].pavarde << "\t" << stud[i].galutinis << std::endl << std::endl;
		};


	}
	else {
		std::cout << "KLAIDA" << std::endl;
		return 0;
	}

};
