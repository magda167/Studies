#pragma once
#include <iostream>                                // dodanie biblioteki iostream ,odczyt i zapis podstawowych strumieni
#include <fstream>                                 // dodanie biblioteki fstream , operacje na plikach zewn�trznych
#include <string>                                  // dodanie biblioteki ,przechowywanie ci�gu znak�w
using namespace std;                               // u�ywanie przestrzeni nazw std
string BigLetters(string word);                    //deklaracja funkcji o argumencie typu string ,zwracaj�ca wartosc typu int
int ToDecSys(string number, int system);        //deklaracja funkcji o argumentach typu string i int ,zwracaj�ca wartosc typu int
string ToTargetSys(int number, int system);     //deklaracja funkcji o argumentach typu string ,zwracaj�ca wartosc typu int

