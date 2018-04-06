#include "function.h"
#include "struct.h"

#define MAX_FILES 100																	// deklaracja iloœci plików
int main(int argc, char *argv[])														// g³ówna funkcja
{
	string files[MAX_FILES];															// deklaracja tablicy typu string
	if (argc == 1)																		// sprawdzanie liczby argumentów
	{
		cout << "Blednie podane argumenty."<< endl;										// komunikat w wierszu poleceñ
		cout << "Przyklad poprawnego podania argumentow :" << endl;						// komunikat w wierszu poleceñ
		cout << "\"indeksy.exe /o PE.txt PI.txt\"" << endl;								// komunikat w wierszu poleceñ
	}
	else
	{
		if (strcmp(argv[1], "/o")==0)														// sprawdzanie ³añcucha znaków
		{
			int counter = 0;															// deklaracja zmiennej counter
			while (--argc > 1)															// dekrementacja i sprawdzanie czy argc >1 
			{
				files[counter] = argv[argc];											// przypisanie tablicy wartoœci tablicy
				counter++;																// zwiêkszanie licznika
			}
		}
		else
			cout << "Bledny format danych wejsciowych." << endl;						// komunikat w konsoli
	}
	Student * head = nullptr;															// przypisanie wartoœci do wskaŸnika
	int counter = 0;																	// deklaracja zmiennej counter
	while (files[counter] != "")														// wykonywanie instrukcji dopóki plik!= ""
	{
		if (!(files[counter].find(".txt") == string::npos))								// czytanie danych dopóki elementy sie nie skoñczy³y
			read_data(files[counter], &head);											// wywo³anie funkcji read_data
		counter++;																		// zwiêkszanie licznika o 1
	}
	create_index(head);																	// wywo³anie funkcji create_index
	empty_memory(&head);																// wywo³anie funkcji empty_memory
	return 0;																			// zwracanie 0
}