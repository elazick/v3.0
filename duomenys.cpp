#include "class.h"

//v0.1
std::vector<int> vedimas_ranka(std::vector<int>duom) {
	std::cout << "Veskite pazymius; 0 baigs vedima." << std::endl;
	int paz;
	bool renkuosi = true;
	while (renkuosi) {
		std::cout << "Veskite pazymi: ";
		std::cin >> paz;
		if (std::cin.fail()) {
			std::cout << "Prasome ivesti skaiciu\n";
			std::cin.clear();
			std::cin.ignore(500, '\n');
			std::cout << "Veskite pazymi: ";
			std::cin >> paz;
		}
		if (paz != 0) {
			duom.push_back(paz);
		}
		else if (paz == 0) {
			renkuosi = false;
		}
	}
	return duom;
}


//v0.1
std::vector<int> auto_generavimas(std::vector<int>duom) {
	srand(time(NULL));
	int pazymiu_sk = ((rand() % 10) + 1);
	int paz;
	for (int j = 0; j < pazymiu_sk; j++) {
		paz = (rand() % 10) + 1;
		duom.push_back(paz);
	}
	return duom;
}


//v0.1
studentas stud() {
	studentas duom;
	std::string vardas, pavarde, pasirinkimas;
	int egzas, sum;
	double galutinis;
	std::vector<int>pazym;
	std::cout << "Veskite duomenis: " << std::endl;
	std::cout << "Vardas: ";
	std::cin >> vardas;
	if (std::cin.fail()) {
		std::cout << "Netinkama ivestis, bandykite darkart\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout << "Vardas: ";
		std::cin >> vardas;
	}
	std::cout << "Pavarde: ";
	std::cin >> pavarde;
	if (std::cin.fail()) {
		std::cout << "Netinkama ivestis, bandykite darkart\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout << "Pavarde: ";
		std::cin >> pavarde;
	}
	std::cout << "Egzamino rezultatas: ";
	std::cin >> egzas;
	if (std::cin.fail()) {
		std::cout << "Netinkama ivestis, bandykite darkart\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout << "Egzamino rezultatas: ";
		std::cin >> egzas;
	}
	duom.setVardas(vardas);
	duom.setPavarde(pavarde);
	duom.setEgzas(egzas);
	std::cout << "Ar vesite duomenis patys, ar generuoti atsitiktinai?(P/A)";
	std::cin >> pasirinkimas;
	if (std::cin.fail()) {
		std::cout << "Netinkama ivestis, bandykite darkart\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout << "Ar vesite duomenis patys, ar generuoti atsitiktinai?(P/A)";
		std::cin >> pasirinkimas;
	}
	if (pasirinkimas == "P" || pasirinkimas == "p") {
		pazym = vedimas_ranka(pazym);
		duom.setPazymiai(pazym);
	}
	else if (pasirinkimas == "A" || pasirinkimas == "a") {
		pazym = auto_generavimas(pazym);
		duom.setPazymiai(pazym);
	}
	sum = accumulate(pazym.begin(), pazym.end(), 0);
	duom.setSum(sum);
	std::cout << "Galutini skaiciuoti su vidurkiu ar mediana?(V/M)";
	std::cin >> pasirinkimas;
	if (std::cin.fail()) {
		std::cout << "Netinkama ivestis, bandykite darkart\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout << "Galutini skaiciuoti su vidurkiu ar mediana?(V/M)";
		std::cin >> pasirinkimas;
	}
	if (pasirinkimas == "V" || pasirinkimas == "v") {
		galutinis = count_galutinis(pazym, sum, egzas);
		duom.setRezultatas(galutinis);
	}
	else if (pasirinkimas == "M" || pasirinkimas == "m") {
		galutinis = count_mediana(pazym, egzas);
		duom.setRezultatas(galutinis);
	}
	return duom;
}
