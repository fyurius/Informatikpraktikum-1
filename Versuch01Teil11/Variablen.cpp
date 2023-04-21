//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;
    
    // Hier folgt Ihr eigener Code

    //Frage 1
    std::cout<<"Bitte geben sie nun zwei ganze Zahlen ein."<<std::endl;
    std::cin>>iErste;
    std::cin>>iZweite;
    int iSumme = iErste+iZweite;
    int iQuotient = iErste/iZweite;
    std::cout<<"Die Summe der beiden von Ihnen eingegebene Zahlen mit Datentyp int lautet:"<<iSumme<<std::endl;
    std::cout<<"Der Quotient der beiden von Ihnen eingegebene Zahlen mit Datentyp int lautet:"<<iQuotient<<std::endl;

    //Frage 2
    double dSumme = iErste+iZweite;
    double dQuotient = iErste/iZweite;
    std::cout<<"Die Summe der beiden von Ihnen eingegebene Zahlen mit Datentyp double lautet:"<<dSumme<<std::endl;
    std::cout<<"Der Quotient der beiden von Ihnen eingegebene Zahlen mit Datentyp double lautet:"<<dQuotient<<std::endl;

    //Frage 3
    double dSummeCast = (double) iErste + (double) iZweite;
    double dQuotientCast = (double) iErste / (double) iZweite;
    std::cout<<"Die Summe der beiden von Ihnen eingegebene Zahlen mit Casting der Zahlen zum Datentyp double lautet:"<<dSummeCast<<std::endl;
    std::cout<<"Der Quotient der beiden von Ihnen eingegebene Zahlen mit Casting der Zahlen zum Datentyp double lautet:"<<dQuotientCast<<std::endl;

    // Warum unterscheiden sich die Ergebnisse?
    // Sie unterscheiden sich bei der Division, weil erst durch die Verwendung von double Nachkommastellen möglich sind. Wenn implizit gecasted wird, kann ebenfalls etwas schiefgehen

    //Frage 4
    std::cout<<"Bitte geben sie nun bitte ihren Vor- und Nachnamen ein."<<std::endl;
    std::string sVorname;
    std::cin>>sVorname;
    std::string sNachname;
    std::cin>>sNachname;
    //sVorname.push_back('');
    std::string sVornameName = sVorname+sNachname;
    sNachname.push_back(', ');
    std::string sNameVorname = sNachname+sVorname;
    std::cout<<"Ihr Name lautet"<<sNameVorname<<"oder"<<sVornameName<<std::endl;

    //Frage 5
    {
    	//Unterpunkt a
    	int iFeld [2] = {1, 2};
    	std::cout<<iFeld[0]<<iFeld[1]<<std::endl;

    	//Unterpunkt b
    	int spielfeld[2] [3] = {{1,2,3},{4,5,6}};
    	std::cout<<spielfeld [0][0]<<""<<spielfeld [0][1]<<""<<spielfeld [0][2]<<std::endl;
    	std::cout<<spielfeld [1][0]<<""<<spielfeld [1][1]<<""<<spielfeld [1][2]<<std::endl;

    	//Unterpunkt c
    	const int iZweite = 1;
    	std::cout<<iZweite<<std::endl;

    			}
    std::cout<<iZweite<<std::endl;

    //Frage 6
    char iName1 = sVorname[0];
    char iName2 = sVorname[1];
    std::cout<<iName1<<iName2<<std::endl;

    //Frage 7
    int position1 = iName1%64;
    int position2 = iName2%64;
    std::cout<<"Die Position des ersten Buchstaben im deutschen Alphabet ist"<<position1<<std::endl;
    std::cout<<"Die Position des zweiten Buchstaben im deutschen Alphabet ist"<<position2<<std::endl;

    //hier muss ich das noch abhängig von GroßundKleinschreibung machen !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    return 0;
    
}
