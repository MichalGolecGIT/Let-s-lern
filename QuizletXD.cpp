// QuizletXD.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//CTRL + F5 odpalasz 

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<ctime>
#include<cmath>
using namespace std;

int ILOSC_SLOW = 318; // Tu wpisujesz ile jest wierszy w pliku (te poziome(plasko)) po czym naciskasz   CTRL + S  (plus oznacza, ze te dwa guziki xD)


int generowanieNumeruSlowaWisielec() {
	srand(time(NULL));

	int numerSlowa = (rand() * 2137 % (ILOSC_SLOW * 2));
	if (numerSlowa % 2 == 0) {
		numerSlowa++;
	}
	return numerSlowa;
}

void generowanieSlowaDoOdgadniecia(int numerSlowa, char* slowoDoOdgadniecia) {
	char pusteWczytanie[80] = { 0 };
	fstream wczytanieSlowaZPliku;
	wczytanieSlowaZPliku.open("Slowniczek_muzyczny.txt", ios::in);// pomiedzy znakami "Tu_Wpisujesz_Nazwe_Swojego_Pliku.txt" nie zapomnij .txt na końcu a potem CTRL+S    
	//Nazwa pliku musi być bez polskich znakow i zamiast spacji wpisz _ (Shift + -  =  _  )
	for (int j = 1; j < numerSlowa; j++) {
		wczytanieSlowaZPliku >> pusteWczytanie;
	}
	wczytanieSlowaZPliku >> slowoDoOdgadniecia;
}

int main()
{
	bool kontynuacja = true;
	int punkty = 0;
	int bledy = 0;
	int przyklad = 0;
	while (kontynuacja) {
		int numer = generowanieNumeruSlowaWisielec();
		przyklad++;
		char slowo_do_odgadniecia[80] = { 0 };
		char slowo_do_odgadniecia2[80] = { 0 };
		generowanieSlowaDoOdgadniecia(numer, slowo_do_odgadniecia);
		generowanieSlowaDoOdgadniecia(numer + 1, slowo_do_odgadniecia2);
		std::cout << "Slowo do odgadniecia nr." << przyklad << " to:\n" << slowo_do_odgadniecia << endl;
		char slowo_zgadywane[30] = { 0 };
		cin >> slowo_zgadywane;
		cout << slowo_do_odgadniecia2 << endl << "Czy napisalas dobrze?\n 1=tak\t2=nie\t3=inne tlumaczenie\ninne = koniec\n";
		int dobrze = 0;
		cin >> dobrze;
		if (dobrze == 1) {
			punkty++;
		}
		else if (dobrze == 2) {
			bledy++;
		}
		else if (dobrze == 3) {
			przyklad--;
		}
		else {
			cout << "WTF?! co ty wpisalas? Przestajemy sie lubic i sie wylaczam \n>:(\n";
			kontynuacja = false;
		}
		cout << "Twoje punkty to:\nDobrze:" << punkty << "\nzle:\t" << bledy << endl;
		system("PAUSE");
		system("CLS");
	}
}



// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
