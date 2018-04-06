#include "function.h"
#include "struct.h"

#define MAX_FILES 100																	// deklaracja ilo�ci plik�w
int main(int argc, char *argv[])														// g��wna funkcja
{
	string files[MAX_FILES];															// deklaracja tablicy typu string
	if (argc == 1)																		// sprawdzanie liczby argument�w
	{
		cout << "Blednie podane argumenty."<< endl;										// komunikat w wierszu polece�
		cout << "Przyklad poprawnego podania argumentow :" << endl;						// komunikat w wierszu polece�
		cout << "\"indeksy.exe /o PE.txt PI.txt\"" << endl;								// komunikat w wierszu polece�
	}
	else
	{
		if (strcmp(argv[1], "/o")==0)														// sprawdzanie �a�cucha znak�w
		{
			int counter = 0;															// deklaracja zmiennej counter
			while (--argc > 1)															// dekrementacja i sprawdzanie czy argc >1 
			{
				files[counter] = argv[argc];											// przypisanie tablicy warto�ci tablicy
				counter++;																// zwi�kszanie licznika
			}
		}
		else
			cout << "Bledny format danych wejsciowych." << endl;						// komunikat w konsoli
	}
	Student * head = nullptr;															// przypisanie warto�ci do wska�nika
	int counter = 0;																	// deklaracja zmiennej counter
	while (files[counter] != "")														// wykonywanie instrukcji dop�ki plik!= ""
	{
		if (!(files[counter].find(".txt") == string::npos))								// czytanie danych dop�ki elementy sie nie sko�czy�y
			read_data(files[counter], &head);											// wywo�anie funkcji read_data
		counter++;																		// zwi�kszanie licznika o 1
	}
	create_index(head);																	// wywo�anie funkcji create_index
	empty_memory(&head);																// wywo�anie funkcji empty_memory
	return 0;																			// zwracanie 0
}