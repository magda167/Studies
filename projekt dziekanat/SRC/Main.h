#ifndef MAIN_H
#define MAIN_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_LENGTH 100
#define MAX_ID 10

/* struktura przechowuj¹ca oceny studenta */
struct Grade
{
	char* leader;
	char *subject;
	double grade;
	char* data;
	struct Grade *next;
};

/* struktura przechowuj¹ca dane studenta */
struct Student
{
	char* Name;
	char* Surname;
	int ID;
	struct Grade *List;
	struct Student *next;
};

int main(int argc, char** argv);

/* funkcja obs³uguje operacje na danych wprowadzonych do wiersza poleceñ
w razie b³êdnego odczytu lub braku argumentów wyœwietla odpowiednie komunikaty
funkcja strcmp porównuje znaki i w przypadku napotkania prze³¹cznika -i rozpoczyna operacje na danych
tworzy tablicê z nazwami poszczególnych protoko³ów egzaminacyjnych wprowadzonych do wiersza poleceñ
wywo³uje funkcjê odczytuj¹c¹ dane z pliku
po dokonaniu operacji wywo³uje funkcjê do tworzenia indeksów i czyszczenia pamiêci */

#endif
