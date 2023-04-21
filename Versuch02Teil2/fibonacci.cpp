//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

//Deklarierung der später benutzten Funktion
int fibonacci(int n);


int main ()
{
	std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
	//Berechnet die Fibonacci-Zahlen und gibt sie nacheinander aus
	for (int i = 0; i <= 12 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}

int fibonacci(int n)
{
	//Logik für einen iterativen Berechnungsansatz
	//Additionen werden jeweils bis zur gefragten Anzahl durchgeführt und zurückgegeben
    int previousFib = 0;
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int newFib = previousFib+currentFib;
        previousFib=currentFib;
        currentFib=newFib;
    }
    return previousFib ;
}


//Frage 2.2.2.3
/*Wie bereits erwartet dauert die von mir geschriebene Rekursivmethode länger, als die iterative Berechnung.
 * Wie bereits im Theorieteil gesagt wurde, muss bei einem rekursiven Aufruf jeweils die Ansammlung
 * an Unterpunkten im Call-Stack abgearbeitet werden. Dies nimmt mehr Zeit in Anspruch, als
 * recht einfache Additionsrechnungen.
 */
