/*!
 * Praktikum Informatik 1 MMXXII
 *
 * @file Magazin.h
 *//*
 * Magazin.h
 *
 *  Created on: 21.05.2022
 *      Author: finle
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"



class Magazin: public Medium {
public:
	Magazin();
	virtual ~Magazin();
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual void ausgabe(std::ostream& out) const;
	bool ausleihen(Person person,Datum ausleihdatum);

private:
	Datum erscheinungsDatum;
	std::string sparte;


};

#endif /* MAGAZIN_H_ */
