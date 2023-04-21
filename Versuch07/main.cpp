
/**
 * Praktikum Informatik 1 MMXXII
 *
 * @file main.cpp
 *
 */

/** @mainpage
 *
 * Praktikum Informatik 1 MMXXII <BR>
 * Versuch 7: STL
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


#include "Student.h"

/**
 * @brief main-Methode
 *
 * Diese main-Methode startet das Programm und gibt die Uebersicht der zur Verfuegung stehenden Methoden aus.
 * Die Eingabe wird gelesen und die demenstprechende Funktion mit den uebergebenen Parametern, falls noetig,
 * ausgefuehrt. Danach wird die Uebersicht erneut ausgegeben, um die naechste Anweisung zu einzulesen.
 * Neu ist hier die Sortierfunktion unter 9 und die Methode zum loeschen unter 5 wurde angepasst.
 *
 */
int main()
{
    std::vector<Student> studentenListe;
    Student student;

    std::vector<Student>::const_iterator it;
    std::vector<Student>::const_reverse_iterator revIt;


    char abfrage;
    /*std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
        studentenListe.push_back(student);
    }*/

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank vorwaerts ausgeben" << std::endl
				  << "(4): Datenbank rueckwaerts ausgeben" << std::endl
				  << "(5): Datensatz loeschen" << std::endl
				  << "(6): Datenelement vorne hinzufügen" << std::endl
				  << "(7): Daten aus einer Datei einlesen" <<std::endl
				  << "(8): Daten in einer Datei sichern" <<std::endl
				  << "(9): Datenbank sortieren" <<std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        std::cout<<student<<std::endl;

                        it = studentenListe.begin();

                        studentenListe.erase(it);
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for (it = studentenListe.begin() ; it != studentenListe.end() ; it ++)
                    {
                    	std::cout<<*it<<std::endl;
                    }



                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            // Datenbank rueckwaerts ausgeben
            case '4':
            	if(!studentenListe.empty())
            	{
            		std::cout << "Inhalt der Liste in ruecklaufender Reihenfolge:" << std::endl;
            		for (revIt = studentenListe.rbegin() ; revIt != studentenListe.rend() ; revIt ++)
            		{
            			std::cout<<*revIt<<std::endl;
            		}
            	}
            	else
            	{
            		std::cout << "Die Liste ist leer!\n\n";
            	}
            	break;

            // Eintrag loeschen
            case '5':
            {

            	std::cout<<"Bitte geben sie die Matrikelnummer des zu loeschenden Studierenden ein: "<<std::endl;

            	unsigned int matNr = 0;
            	std::cin >> matNr;
            	std::cin.ignore(10, '\n');


            		if(studentenListe.empty())
            		{
            			std::cout << "Die Liste ist leer!\n\n";
            		}
            		else
            		{
            			std::vector<Student>::const_iterator loeschZeiger;

            			Student dummy = Student(matNr, "", "", "");

            			loeschZeiger = find(studentenListe.begin(),studentenListe.end(), dummy);
            			std::cout<<"Der folgende Student wird nun geloescht : \n"<<std::endl;
            			std::cout<<&loeschZeiger<<std::endl;
            			studentenListe.erase(loeschZeiger);
            		}

            }
        	break;

        	//Element am Anfang der Liste einfuegen
            case '6':
            {
            unsigned int matNr = 0;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";

            std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
            getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

            std::cout << "Geburtsdatum: ";
            getline(std::cin, geburtstag);

            std::cout << "Adresse: ";
            getline(std::cin, adresse);

            std::cout << "Matrikelnummer: ";
            std::cin >> matNr;
            std::cin.ignore(10, '\n');

            student = Student(matNr, name, geburtstag, adresse);

            it = studentenListe.begin();
            studentenListe.insert(it, student);
            }
            break;

            case '7':
            {
            	studentenListe.clear();

            	std::string dateiName = "";
            	std::string eName = "";
            	std::string eAdresse = "";
            	std::string eGeburtstag = "";
            	int eMatNr = 0;

            	std::cout << "Bitte geben sie den Dateinamen ein.\nName: ";
            	getline(std::cin, dateiName);
            	std::ifstream eingabe(dateiName);

            	if (!eingabe)
            	{
            		std::cout<<" Fehler beim Oeffnen der Datei !";
            		exit(1);
            	}


            	eingabe>>eMatNr;

            	while(!eingabe.eof())
            	{
            		eingabe.ignore(1, '\n');
            		std::getline(eingabe,eName);
            		eingabe>>eGeburtstag;
            		eingabe.ignore(1, '\n');
            		std::getline(eingabe,eAdresse);

            		student = Student(eMatNr, eName, eGeburtstag, eAdresse);
            		studentenListe.push_back(student);

            		eingabe>>eMatNr;
            	}

            	std::cout<<"Alle Datein wurden korrekt eingelesen"<<std::endl;

            }
            break;

            case'8':
            {
            	std::string dateiName = "";
            	std::cout << "Bitte geben sie einen Namen fuer die Sicherungsdatei ein:\nName: ";
            	getline(std::cin, dateiName);

            	std::ofstream ausgabe;
            	ausgabe.open(dateiName);

            	std::string aName = "";
            	std::string aAdresse = "";
            	std::string aGeburtstag = "";
            	int aMatNr = 0;

            	for (it = studentenListe.begin() ; it != studentenListe.end() ; it ++)
            	{
            		aName = it->getName();
            		aAdresse = it->getAdresse();
            		aGeburtstag = it->getGeburtstag();
            		aMatNr = it->getMatNr();

            		ausgabe << aName <<std::endl;
            		ausgabe << aAdresse <<std::endl;
            		ausgabe << aGeburtstag <<std::endl;
            		ausgabe << aMatNr <<std::endl;
            	}

            	std::cout<<"Datei wurde erfolgreich erstellt"<<std::endl;

            }
            break;

            case '9':
            {

            	std::sort(studentenListe.begin(), studentenListe.end());

            	std::cout<<"Datenbank wurde sortiert. Ausgabe ist nun: \n"<<std::endl;

            	for (it = studentenListe.begin() ; it != studentenListe.end() ; it ++)
            	{
            		std::cout<<*it<<std::endl;
            	}
            }
            break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }

    }while (abfrage != '0');

    return 0;
}
