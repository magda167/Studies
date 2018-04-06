#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "function.h"

using namespace std;

// struktura Grade (Ocena) zawierajaca przedmiot i ocene z przedmiotu oraz wskaŸnik na nastepny element 
struct Grade
{
	string Subject;				// zmienna Subject (przedmiot) typu string przechowuj¹ca nazwy przedmiotów
	double grade;				// zmienna grade (ocena) typu double przechowuj¹ca oceny z danych przedmiotów 
	Grade * next;				// next - wskaŸnik na nastêpny element
};

// struktura Student (Student) zawieraj¹ca imiê , nazwisko i wykaz ocen dla danego studenta oraz wskaŸnik na nastêpny element
struct Student
{
	string Name;				// zmienna Name (imiê) typu string przechowuj¹ca imiona studentów
	string Surname;				// zmienna Surname (nazwisko) typu string przechowuj¹ca imiona studentów
	Grade * List;				// List (lista) - wskaŸnik na obiekt typu Grade
	Student * next;				// next - wskaŸnik na nastêpny element
};
