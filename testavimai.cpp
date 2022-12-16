#include "class.h"

double list1(int a, std::string metodas) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + ".txt";
	std::ifstream file(name);
	std::list<studentas>stud;
	if (file.is_open()) {
		std::string line;
		int paz, egzas, sum;
		int paz_sk = 5;
		double galutinis;
		std::vector<int>pazymiai;
		std::string vardas, pavarde;
		std::stringstream s(line);
		while (getline(file, line)) {
			studentas duom;
			file >> vardas;
			duom.setVardas(vardas);
			file >> pavarde;
			duom.setPavarde(pavarde);
			for (int i = 0; i < paz_sk; i++) {
				file >> paz;
				pazymiai.push_back(paz);
			}
			duom.setPazymiai(pazymiai);
			sum = accumulate(pazymiai.begin(), pazymiai.end(), 0);
			duom.setSum(sum);
			file >> egzas;
			duom.setEgzas(egzas);
			if (metodas == "V" || metodas == "v") {
				galutinis = count_galutinis(pazymiai, sum, egzas);
				duom.setRezultatas(galutinis);
			}
			else if (metodas == "M" || metodas == "m") {
				galutinis = count_mediana(pazymiai, egzas);
				duom.setRezultatas(galutinis);
			}
			stud.push_back(duom);
			pazymiai.clear();
		}
		file.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	stud.sort(palyginimas);
	std::list<studentas> n;
	auto z = (std::find_if(stud.begin(), stud.end(), [](const studentas& s) {return s.getRezultatas() == 5.0; }));
	std::move(stud.begin(), z, std::back_inserter(n));
	stud.erase(stud.begin(), z);
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_l1_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_l1_" + std::to_string(a) + ".txt");
	f1 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	f2 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	for (studentas m : stud) {
		f1 << std::left << std::setw(15) << m.getVardas() << std::left << std::setw(15) << m.getPavarde() << std::left << std::setw(15) << m.getRezultatas() << std::endl;
	}
	for (studentas m : n) {
		f2 << std::left << std::setw(15) << m.getVardas() << std::left << std::setw(15) << m.getPavarde() << std::left << std::setw(15) << m.getRezultatas() << std::endl;
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
	std::ifstream file(name);
	std::list<studentas>stud;
	if (file.is_open()) {
		std::string line;
		int paz, egzas, sum;
		int paz_sk = 5;
		double galutinis;
		std::vector<int>pazymiai;
		std::string vardas, pavarde;
		std::stringstream s(line);
		while (getline(file, line)) {
			studentas duom;
			file >> vardas;
			duom.setVardas(vardas);
			file >> pavarde;
			duom.setPavarde(pavarde);
			for (int i = 0; i < paz_sk; i++) {
				file >> paz;
				pazymiai.push_back(paz);
			}
			duom.setPazymiai(pazymiai);
			sum = accumulate(pazymiai.begin(), pazymiai.end(), 0);
			duom.setSum(sum);
			file >> egzas;
			duom.setEgzas(egzas);
			if (metodas == "V" || metodas == "v") {
				galutinis = count_galutinis(pazymiai, sum, egzas);
				duom.setRezultatas(galutinis);
			}
			else if (metodas == "M" || metodas == "m") {
				galutinis = count_mediana(pazymiai, egzas);
				duom.setRezultatas(galutinis);
			}
			stud.push_back(duom);
			pazymiai.clear();
		}
		file.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	stud.sort(palyginimas);
	std::list<studentas> moksliukai;
	std::list<studentas> vargsiukai;
	auto z = (std::find_if(stud.begin(), stud.end(), [](const studentas& s) {return s.getRezultatas() == 5.0; }));
	std::move(stud.begin(), z, std::back_inserter(vargsiukai));
	std::move(z, stud.end(), std::back_inserter(moksliukai));
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_l2_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_l2_" + std::to_string(a) + ".txt");
	f1 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	f2 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	for (studentas c : moksliukai) {
		f1 << std::left << std::setw(15) << c.getVardas() << std::left << std::setw(15) << c.getPavarde() << std::left << std::setw(15) << c.getRezultatas() << std::endl;
	}
	for (studentas d : vargsiukai) {
		f2 << std::left << std::setw(15) << d.getVardas() << std::left << std::setw(15) << d.getPavarde() << std::left << std::setw(15) << d.getRezultatas() << std::endl;
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
	std::ifstream file(name);
	std::vector<studentas>stud;
	if (file.is_open()) {
		std::string line;
		int paz, egzas, sum;
		int paz_sk = 5;
		double galutinis;
		std::vector<int>pazymiai;
		std::string vardas, pavarde;
		std::stringstream s(line);
		while (getline(file, line)) {
			studentas duom;
			file >> vardas;
			duom.setVardas(vardas);
			file >> pavarde;
			duom.setPavarde(pavarde);
			for (int i = 0; i < paz_sk; i++) {
				file >> paz;
				pazymiai.push_back(paz);
			}
			duom.setPazymiai(pazymiai);
			sum = accumulate(pazymiai.begin(), pazymiai.end(), 0);
			duom.setSum(sum);
			file >> egzas;
			duom.setEgzas(egzas);
			if (metodas == "V" || metodas == "v") {
				galutinis = count_galutinis(pazymiai, sum, egzas);
				duom.setRezultatas(galutinis);
			}
			else if (metodas == "M" || metodas == "m") {
				galutinis = count_mediana(pazymiai, egzas);
				duom.setRezultatas(galutinis);
			}
			stud.push_back(duom);
			pazymiai.clear();
		}
		file.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::sort(stud.begin(), stud.end(), palyginimas);
	std::vector<studentas> n;
	auto z = (std::find_if(stud.begin(), stud.end(), [](const studentas& s) {return s.getRezultatas() == 5.0; }));
	std::move(stud.begin(), z, std::back_inserter(n));
	stud.erase(stud.begin(), z);
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_v1_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_v1_" + std::to_string(a) + ".txt");
	f1 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	f2 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	for (studentas m : stud) {
		f1 << std::left << std::setw(15) << m.getVardas() << std::left << std::setw(15) << m.getPavarde() << std::left << std::setw(15) << m.getRezultatas() << std::endl;
	}
	for (studentas m : n) {
		f2 << std::left << std::setw(15) << m.getVardas() << std::left << std::setw(15) << m.getPavarde() << std::left << std::setw(15) << m.getRezultatas() << std::endl;
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
	std::ifstream file(name);
	std::vector<studentas>stud;
	if (file.is_open()) {
		std::string line;
		int paz, egzas, sum;
		int paz_sk = 5;
		double galutinis;
		std::vector<int>pazymiai;
		std::string vardas, pavarde;
		std::stringstream s(line);
		while (getline(file, line)) {
			studentas duom;
			file >> vardas;
			duom.setVardas(vardas);
			file >> pavarde;
			duom.setPavarde(pavarde);
			for (int i = 0; i < paz_sk; i++) {
				file >> paz;
				pazymiai.push_back(paz);
			}
			duom.setPazymiai(pazymiai);
			sum = accumulate(pazymiai.begin(), pazymiai.end(), 0);
			duom.setSum(sum);
			file >> egzas;
			duom.setEgzas(egzas);
			if (metodas == "V" || metodas == "v") {
				galutinis = count_galutinis(pazymiai, sum, egzas);
				duom.setRezultatas(galutinis);
			}
			else if (metodas == "M" || metodas == "m") {
				galutinis = count_mediana(pazymiai, egzas);
				duom.setRezultatas(galutinis);
			}
			stud.push_back(duom);
			pazymiai.clear();
		}
		file.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::sort(stud.begin(), stud.end(), palyginimas);
	std::vector<studentas> moksliukai;
	std::vector<studentas> vargsiukai;
	auto z = (std::find_if(stud.begin(), stud.end(), [](const studentas& s) {return s.getRezultatas() == 5.0; }));
	std::move(stud.begin(), z, std::back_inserter(vargsiukai));
	std::move(z, stud.end(), std::back_inserter(moksliukai));
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_v2_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_v2_" + std::to_string(a) + ".txt");
	f1 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	f2 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	for (studentas c : moksliukai) {
		f1 << std::left << std::setw(15) << c.getVardas() << std::left << std::setw(15) << c.getPavarde() << std::left << std::setw(15) << c.getRezultatas() << std::endl;
	}
	for (studentas d : vargsiukai) {
		f2 << std::left << std::setw(15) << d.getVardas() << std::left << std::setw(15) << d.getPavarde() << std::left << std::setw(15) << d.getRezultatas() << std::endl;
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
	std::ifstream file(name);
	std::vector<studentas>stud;
	if (file.is_open()) {
		std::string line;
		int paz, egzas, sum;
		int paz_sk = 5;
		double galutinis;
		std::vector<int>pazymiai;
		std::string vardas, pavarde;
		std::stringstream s(line);
		while (getline(file, line)) {
			studentas duom;
			file >> vardas;
			duom.setVardas(vardas);
			file >> pavarde;
			duom.setPavarde(pavarde);
			for (int i = 0; i < paz_sk; i++) {
				file >> paz;
				pazymiai.push_back(paz);
			}
			duom.setPazymiai(pazymiai);
			sum = accumulate(pazymiai.begin(), pazymiai.end(), 0);
			duom.setSum(sum);
			file >> egzas;
			duom.setEgzas(egzas);
			if (metodas == "V" || metodas == "v") {
				galutinis = count_galutinis(pazymiai, sum, egzas);
				duom.setRezultatas(galutinis);
			}
			else if (metodas == "M" || metodas == "m") {
				galutinis = count_mediana(pazymiai, egzas);
				duom.setRezultatas(galutinis);
			}
			stud.push_back(duom);
			pazymiai.clear();
		}
		file.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::vector<studentas> n;
	auto it = std::stable_partition(stud.begin(), stud.end(), [](const studentas& s) {return s.getRezultatas() < 5.0; });
	std::copy(stud.begin(), it, std::back_inserter(n));
	stud.erase(stud.begin(), it);
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_p_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_p_" + std::to_string(a) + ".txt");
	f1 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	f2 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	for (studentas m : stud) {
		f1 << std::left << std::setw(15) << m.getVardas() << std::left << std::setw(15) << m.getPavarde() << std::left << std::setw(15) << m.getRezultatas() << std::endl;
	}
	for (studentas m : n) {
		f2 << std::left << std::setw(15) << m.getVardas() << std::left << std::setw(15) << m.getPavarde() << std::left << std::setw(15) << m.getRezultatas() << std::endl;
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
	std::ifstream file(name);
	std::vector<studentas>stud;
	if (file.is_open()) {
		std::string line;
		int paz, egzas, sum;
		int paz_sk = 5;
		double galutinis;
		std::vector<int>pazymiai;
		std::string vardas, pavarde;
		std::stringstream s(line);
		while (getline(file, line)) {
			studentas duom;
			file >> vardas;
			duom.setVardas(vardas);
			file >> pavarde;
			duom.setPavarde(pavarde);
			for (int i = 0; i < paz_sk; i++) {
				file >> paz;
				pazymiai.push_back(paz);
			}
			duom.setPazymiai(pazymiai);
			sum = accumulate(pazymiai.begin(), pazymiai.end(), 0);
			duom.setSum(sum);
			file >> egzas;
			duom.setEgzas(egzas);
			if (metodas == "V" || metodas == "v") {
				galutinis = count_galutinis(pazymiai, sum, egzas);
				duom.setRezultatas(galutinis);
			}
			else if (metodas == "M" || metodas == "m") {
				galutinis = count_mediana(pazymiai, egzas);
				duom.setRezultatas(galutinis);
			}
			stud.push_back(duom);
			pazymiai.clear();
		}
		file.close();
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	std::sort(stud.begin(), stud.end(), palyginimas);
	std::vector<studentas> moksliukai;
	std::vector<studentas> vargsiukai;
	auto z = (std::find_if(stud.begin(), stud.end(), [](const studentas& s) {return s.getRezultatas() == 5.0; }));
	std::move(stud.begin(), z, std::back_inserter(vargsiukai));
	std::move(z, stud.end(), std::back_inserter(moksliukai));
	auto laikas = t.elapsed();
	std::ofstream f1("moksliukai_part_" + std::to_string(a) + ".txt");
	std::ofstream f2("vargsiukai_part_" + std::to_string(a) + ".txt");
	f1 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	f2 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	for (studentas c : moksliukai) {
		f1 << std::left << std::setw(15) << c.getVardas() << std::left << std::setw(15) << c.getPavarde() << std::left << std::setw(15) << c.getRezultatas() << std::endl;
	}
	for (studentas d : vargsiukai) {
		f2 << std::left << std::setw(15) << d.getVardas() << std::left << std::setw(15) << d.getPavarde() << std::left << std::setw(15) << d.getRezultatas() << std::endl;
	}
	moksliukai.clear();
	vargsiukai.clear();
	f1.close();
	f2.close();
	stud.clear();
	return laikas;
}