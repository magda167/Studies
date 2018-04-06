#ifndef FUNCTION_TO_LIST
#define FUNCTION_TO_LIST


struct Student* find_student(int ID_number, struct Student * headx);
/* funkcja sprawdzaj�ca czy dany student pojawil sie juz na li�cie
funkcja wyszukuje studenta na li�cie
je�li nie zosta� odnaleziony zwraca NULL
je�li zosta� znaleziony zwraca wska�nik na tego studenta */


void empty_memory(struct Student ** head);
/* funkcja do zwalniania pami�ci
tworzy wska�nik tymczasowy aby nie utraci� g�owy listy
usuwa dane studenta i informacje o jego ocenach i przechodzi do nast�pnego studenta */

#endif
