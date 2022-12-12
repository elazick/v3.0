#include "strukt.h"


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
		else {
			std::cout << "KLAIDA" << std::endl;
			throw std::exception();;
		}
	}
	return duom;
}

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

studentas stud() {
	studentas duom;
	std::string pasirinkimas;
	std::cout << "Veskite duomenis: " << std::endl;
	std::cout << "Vardas: ";
	std::cin >> duom.vardas;
	if (std::cin.fail()) {
		std::cout << "Netinkama ivestis, bandykite darkart\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout << "Vardas: ";
		std::cin >> duom.vardas;
	}
	std::cout << "Pavarde: ";
	std::cin >> duom.pavarde;
	if (std::cin.fail()) {
		std::cout << "Netinkama ivestis, bandykite darkart\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout << "Pavarde: ";
		std::cin >> duom.pavarde;
	}
	std::cout << "Egzamino rezultatas: ";
	std::cin >> duom.egzas;
	if (std::cin.fail()) {
		std::cout << "Netinkama ivestis, bandykite darkart\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cout << "Egzamino rezultatas: ";
		std::cin >> duom.egzas;
	}
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
		duom.pazymiai = vedimas_ranka(duom.pazymiai);
	}
	else if (pasirinkimas == "A" || pasirinkimas == "a") {
		duom.pazymiai = auto_generavimas(duom.pazymiai);
	}
	
	duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
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
		duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
	}
	else if (pasirinkimas == "M" || pasirinkimas == "m") {
		duom.rezultatas = count_mediana(duom.pazymiai, duom.egzas);
	}
	return duom;
}
