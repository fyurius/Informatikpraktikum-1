//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////
/**
 * Praktikum Informatik 1 MMXXII
 *
 * @file Vektor.cpp
 *
 */

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Funktion zur Ermittlung der Laenge eines Vektors
 *
 */
double Vektor::laenge() const
{
	double ergebnis = sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
	return ergebnis;
}


/**
 * @brief Funktion bildet Skalar-Produkt zweier Vektoren
 *
 * Diese Funktion bildet das Skalarprodukt des Vektors mit der sie aufgerufen wurde, und dem Vektor der
 * uebergeben wird.
 *
 * @param const Vektor& input, der Vektor mit dem das Skalarprodukt gebildet werden soll.
 * @return ergebnis, Zahlenwert des Skalarproduktes in double
 */
double Vektor::skalarProd(const Vektor& input) const
{
	double ergebnis = (this->x * input.x + this->y * input.y + this->z * input.z);
	return ergebnis;
}


/**
 * @brief Funktion zieht ein Vektor von einem anderen ab
 *
 * Diese Funktion subtrahiert den Vektor der uebergeben wird von dem Vektor mit dem sie aufgerufen wurde.
 *
 * @param const Vektor& input, der Vektor der abgezogen werden soll.
 * @return Vektor, ist Bezugsvektor subtrahiert mit uebergebenem Vektor
 */
Vektor Vektor::sub(const Vektor& input) const
{
	return Vektor(this->x - input.x, this->y - input.y, this->z -input.z);
}

/**
 * @brief Funktion ermittelt Winkel zwischen zwei Vektor
 *
 * Diese Funktion ermittelt den Winkel zwischen dem Vektor mit der sie aufgerufen wurde,
 * und dem Vektor der uebergeben wird.
 *
 * @param const Vektor& input, der Vektor dessen Winkel zum Bezugsvektor ermittelt werden soll.
 * @return ergebnis, Winkel zwischen den beiden Vektoren in Grad
 */
double Vektor::winkel(const Vektor& input) const
{
	//Deklarierung und Initialisierung von benötigten Variablen
	double skalar = this->skalarProd(input);
	double laenge1 = this->laenge();
	double laenge2 = input.laenge();

	//Logik für Winkelermittlung mit anschließender Umformung in Grad
	double ergebnis =acos(skalar/(laenge1*laenge2));
	ergebnis= ergebnis*(180/3.14159);
	return ergebnis;

}

/**
 * @brief Funktion rotiert Vektor um z-Achse
 *
 * Diese Funktion laesst den Vektor mit der sie aufgerufen wird um den uebergebenen Wert in rad um
 * die z-Achse drehen.
 *
 * @param const double rad, Wert um den gedreht werden soll
 */
void Vektor::rotiereUmZ(const double rad)
{
	//Logik fürs drehen, vgl. Drehmatrix
	this->x = cos(rad) * this->x - sin(rad) * this->y;
	this->y = sin(rad) * this->x + cos(rad) * this->y;
}
