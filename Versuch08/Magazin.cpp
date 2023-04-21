/*!
 * Praktikum Informatik 1 MMXXII
 *
 * @file Magazin.cpp
 *//*
 * Magazin.cpp
 *
 *  Created on: 21.05.2022
 *      Author: finle
 */

#include "Magazin.h"
#include "Datum.h"

/**
 * @brief Konstruktor, der einen neues Magazin erstellt
 *
 * @param initTitel Konstruktor der Vaterklasse
 * @param Datum initDatumAusgabe
 * @param string initSparte
 */
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
: Medium(initTitel), erscheinungsDatum(initDatumAusgabe), sparte(initSparte)
{
}

/**
 * @brief Destruktor
 *
 */
Magazin::~Magazin() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Ausgabemethode, welche die Ausgabefunktion der Vaterklasse um die Ausgabe und die Sparte ergaenzt
 *
 * @param out notwendig zum ueberladen auﬂerhalb der Klasse, erster Parameter ist Objekt vom Typ Magazin
 */
void Magazin::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
    std::cout <<"Ausgabe: " << erscheinungsDatum << std::endl;
    std::cout <<"Sparte: " << sparte << std::endl;
}

/**
 * @brief Ueberladene Ausleihmethode, wurde um Reglung bezueglich Aktualitaet ergaenzt
 *
 * @param Person person
 * @param Datum ausleihdatum
 */
bool Magazin::ausleihen(Person person,Datum ausleihdatum)
{
	Datum referenzDatum = ausleihdatum;
if(!status && erscheinungsDatum-referenzDatum !=1)
{
	std::cout<<"Das ist die neuste Ausgabe des Magazins. Sie darf noch nicht verliehen werden";
	return false;
}
else{
	Medium::ausleihen(person, ausleihdatum);
	return true;
}

}
