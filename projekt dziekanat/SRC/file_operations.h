#ifndef FILE_OPERATIONS
#define FILE_OPERATIONS

void create_index(struct Student * list);

/* funkcja tworzy indeksy na podstawie listy stworzonej w programie
tworzy plik do zapisu
alokuje pami�� na nazw� pliku tekstowego opartego na numerze ID studenta
sprintf - rzutuje numer ID studenta na ci�g znak�w
otwiera plik do zapisu je�li taki istnieje, je�li nie to go tworzy
zapisuje do pliku kolejne informacje o studencie, a nast�pnie wykaz jego ocen
zamyka plik i przechodzi do obs�ugi kolejnego studenta */

void read_data(char* fileName, struct Student ** head);

/* funkcja odczytuje dane z pliku
najpierw otwiera plik do odczytu
alokuje pami�� dla zczytywanych z pliku element�w
czyta z pocz�tku pliku przedmiot i prowadz�cego
wywo�uje funkcje sprawdzaj�c� czy student pojawi� si� ju� na li�cie
je�li student ten jeszcze nie zosta� wpisany na liste - dodaje studenta na list�
przypisuje ocene do studenta na li�cie 
zwalnia pami�� przydzielon� dla zmiennych przechowuj�cych dane z pliku */

#endif
