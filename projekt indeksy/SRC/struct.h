#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "function.h"

using namespace std;

// struktura Grade (Ocena) zawierajaca przedmiot i ocene z przedmiotu oraz wskaźnik na nastepny element 
struct Grade
{
	string Subject;				// zmienna Subject (przedmiot) typu string przechowująca nazwy przedmiotów
	double grade;				// zmienna grade (ocena) typu double przechowująca oceny z danych przedmiotów 
	Grade * next;				// next - wskaźnik na następny element
};

// struktura Student (Student) zawierająca imię , nazwisko i wykaz ocen dla danego studenta oraz wskaźnik na następny element
struct Student
{
	string Name;				// zmienna Name (imię) typu string przechowująca imiona studentów
	string Surname;				// zmienna Surname (nazwisko) typu string przechowująca imiona studentów
	Grade * List;				// List (lista) - wskaźnik na obiekt typu Grade
	Student * next;				// next - wskaźnik na następny element
};
