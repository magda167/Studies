#include "Header.h"                                                                 // za³¹czanie pliku nag³ówkowego
int main(int argc, char ** argv)                                                // g³ówna funkcja programu 
{
	string startnumber;                                                         // deklaracja argumentu typu string
	int startsystem, targetsystem, quantity;                                    // deklaracje argumentów typu int
	fstream fileopen, filesave;                                                 // deklaracje obiektów typu fstream 
	char *fileopen1 = 0;                                                        // przypisanie wartoœci pocz¹tkowej
	char *filesave1 = 0;                                                        // przypisanie wartoœci pocz¹tkowej
	if (argc == 1)                                                              // sprawdzanie liczby argumentów przekazanych do programu
	{
		cout << "Nie podano argumentow.";                                       // wyœwietlenie komunikatu w wierszu poleceñ
		cout << endl << "Przyklad: konwerter.exe /o a.txt /s b.txt" << endl;     // wyœwietlenie komunikatu w wierszu poleceñ
		return 0;                                                                // zwracanie wartoœci 0
	}
	else                                                                         // albo
	{

		char *openstring = "/o";                                                // wskaŸnik do pokazywania na obiekt typu char
		char *savestring = "/s";                                                // wskaŸnik do pokazywania na obiekt typu char
		for (int a = 1; a < argc; ++a)                                          // pêtla okreœlaj¹ca jak d³ugo ma nastêpowaæ porównanie ³ancuchów znaków
		{
			if (!strcmp(argv[a], openstring))                                   // porówananie dwóch ³añcuchów znaków
			{
				fileopen1 = argv[a + 1];                                        // nadanie elementowi wartoœci tablicy
			}
			else if (!strcmp(argv[a], savestring))                              // porówananie dwóch ³añcuchów znaków
			{
				filesave1 = argv[a + 1];                                        // nadanie elementowi wartoœci tablicy 
			}
		}
		if (!fileopen1)                                                         // sprawdzanie czy podano prawid³owy plik do otwarcia
		{
			cout << "Nie podano pliku do otwarcia." << endl;                    // wyœwietlenie komunikatu w wierszu poleceñ
			return 0;                                                           // zwracanie wartoœci 0
		}
		if (!filesave1)                                                         // sprawdzanie czy podano prawid³owo plik do zapisu
		{
			cout << "Nie podano pliku do zapisu." << endl;                      // wyswietlenie komunikatu w wierszu poleceñ
			return 0;                                                           // zwracanie wartosci 0;
		}

	}
	fileopen.open(fileopen1, ios::in);                                          // otwieraie pliku do odczytu
	filesave.open(filesave1, ios::out);                                         // otwieranie pliku do zapisu
	if (fileopen.good())                                                        // sprawdzanie czy plik zosta³ wczytany prawid³owo
	{
		fileopen >> quantity;                                                   // wczytanie z pliku iloœci liczb do konwersji
		for (int i = 0; i < quantity; i++)                                      // pêtla okreœlaj¹ca do jakiego momentu program ma zczytywaæ dane z pliku 
		{
			fileopen >> startnumber;                                            // wczytanie z pliku liczby pocz¹tkowej
			fileopen >> startsystem;                                            // wczytanie z pliku systemu pocz¹tkowego 
			fileopen >> targetsystem;                                           // wczytanie z pliku systemu koñcowego
			if (startnumber != "0")                                             // sprawdzanie czy pocz¹tkowa liczba jest ró¿na od 0
			{
				startnumber = BigLetters(startnumber);                          // wywo³anie funkcji , zamiana na du¿e litery
				int l = ToDecSys(startnumber, startsystem);                  // wywo³anie funkcji ,zamiana na system dziesiêtny
				if (l != 0)                                                     // sprawdzanie czy wartosc funkcji ToDecSytem jest ró¿na od 0
					filesave << ToTargetSys(l, targetsystem) << endl;        // wpisanie do pliku wartoœci funkcji ToTargetSystem
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
