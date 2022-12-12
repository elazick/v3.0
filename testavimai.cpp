#include "strukt.h"

double vektoriaus_laikas(int a, std::string metodas) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + ".txt";
	std::ifstream failas(name);
	std::vector<studentas> stud;
	if (failas.is_open()) {
		std::string line;
		int pazymys;
		int paz_sk = 5;
		std::stringstream s(line);
		while (getline(failas, line)) {
			studentas duom;
			failas >> duom.vardas;
			failas >> duom.pavarde;
			for (int i = 0; i < paz_sk; i++) {
				failas >> pazymys;
				duom.pazymiai.push_back(pazymys);
			}
			failas >> duom.egzas;
			duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
			if (metodas == "V" || metodas == "v") {
				duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
			}
			else if (metodas == "M" || metodas == "m") {
				duom.rezultatas = count_mediana(duom.pazymiai, duom.egzas);
			}
			else { std::cout << "KLAIDA" << std::endl; exit(0); }
			stud.push_back(duom);
			duom.pazymiai.clear();
		}
		failas.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::vector<studentas> moksliukai;
	std::vector<studentas> vargsiukai;
	for (studentas b : stud) {
		if (b.rezultatas >= 5.0) {
			moksliukai.push_back(b);
		}
		else vargsiukai.push_back(b);
	}
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_v" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_v" + std::to_string(a) + ".txt");
	f1 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	f2 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	for (studentas c : moksliukai) {
		f1 << c.vardas << "\t" << c.pavarde << "\t" << c.rezultatas << std::endl;
	}
	for (studentas d : vargsiukai) {
		f2 << d.vardas << "\t" << d.pavarde << "\t" << d.rezultatas << std::endl;
	}
	moksliukai.clear();
	vargsiukai.clear();
	f1.close();
	f2.close();
	stud.clear();
	return laikas;
}

double list_laikas(int a, std::string metodas) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + ".txt";
	std::ifstream failas(name);
	std::list<studentas> stud;
	if (failas.is_open()) {
		std::string line;
		int pazymys;
		int paz_sk = 5;
		std::stringstream s(line);
		while (getline(failas, line)) {
			studentas duom;
			failas >> duom.vardas;
			failas >> duom.pavarde;
			for (int i = 0; i < paz_sk; i++) {
				failas >> pazymys;
				duom.pazymiai.push_back(pazymys);
			}
			failas >> duom.egzas;
			duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
			if (metodas == "V" || metodas == "v") {
				duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
			}
			else if (metodas == "M" || metodas == "m") {
				duom.rezultatas = count_mediana(duom.pazymiai, duom.egzas);
			}
			else { std::cout << "KLAIDA" << std::endl; exit(0); }
			stud.push_back(duom);
			duom.pazymiai.clear();
		}
		failas.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::list<studentas>moksliukai;
	std::list<studentas>vargsiukai;
	for (studentas b : stud) {
		if (b.rezultatas >= 5.0) {
			moksliukai.push_back(b);
		}
		else vargsiukai.push_back(b);
	}
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_l" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_l" + std::to_string(a) + ".txt");
	f1 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	f2 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	for (studentas c : moksliukai) {
		f1 << c.vardas << "\t" << c.pavarde << "\t" << c.rezultatas << std::endl;
	}
	for (studentas d : vargsiukai) {
		f2 << d.vardas << "\t" << d.pavarde << "\t" << d.rezultatas << std::endl;
	}
	moksliukai.clear();
	vargsiukai.clear();
	f1.close();
	f2.close();
	stud.clear();
	return laikas;
}

double list1(int a, std::string metodas) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + ".txt";
	std::ifstream failas(name);
	std::list<studentas> stud;
	if (failas.is_open()) {
		std::string line;
		int pazymys;
		int paz_sk = 5;
		std::stringstream s(line);
		while (getline(failas, line)) {
			studentas duom;
			failas >> duom.vardas;
			failas >> duom.pavarde;
			for (int i = 0; i < paz_sk; i++) {
				failas >> pazymys;
				duom.pazymiai.push_back(pazymys);
			}
			failas >> duom.egzas;
			duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
			if (metodas == "V" || metodas == "v") {
				duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
			}
			else if (metodas == "M" || metodas == "m") {
				duom.rezultatas = count_mediana(duom.pazymiai, duom.egzas);
			}
			else { std::cout << "KLAIDA" << std::endl; exit(0); }
			stud.push_back(duom);
			duom.pazymiai.clear();
		}
		failas.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	stud.sort(palyginimas);
	std::list<studentas> n;
	auto z = (std::find_if(stud.begin(), stud.end(), [](const studentas& s) {return s.rezultatas == 5.0;}));
	std::move(stud.begin(), z, std::back_inserter(n));
	stud.erase(stud.begin(), z);
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_l1_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_l1_" + std::to_string(a) + ".txt");
	f1 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	f2 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	for (studentas m : stud) {
		f1 << m.vardas << "\t" << m.pavarde << "\t" << m.rezultatas << std::endl;
	}
	for (studentas m : n) {
		f2 << m.vardas << "\t" << m.pavarde << "\t" << m.rezultatas << std::endl;
	}
	n.clear();
	f1.close();
	f2.close();
	stud.clear();
	return laikas;
}

