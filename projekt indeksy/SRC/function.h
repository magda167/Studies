#pragma once
#include "struct.h"

using namespace std;

void add_student(Student ** list, string name, string surname);
// add_student (dodaj_studenta) - funkcja do tworzenia listy nazwisk i imion student�w 
// funkcja pobiera dwa elementy typu string name, surname ( imie i nazwisko studenta)
// funkcja pobiera r�wnie� jeden element list (lista) , kt�ry jest wska�nikiem na wska�nik na element typu Student
// funkcja tworzy nowy element listy tmp (temporary - tymczasowy)
// do elementu wpisuje dane studenta (name, surname - imie, nazwisko)
// sprawdza czy lista ma kolejne elementy
// wstawia do listy nowy element - dopisuje do listy imie i nazwisko nast�pnego studenta


bool check_student(Student *list, string name, string surname);
// check_student (sprawd� studenta) - funkcja typu bool zwracaj�ca warto�� prawda lub fa�sz
// funkcja pobiera dwa argumenty typu string name,surname ( imie i nazwisko studenta)
// do funkcji przekazywany jest tak�e element list (lista) - wska�nik na obiekt typu Student
// w przypadku gdy lista student�w nie jest pusta sprawdza czy dany student juz pojawil sie na liscie
// gdy name, surname (imie i nazwisko) juz by�o na liscie zwraca wartosc true i wskazuje na kolejny element
// w innym przypadku zwraca warto�� false

void add_grade(Student *student, double grade, string subject);
// funkcja add_grade (dodaj_ocen�) - funkcja typu void do tworzenia wykazu ocen 
// funkcja pobiera dwa argumenty - grade (ocena) typu double i subject(przedmiot) typu string
// do funkcji przekazywany jest tak�e wska�nik student na obiekt typu Student
// funkcja tworzy nowy element listy tmp (temporary - tymczasowy) 
// do elementu wpisuje grade, subject (ocen� i przedmiot)
// sprawdza czy lista ma kolejne elementy 
// wstawia do listy nowy element - dopisuje do listy (grade, subject - ocen�, przedmiot)

void create_index(Student *list);
// create_index (stw�rz_indeks) - funkcja typu void do generowania indeks�w
// funkcja pobiera jeden element list (lista) - wska�nik na obiekt typu student
// najpierw sprawdza czy obiekt list (lista) nie jest pusty
// generuje nazwe (fileName) pliku dla ka�dego studenta postaci NameSurname.txt (ImieNazwisko.txt)
// otwiera plik wyj�ciowy i sprawdza czy zosta� on poprawnie wygenerowany
// korzystaj�c ze stworzonej wcze�niej listy ocen dla danego studenta pobiera kolejne dane
// zapisuje (grade, Subject - ocena, przedmiot) do pliku wyj�ciowego 
// przechodzi do nastepnego elementu listy
// zamyka plik do zapisu 

void read_data(string fileName, Student **head);
// funkcja typu void zajmuj�ca si� pobieraniem danych z plik�w wej�ciowych 
// funkcja pobiera argument fileName (nazwa pliku) typu string
// funkcja pobiera tak�e wska�nik na wska�nik head (g�owa) na element typu Student
// funkcja pobiera z nazwy pliku nazw� przedmiotu i zapisuje ja do zmiennej subject (przedmiot)
// otwiera plik wej�ciowy i sprawdza czy zosta� otwarty prawid�owo
// je�li tak to pobiera z pliku kolejno name, surname, grade (imi�, nazwisko, ocen� daneo studenta)
// wywo�uje funkcje check_student i dodaje studenta do listy 
// lub wywo�uje powy�sz� funkcj� nastepnie wywoluje funkcj� find_student i dodaje studenta do listy

Student * find_student(string name, string surname, Student *head);
// funkcja find_student wskazuj�ca na element typu student , funkcja do szukania studenta
// funkcja pobiera dwa argumenty (name, surname - imi�, nazwisko) typu string 
// funkcja pobiera tak�e wska�nik head (glowa) na element typu Student
// funkcja sprawdza czy istnieje g�owa listy
// jesli istnieje to sprawdza czy wskazuje ona na (Name, Surname - imi� i nazwisko studenta)
// jesli warunek jest spelniony zwraca warto�� (head) g�owy i wskazuje na nastepny (next) element
// jesli warunek nie jest spelniony zwraca 0

void empty_memory(Student **head);
// funkcja empty_memory (zwolnij pami��) typu void do zwalniania pami�ci
// do funkcji przekazywany jest jeden argument head (g�owa) kt�ry jest wska�nikiem na wska�nik typu Student
// funkcja tworzy wska�nik tmp (temporary - tymczasowy) wskazuj�cy na g�ow�
// sprawdza czy wska�nik na head (g�ow�) nie jest zerem
// jesli jest przypisuje wska�nikowi tmp warto�� wska�nika na head (g�ow�)
// sprawdza czy wska�nik tmp (tymczasowy) na element List (lista) jest r�ny od zera
// je�li tak to tworzy kolejny wska�nik tmp (tymczasowy2) r�wny wska�nikowi tmp wskazuj�cemu na element List (lista)
// przechodzi do nast�pnego elementu i usuwa wska�nik tmp2
// przechodzi do nast�pnego elementu na kt�ry wskazuje head (g�owa) i usuwa wska�nik tmp


