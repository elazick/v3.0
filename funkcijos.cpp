#include "strukt.h"


unsigned int countWordsInString(std::string const& str)
{
	std::stringstream stream(str);
	return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

std::vector<int> vedimas_ranka(std::vector<int>duom) {
	std::cout << "Veskite pazymius; 0 baigs vedima." << std::endl;
	int paz;
	bool renkuosi = true;
	while (renkuosi) {
		std::cout << "Veskite pazymi: ";
		std::cin >> paz;
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

double count_mediana(std::vector<int>pazymiai) {
	sort(pazymiai.begin(), pazymiai.end());
	double mediana;
	if (pazymiai.size() % 2 != 0) {
		mediana = (double)pazymiai[pazymiai.size() / 2];
	}
	else {
		mediana = (double)(pazymiai[(pazymiai.size() - 1) / 2] + pazymiai[pazymiai.size() / 2]) / 2;
	}
	return mediana;
}

double count_galutinis(std::vector<int> pazymiai, int sum, int egzas) {
	double galutinis = double(sum) / pazymiai.size() * 0.4 + egzas * 0.6;
	return galutinis;
}

std::vector<studentas> read_from_file(std::vector<studentas>stud) {
	studentas duom;
	std::string pasirinkimas;
	int stud_sk = 0;
	int pazymiu_sk;
	int paz;
	std::string line;
	std::ifstream readFile;
	readFile.open("studentai10000.txt");
	if (readFile.is_open()) {

		getline(readFile, line);

		pazymiu_sk = countWordsInString(line) - 3;
		while (!readFile.eof()) {
			stud.resize(stud.size() + 1);
			readFile >> stud.at(stud_sk).vardas;
			if (readFile.eof()) { stud.pop_back(); break; }
			readFile >> stud.at(stud_sk).pavarde;

			for (int i = 0; i < pazymiu_sk; i++) {
				readFile >> paz;
				stud.at(stud_sk).pazymiai.push_back(paz);
			}
			readFile >> stud.at(stud_sk).egzas;
			stud_sk++;
		}
	}
	else {
		std::cout << "KLAIDA" << std::endl;
		throw std::exception();
	}
	for (int i = 0; i < stud_sk; i++) {
		stud[i].sum = std::accumulate(stud[i].pazymiai.begin(), stud[i].pazymiai.end(), 0);
	}
	std::cout << "Ar skaiciuoti galutini, ar mediana?(G/M)";
	std::cin >> pasirinkimas;
	if (pasirinkimas == "G" || pasirinkimas == "g") {
		for (int i = 0; i < stud_sk; i++) {
			stud[i].rezultatas = count_galutinis(stud[i].pazymiai, stud[i].sum, stud[i].egzas);
		}
	}
	else if (pasirinkimas == "M" || pasirinkimas == "m") {
		for (int i = 0; i < stud_sk; i++) {
			stud[i].rezultatas = count_mediana(stud[i].pazymiai);
		}
	}
	else {
		std::cout << "KLAIDA" << std::endl;
		throw std::exception();
	}
	return stud;
}

void write_to_file(std::vector<studentas> duom) {
	std::ofstream output;
	output.open("rezultatai.txt");
	output << "Vardas\t" << "Pavarde\t" << "Rezultatas" << std::endl;
	for (int i = 0; i < duom.size(); i++) {
		output << duom.at(i).vardas << "\t" << duom.at(i).pavarde << "\t" << duom.at(i).rezultatas << std::endl;
	}
}

studentas stud() {
	studentas duom;
	std::string pasirinkimas;
	std::cout << "Veskite duomenis: " << std::endl;
	std::cout << "Vardas: ";
	std::cin >> duom.vardas;
	std::cout << "Pavarde: ";
	std::cin >> duom.pavarde;
	std::cout << "Egzamino rezultatas: ";
	std::cin >> duom.egzas;
	std::cout << "Ar vesite duomenis patys, ar generuoti atsitiktinai?(P/A)";
	std::cin >> pasirinkimas;
	if (pasirinkimas == "P" || pasirinkimas == "p") {
		duom.pazymiai = vedimas_ranka(duom.pazymiai);
	}
	else if (pasirinkimas == "A" || pasirinkimas == "a") {
		duom.pazymiai = auto_generavimas(duom.pazymiai);
	}
	else {
		std::cout << "KLAIDA" << std::endl;
		throw std::exception();
	}
	duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
	std::cout << "Ar skaiciuoti galutini, ar mediana?(G/M)";
	std::cin >> pasirinkimas;
	if (pasirinkimas == "G" || pasirinkimas == "g") {
		duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
	}
	else if (pasirinkimas == "M" || pasirinkimas == "m") {
		duom.rezultatas = count_mediana(duom.pazymiai);
	}
	else {
		std::cout << "KLAIDA" << std::endl;
		throw std::exception();
	}
	return duom;
}
