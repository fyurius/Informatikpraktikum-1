 /////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 2.0: Fibonacci
//
// Datei:  Funktion.cpp
// Inhalt: Fibonacci-Berechnung
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

//Deklaration der später genutzten Funktion
int algorithmus (int startwert);

int main()
{
	int count = 0;
	int traeger = 0;

	//Gibt die Fibonacci-Zahlen nacheinander aus
	while(count<26)
	{
		traeger = algorithmus(count);
		std::cout<<traeger<<std::endl;
		count++;
	}
}

//Logik um eine rekursive Berechnung und Ausgabe ausgehend von einem Startwert zu realisieren
//Zahl besteht aus Summe der beiden vorherigen
int algorithmus (int startwert)
{
	if (startwert==0)
	{
		return 0;
	}
	else if (startwert == 1)
	{
		return 1;
	}
	else
	{
		return algorithmus(startwert-1)+algorithmus(startwert-2);
	}
	return 0;
	}
