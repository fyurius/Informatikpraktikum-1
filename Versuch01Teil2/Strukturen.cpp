/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	//Deklarierung des structs person
	struct person
	{
		std::string sNachname;
		std::string sVorname;
		int iGeburtsjahr;
		int iAlter;
	};

	//Initialisierung eines Objektes vom Typ person
	//Aufforderung zur Eingabe und einlesen der jeweiligen Eingabe

	person nBenutzer;
	std::cout<<"Bitte geben sie ihren Nachnamen ein"<<std::endl;
	std::cin>>nBenutzer.sNachname;
	std::cout<<"Bitte geben sie ihren Vornamen ein"<<std::endl;
	std::cin>>nBenutzer.sVorname;
	std::cout<<"Bitte geben sie ihr Geburtsjahr ein"<<std::endl;
	std::cin>>nBenutzer.iGeburtsjahr;
	std::cout<<"Bitte geben sie ihr Alter ein"<<std::endl;
	std::cin>>nBenutzer.iAlter;

	//Erste Ausgabe der vorher eingegebenen Attribute
	std::cout<<"Ihr Nachname:"<<nBenutzer.sNachname<<std::endl;
	std::cout<<"Ihr Vorname:"<<nBenutzer.sVorname<<std::endl;
	std::cout<<"Ihr Geburtsjahr:"<<nBenutzer.iGeburtsjahr<<std::endl;
	std::cout<<"Ihr Alter:"<<nBenutzer.iAlter<<std::endl;

	//Erstellen eines neuen Objektes vom Typ person, welches Kopie des vorherigen Elementes ist
	//Jedes Attribut wird einzeln angewählt und kopiert
	person nKopieEinzeln;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	//Erstellen eines neuen Objektes vom Typ person, welches Kopie des vorherigen Elementes ist
	//Es wird dirkt das gesamte Element in einem kopiert
	person nKopieGesamt = nBenutzer;

	//Ausgabe der ersten Kopie
	std::cout<<nKopieEinzeln.sVorname<<std::endl;
	std::cout<<nKopieEinzeln.sNachname<<std::endl;
	std::cout<<nKopieEinzeln.iGeburtsjahr<<std::endl;
	std::cout<<nKopieEinzeln.iAlter<<std::endl;

	//Ausgabe der zweiten Kopie
	std::cout<<nKopieGesamt.sVorname<<std::endl;
	std::cout<<nKopieGesamt.sNachname<<std::endl;
	std::cout<<nKopieGesamt.iGeburtsjahr<<std::endl;
	std::cout<<nKopieGesamt.iAlter<<std::endl;

    return 0;
    
}
