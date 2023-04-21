/*!
 * Praktikum Informatik 1 MMXXII
 *
 * @file DVD.cpp
 *//*
 * DVD.cpp
 *
 *  Created on: 21.05.2022
 *      Author: finle
 */

#include "DVD.h"

/**
 * @brief Konstruktor, der eine DVD erstellt
 *
 * @param initTitel Konstruktor der Vaterklasse
 * @param initAltersfreigabe freigabe
 * @param initGenre genre
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
: Medium(initTitel), freigabe(initAltersfreigabe), genre(initGenre)
{
}

/**
 * @brief Destruktor
 *
 */
DVD::~DVD() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Ausgabemethode, welche die Ausgabefunktion der Vaterklasse um den Autor ergaenzt
 *
 * @param out notwendig zum ueberladen auﬂerhalb der Klasse, erster Parameter ist Objekt vom Typ DVD
 */
void DVD::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
    std::cout <<"FSK: " << "ab " << freigabe << " Jahre"<< std::endl;
    std::cout <<"Genre: " << genre << std::endl;
}

/**
 * @brief Ueberladene Ausleihmethode, wurde um Jugendschutz ergaenzt
 *
 * @param Person person
 * @param Datum ausleihdatum
 */
bool DVD::ausleihen(Person person,Datum ausleihdatum)
{

if(!status && (ausleihdatum-person.getGeburtsdatum())/12 >= freigabe)
{
	Medium::ausleihen(person, ausleihdatum);
	return true;
}
else{
	std::cout<<"Die Jugendschutzfreigabe ist noch nicht erfuellt, der Kunde darf das Medium nicht ausleihen!";
	return false;

}

}
