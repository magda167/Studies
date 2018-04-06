#include "Main.h"
#include "file_operations.h"
#include "function_to_list.h"

int main(int argc, char** argv)
{
	struct Student * head = NULL; //head -  wskaŸnik na g³owê listy 
	if (argc == 1)
	{
		printf("Blednie podane argumenty.\n");
		printf("Prosze podac inne argumenty.\n");
		printf("Przyklad poprawnego podania plikow : Dziekanat.exe -i Informatyka.txt Matematyka.txt . \n");
	}
	else
	{
		if (!strcmp(argv[1], "-i"))
		{
			while (--argc>1)
			{
				read_data(argv[argc], &head);
			}
		}
		else
			printf("Bledny format danych wejsciowych.\n");
	}
	create_index(head);
	empty_memory(&head);
	return 0;
}