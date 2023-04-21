//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
//////////////////////////////////////////////////////////////////////////////
/**
 * Praktikum Informatik 1 MMXXII
 *
 * @file Liste.cpp
 *
 */

#include "Liste.h"
#include <iostream>

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back);
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enthält nur ein Listenelement
    {
        delete front;                                        // Listenelement löschen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor; 				//loescht vorderstes Element, waere sonst ohne Zeiger nicht mehr auffindbar
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}

/**
 * @brief das Element mit uebergebener Matrikelnummer wird aus Liste geloescht.
 *
 * @param unsigned int pMatNr, Matrikelnummer des zu loeschenden Elements
 * @return void
 */
void Liste::loesche(unsigned int pMatNr)
{
    ListenElement* cursor = front;
	 while (cursor != nullptr)
	    {
		 if(cursor->getData().getMatNr()==pMatNr)
		 {
			 std::cout<<"Student gefunden"<<std::endl;
			 cursor->getData().ausgabe();

			 //Je nachdem wo sich das Element befindet muss verschieden vorgegangen werden.
			 if(cursor->getNext()!=nullptr)
			 {
				 cursor->getNext()->setPrev(cursor->getPrev());
			 }else
			 {
				 back=cursor->getPrev();
			 }
			 if(cursor->getPrev()!=nullptr)
			 {
				 cursor->getPrev()->setNext(cursor->getNext());
			 }else
			 {
				 front = cursor->getNext();
			 }

			 delete cursor;
			 return;
		 }else
		 {
			 cursor = cursor->getNext();
		 }
	    }
	 std::cout<<"Eintrag wurde nicht gefunden"<<std::endl;
}

/**
 * @brief Fuegt ein Element am Anfang der Liste ein.
 *
 * @param pData
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        front->setPrev(neuesElement);
        neuesElement->setNext(front);
        front = neuesElement;
    }
}
