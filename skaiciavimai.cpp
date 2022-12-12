#include "strukt.h"

double count_galutinis(std::vector<int> pazymiai, int sum, int egzas) {
	double galutinis = double(sum) / pazymiai.size() * 0.4 + egzas * 0.6;
	return galutinis;
}

double count_mediana(std::vector<int>pazymiai, int egzas) {
	sort(pazymiai.begin(), pazymiai.end());
	double mediana;
	if (pazymiai.size() % 2 != 0) {
		mediana = (double)pazymiai[pazymiai.size() / 2];
	}
	else {
		mediana = (double)(pazymiai[(pazymiai.size() - 1) / 2] + pazymiai[pazymiai.size() / 2]) / 2;
	}
	double galutinis = mediana * 0.4 + egzas * 0.6;
	return galutinis;
}

unsigned int countWordsInString(std::string const& str)
{
	std::stringstream stream(str);
	return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

std::string pazGeneravimas() {
	std::vector<std::string> paz;
	for (int i = 0; i < 5; i++) {
		paz.push_back(std::to_string(rand() % 10 + 1) + " ");
	}
	std::string p = std::accumulate(paz.begin(), paz.end(), std::string(""));
	return p;
};

std::string egzo_rezultatas() {
	int egzas = (rand() % 10) + 1;
	std::string p = std::to_string(egzas);
	return p;
}

bool palyginimas(const studentas& a, const studentas& b) {
	return a.rezultatas < b.rezultatas;
}


