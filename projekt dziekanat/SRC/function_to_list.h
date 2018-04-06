#ifndef FUNCTION_TO_LIST
#define FUNCTION_TO_LIST


struct Student* find_student(int ID_number, struct Student * headx);
/* funkcja sprawdzaj¹ca czy dany student pojawil sie juz na liœcie
funkcja wyszukuje studenta na liœcie
jeœli nie zosta³ odnaleziony zwraca NULL
jeœli zosta³ znaleziony zwraca wskaŸnik na tego studenta */


void empty_memory(struct Student ** head);
/* funkcja do zwalniania pamiêci
tworzy wskaŸnik tymczasowy aby nie utraciæ g³owy listy
usuwa dane studenta i informacje o jego ocenach i przechodzi do nastêpnego studenta */

#endif
