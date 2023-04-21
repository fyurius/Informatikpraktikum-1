/*!
 * Praktikum Informatik 1 MMXXII
 *
 * @file DVD.h
 *//*
 * DVD.h
 *
 *  Created on: 21.05.2022
 *      Author: finle
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

class DVD: public Medium {
public:
	DVD();
	virtual ~DVD();
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual void ausgabe(std::ostream& out) const;
	virtual bool ausleihen(Person person,Datum ausleihdatum);

private:
	int freigabe;
	std::string genre;
};

#endif /* DVD_H_ */
