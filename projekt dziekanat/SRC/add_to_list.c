#include "add_to_list.h"
#include "Main.h"

void add_grade_to_list(struct Student * list, struct Grade *new_grade)
{
	if (list->List == NULL)
	{
		list->List = new_grade;
	}
	else
	{
		new_grade->next = list->List;
		list->List = new_grade;
	}
}

struct Grade* add_grade(char* leadery, char* subjecty, double gradey, char* datay)
{
	struct Grade * tmp = (struct Grade*)malloc(sizeof(struct Grade)); //  tmp - wskaŸnik na element listy w ktorym bêd¹ dane dot.oceny 
	tmp->grade = gradey;
	tmp->subject = (char*)malloc(sizeof(char) * strlen(subjecty) + 1);    
	strcpy(tmp->subject, subjecty);
	tmp->leader = (char*)malloc(sizeof(char) * strlen(leadery) + 1);      
	strcpy(tmp->leader, leadery);
	tmp->data = (char*)malloc(sizeof(char) * strlen(datay) + 1);	
	strcpy(tmp->data, datay);
	tmp->next = NULL;
	return tmp;
}

struct Student* add_student(char *name, char *surname, int id_number)
{
	struct Student*tmp = (struct Student*)malloc(sizeof(struct Student)); // tmp - wskaŸnik na element w którym bêd¹ dane studenta	
	tmp->Name = (char*)malloc(sizeof(char) * strlen(name) + 1);				
	strcpy(tmp->Name, name);
	tmp->Surname = (char*)malloc(sizeof(char) * strlen(surname) + 1);	
	strcpy(tmp->Surname, surname);
	tmp->ID = id_number;
	tmp->List = NULL;
	tmp->next = NULL;
	return tmp;
};

void add_student_to_list(struct Student ** list, struct Student* new_student)
{
	if ((*list) == NULL)
	{
		(*list) = new_student;
	}
	else
	{
		struct Student* it = (*list); // it - wskaŸnik zapamiêtuj¹cy to na co wskazuje list
		while (it->next != NULL)
		{
			it = it->next;
		}
		it->next = new_student;
	}
}