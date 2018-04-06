#include "function_to_list.h"
#include "Main.h"

struct Student* find_student(int ID_number, struct Student * list)
{
	struct Student * head = list; // head - wskaŸnik wskazuj¹cy na to samo co list
	while (head != NULL)
	{
		if (head->ID == ID_number)
			return head;
		else
		head = head->next;
	}
	return NULL;
}

void empty_memory(struct Student ** head)
{
	struct Student * tmp = (*head); // tmp - wskaŸnik wskazuj¹cy na to samo co head
	while ((*head) != NULL)
	{
		tmp = (*head);
		free(tmp->Name);
		free(tmp->Surname);
		while (tmp->List != NULL)
		{
			struct Grade * tmp2 = tmp->List; // wskaŸnik wskazuj¹cy na to samo co tmp-> List
			tmp->List = tmp->List->next;
			free(tmp2->data);
			free(tmp2->leader);
			free(tmp2->subject);
			free(tmp2);
		}
		(*head) = (*head)->next;
		free(tmp);
	}
}
