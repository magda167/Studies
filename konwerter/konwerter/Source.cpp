#include "Header.h"                                                                 // za��czanie pliku nag��wkowego
int main(int argc, char ** argv)                                                // g��wna funkcja programu 
{
	string startnumber;                                                         // deklaracja argumentu typu string
	int startsystem, targetsystem, quantity;                                    // deklaracje argument�w typu int
	fstream fileopen, filesave;                                                 // deklaracje obiekt�w typu fstream 
	char *fileopen1 = 0;                                                        // przypisanie warto�ci pocz�tkowej
	char *filesave1 = 0;                                                        // przypisanie warto�ci pocz�tkowej
	if (argc == 1)                                                              // sprawdzanie liczby argument�w przekazanych do programu
	{
		cout << "Nie podano argumentow.";                                       // wy�wietlenie komunikatu w wierszu polece�
		cout << endl << "Przyklad: konwerter.exe /o a.txt /s b.txt" << endl;     // wy�wietlenie komunikatu w wierszu polece�
		return 0;                                                                // zwracanie warto�ci 0
	}
	else                                                                         // albo
	{

		char *openstring = "/o";                                                // wska�nik do pokazywania na obiekt typu char
		char *savestring = "/s";                                                // wska�nik do pokazywania na obiekt typu char
		for (int a = 1; a < argc; ++a)                                          // p�tla okre�laj�ca jak d�ugo ma nast�powa� por�wnanie �ancuch�w znak�w
		{
			if (!strcmp(argv[a], openstring))                                   // por�wananie dw�ch �a�cuch�w znak�w
			{
				fileopen1 = argv[a + 1];                                        // nadanie elementowi warto�ci tablicy
			}
			else if (!strcmp(argv[a], savestring))                              // por�wananie dw�ch �a�cuch�w znak�w
			{
				filesave1 = argv[a + 1];                                        // nadanie elementowi warto�ci tablicy 
			}
		}
		if (!fileopen1)                                                         // sprawdzanie czy podano prawid�owy plik do otwarcia
		{
			cout << "Nie podano pliku do otwarcia." << endl;                    // wy�wietlenie komunikatu w wierszu polece�
			return 0;                                                           // zwracanie warto�ci 0
		}
		if (!filesave1)                                                         // sprawdzanie czy podano prawid�owo plik do zapisu
		{
			cout << "Nie podano pliku do zapisu." << endl;                      // wyswietlenie komunikatu w wierszu polece�
			return 0;                                                           // zwracanie wartosci 0;
		}

	}
	fileopen.open(fileopen1, ios::in);                                          // otwieraie pliku do odczytu
	filesave.open(filesave1, ios::out);                                         // otwieranie pliku do zapisu
	if (fileopen.good())                                                        // sprawdzanie czy plik zosta� wczytany prawid�owo
	{
		fileopen >> quantity;                                                   // wczytanie z pliku ilo�ci liczb do konwersji
		for (int i = 0; i < quantity; i++)                                      // p�tla okre�laj�ca do jakiego momentu program ma zczytywa� dane z pliku 
		{
			fileopen >> startnumber;                                            // wczytanie z pliku liczby pocz�tkowej
			fileopen >> startsystem;                                            // wczytanie z pliku systemu pocz�tkowego 
			fileopen >> targetsystem;                                           // wczytanie z pliku systemu ko�cowego
			if (startnumber != "0")                                             // sprawdzanie czy pocz�tkowa liczba jest r�na od 0
			{
				startnumber = BigLetters(startnumber);                          // wywo�anie funkcji , zamiana na du�e litery
				int l = ToDecSys(startnumber, startsystem);                  // wywo�anie funkcji ,zamiana na system dziesi�tny
				if (l != 0)                                                     // sprawdzanie czy wartosc funkcji ToDecSytem jest r�na od 0
					filesave << ToTargetSys(l, targetsystem) << endl;        // wpisanie do pliku warto�ci funkcji ToTargetSystem
				else                                                            // albo
					filesave << "Bledna liczba lub system wyjsciowy\n";         // wpisanie do pliku komunikatu
			}
			else                                                                // albo  
			{
				filesave << 0;                                                  // wpisanie do pliku wartosci 0
			}
		}
		fileopen.close();                                                       // zamykanie pliku do odczytu
		filesave.close();                                                       // zamykanie pilku do zapisu
	}
	return 0;                                                                   // zwracanie 0
}
