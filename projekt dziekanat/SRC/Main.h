#ifndef MAIN_H
#define MAIN_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_LENGTH 100
#define MAX_ID 10

/* struktura przechowuj�ca oceny studenta */
struct Grade
{
	char* leader;
	char *subject;
	double grade;
	char* data;
	struct Grade *next;
};

/* struktura przechowuj�ca dane studenta */
struct Student
{
	char* Name;
	char* Surname;
	int ID;
	struct Grade *List;
	struct Student *next;
};

int main(int argc, char** argv);

/* funkcja obs�uguje operacje na danych wprowadzonych do wiersza polece�
w razie b��dnego odczytu lub braku argument�w wy�wietla odpowiednie komunikaty
funkcja strcmp por�wnuje znaki i w przypadku napotkania prze��cznika -i rozpoczyna operacje na danych
tworzy tablic� z nazwami poszczeg�lnych protoko��w egzaminacyjnych wprowadzonych do wiersza polece�
wywo�uje funkcj� odczytuj�c� dane z pliku
po dokonaniu operacji wywo�uje funkcj� do tworzenia indeks�w i czyszczenia pami�ci */

#endif