double list2(int a, std::string metodas) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + ".txt";
	std::ifstream failas(name);
	std::list<studentas> stud;
	if (failas.is_open()) {
		std::string line;
		int pazymys;
		int paz_sk = 5;
		std::stringstream s(line);
		while (getline(failas, line)) {
			studentas duom;
			failas >> duom.vardas;
			failas >> duom.pavarde;
			for (int i = 0; i < paz_sk; i++) {
				failas >> pazymys;
				duom.pazymiai.push_back(pazymys);
			}
			failas >> duom.egzas;
			duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
			if (metodas == "V" || metodas == "v") {
				duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
			}
			else if (metodas == "M" || metodas == "m") {
				duom.rezultatas = count_mediana(duom.pazymiai, duom.egzas);
			}
			else { std::cout << "KLAIDA" << std::endl; exit(0); }
			stud.push_back(duom);
			duom.pazymiai.clear();
		}
		failas.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	stud.sort(palyginimas);
	std::list<studentas> moksliukai;
	std::list<studentas> vargsiukai;
	auto z = (std::find_if(stud.begin(), stud.end(), [](const studentas& s) {return s.rezultatas == 5.0; }));
	std::move(stud.begin(), z, std::back_inserter(vargsiukai));
	std::move(z, stud.end(), std::back_inserter(moksliukai));
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_l2_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_l2_" + std::to_string(a) + ".txt");
	f1 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	f2 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	for (studentas c : moksliukai) {
		f1 << c.vardas << "\t" << c.pavarde << "\t" << c.rezultatas << std::endl;
	}
	for (studentas d : vargsiukai) {
		f2 << d.vardas << "\t" << d.pavarde << "\t" << d.rezultatas << std::endl;
	}
	moksliukai.clear();
	vargsiukai.clear();
	f1.close();
	f2.close();
	stud.clear();
	return laikas;
}

double vector1(int a, std::string metodas) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + ".txt";
	std::ifstream failas(name);
	std::vector<studentas> stud;
	if (failas.is_open()) {
		std::string line;
		int pazymys;
		int paz_sk = 5;
		std::stringstream s(line);
		while (getline(failas, line)) {
			studentas duom;
			failas >> duom.vardas;
			failas >> duom.pavarde;
			for (int i = 0; i < paz_sk; i++) {
				failas >> pazymys;
				duom.pazymiai.push_back(pazymys);
			}
			failas >> duom.egzas;
			duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
			if (metodas == "V" || metodas == "v") {
				duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
			}
			else if (metodas == "M" || metodas == "m") {
				duom.rezultatas = count_mediana(duom.pazymiai, duom.egzas);
			}
			else { std::cout << "KLAIDA" << std::endl; exit(0); }
			stud.push_back(duom);
			duom.pazymiai.clear();
		}
		failas.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::sort(stud.begin(), stud.end(), palyginimas);
	std::vector<studentas> n;
	auto z = (std::find_if(stud.begin(), stud.end(), [](const studentas& s) {return s.rezultatas == 5.0; }));
	std::move(stud.begin(), z, std::back_inserter(n));
	stud.erase(stud.begin(), z);
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_v1_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_v1_" + std::to_string(a) + ".txt");
	f1 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	f2 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	for (studentas m : stud) {
		f1 << m.vardas << "\t" << m.pavarde << "\t" << m.rezultatas << std::endl;
	}
	for (studentas m : n) {
		f2 << m.vardas << "\t" << m.pavarde << "\t" << m.rezultatas << std::endl;
	}
	n.clear();
	f1.close();
	f2.close();
	stud.clear();
	return laikas;
}

