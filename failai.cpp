#include "strukt.h"

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
	std::cout << "Galutini skaiciuoti su vidurkiu ar mediana?(V/M)";
	std::cin >> pasirinkimas;
	if (pasirinkimas == "V" || pasirinkimas == "v") {
		for (int i = 0; i < stud_sk; i++) {
			stud[i].rezultatas = count_galutinis(stud[i].pazymiai, stud[i].sum, stud[i].egzas);
		}
	}
	else if (pasirinkimas == "M" || pasirinkimas == "m") {
		for (int i = 0; i < stud_sk; i++) {
			stud[i].rezultatas = count_mediana(stud[i].pazymiai, stud[i].egzas);
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
	output.close();
}

void stud_gen(int a) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + std::string(".txt");
	std::ofstream failas(name);
	failas << "Vardas" << "\tPavarde" << "\tPazymiai" << "\tEgzaminas" << std::endl;
	for (int i = 1; i < a + 1; i++) {
		failas << "Vardas" << i << "\tPavarde" << i << "\t" << pazGeneravimas() << "\t" << egzo_rezultatas() << std::endl;
	}
	std::cout << "Failo is " << a << " irasu sukurimo laikas:" << t.elapsed() << std::endl;
}

std::vector<studentas> gen_nuskaitymas(int a) {
	Timer t;
	std::string pasirinkimas;
	std::string name = "stud" + std::to_string(a) + std::string(".txt");
	std::ifstream failas(name);
	std::vector<studentas> stud;
	int stud_sk = 0;
	if (failas.is_open()) {
		std::string line;
		std::vector<int> pazymiai;
		int paz;
		int paz_sk = 5;
		std::stringstream s(line);
		while (getline(failas, line, '\n')) {
			stud.resize(stud.size() + 1);
			failas >> stud.at(stud_sk).vardas;
			if (stud.at(stud_sk).vardas == "") { break; }
			failas >> stud.at(stud_sk).pavarde;
			for (int i = 0; i < paz_sk; i++) {
				failas >> paz;
				stud.at(stud_sk).pazymiai.push_back(paz);
			}
			failas >> stud.at(stud_sk).egzas;
			stud.at(stud_sk).sum = std::accumulate(stud.at(stud_sk).pazymiai.begin(), stud.at(stud_sk).pazymiai.end(), 0);
			stud_sk++;
		}
		failas.close();
		std::cout << "Failo is " << a << " irasu nuskaitymo laikas: " << t.elapsed() << std::endl;
	}
	else {
		std::cout << "KLAIDA" << std::endl;
		exit(0);
	}
	std::cout << "Galutini skaiciuoti su vidurkiu ar mediana?(V/M)";
	std::cin >> pasirinkimas;
	if (pasirinkimas == "V" || pasirinkimas == "v") {
		for (int i = 0; i < stud_sk; i++) {
			stud[i].rezultatas = count_galutinis(stud[i].pazymiai, stud[i].sum, stud[i].egzas);
		}
	}
	else if (pasirinkimas == "M" || pasirinkimas == "m") {
		for (int i = 0; i < stud_sk; i++) {
			stud[i].rezultatas = count_mediana(stud[i].pazymiai, stud[i].egzas);
		}
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	return stud;
}

void gen_irasymas(std::vector<studentas> duom, std::string a) {
	studentas stud;
	Timer t;
	std::vector<studentas> moksliukai;
	std::vector<studentas>vargsiukai;
	for (int i = 0; i < duom.size() - 1; i++) {
		stud = duom[i];
		if (stud.rezultatas >= 5.0) {
			moksliukai.push_back(stud);
		}
		else {
			vargsiukai.push_back(stud);
		}
	}
	std::cout << "Studentu suskirstymas i 2 grupes uztruko " << t.elapsed() << std::endl;
	t.reset();
	std::ofstream f1("moksliukai" + a + ".txt");
	std::ofstream f2("vargsiukai" + a + ".txt");
	f1 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	f2 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	for (int i = 0; i < moksliukai.size(); i++) {
		stud = moksliukai[i];

		f1 << stud.vardas << "\t" << stud.pavarde << "\t" << stud.rezultatas << std::endl;
	}
	for (int i = 0; i < vargsiukai.size(); i++) {
		stud = vargsiukai[i];
		f2 << stud.vardas << "\t" << stud.pavarde << "\t" << stud.rezultatas << std::endl;
	}
	std::cout << "Studentu grupiu rasymas i 2 failus uztruko " << t.elapsed() << std::endl;
};