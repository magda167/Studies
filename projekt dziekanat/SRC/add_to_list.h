#ifndef ADD_TO_LIST
#define ADD_TO_LIST

void add_grade_to_list(struct Student * list, struct Grade *new_grade);
/*funkcja w pierwszej kolejnoœci sprawdza czy lista jest pusta
jeœli jest pusta dodany zostaje element i to on staje sie pierwszym elementem listy 
jeœli nie, dodaje element na pocz¹tku listy */

struct Grade* add_grade(char* leadery, char* subjecty, double gradey, char* datay);
/* funkcja pobiera dane dotycz¹ce oceny studenta z danego przedmiotu
za pomoc¹ malloc alokuje pamiêæ na kolejne elementy sk³adowe nale¿¹ce do tmp
za pomoc¹ funkcji strcpy kopiuje kolejne dane do odpowiednich sk³adowych elementu tmp
za pomoc¹ strlen odczytuje d³ugoœæ danego ci¹gu znaków 
zwraca wskaŸnik na utworzony element */

struct Student* add_student(char *name, char *surname, int id_number);
/* funkcja dodaje studenta do listy w razie gdy ten nie zosta³ odnaleziony na liœcie
funkcja alokuje pamiêæ na nowego studenta i jego dane
funkcja strlen odczytuje d³ugoœæ danego ci¹gu znaków 
zwraca wskaŸnik na dodany element*/

void add_student_to_list(struct Student ** list, struct Student* new_student);
/*funkcja w pierwszej kolejnoœci sprawdza czy lista jest pusta
jeœli jest pusta, dodaje nowego studenta i to on staje siê pierwszym elementem listy
jeœli nie, dodaje element na pocz¹tku listy i zwraca wskaŸnik na tego studenta*/

#endif
