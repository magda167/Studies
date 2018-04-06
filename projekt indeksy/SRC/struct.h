#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "function.h"

using namespace std;

// struktura Grade (Ocena) zawierajaca przedmiot i ocene z przedmiotu oraz wska�nik na nastepny element 
struct Grade
{
	string Subject;				// zmienna Subject (przedmiot) typu string przechowuj�ca nazwy przedmiot�w
	double grade;				// zmienna grade (ocena) typu double przechowuj�ca oceny z danych przedmiot�w 
	Grade * next;				// next - wska�nik na nast�pny element
};

// struktura Student (Student) zawieraj�ca imi� , nazwisko i wykaz ocen dla danego studenta oraz wska�nik na nast�pny element
struct Student
{
	string Name;				// zmienna Name (imi�) typu string przechowuj�ca imiona student�w
	string Surname;				// zmienna Surname (nazwisko) typu string przechowuj�ca imiona student�w
	Grade * List;				// List (lista) - wska�nik na obiekt typu Grade
	Student * next;				// next - wska�nik na nast�pny element
};
