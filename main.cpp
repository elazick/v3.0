#include "class.h"

int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	studentas duom;
	std::vector<studentas>stud_arr;
	bool runProgram = true;
	std::string pasirinkimas;
	int funkcija;
	SetConsoleTextAttribute(h, 15);
	std::cout << "Laba diena!" << std::endl;
	std::cout << "1. Duomenu vedimas ranka\n2. Duomenu skaitymas is failo\n3. Failu generavimas\n4. Spartos testas\n5. Spartos testas su skirtingais algoritmais" << std::endl;
	while (runProgram) {
		std::cout << "Iveskite norimos funkcijos numeri: ";
		std::cin >> funkcija;
		if (std::cin.fail())
		{
			SetConsoleTextAttribute(h, 12);
			std::cout << "Netinkamas pasirinkimas, bandykite darkart\n";
			SetConsoleTextAttribute(h, 15);
			std::cin.clear();
			std::cin.ignore(500, '\n');
			std::cout << "Iveskite norimos funkcijos numeri: ";
			std::cin >> funkcija;
		}
		if (funkcija == 1) {
			bool vedimas = true;
			while (vedimas) {
				duom = stud();
				std::cout << "Ar vesite dar duomenu?(T/N) ";
				std::cin >> pasirinkimas;
				if (std::cin.fail()) {
					std::cout << "Netinkama ivestis, bandykite darkart\n";
					std::cin.clear();
					std::cin.ignore(500, '\n');
					std::cout << "Ar vesite dar duomenu(T/N) ";
					std::cin >> pasirinkimas;
				}
				if (pasirinkimas == "T" || pasirinkimas == "t") {
					vedimas = true;
				}
				else if (pasirinkimas == "N" || pasirinkimas == "n") {
					vedimas = false;
				}
				stud_arr.push_back(duom);
			}
			for (int i = 0; i < stud_arr.size(); i++) {
				SetConsoleTextAttribute(h, 10);
				std::cout << "Vardas\t" << "Pavarde\t" << "Rezultatas\t" << std::endl;
				SetConsoleTextAttribute(h, 15);
				std::cout << stud_arr[i].getVardas() << "\t" << stud_arr[i].getPavarde() << "\t" << stud_arr[i].getRezultatas() << std::endl << std::endl;
			}
			stud_arr.clear();
		}
		if (funkcija == 2) {
			std::string pavadinimas, name;
			std::cout << "Iveskite failo pavadinima: ";
			std::cin >> pavadinimas;
			name = pavadinimas + std::string(".txt");
			std::cout << "Galutini skaiciuoti su vidurkiu ar mediana?(V/M) ";
			std::cin >> pasirinkimas;
			if (std::cin.fail()) {
				SetConsoleTextAttribute(h, 12);
				std::cout << "Netinkama ivestis, bandykite darkart\n";
				SetConsoleTextAttribute(h, 15);
				std::cin.clear();
				std::cin.ignore(500, '\n');
				std::cout << "Galutini skaiciuoti su vidurkiu ar mediana?(V/M) ";
				std::cin >> pasirinkimas;
			}
			stud_arr = read_from_file(name, stud_arr, pasirinkimas);
			sort(stud_arr.begin(), stud_arr.end(), palyginimas);
			write_to_file(stud_arr);
			stud_arr.clear();
			SetConsoleTextAttribute(h, 12);
			std::cout << "\nRezultatu failas vadinasi 'rezultatai.txt' ji rasite C : disko paieskoje ivede pavadinima." << std::endl;
			SetConsoleTextAttribute(h, 15);
		}
		if (funkcija == 3) {
			int a;
			std::cout << "Kiek duomenu generuoti? ";
			std::cin >> a;
			if (std::cin.fail()) {
				SetConsoleTextAttribute(h, 12);
				std::cout << "Netinkamas pasirinkimas, bandykite darkart\n";
				SetConsoleTextAttribute(h, 15);
				std::cin.clear();
				std::cin.ignore(500, '\n');
				std::cout << "Kiek duomenu generuoti? ";
				std::cin >> a;
			}
			stud_gen(a);
			std::cout << "Galutini skaiciuoti su vidurkiu ar mediana?(V/M) ";
			std::cin >> pasirinkimas;
			if (std::cin.fail()) {
				SetConsoleTextAttribute(h, 12);
				std::cout << "Netinkama ivestis, bandykite darkart\n";
				SetConsoleTextAttribute(h, 15);
				std::cin.clear();
				std::cin.ignore(500, '\n');
				std::cout << "Galutini skaiciuoti su vidurkiu ar mediana?(V/M) ";
				std::cin >> pasirinkimas;
			}
			stud_arr = gen_nuskaitymas(stud_arr, a, pasirinkimas);
			gen_irasymas(stud_arr, std::to_string(a));
			stud_arr.clear();
			std::cout << std::endl;
		}
		if (funkcija == 4) {
			std::cout << "Rezultata skaiciuoti naudojant vidurki ar mediana?(V/M)";
			std::cin >> pasirinkimas;
			if (std::cin.fail())
			{
				SetConsoleTextAttribute(h, 12);
				std::cout << "Netinkamas pasirinkimas, bandykite darkart\n";
				SetConsoleTextAttribute(h, 15);
				std::cin.clear();
				std::cin.ignore(500, '\n');
				std::cout << "Rezultata skaiciuoti naudojant vidurki ar mediana?(V/M)";
				std::cin >> pasirinkimas;
			}
			
			SetConsoleTextAttribute(h, 12);
			std::cout << "Laikas pateikiamas sekundemis!" << std::endl;
			SetConsoleTextAttribute(h, 15);
			std::cout << std::left << std::setw(25) << "Irasu skaicius faile" << std::left << std::setw(30) << "Vienas naujas konteineris" << std::left << std::setw(30) << "Du nauji konteineriai" << "\n" << std::left << std::setw(25) << "" << std::left << std::setw(15) << "List" << std::left << std::setw(15) << "Vector" << std::left << std::setw(15) << "List" << std::left << std::setw(15) << "Vector" << std::endl;
			std::cout << std::left << std::setw(25) << "1000" << std::left << std::setw(15) << list1(1000, pasirinkimas) << std::left << std::setw(15) << vector1(1000, pasirinkimas) << std::left << std::setw(15) << list2(1000, pasirinkimas) << std::left << std::setw(15) << vector2(1000, pasirinkimas) << std::endl;
			std::cout << std::left << std::setw(25) << "10000" << std::left << std::setw(15) << list1(10000, pasirinkimas) << std::left << std::setw(15) << vector1(10000, pasirinkimas) << std::left << std::setw(15) << list2(10000, pasirinkimas) << std::left << std::setw(15) << vector2(10000, pasirinkimas) << std::endl;
			std::cout << std::left << std::setw(25) << "100000" << std::left << std::setw(15) << list1(100000, pasirinkimas) << std::left << std::setw(15) << vector1(100000, pasirinkimas) << std::left << std::setw(15) << list2(100000, pasirinkimas) << std::left << std::setw(15) << vector2(100000, pasirinkimas) << std::endl;
			std::cout << std::left << std::setw(25) << "1000000" << std::left << std::setw(15) << list1(1000000, pasirinkimas) << std::left << std::setw(15) << vector1(1000000, pasirinkimas) << std::left << std::setw(15) << list2(1000000, pasirinkimas) << std::left << std::setw(15) << vector2(1000000, pasirinkimas) << std::endl;
			std::cout << std::left << std::setw(25) << "10000000" << std::left << std::setw(15) << list1(10000000, pasirinkimas) << std::left << std::setw(15) << vector1(10000000, pasirinkimas) << std::left << std::setw(15) << list2(10000000, pasirinkimas) << std::left << std::setw(15) << vector2(10000000, pasirinkimas) << std::endl;
			std::cout << std::endl;
		}
		if (funkcija == 5) {
			std::cout << "Rezultata skaiciuoti naudojant vidurki ar mediana?(V/M)";
			std::cin >> pasirinkimas;
			if (std::cin.fail())
			{
				SetConsoleTextAttribute(h, 12);
				std::cout << "Netinkamas pasirinkimas, bandykite darkart\n";
				SetConsoleTextAttribute(h, 15);
				std::cin.clear();
				std::cin.ignore(500, '\n');
				std::cout << "Rezultata skaiciuoti naudojant vidurki ar mediana?(V/M)";
				std::cin >> pasirinkimas;
			}

			SetConsoleTextAttribute(h, 12);
			std::cout << "Laikas pateikiamas sekundemis!" << std::endl;
			SetConsoleTextAttribute(h, 15);
			std::cout << "\n" << std::left << std::setw(25) << "Irasu skaicius faile" << std::left << std::setw(20) << "find_if + move" << std::left << std::setw(20) << "stable_partition" << std::left << std::setw(20) << "find_if + 2x move" << std::left << std::setw(20) << "partition_copy" << std::endl;
			std::cout << std::left << std::setw(25) << "1000" << std::left << std::setw(20) << vector1(1000, pasirinkimas) << std::left << std::setw(20) << st_part(1000, pasirinkimas) << std::left << std::setw(20) << vector2(1000, pasirinkimas) << std::left << std::setw(20) << partition(1000, pasirinkimas) << std::endl;
			std::cout << std::left << std::setw(25) << "10000" << std::left << std::setw(20) << vector1(10000, pasirinkimas) << std::left << std::setw(20) << st_part(10000, pasirinkimas) << std::left << std::setw(20) << vector2(10000, pasirinkimas) << std::left << std::setw(20) << partition(10000, pasirinkimas) << std::endl;
			std::cout << std::left << std::setw(25) << "100000" << std::left << std::setw(20) << vector1(100000, pasirinkimas) << std::left << std::setw(20) << st_part(100000, pasirinkimas) << std::left << std::setw(20) << vector2(100000, pasirinkimas) << std::left << std::setw(20) << partition(100000, pasirinkimas) << std::endl;
			std::cout << std::left << std::setw(25) << "1000000" << std::left << std::setw(20) << vector1(1000000, pasirinkimas) << std::left << std::setw(20) << st_part(1000000, pasirinkimas) << std::left << std::setw(20) << vector2(1000000, pasirinkimas) << std::left << std::setw(20) << partition(1000000, pasirinkimas) << std::endl;
			std::cout << std::left << std::setw(25) << "10000000" << std::left << std::setw(20) << vector1(10000000, pasirinkimas) << std::left << std::setw(20) << st_part(10000000, pasirinkimas) << std::left << std::setw(20) << vector2(10000000, pasirinkimas) << std::left << std::setw(20) << partition(10000000, pasirinkimas) << std::endl;
			std::cout << std::endl;
		}
		std::cout << "Ar norite baigti darba?(T/N)";
		std::cin >> pasirinkimas;
		if (std::cin.fail())
		{
			SetConsoleTextAttribute(h, 12);
			std::cout << "Netinkamas pasirinkimas, bandykite darkart\n";
			SetConsoleTextAttribute(h, 15);
			std::cin.clear();
			std::cin.ignore(500, '\n');
			std::cout << "Ar norite baigti darba?(T/N)";
			std::cin >> pasirinkimas;
		}
		if (pasirinkimas == "N" || pasirinkimas == "n") {
			runProgram = true;
		}
		else if (pasirinkimas == "T" || pasirinkimas == "t") {
			SetConsoleTextAttribute(h, 10);
			std::cout << "Spauskite bet kuri mygtuka programai uzdaryti";
			SetConsoleTextAttribute(h, 15);
			runProgram = false;
		}
	}
}

