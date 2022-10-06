#include "strukt.h"


int main() {
	studentas duom;
	std::vector<studentas>stud_arr;
	std::string pasirinkimas;
	std::cout << "Laba diena!" << std::endl;
	std::cout << "Ar norite duomenis skaityti is failo?(T/N)";
	std::cin >> pasirinkimas;
	if (pasirinkimas == "N" || pasirinkimas == "n") {
		bool vedimas = true;
		while (vedimas) {
			duom = stud();
			std::cout << "Ar vesite dar duomenu?(T/N)";
			std::cin >> pasirinkimas;
			if (pasirinkimas == "T" || pasirinkimas == "t") {
				vedimas = true;
			}
			else if (pasirinkimas == "n" || pasirinkimas == "N") {
				vedimas = false;
			}
			else {
				std::cout << "KLAIDA";
				return 0;
			}
			stud_arr.push_back(duom);
		}
		for (int i = 0; i < stud_arr.size(); i++) {
			std::cout << "Vardas\t" << "Pavarde\t" << "Rezultatas\t" << std::endl;
			std::cout << stud_arr[i].vardas << "\t" << stud_arr[i].pavarde << "\t" << stud_arr[i].rezultatas << std::endl << std::endl;			
		}
		std::cout << "Spauskite bet koki mygtuka programai uzdaryti";
	}
	else if (pasirinkimas == "T" || pasirinkimas == "t") {
		stud_arr = read_from_file(stud_arr);
		write_to_file(stud_arr);
		std::cout << "\n" << "Rezultatu failas vadinasi 'rezultatai.txt' ji rasite C : disko paieskoje ivede pavadinima." << std::endl << std::endl;;
		std::cout << "Spauskite bet kuri mygtuka programai uzdaryti" << std::endl; 
	}
	
}	
