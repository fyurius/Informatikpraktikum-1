///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

//bad practice !!!
using namespace std;

#include <iostream>
#include <string>

//Deklarierung f�r spaetere Funktion
string verschluesseln(char schluessel[2][26], string wort);
string entschluesseln(char schluessel[2][26], string wort);



int main()
{
	// Hier folgt Ihr Code

	//Frage 2
	//Erstellung einer Chiffre, welche einen Buchstaben mit seinem Komplement im Alphabet verschl�sselt
	char chiffre [2][26];
	for(int i=0; i<1;i++)
	{
		//Erste Zeile alphabetisch aufsteigender Buchstaben
		for (int c=0;c<=25;c++)
		{
			chiffre[i][c] = 65+c;
		}
	}
	for(int i=1; i<2;i++)
		{
		//Zweite Zeile alphabetisch fallender Buchstaben
			for (int c=0;c<=25;c++)
			{
				chiffre[i][c] = 90-c;
			}
		}

	//Frage 5
	//Gegenst�ck zur Chiffre, entschl�sselt einen Buchstaben anhand seines Komplementes im Alphabet
	char dechiffre [2][26];
		for(int i=0; i<1;i++)
		{
			//Erste Zeile alphabetisch fallender Buchstaben
			for (int c=0;c<=25;c++)
			{
				dechiffre[i][c] = 90-c;
			}
		}
		for(int i=1; i<2;i++)
			{
			//Zweite Zeile alphabetisch steigender Buchstaben
				for (int c=0;c<=25;c++)
				{
					dechiffre[i][c] = 65+c;
				}
			}

	//Frage 4
	//Aufforderung zur Eingabe, einlesen und verschluesseln sowie ausgeben der Eingabe
	std::cout<<"Bitte geben Sie nun ihr zu verschluesselndes Wort in Gro�buchstaben ein:"<<std::endl;
	std::string eingabe;
	std::cin>>eingabe;
	std::cout<<"Ihr Wort im Klartext: "<<eingabe<<std::endl;
	std::cout<<"Ihr Wort verschluesselt: "<<verschluesseln(dechiffre, eingabe)<<std::endl;

	//Frage 6
	//Aufforderung zur Eingabe, einlesen und entschluesseln sowie ausgeben der Eingabe
	std::cout<<"Bitte geben Sie nun ihr  verschluesseltes Wort in Gro�buchstaben ein:"<<std::endl;
	std::cin>>eingabe;
	std::cout<<"Ihr Wort im Klartext: "<<eingabe<<std::endl;
	std::cout<<"Ihr Wort entschluesselt: "<<entschluesseln(dechiffre, eingabe)<<std::endl;

	return 0;
}

//Frage 3
//Verschluesselt das �bergebene Wort mithilfe des uebergebenen Uebersetzungsfeldes und gibt das Ergebnis zur�ck
string verschluesseln(char schluessel[2][26], string wort)
{
	int laenge = wort.length();
	std::string ausgabe;

	for(int i=0; i<laenge;i++)
	{
		char z = wort[i];
		for (int c=0;c<=25;c++)
			{
				if(z==schluessel[0][c])
				{
					ausgabe.push_back(schluessel[1][c]);
				}
			}
	}

	return ausgabe;
}

//Frage 4
//Entschluesselt das uebergebene Wort mithilfe des uebergebenen Uebersetzungsfeldes und gibt das Ergebnis zur�ck
string entschluesseln(char schluessel[2][26], string wort)
{
	int laenge = wort.length();
	std::string ausgabe;

	for(int i=0; i<laenge;i++)
	{
		char z = wort[i];
		for (int c=0;c<=25;c++)
			{
				if(z==schluessel[0][c])
				{
					ausgabe.push_back(schluessel[1][c]);
				}
			}
	}

	return ausgabe;
}
