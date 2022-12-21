#include "class.h"

//v0.2
std::vector<studentas> read_from_file(std::string name, std::vector<studentas>stud, std::string metodas) {
	studentas duom;
	std::ifstream readFile(name);
	if (readFile.is_open()) {
		std::string line;
		std::vector<int> pazymiai; 
		std::stringstream s(line);
		int paz_sk = 5;
		while (getline(readFile, line)) {
			std::string vardas, pavarde;
			int paz, sum, egzas;
			double galutinis;
			readFile >> vardas;
			duom.setVardas(vardas);
			readFile >> pavarde;
			duom.setPavarde(pavarde);
			for (int i = 0; i < paz_sk; i++) {
				readFile >> paz;
				pazymiai.push_back(paz);
			}
			duom.setPazymiai(pazymiai);
			sum = accumulate(pazymiai.begin(), pazymiai.end(), 0);
			duom.setSum(sum);
			readFile >> egzas;
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
		}
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	return stud;
}


//v0.2
void write_to_file(std::vector<studentas>duom) {
	std::ofstream output;
	output.open("rezultatai.txt");
	output << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	for (int i = 0; i < duom.size(); i++) {
		output << std::left << std::setw(15) << duom.at(i).getVardas() << std::left << std::setw(15) << duom.at(i).getPavarde() << std::left << std::setw(15) << duom.at(i).getRezultatas() << std::endl;
	}
	output.close();
}


//v0.3
void stud_gen(int a) {
	Timer t;
	std::string name = "stud" + std::to_string(a) + std::string(".txt");
	std::ofstream file(name);
	file << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Pazymiai" << std::left << std::setw(15) << "Egzaminas" << std::endl;
	for (int i = 1; i <= a; i++) {
		file << std::left << std::setw(15) << "Vardas" + std::to_string(i) << std::left << std::setw(15) << "Pavarde" + std::to_string(i) << std::left << std::setw(15) << pazGeneravimas() << std::left << std::setw(15) << egzo_rezultatas() << std::endl;
	}
	if (t.elapsed() < 60) {
		std::cout << "Failo is " + std::to_string(a) + " irasu sukurimo laikas: " << t.elapsed() << " sek." << std::endl;
	}
	else {
		std::cout << "Failo is " + std::to_string(a) + " irasu sukurimo laikas: " << t.elapsed() / 60 << " min." << std::endl;
	}
	file.close();
}

//v0.3
std::vector<studentas> gen_nuskaitymas(std::vector<studentas> stud, int a, std::string metodas) {
	studentas duom;
	Timer t;
	std::string name = "stud" + std::to_string(a) + std::string(".txt");
	std::ifstream file(name);
	if (file.is_open()) {
		std::string line;
		std::vector<int>pazymiai;
		int paz;
		int paz_sk = 5;
		double galutinis;
		std::stringstream s(line);
		while (getline(file, line)) {
			std::string vardas, pavarde;
			int paz, sum, egzas;
			double galutinis;
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
	}
	else { std::cout << "KLAIDA" << std::endl; exit(0); }
	return stud;
	file.close();
	stud.clear();
}

//v0.3
void gen_irasymas(std::vector<studentas> duom, std::string a) {
	studentas stud;
	Timer t;
	std::vector<studentas> moksliukai;
	std::vector<studentas> vargsiukai;
	for (int i = 0; i < duom.size() - 1; i++) {
		stud = duom[i];
		if (stud.getRezultatas() >= 5.0) {
			moksliukai.push_back(stud);
		}
		else {
			vargsiukai.push_back(stud);
		}
	}
	if (t.elapsed() < 60) {
		std::cout << "Studentu isskirstymas i dvi grupes uztruko " << t.elapsed() << " sek." << std::endl;
	}
	else {
		std::cout << "Studentu isskirtsymas i dvi grupes uztruko " << t.elapsed() / 60 << " min." << std::endl;
	}
	sort(moksliukai.begin(), moksliukai.end(), palyginimas);
	sort(vargsiukai.begin(), vargsiukai.end(), palyginimas);
	t.reset();
	std::ofstream f1("moksliukai" + a + ".txt");
	std::ofstream f2("vargsiukai" + a + ".txt");
	f1 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	f2 << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Rezultatas" << std::endl;
	for (int i = 0; i < moksliukai.size(); i++) {
		stud = moksliukai[i];
		f1 << std::left << std::setw(15) << stud.getVardas() << std::left << std::setw(15) << stud.getPavarde() << std::left << std::setw(15) << stud.getRezultatas() << std::endl;
	}
	for (int i = 0; i < vargsiukai.size(); i++) {
		stud = vargsiukai[i];
		f2 << std::left << std::setw(15) << stud.getVardas() << std::left << std::setw(15) << stud.getPavarde() << std::left << std::setw(15) << stud.getRezultatas() << std::endl;
	}
	if (t.elapsed() < 60) {
		std::cout << "Studentu grupiu irasymas i failus uztruko " << t.elapsed() << " sek." << std::endl;
	}
	else {
		std::cout << "Studentu grupiu irasymas i failus uztruko " << t.elapsed() / 60 << " min." << std::endl;
	}
	f1.close();
	f2.close();
	moksliukai.clear();
	vargsiukai.clear();	
}