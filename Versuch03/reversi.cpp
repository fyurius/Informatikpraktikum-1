/**
 * Praktikum Informatik 1 MMXXII
 *
 * @file reversi.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    // Hier erfolgt jetzt Ihre Implementierung ...

	//Abfrage ob uebergebene Indexe auf Spielfeld liegen
	if ((posX < GROESSE_X && posX>0) && (posY < GROESSE_Y && posY > 0))
	{
		return true;
	}


    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, int posX, int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
    								   //               if aktuellerSpieler == 2 -> gegner = 1


    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...

        	//Eigener Stein gefunden, muss nicht weiter gemacht werden
        	if(spielfeld[posY + j][posX + i] != gegner)
        	{
        		continue;
        	}

        		int nposY = posY;
        		int nposX = posX;

        		//Ist am Ende der Reihe von generischen Steinen ein eigener Stein?
        		while ((nposX += i) >= 0 && nposX < GROESSE_X && (nposY += j) >= 0 && nposY < GROESSE_Y)
        		{
        			if (spielfeld[nposY][nposX] == aktuellerSpieler)
        			{
        				return true;
        			} else if(spielfeld[nposY][nposX] == 0)
        			{
        				break;
        			}
        		}



        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...

        	/* aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
				allen Richtungen in Ihre eigenen Steine umgewandelt werden*/
        	if(spielfeld[posY + j][posX + i] != gegner)
        	  {
        		continue;
        	  }

        	int uposY = posY + j;
        	int uposX = posX + i;

        	while ((uposX) >= 0 && uposX < GROESSE_X && (uposY) >= 0 && uposY < GROESSE_Y)
        	{
        		if (spielfeld[uposY][uposX] == gegner)
        		{
        			uposY += j;
        			uposX += i;
        			continue;

        		} else if(spielfeld[uposY][uposX] == aktuellerSpieler)
        		{
        			//Ersetzen der Steine
        			while(uposY != posY || uposX != posX)
        			{
        				uposY -= j;
        				uposX -= i;
        				spielfeld[uposY][uposX] = aktuellerSpieler;
        			}
        			break;
        		}
        			else
        			{
        				break;
        			}
        	}



        }
    }

}

/**
 * @brief Funktion, die Anzahl der moeglichen Zuege berechnet
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return moegelicheZuege, Anzahl der noch moeglichen Zuege des respektiven Spielers in int
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
    
	int moeglicheZuege = 0;
		for (int i=0;i<GROESSE_X;i++)
		{
			for (int j=0;j<GROESSE_Y;j++)
			{
				//Geht alle Spielfelder durch, und ermittelt ob ein Zug auf das Feld moeglich waere
				if (zugGueltig(spielfeld, aktuellerSpieler, i, j)) {
					moeglicheZuege++;
				}
			}
		}
		return moeglicheZuege;
}

/**
 * @brief Funktion, die einen menschlichen Zug moeglich macht
 *
 *In dieser Funktion befindet sich die Logik für einen menschlichen Spielzug.
 *Neben der Logik ist außerdem Input und Output für das Zuggeschehen enthalten.
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}

/**
 * @brief Funktion, die das Spielen moeglich macht
 *
 * @param const int spielerTyp[2], Spielertyp, damit sowohl ein menschlicher, als auch ein KI-Zug moeglich ist
 */
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);


    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    
    do
    {
    	std::cout<<std::endl;
		switch(spielerTyp[aktuellerSpieler-1])
		{
		case 1: std::cout<<"Spieler "<<aktuellerSpieler<<" (Mensch) ist an der Reihe"<<std::endl;
		if(!menschlicherZug(spielfeld,aktuellerSpieler)){
			std::cout<<"kein Zug moeglich fuer Spieler "<<aktuellerSpieler<<"."<<std::endl;
		}
		break;
		case 2: std::cout<<"Spieler "<<aktuellerSpieler<<" (Computer) ist an der Reihe"<<std::endl;
		if(!computerZug(spielfeld,aktuellerSpieler)){
			std::cout<<"kein Zug moeglich fuer Spieler "<<aktuellerSpieler<<"."<<std::endl;
		}
		};

		//Spielerwechsel am Ende eines Zuges
		aktuellerSpieler = 3-aktuellerSpieler;
		zeigeSpielfeld(spielfeld);
    }while (!(moeglicheZuege(spielfeld,1) == 0 && moeglicheZuege(spielfeld,2) == 0));

    switch (gewinner(spielfeld))
    {
        // Hier erfolgt jetzt Ihre Implementierung ...

    case 0:	std::cout<<"Kein Spieler hat gewonnen"<<std::endl;
    break;
    case 1: std::cout<<"Spieler 1 ist Sieger."<<std::endl;
    break;
    case 2:	std::cout<<"Spieler 2 ist Sieger."<<std::endl;
    }
}

/**
 * @brief main-Funktion, welche das Spiel Reverso moeglich macht
 *
 * In dieser main-Methode kann man konfigurieren, welche Spielertypen das Spiel spielen, indem man die
 * Eintraege im Array anpasst. Die Tests werden ebenfalls hier gestartet. Außerdem erfolgt hier nur noch der
 * Aufruf das Spiel zu starten.
 */
int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    int spielfeld[GROESSE_Y][GROESSE_X];

    initialisiereSpielfeld(spielfeld);

    int spielerTyp[2] = { COMPUTER, COMPUTER};  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    spielen(spielerTyp);

    return 0;
}
