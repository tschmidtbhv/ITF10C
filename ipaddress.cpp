#ifndef subnet_functions
#define subnet_functions
// Header für die Klassen einbinden, damit Sie sich selbst kennt.
#include "ipaddress.h"

// Header für String
#include <string>

// Header um Konvertierung von Int zu String zu ermöglichen
#include <sstream>

// Header für Pow-Funktion, also Rechnen mit Potenzen
#include <math.h>

// Nötig für Os X und spart schreiben
using std::string;
using std::stringstream;

// Default-Konstruktor
ipaddress::ipaddress() {};

// Konstruktor für 192.168.XXX.XXX
ipaddress::ipaddress(
    int paramblock3,
    int paramblock4
)
{
    this->block1 = 192;
    this->block2 = 168;
    this->block3 = paramblock3;
    this->block4 = paramblock4;
};


// Konstruktor für XXX.XXX.XXX.XXX
ipaddress::ipaddress(
    int paramblock1,
    int paramblock2,
    int paramblock3,
    int paramblock4
)
{
    this->block1 = 192;
    this->block2 = 168;
    this->block3 = paramblock3;
    this->block4 = paramblock4;
};

// Ip-Adresse als String abfragen
string ipaddress::getString() {

    // Stringstream für die Konvertierung anlegen
    stringstream output;
    
    // Werte in den Stringstream schreiben
    output << this->block1 << ".";
    output << this->block2 << ".";
    output << this->block3 << ".";
    output << this->block4;
    
    // Stringstream als String gewandelt zurückgeben
    return output.str();
};

// Ip-Adresse als Integer abfragen
long int ipaddress::getLong() {
    
    /*
     Beispiel:
     192168000001
     192......... (also 10^9)
        168...... (also 10^6)
           000... (also 10^3)
              001 (also nichts weiter) 
    */
    
    // Variable anlegen
    long output = 0;
    
    output += this->block1 * pow(10,9);
    output += this->block2 * pow(10,6);
    output += this->block3 * pow(10,3);
    output += this->block4;
    
    // Variable zurückgeben
    return output;
};
#endif