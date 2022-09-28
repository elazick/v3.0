#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>


struct studentai {
	std::string vardas;
	std::string pavarde;
	int egzas;	
	std::vector<int> pazymiai;
	double sum = 0;
	int nd_sk=0;
	double mediana;
	double galutinis;
};



int main() {		
	std::vector<studentai>stud;
	studentai duom;
	std::string renkuosi;
	bool pasirinkimas1 = true;
	std::cout << "Veskite duomenis." << std::endl;
	int count = 0;
	while (pasirinkimas1) {		
		stud.push_back(duom);
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
					stud[count].pazymiai.push_back(paz);
					stud[count].sum += paz;
					stud[count].nd_sk++;
				}
				else if (paz == 0) {
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
				stud[count].pazymiai.push_back(paz);
				stud[count].sum += paz;
				stud[count].nd_sk++;
			}
			
			//savikontrole
			//for (int j = 0; j < stud[count].pazymiai.size(); j++) {
				//std::cout << stud[count].pazymiai[j] << std::endl;
			//}

		}
		else {
			std::cout << "KLAIDA" << std::endl;
			return 0;
		}
		
		//savikontrole
		//for (int j = 0; j < stud[count].pazymiai.size(); j++) {
			//std::cout << stud[count].pazymiai[j] << std::endl;
		//}									
		
		std::cout << "Ar vesite dar duomenu?(T/N): ";
		std::cin >> renkuosi;
		if (renkuosi == "T" || renkuosi == "t") {
			count++;
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
		for (int i = 0; i < stud.size(); i++) {
			sort(stud[i].pazymiai.begin(), stud[i].pazymiai.end());			
			if (stud[i].pazymiai.size() % 2 != 0) {
				stud[i].mediana = (double)stud[i].pazymiai[stud[i].pazymiai.size() / 2];
			}
			else {
				stud[i].mediana = (double)(stud[i].pazymiai[(stud[i].pazymiai.size() - 1) / 2] + stud[i].pazymiai[stud[i].pazymiai.size() / 2]) / 2;;
			}

			std::cout << "Vardas\t" << "Pavarde\t" << "Mediana\t" << std::endl;
			std::cout << stud[i].vardas << "\t" << stud[i].pavarde << "\t" << stud[i].mediana << std::endl << std::endl;
		};
	}
	else if (renkuosi == "V" || renkuosi == "v") {
		for (int i = 0; i < stud.size(); i++) {
			stud[i].galutinis = double(stud[i].sum) / stud[i].pazymiai.size() * 0.4 + stud[i].egzas * 0.6;
		}
		

		for (int i = 0; i < stud.size(); i++) {

			std::cout << "Vardas\t" << "Pavarde\t" << "Galutinis\t" << std::endl;
			std::cout << stud[i].vardas << "\t" << stud[i].pavarde << "\t" << stud[i].galutinis << std::endl << std::endl;
		};


	}
	else {
		std::cout << "KLAIDA" << std::endl;
		return 0;
	}

};
