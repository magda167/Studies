#include "file_operations.h"
#include "add_to_list.h"
#include "function_to_list.h"
#include "Main.h"

void read_data(char* fileName, struct Student ** head)
{
	FILE* stream;
	struct Student* present_student; //present_student -  wskaŸnik na element typu struct Student
	struct Grade* new_grade; //new_grade - wskaŸnik na element typu 
	stream = fopen(fileName, "r");
	if (stream != NULL)
	{
		int idx; // idx - zmienna przechowuj¹ca numer ID studenta
		float gradex; //gradex - zmienna przechowuj¹ca ocenê studenta
		char* datax = (char*)malloc(sizeof(char) * MAX_LENGTH); // datax - zmienna typu char*, przechowuj¹ca datê wystawienia oceny
		char* namex = (char*)malloc(sizeof(char) * MAX_LENGTH); // namex - zmienna typu char*, przechowuj¹ca imiê
		char* surnamex = (char*)malloc(sizeof(char) * MAX_LENGTH);// surnamexx - zmienna typu char*, przechowuj¹ca nazwisko
		char* subjectx = (char*)malloc(sizeof(char) * MAX_LENGTH);// subjectx - zmienna typu char*, przechowuj¹ca przedmiot
		char * leaderx = (char*)malloc(sizeof(char) * MAX_LENGTH);// leaderx - zmienna typu char*, przechowuj¹ca nazwe prowadz¹cego
		fscanf(stream, "%[^\n]\n", subjectx);
		fscanf(stream, "%[^\n]\n", leaderx);
		while (feof(stream) == 0)
		{
			fscanf(stream, "%s %s %d %f %s\n", namex, surnamex, &idx, &gradex, datax);
			present_student = find_student(idx, (*head));
			if (!present_student)
			{
				present_student= add_student(namex, surnamex, idx);
				add_student_to_list(head, present_student);
			}
			new_grade = add_grade(leaderx, subjectx, gradex, datax);
			add_grade_to_list(present_student, new_grade);
		}
		free(namex);
		free(surnamex);
		free(subjectx);
		free(leaderx);
		free(datax);
		fclose(stream);
	}
	else
	{
		printf("Nie ma takiego pliku.\n");
	}
}

void create_index(struct Student * list)
{
	FILE* filesave = NULL;
	if (list == NULL)
		printf("Nie ma elementow do zapisania.\n");
	else
	{

		while (list != NULL)
		{
			char fileName[MAX_ID];
			sprintf(fileName, "%d.txt", list->ID);
			filesave = fopen(fileName, "w");
			if (filesave != NULL)
			{
				struct Grade * tmp = list->List;
				fprintf(filesave, "%s %s\nnr albumu: %d\n", list->Name, list->Surname, list->ID);
				while (tmp != NULL)
				{
					fprintf(filesave, "%s %s %.1f %s\n", tmp->leader, tmp->subject, tmp->grade, tmp->data);
					tmp = tmp->next;
				}
				fclose(filesave);
			}
			else
			{
				printf("Blad otwarcia pliku.\n");
			}
			list = list->next;
		}

	}
}
