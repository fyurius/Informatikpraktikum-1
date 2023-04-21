//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/**
 * Praktikum Informatik 1 MMXXII
 *
 * @file main.cpp
 *
 */

#include "Vektor.h"

/**
 * @brief main-Methode, ermittelt Blickweite
 *
 * In dieser Methode wird die Blickweite einer Person, welche sich auf einer bestimmten Hoehe befindet
 * durch iterative Berechnung ermittelt. Die folgenden Parameter werden nicht uebergeben, sondern sind als Praeprozessorkonstante
 * definiert um Anpassungen zu erleichtern.
 *
 * @param radiusErde, Konstante welche den Erdradius repraesentiert
 * @param hoeheTurm, Konstante welche die Hoehe des Turms definiert
 * @param hoehePerson, Konstante welche fuer gesamtHoehe benoetigt wird
 */

int main()
{
	//Testausgaben wurden nur zum testen genutzt
    /*
    Vektor vector2(0, 1, 0);
	Vektor vector1(0, 1, 0);
    vector1.ausgabe();
    vector2.ausgabe();

    std::cout<<vector1.laenge()<<std::endl;

    std::cout<<vector1.skalarProd(vector2)<<std::endl;

    Vektor vector3(0,0,0);
    vector3 = vector1.sub(vector2);
    vector3.ausgabe();

    double winkel = vector1.winkel(vector2);
    std::cout<<winkel<<std::endl;

    vector1.ausgabe();
    vector1.rotiereUmZ(1);
    vector1.ausgabe();
    return 0;
	*/

	int count = 0;
	double hoeheAbNormalNull = hoehePerson+hoeheTurm;
	double gesamtHoehe = hoeheAbNormalNull + radiusErde;

	//Initialisierung und Deklarierung der benötigten Vektoren und Variablen
	Vektor menschVektor(0, gesamtHoehe, 0);
	Vektor radiusVektor(0, radiusErde, 0);
	Vektor blickVektor(0,0,0);

	blickVektor = radiusVektor.sub(menschVektor);
	int skalarProdukt = (double) blickVektor.skalarProd(radiusVektor);
	double sichtweite =0;

	//Berechnung des maximalen Blickvektors
	while(skalarProdukt)
	{
		count++;
		radiusVektor.rotiereUmZ(0.0000001);
		blickVektor = radiusVektor.sub(menschVektor);
		skalarProdukt = (double) blickVektor.skalarProd(radiusVektor);

	}

	//Beschränkungen der Ausgabe auf die vorgegebenen Spezifikationen
	std :: cout << std :: fixed ;
	std :: cout << std :: setprecision (4);

	//Ausgabe nach Aufgabenstellung
	sichtweite = blickVektor.laenge();
	std::cout<<"Sie können "<<sichtweite<<" Km weit sehen."<<std::endl;

	std::cout<<"Sie sind "<<hoeheAbNormalNull*1000<<" Meter hoch über Normalnull"<<std::endl;

	double winkelB = menschVektor.winkel(radiusVektor);
	std::cout<<"Der Winkel beträgt "<<winkelB<<"°"<<std::endl;

	std::cout<<"Anzahl Schritte:  "<<count<<std::endl;

}
