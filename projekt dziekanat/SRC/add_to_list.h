#ifndef ADD_TO_LIST
#define ADD_TO_LIST

void add_grade_to_list(struct Student * list, struct Grade *new_grade);
/*funkcja w pierwszej kolejno�ci sprawdza czy lista jest pusta
je�li jest pusta dodany zostaje element i to on staje sie pierwszym elementem listy 
je�li nie, dodaje element na pocz�tku listy */

struct Grade* add_grade(char* leadery, char* subjecty, double gradey, char* datay);
/* funkcja pobiera dane dotycz�ce oceny studenta z danego przedmiotu
za pomoc� malloc alokuje pami�� na kolejne elementy sk�adowe nale��ce do tmp
za pomoc� funkcji strcpy kopiuje kolejne dane do odpowiednich sk�adowych elementu tmp
za pomoc� strlen odczytuje d�ugo�� danego ci�gu znak�w 
zwraca wska�nik na utworzony element */

struct Student* add_student(char *name, char *surname, int id_number);
/* funkcja dodaje studenta do listy w razie gdy ten nie zosta� odnaleziony na li�cie
funkcja alokuje pami�� na nowego studenta i jego dane
funkcja strlen odczytuje d�ugo�� danego ci�gu znak�w 
zwraca wska�nik na dodany element*/

void add_student_to_list(struct Student ** list, struct Student* new_student);
/*funkcja w pierwszej kolejno�ci sprawdza czy lista jest pusta
je�li jest pusta, dodaje nowego studenta i to on staje si� pierwszym elementem listy
je�li nie, dodaje element na pocz�tku listy i zwraca wska�nik na tego studenta*/

#endif
