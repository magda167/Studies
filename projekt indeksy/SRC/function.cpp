#include "function.h"
#include "struct.h"

void add_student(Student ** list, string name, string surname)		// funkcja add_student typu void z trzema argumentami
{
	Student * tmp = new Student;									// alokacja pami�ci
	tmp->Name = name;												// wpisanie warto�ci do elementu na kt�ry wskazuje wska�nik
	tmp->Surname = surname;											// wpisanie warto�ci do elementu na kt�ry wskazuje wska�nik
	tmp->List = nullptr;											// przypisanie 0 do elementu na kt�ry wskazuje wska�nik
	tmp->next = nullptr;											// przypisanie 0 do elementu na ktry wskazuje wska�nik
	if ((*list) == nullptr)											// sprawdzanie czy wska�nik wskazuje na 0
	{
		(*list) = tmp;												// przypisanie warto�ci do wska�nika
	}
	else
	{
		Student * it = (*list);										// tworzenie nowego wska�nika i okreslenie na co wskazuje
		while (it->next != nullptr)									// sprawdzenie czy wska�nik nie wskazuje na 0
		{
			it = it->next;											// wska�nik na nast�pny element
		}
		it->next = tmp;												// wpisanie warto�ci do elementu na kt�ry wskazuje wska�nik
	}
}
/*
bool check_student(Student * list, string name, string surname)		// funkcja check_student typu bool z trzema argumentami
{
	while (list != nullptr)											// sprawdzanie czy wska�nik nie wskazuje na 0
	{
		if (list->Name == name && list->Surname == surname)			// sprawdzanie czy wska�nik wskazuje na dany element
			return true;											// zwracanie warto�ci true
		list = list->next;											// wska�nik na nast�pny element
	}
	return false;													// zwracanie warto�ci false
}*/

void add_grade(Student * student, double grade, string subject)		// funkcja add_grade typu void z trzema argumentami
{
	Grade * tmp = new Grade;										// alokacja pamieci na nowy element
	tmp->grade = grade;												// wpisanie warto�ci do elementu na kt�ry pokazuje wska�nik
	tmp->Subject = subject;											// wpisanie warto�ci do elementu na kt�ry pokazuje wska�nik
	tmp->next = nullptr;											// przypisanie 0 do elementu na kt�ry wskazuje wska�nik
	if (student->List == nullptr)									// sprawdzanie czy wska�nik nie wskazuje na 0
	{
		student->List = tmp;										// przypisanie wartosci do elementu na kt�ry wskazuje wska�nik
	}
	else
	{
		tmp->next = student->List;									// przypisanie do wska�nika innego wska�nika
		student->List = tmp;										// przypisanie warto�ci do elementu na kt�ry wskazuje wska�nik
	}
}

void create_index(Student * list)									// funkcja create_index typu void z jednym argumentem
{
	while (list != nullptr)											// sprawdzanie czy wska�nik nie wskazuje na 0
	{
		string fileName = list->Name + list->Surname + ".txt";		// przypisanie do zmiennej fileName Name+Surname+".txt"
		ofstream stream;											// deklaracja obiektu stream typu ofstream
		stream.open(fileName);										// otwieranie pliku wyj�ciowego
		if (stream.is_open())										// sprawdzanie czy plik zosta� otwarty
		{
			Grade * tmp = list->List;								// przypisanie warto�ci do wska�nika
			while (tmp != nullptr)									// sprawdzanie czy wska�nik tmp nie wskazuje na 0
			{
				stream << tmp->Subject << ": " << tmp->grade << endl;	// zapisanie do pliku Subject i grade
				tmp = tmp->next;									// wska�nik na nast�pny element
			}
			stream.close();											// zamykanie strumienia wyj�ciowego
		}
		list = list->next;											// wska�nik na nast�pny element


	}
}

void read_data(string fileName, Student ** head)					// funkcja read_data typu void z dwoma argumentami
{
	string subject = fileName.substr(0, fileName.find(".txt"));		// zapisanie fileName do zmiennej subject typu string
	ifstream stream;												// deklaracja obiektu stream typu ifstream
	stream.open(fileName);											// otwieranie pliku wej�ciowego
	if (stream.is_open())											// sprawdzanie czy strumie� wej�ciowy jest otwarty
	{
		while (stream.good())										// sprawdzanie czy strumie� wej�ciowy jest prawid�owy
		{
			string name;											// deklaracja obiektu name typu string
			stream >> name;											// czytanie z pliku imienia
			string surname;											// deklaracja obiektu surname typu string
			stream >> surname;										// czytanie z pliku nazwiska
			double grade;											// deklaracja obiektu grade typu double
			stream >> grade;										// czytanie z pliku oceny
			if (!stream.fail())										// sprawdzanie czy strumie� wyj�ciowy jest poprawny
			{
				if (!check_student((*head), name, surname))			// wywo�anie funkcji sprawd� studenta i warunek
					add_student(head, name, surname);				// wywo�anie funkcji dodaj studenta
				Student * present_student = find_student(name, surname, (*head));	// przypisanie wska�nikowi warto�ci funkcji
				add_grade(present_student, grade, subject);			// wywo�anie funkcji dodaj studenta
			}
		}
		stream.close();												// zamykanie strumienia wyj�ciowego
	}
}

/*Student * find_student(string name, string surname, Student * head)	// funkcja find_student typu Student z trzema argumentami
{
	while (head != nullptr)											// sprawdzanie czy wska�nik head nie wskazuje na 0
	{
		if (head->Name == name && head->Surname == surname)			// sprawdzanie czy wska�nik wskazuje na dany element
			return head;											// zwracanie warto�ci head
		head = head->next;											// przej�cie do nast�pnego elementu
	}
	return nullptr;													// zwracanie 0
}*/

/*void empty_memory(Student ** head)									// funkcja empty_memory typu void z jednym argumentem 
{
	Student * tmp = (*head);										// utworzenie wska�nika pomocniczego tmp
	while ((*head) != nullptr)										// sprawdzanie czy wska�nik head nie wskazuje na 0
	{
		tmp = (*head);												// przypisanie warto�ci do wska�nika
		while (tmp->List != nullptr)								// sprawdzanie czy wska�nik wskazuje na element r�wny 0
		{
			Grade * tmp2 = tmp->List;								// tworzenie wska�nika
			tmp->List = tmp->List->next;							// przypisanie warto�ci do wska�nika
			delete tmp2;											// usuwanie wska�nika
		}
		(*head) = (*head)->next;									// przej�cie do nastepnego elementu
		delete tmp;													// usuwanie wska�nika
	}
}*/