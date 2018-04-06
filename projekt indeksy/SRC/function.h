#pragma once
#include "struct.h"

using namespace std;

void add_student(Student ** list, string name, string surname);
// add_student (dodaj_studenta) - funkcja do tworzenia listy nazwisk i imion studentów 
// funkcja pobiera dwa elementy typu string name, surname ( imie i nazwisko studenta)
// funkcja pobiera równie¿ jeden element list (lista) , który jest wskaŸnikiem na wskaŸnik na element typu Student
// funkcja tworzy nowy element listy tmp (temporary - tymczasowy)
// do elementu wpisuje dane studenta (name, surname - imie, nazwisko)
// sprawdza czy lista ma kolejne elementy
// wstawia do listy nowy element - dopisuje do listy imie i nazwisko nastêpnego studenta


bool check_student(Student *list, string name, string surname);
// check_student (sprawdŸ studenta) - funkcja typu bool zwracaj¹ca wartoœæ prawda lub fa³sz
// funkcja pobiera dwa argumenty typu string name,surname ( imie i nazwisko studenta)
// do funkcji przekazywany jest tak¿e element list (lista) - wskaŸnik na obiekt typu Student
// w przypadku gdy lista studentów nie jest pusta sprawdza czy dany student juz pojawil sie na liscie
// gdy name, surname (imie i nazwisko) juz by³o na liscie zwraca wartosc true i wskazuje na kolejny element
// w innym przypadku zwraca wartoœæ false

void add_grade(Student *student, double grade, string subject);
// funkcja add_grade (dodaj_ocenê) - funkcja typu void do tworzenia wykazu ocen 
// funkcja pobiera dwa argumenty - grade (ocena) typu double i subject(przedmiot) typu string
// do funkcji przekazywany jest tak¿e wskaŸnik student na obiekt typu Student
// funkcja tworzy nowy element listy tmp (temporary - tymczasowy) 
// do elementu wpisuje grade, subject (ocenê i przedmiot)
// sprawdza czy lista ma kolejne elementy 
// wstawia do listy nowy element - dopisuje do listy (grade, subject - ocenê, przedmiot)

void create_index(Student *list);
// create_index (stwórz_indeks) - funkcja typu void do generowania indeksów
// funkcja pobiera jeden element list (lista) - wskaŸnik na obiekt typu student
// najpierw sprawdza czy obiekt list (lista) nie jest pusty
// generuje nazwe (fileName) pliku dla ka¿dego studenta postaci NameSurname.txt (ImieNazwisko.txt)
// otwiera plik wyjœciowy i sprawdza czy zosta³ on poprawnie wygenerowany
// korzystaj¹c ze stworzonej wczeœniej listy ocen dla danego studenta pobiera kolejne dane
// zapisuje (grade, Subject - ocena, przedmiot) do pliku wyjœciowego 
// przechodzi do nastepnego elementu listy
// zamyka plik do zapisu 

void read_data(string fileName, Student **head);
// funkcja typu void zajmuj¹ca siê pobieraniem danych z plików wejœciowych 
// funkcja pobiera argument fileName (nazwa pliku) typu string
// funkcja pobiera tak¿e wskaŸnik na wskaŸnik head (g³owa) na element typu Student
// funkcja pobiera z nazwy pliku nazwê przedmiotu i zapisuje ja do zmiennej subject (przedmiot)
// otwiera plik wejœciowy i sprawdza czy zosta³ otwarty prawid³owo
// jeœli tak to pobiera z pliku kolejno name, surname, grade (imiê, nazwisko, ocenê daneo studenta)
// wywo³uje funkcje check_student i dodaje studenta do listy 
// lub wywo³uje powy¿sz¹ funkcjê nastepnie wywoluje funkcjê find_student i dodaje studenta do listy

Student * find_student(string name, string surname, Student *head);
// funkcja find_student wskazuj¹ca na element typu student , funkcja do szukania studenta
// funkcja pobiera dwa argumenty (name, surname - imiê, nazwisko) typu string 
// funkcja pobiera tak¿e wskaŸnik head (glowa) na element typu Student
// funkcja sprawdza czy istnieje g³owa listy
// jesli istnieje to sprawdza czy wskazuje ona na (Name, Surname - imiê i nazwisko studenta)
// jesli warunek jest spelniony zwraca wartoœæ (head) g³owy i wskazuje na nastepny (next) element
// jesli warunek nie jest spelniony zwraca 0

void empty_memory(Student **head);
// funkcja empty_memory (zwolnij pamiêæ) typu void do zwalniania pamiêci
// do funkcji przekazywany jest jeden argument head (g³owa) który jest wskaŸnikiem na wskaŸnik typu Student
// funkcja tworzy wskaŸnik tmp (temporary - tymczasowy) wskazuj¹cy na g³owê
// sprawdza czy wskaŸnik na head (g³owê) nie jest zerem
// jesli jest przypisuje wskaŸnikowi tmp wartoœæ wskaŸnika na head (g³owê)
// sprawdza czy wskaŸnik tmp (tymczasowy) na element List (lista) jest ró¿ny od zera
// jeœli tak to tworzy kolejny wskaŸnik tmp (tymczasowy2) równy wskaŸnikowi tmp wskazuj¹cemu na element List (lista)
// przechodzi do nastêpnego elementu i usuwa wskaŸnik tmp2
// przechodzi do nastêpnego elementu na który wskazuje head (g³owa) i usuwa wskaŸnik tmp


