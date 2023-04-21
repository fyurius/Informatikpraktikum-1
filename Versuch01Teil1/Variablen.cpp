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

	//deklarieren und initialisieren der beiden Eingabevariablen
    int iErste = 0;
    int iZweite = 0;
    
    // Hier folgt Ihr eigener Code

    /*Frage 1
    Es werden zwei Variablen eingelesen, Summe und Quotient ermittelt und wieder ausgegeben.
    Die Summe bzw. der Quotient sind hier vom Typ int, also ganzzahlig.*/

    std::cout<<"Bitte geben sie nun zwei ganze Zahlen ein."<<std::endl;
    std::cin>>iErste;
    std::cin>>iZweite;
    int iSumme = iErste+iZweite;
    int iQuotient = iErste/iZweite;
    std::cout<<"Die Summe der beiden von Ihnen eingegebene Zahlen mit Datentyp int lautet:"<<iSumme<<std::endl;
    std::cout<<"Der Quotient der beiden von Ihnen eingegebene Zahlen mit Datentyp int lautet:"<<iQuotient<<std::endl;

    /*Frage 2
    Die Variablen wurden bereits eingelesen, nun wird ebenfalls Summe und Quotient ermittelt.
    Summe und Quotient sind nun allerdings vom Typ double, was theoretisch Kommazahlen moeglich macht.
    Typcasting wird hier nur Implizit durchgeführt.*/

    double dSumme = iErste+iZweite;
    double dQuotient = iErste/iZweite;
    std::cout<<"Die Summe der beiden von Ihnen eingegebene Zahlen mit Datentyp double lautet:"<<dSumme<<std::endl;
    std::cout<<"Der Quotient der beiden von Ihnen eingegebene Zahlen mit Datentyp double lautet:"<<dQuotient<<std::endl;

    /*Frage 3
    Auch hier wird die Summe und der Quotient der beiden Eingangsvariablen gebildet.
    Das Typecasting ist hier allerdings explizit.*/

    double dSummeCast = (double) iErste + (double) iZweite;
    double dQuotientCast = (double) iErste / (double) iZweite;
    std::cout<<"Die Summe der beiden von Ihnen eingegebene Zahlen mit Casting der Zahlen zum Datentyp double lautet:"<<dSummeCast<<std::endl;
    std::cout<<"Der Quotient der beiden von Ihnen eingegebene Zahlen mit Casting der Zahlen zum Datentyp double lautet:"<<dQuotientCast<<std::endl;

    /*Warum unterscheiden sich die Ergebnisse?
    Sie unterscheiden sich bei der Division,
    weil erst durch die Verwendung von double Nachkommastellen möglich sind.
    Wenn nur implizit gecasted wird, ist die Ausgabe auch falsch, weil der Compiler selbst ein Typecasting
    vornimmt, was nicht immer wie gewünscht ausfällt*/

    /*Frage 4
     Hier wird der Benutzer aufgefordert seinen Namen einzugeben, welcher eingelesen und in
     zwei verschiedenen Formaten ausgegeben wird.*/

    std::cout<<"Bitte geben sie nun bitte ihren Vor- und Nachnamen ein."<<std::endl;
    std::string sVorname;
    std::cin>>sVorname;
    std::string sNachname;
    std::cin>>sNachname;
    //sVorname.push_back('');
    std::string sVornameName = sVorname+" "+sNachname;
    sNachname.push_back(44);
    std::string sNameVorname = sNachname+" "+sVorname;
    std::cout<<"Ihr Name lautet "<<sNameVorname<<" oder "<<sVornameName<<std::endl;

    //Frage 5
    {
    	//Unterpunkt a
    	//Hier wird ein Feld mit zwei Einträgen erstellt und ausgegeben
    	int iFeld [2] = {1, 2};
    	std::cout<<iFeld[0]<<iFeld[1]<<std::endl;

    	//Unterpunkt b
    	//Hier wird ein Feld mit 6 Feldern erstellt und in einem bestimmten Format ausgegeben
    	int spielfeld[2] [3] = {{1,2,3},{4,5,6}};
    	std::cout<<spielfeld [0][0]<<" "<<spielfeld [0][1]<<" "<<spielfeld [0][2]<<std::endl;
    	std::cout<<spielfeld [1][0]<<" "<<spielfeld [1][1]<<" "<<spielfeld [1][2]<<std::endl;

    	//Unterpunkt c
    	//Hier wird eine Konstante definiert und ausgegeben
    	const int iZweite = 1;
    	std::cout<<iZweite<<std::endl;

    }
    //Diese Konstante hat zwar den selben Namen wie die in Zeile 88, ist allerdings nicht im selben Block
    std::cout<<iZweite<<std::endl;

    //Frage 6
    /*Hier wird der Erste und der zweite Buchstabe des eingegebenen Vornamens anhand der ASCII Tabelle
      in eine Zahl übersetzt und ausgegeben*/
    int iName1 = (char) sVorname[0];
    int iName2 = (char) sVorname[1];
    std::cout<<iName1<<"    "<<iName2<<std::endl;

    //Frage 7
    /*Hier wird die Position des ersten und zweiten Buchstaben des eingegebenen Namens im deutschen
      Alphabet ermittelt und ausgegeben*/
    int position1 = iName1%32;
    int position2 = iName2%32;
    std::cout<<"Die Position des ersten Buchstaben im deutschen Alphabet ist "<<position1<<std::endl;
    std::cout<<"Die Position des zweiten Buchstaben im deutschen Alphabet ist "<<position2<<std::endl;
    
    return 0;
    
}
