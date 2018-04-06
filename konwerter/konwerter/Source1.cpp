# include "Header.h"                                    // do��czanie pliku nag��wkowego 
string BigLetters(string word)                          // deklaracja funkcji zamieniaj�cej ma�e litery na du�e
{
	for (int i = 0; i < word.length(); i++)             // p�tla okre�laj�ca do jakiego momentu funkcja ma zamienia� ma�e litery
	{
		if (word[i] > 96 && word[i] < 123)              // sprawdzanie  czy znak jest ma�� liter�
			word[i] -= 32;                              // odejmowanie 32 w przypadku gdy podana zosta�a ma�a litera
	}

	return word;                                        // zwracanie warto�ci s�owa
}
int ToDecSys(string number, int system)              // deklaracja funkcji zamieniaj�cej liczbe na system dziesi�tny
{
	int decnumber = 0, basis = 1;                     // deklaracja argument�w typu int i nadanie im warto�ci pocz�tkowych
	bool negativenumber = false;                        // deklaracja argumentu i nadanie warto�ci pocz�tkowej

	if (number[0] == '-')                               // sprawdzanie czy podana liczba by�a ujemna
	{
		negativenumber = true;                          // przypisanie do argumentu warto�ci true
		number = number.erase(0, 1);                    // usuwanie pierwszego znaku z ci�gu znak�w
	}

	for (int i = number.length() - 1; i >= 0; i--)      // p�tla okre�laj�ca jak d�ugo b�d� zamieniane znaki na warto�ci liczbowe
	{
		int temp;                                       // deklaracja zmiennej typu int
		if (number[i] > 64)                             // sprawdzanie czy w argumencie zosta�y podane litery
			temp = number[i] - 55;                      // przypisanie do zmiennej warto�ci liczbowej litery w kodzie asci
		else                                            // albo
			temp = number[i] - 48;                      // przypisanie do zmiennej warto�ci zamienianej wg. kodu asci
		if (temp >= system)                             // sprawdzanie czy zmienna jest mniejsza od argumentu funkcji
			return 0;                                   // zwracanie warto�ci 0
		decnumber += basis * temp;                    // dodawanie do zmiennej argumentu pomno�onego razy zmienn�
		basis *= system;                                  // mno�enie zmiennej razy argument
	}

	if (negativenumber)                                 // sprawdzanie czy argument jest liczb� ujemn�
		decnumber *= -1;                            // mno�enie argumentu razy -1
	return decnumber;                               // zwracanie warto�ci dziesi�tnej
}

string ToTargetSys(int number, int system)           //definicja funkcji zamieniaj�cej liczb� dziesi�tna na inny system
{
	string tempstring = "", numberstring = "";          // deklaracja argument�w typu string i ich poczatkowej wartosci
	bool negativenumber = false;                        // przypisanie warto�ci false do zmiennej typu prawda-fa�sz
	if (number < 0)                                     // sprawdzanie czy argument jest mniejszy od 0
	{
		number *= -1;                                   // mno�enie argumentu razy -1
		negativenumber = true;                          // przypisanie argumentowi warto�ci true
	}
	while (number > 0)                                  // sprawdzanie czy argument jest wi�kszy od zera
	{
		int temp = number % system;                     // przypisanie zmiennej wyniku dzielenia modulo dw�ch argument�w
		if (temp < 10)                                  // sprawdzanie czy warto�� zmiennej jest mniejsza od 10
			tempstring += char(temp + 48);              // dodanie do zmiennej znaku (liczba + 48)

		else                                            // albo 
			tempstring += char(temp + 55);              // dodanie do zmiennej znaku (liczba + 55)
		number /= system;                               // przypisanie do argumentu wyniku dzielenia argment�w
	}
	for (int i = tempstring.length() - 1; i >= 0; i--)  // p�tla okre�laj�ca jak d�ugo b�d� wykonywane dzia�ania na ci�gu znak�w
		numberstring += tempstring[i];                  // dodanie do zmiennej typu string warto�ci zmiennej typu string
	if (negativenumber)                                 // sprawdzanie czy liczba jest ujemna
		numberstring = "-" + numberstring;              // przypisanie minusa do liczby ujemnej
	return numberstring;                                // zwracanie wartosci w innym systemie
}