# include "Header.h"                                    // do³¹czanie pliku nag³ówkowego 
string BigLetters(string word)                          // deklaracja funkcji zamieniaj¹cej ma³e litery na du¿e
{
	for (int i = 0; i < word.length(); i++)             // pêtla okreœlaj¹ca do jakiego momentu funkcja ma zamieniaæ ma³e litery
	{
		if (word[i] > 96 && word[i] < 123)              // sprawdzanie  czy znak jest ma³¹ liter¹
			word[i] -= 32;                              // odejmowanie 32 w przypadku gdy podana zosta³a ma³a litera
	}

	return word;                                        // zwracanie wartoœci s³owa
}
int ToDecSys(string number, int system)              // deklaracja funkcji zamieniaj¹cej liczbe na system dziesiêtny
{
	int decnumber = 0, basis = 1;                     // deklaracja argumentów typu int i nadanie im wartoœci pocz¹tkowych
	bool negativenumber = false;                        // deklaracja argumentu i nadanie wartoœci pocz¹tkowej

	if (number[0] == '-')                               // sprawdzanie czy podana liczba by³a ujemna
	{
		negativenumber = true;                          // przypisanie do argumentu wartoœci true
		number = number.erase(0, 1);                    // usuwanie pierwszego znaku z ci¹gu znaków
	}

	for (int i = number.length() - 1; i >= 0; i--)      // pêtla okreœlaj¹ca jak d³ugo bêd¹ zamieniane znaki na wartoœci liczbowe
	{
		int temp;                                       // deklaracja zmiennej typu int
		if (number[i] > 64)                             // sprawdzanie czy w argumencie zosta³y podane litery
			temp = number[i] - 55;                      // przypisanie do zmiennej wartoœci liczbowej litery w kodzie asci
		else                                            // albo
			temp = number[i] - 48;                      // przypisanie do zmiennej wartoœci zamienianej wg. kodu asci
		if (temp >= system)                             // sprawdzanie czy zmienna jest mniejsza od argumentu funkcji
			return 0;                                   // zwracanie wartoœci 0
		decnumber += basis * temp;                    // dodawanie do zmiennej argumentu pomno¿onego razy zmienn¹
		basis *= system;                                  // mno¿enie zmiennej razy argument
	}

	if (negativenumber)                                 // sprawdzanie czy argument jest liczb¹ ujemn¹
		decnumber *= -1;                            // mno¿enie argumentu razy -1
	return decnumber;                               // zwracanie wartoœci dziesiêtnej
}

string ToTargetSys(int number, int system)           //definicja funkcji zamieniaj¹cej liczbê dziesiêtna na inny system
{
	string tempstring = "", numberstring = "";          // deklaracja argumentów typu string i ich poczatkowej wartosci
	bool negativenumber = false;                        // przypisanie wartoœci false do zmiennej typu prawda-fa³sz
	if (number < 0)                                     // sprawdzanie czy argument jest mniejszy od 0
	{
		number *= -1;                                   // mno¿enie argumentu razy -1
		negativenumber = true;                          // przypisanie argumentowi wartoœci true
	}
	while (number > 0)                                  // sprawdzanie czy argument jest wiêkszy od zera
	{
		int temp = number % system;                     // przypisanie zmiennej wyniku dzielenia modulo dwóch argumentów
		if (temp < 10)                                  // sprawdzanie czy wartoœæ zmiennej jest mniejsza od 10
			tempstring += char(temp + 48);              // dodanie do zmiennej znaku (liczba + 48)

		else                                            // albo 
			tempstring += char(temp + 55);              // dodanie do zmiennej znaku (liczba + 55)
		number /= system;                               // przypisanie do argumentu wyniku dzielenia argmentów
	}
	for (int i = tempstring.length() - 1; i >= 0; i--)  // pêtla okreœlaj¹ca jak d³ugo bêd¹ wykonywane dzia³ania na ci¹gu znaków
		numberstring += tempstring[i];                  // dodanie do zmiennej typu string wartoœci zmiennej typu string
	if (negativenumber)                                 // sprawdzanie czy liczba jest ujemna
		numberstring = "-" + numberstring;              // przypisanie minusa do liczby ujemnej
	return numberstring;                                // zwracanie wartosci w innym systemie
}