double vector2(int a, std::string metodas) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + ".txt";
	std::ifstream failas(name);
	std::vector<studentas> stud;
	if (failas.is_open()) {
		std::string line;
		int pazymys;
		int paz_sk = 5;
		std::stringstream s(line);
		while (getline(failas, line)) {
			studentas duom;
			failas >> duom.vardas;
			failas >> duom.pavarde;
			for (int i = 0; i < paz_sk; i++) {
				failas >> pazymys;
				duom.pazymiai.push_back(pazymys);
			}
			failas >> duom.egzas;
			duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
			if (metodas == "V" || metodas == "v") {
				duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
			}
			else if (metodas == "M" || metodas == "m") {
				duom.rezultatas = count_mediana(duom.pazymiai, duom.egzas);
			}
			else { std::cout << "KLAIDA" << std::endl; exit(0); }
			stud.push_back(duom);
			duom.pazymiai.clear();
		}
		failas.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::sort(stud.begin(), stud.end(), palyginimas);
	std::vector<studentas> moksliukai;
	std::vector<studentas> vargsiukai;
	auto z = (std::find_if(stud.begin(), stud.end(), [](const studentas& s) {return s.rezultatas == 5.0; }));
	std::move(stud.begin(), z, std::back_inserter(vargsiukai));
	std::move(z, stud.end(), std::back_inserter(moksliukai));
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_v2_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_v2_" + std::to_string(a) + ".txt");
	f1 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	f2 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	for (studentas c : moksliukai) {
		f1 << c.vardas << "\t" << c.pavarde << "\t" << c.rezultatas << std::endl;
	}
	for (studentas d : vargsiukai) {
		f2 << d.vardas << "\t" << d.pavarde << "\t" << d.rezultatas << std::endl;
	}
	moksliukai.clear();
	vargsiukai.clear();
	f1.close();
	f2.close();
	stud.clear();
	return laikas;
}

double st_part(int a, std::string metodas) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + ".txt";
	std::ifstream failas(name);
	std::vector<studentas> stud;
	if (failas.is_open()) {
		std::string line;
		int pazymys;
		int paz_sk = 5;
		std::stringstream s(line);
		while (getline(failas, line)) {
			studentas duom;
			failas >> duom.vardas;
			failas >> duom.pavarde;
			for (int i = 0; i < paz_sk; i++) {
				failas >> pazymys;
				duom.pazymiai.push_back(pazymys);
			}
			failas >> duom.egzas;
			duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
			if (metodas == "V" || metodas == "v") {
				duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
			}
			else if (metodas == "M" || metodas == "m") {
				duom.rezultatas = count_mediana(duom.pazymiai, duom.egzas);
			}
			else { std::cout << "KLAIDA" << std::endl; exit(0); }
			stud.push_back(duom);
			duom.pazymiai.clear();
		}
		failas.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::vector<studentas> n;
	auto it = std::stable_partition(stud.begin(), stud.end(), [](const studentas& s) {return s.rezultatas < 5.0; });
	std::copy(stud.begin(), it, std::back_inserter(n));
	stud.erase(stud.begin(), it);
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_p_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_p_" + std::to_string(a) + ".txt");
	f1 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	f2 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	for (studentas m : stud) {
		f1 << m.vardas << "\t" << m.pavarde << "\t" << m.rezultatas << std::endl;
	}
	for (studentas m : n) {
		f2 << m.vardas << "\t" << m.pavarde << "\t" << m.rezultatas << std::endl;
	}
	n.clear();
	f1.close();
	f2.close();
	stud.clear();
	return laikas;
}

double partition(int a, std::string metodas) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + ".txt";
	std::ifstream failas(name);
	std::vector<studentas> stud;
	if (failas.is_open()) {
		std::string line;
		int pazymys;
		int paz_sk = 5;
		std::stringstream s(line);
		while (getline(failas, line)) {
			studentas duom;
			failas >> duom.vardas;
			failas >> duom.pavarde;
			for (int i = 0; i < paz_sk; i++) {
				failas >> pazymys;
				duom.pazymiai.push_back(pazymys);
			}
			failas >> duom.egzas;
			duom.sum = std::accumulate(duom.pazymiai.begin(), duom.pazymiai.end(), 0);
			if (metodas == "V" || metodas == "v") {
				duom.rezultatas = count_galutinis(duom.pazymiai, duom.sum, duom.egzas);
			}
			else if (metodas == "M" || metodas == "m") {
				duom.rezultatas = count_mediana(duom.pazymiai, duom.egzas);
			}
			else { std::cout << "KLAIDA" << std::endl; exit(0); }
			stud.push_back(duom);
			duom.pazymiai.clear();
		}
		failas.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::vector<studentas> moksliukai;
	std::vector<studentas> vargsiukai;
	std::partition_copy(stud.begin(), stud.end(), std::back_inserter(vargsiukai), std::back_inserter(moksliukai), [](const studentas &s) {return s.rezultatas < 5.0; });
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_part_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_part_" + std::to_string(a) + ".txt");
	f1 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	f2 << "Vardas" << "\tPavarde" << "\tRezultatas" << std::endl;
	for (studentas c : moksliukai) {
		f1 << c.vardas << "\t" << c.pavarde << "\t" << c.rezultatas << std::endl;
	}
	for (studentas d : vargsiukai) {
		f2 << d.vardas << "\t" << d.pavarde << "\t" << d.rezultatas << std::endl;
	}
	moksliukai.clear();
	vargsiukai.clear();
	f1.close();
	f2.close();
	stud.clear();
	return laikas;
}