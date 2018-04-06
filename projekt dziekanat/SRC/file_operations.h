#ifndef FILE_OPERATIONS
#define FILE_OPERATIONS

void create_index(struct Student * list);

/* funkcja tworzy indeksy na podstawie listy stworzonej w programie
tworzy plik do zapisu
alokuje pamiêæ na nazwê pliku tekstowego opartego na numerze ID studenta
sprintf - rzutuje numer ID studenta na ci¹g znaków
otwiera plik do zapisu jeœli taki istnieje, jeœli nie to go tworzy
zapisuje do pliku kolejne informacje o studencie, a nastêpnie wykaz jego ocen
zamyka plik i przechodzi do obs³ugi kolejnego studenta */

void read_data(char* fileName, struct Student ** head);

/* funkcja odczytuje dane z pliku
najpierw otwiera plik do odczytu
alokuje pamiêæ dla zczytywanych z pliku elementów
czyta z pocz¹tku pliku przedmiot i prowadz¹cego
wywo³uje funkcje sprawdzaj¹c¹ czy student pojawi³ siê ju¿ na liœcie
jeœli student ten jeszcze nie zosta³ wpisany na liste - dodaje studenta na listê
przypisuje ocene do studenta na liœcie 
zwalnia pamiêæ przydzielon¹ dla zmiennych przechowuj¹cych dane z pliku */

#endif
