/*!
 * Praktikum Informatik 1 MMXXII
 *
 * @file Buch.cpp
 *//*
 * Buch.cpp
 *
 *  Created on: 21.05.2022
 *      Author: finle
 */

#include "Buch.h"

/**
 * @brief Konstruktor, der einen neues Buch erstellt
 *
 * @param initTitel Konstruktor der Vaterklasse
 * @param initAutor autor
 */
Buch::Buch(std::string initTitel, std::string initAutor)
: Medium(initTitel), autor(initAutor)
{
}

/**
 * @brief Destruktor
 *
 */

Buch::~Buch() {
	// TODO Auto-generated destructor stub
}
/**
 * @brief Ausgabemethode, welche die Ausgabefunktion der Vaterklasse um den Autor ergaenzt
 *
 * @param out notwendig zum ueberladen auﬂerhalb der Klasse, erster Parameter ist Objekt vom Typ Buch
 */
void Buch::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
    std::cout <<"Autor: " << autor << std::endl;
}
