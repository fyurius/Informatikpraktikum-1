/*!
 * Praktikum Informatik 1 MMXXII
 *
 * @file Buch.h
 *//*
 * Buch.h
 *
 *  Created on: 21.05.2022
 *      Author: finle
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"

class Buch: public Medium {
public:
	Buch();
	Buch(std::string initTitel = " ", std::string initAutor = " ");
	virtual ~Buch();
	virtual void ausgabe(std::ostream& out) const;


private:
	std::string autor;
};

#endif /* BUCH_H_ */
