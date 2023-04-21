//
// Praktikum Informatik 1 MMXXII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.h
// Inhalt: Headerdatei der Klasse Vektor
//

/**
 * Praktikum Informatik 1 MMXXII
 *
 * @file Vektor.h
 *
 */

#ifndef Vektor_H
#define Vektor_H
#define hoehePerson 0.00017
#define hoeheTurm 0.5557
#define radiusErde 6371.0


#include <iostream>
#include <cmath>
#include <iomanip>

class Vektor
{
   public:
    Vektor(double x, double y, double z);
    ~Vektor();

    void ausgabe() const;
    Vektor sub(const Vektor& input) const;
    double laenge() const;
    double skalarProd(const Vektor& input) const;
    double winkel(const Vektor& input) const;
    void rotiereUmZ(const double rad);
    
   private:
    double x;
    double y;
    double z;

};

#endif
