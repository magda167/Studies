#include "function.h"
#include "struct.h"

void add_student(Student ** list, string name, string surname)		// funkcja add_student typu void z trzema argumentami
{
	Student * tmp = new Student;									// alokacja pamiÍci
	tmp->Name = name;												// wpisanie wartoúci do elementu na ktÛry wskazuje wskaünik
	tmp->Surname = surname;											// wpisanie wartoúci do elementu na ktÛry wskazuje wskaünik
	tmp->List = nullptr;											// przypisanie 0 do elementu na ktÛry wskazuje wskaünik
	tmp->next = nullptr;											// przypisanie 0 do elementu na ktry wskazuje wskaünik
	if ((*list) == nullptr)											// sprawdzanie czy wskaünik wskazuje na 0
	{
		(*list) = tmp;												// przypisanie wartoúci do wskaünika
	}
	else
	{
		Student * it = (*list);										// tworzenie nowego wskaünika i okreslenie na co wskazuje
		while (it->next != nullptr)									// sprawdzenie czy wskaünik nie wskazuje na 0
		{
			it = it->next;											// wskaünik na nastÍpny element
		}
		it->next = tmp;												// wpisanie wartoúci do elementu na ktÛry wskazuje wskaünik
	}
}
/*
bool check_student(Student * list, string name, string surname)		// funkcja check_student typu bool z trzema argumentami
{
	while (list != nullptr)											// sprawdzanie czy wskaünik nie wskazuje na 0
	{
		if (list->Name == name && list->Surname == surname)			// sprawdzanie czy wskaünik wskazuje na dany element
			return true;											// zwracanie wartoúci true
		list = list->next;											// wskaünik na nastÍpny element
	}
	return false;													// zwracanie wartoúci false
}*/

void add_grade(Student * student, double grade, string subject)		// funkcja add_grade typu void z trzema argumentami
{
	Grade * tmp = new Grade;										// alokacja pamieci na nowy element
	tmp->grade = grade;												// wpisanie wartoúci do elementu na ktÛry pokazuje wskaünik
	tmp->Subject = subject;											// wpisanie wartoúci do elementu na ktÛry pokazuje wskaünik
	tmp->next = nullptr;											// przypisanie 0 do elementu na ktÛry wskazuje wskaünik
	if (student->List == nullptr)									// sprawdzanie czy wskaünik nie wskazuje na 0
	{
		student->List = tmp;										// przypisanie wartosci do elementu na ktÛry wskazuje wskaünik
	}
	else
	{
		tmp->next = student->List;									// przypisanie do wskaünika innego wskaünika
		student->List = tmp;										// przypisanie wartoúci do elementu na ktÛry wskazuje wskaünik
	}
}

void create_index(Student * list)									// funkcja create_index typu void z jednym argumentem
{
	while (list != nullptr)											// sprawdzanie czy wskaünik nie wskazuje na 0
	{
		string fileName = list->Name + list->Surname + ".txt";		// przypisanie do zmiennej fileName Name+Surname+".txt"
		ofstream stream;											// deklaracja obiektu stream typu ofstream
		stream.open(fileName);										// otwieranie pliku wyjúciowego
		if (stream.is_open())										// sprawdzanie czy plik zosta≥ otwarty
		{
			Grade * tmp = list->List;								// przypisanie wartoúci do wskaünika
			while (tmp != nullptr)									// sprawdzanie czy wskaünik tmp nie wskazuje na 0
			{
				stream << tmp->Subject << ": " << tmp->grade << endl;	// zapisanie do pliku Subject i grade
				tmp = tmp->next;									// wskaünik na nastÍpny element
			}
			stream.close();											// zamykanie strumienia wyjúciowego
		}
		list = list->next;											// wskaünik na nastÍpny element


	}
}

void read_data(string fileName, Student ** head)					// funkcja read_data typu void z dwoma argumentami
{
	string subject = fileName.substr(0, fileName.find(".txt"));		// zapisanie fileName do zmiennej subject typu string
	ifstream stream;												// deklaracja obiektu stream typu ifstream
	stream.open(fileName);											// otwieranie pliku wejúciowego
	if (stream.is_open())											// sprawdzanie czy strumieÒ wejúciowy jest otwarty
	{
		while (stream.good())										// sprawdzanie czy strumieÒ wejúciowy jest prawid≥owy
		{
			string name;											// deklaracja obiektu name typu string
			stream >> name;											// czytanie z pliku imienia
			string surname;											// deklaracja obiektu surname typu string
			stream >> surname;										// czytanie z pliku nazwiska
			double grade;											// deklaracja obiektu grade typu double
			stream >> grade;										// czytanie z pliku oceny
			if (!stream.fail())										// sprawdzanie czy strumieÒ wyjúciowy jest poprawny
			{
				if (!check_student((*head), name, surname))			// wywo≥anie funkcji sprawdü studenta i warunek
					add_student(head, name, surname);				// wywo≥anie funkcji dodaj studenta
				Student * present_student = find_student(name, surname, (*head));	// przypisanie wskaünikowi wartoúci funkcji
				add_grade(present_student, grade, subject);			// wywo≥anie funkcji dodaj studenta
			}
		}
		stream.close();												// zamykanie strumienia wyjúciowego
	}
}

/*Student * find_student(string name, string surname, Student * head)	// funkcja find_student typu Student z trzema argumentami
{
	while (head != nullptr)											// sprawdzanie czy wskaünik head nie wskazuje na 0
	{
		if (head->Name == name && head->Surname == surname)			// sprawdzanie czy wskaünik wskazuje na dany element
			return head;											// zwracanie wartoúci head
		head = head->next;											// przejúcie do nastÍpnego elementu
	}
	return nullptr;													// zwracanie 0
}*/

/*void empty_memory(Student ** head)									// funkcja empty_memory typu void z jednym argumentem 
{
	Student * tmp = (*head);										// utworzenie wskaünika pomocniczego tmp
	while ((*head) != nullptr)										// sprawdzanie czy wskaünik head nie wskazuje na 0
	{
		tmp = (*head);												// przypisanie wartoúci do wskaünika
		while (tmp->List != nullptr)								// sprawdzanie czy wskaünik wskazuje na element rÛwny 0
		{
			Grade * tmp2 = tmp->List;								// tworzenie wskaünika
			tmp->List = tmp->List->next;							// przypisanie wartoúci do wskaünika
			delete tmp2;											// usuwanie wskaünika
		}
		(*head) = (*head)->next;									// przejúcie do nastepnego elementu
		delete tmp;													// usuwanie wskaünika
	}
}*/