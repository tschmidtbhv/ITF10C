#ifndef subnet_functions
#define subnet_functions

// Header um Konvertierung von Int zu String zu ermöglichen
#include <sstream>

// Header für Pow-Funktion, also Rechnen mit Potenzen
#include <math.h>

// Header für die Klassen einbinden, damit Sie sich selbst kennt.
#include "headers/ipaddress.h"

// Nötig für Os X und spart schreiben
using namespace std;

// Default-Konstruktor
ipaddress::ipaddress() {};

// Konstruktor für 192.168.XXX.XXX
ipaddress::ipaddress(
    int paramblock3,
    int paramblock4,
    string paramName,
    string paramNotice
)
{
    this->block1 = 192;
    this->block2 = 168;
    this->block3 = paramblock3;
    this->block4 = paramblock4;
    this->hostname = paramName;
    this->notice = paramNotice;
};


// Konstruktor für XXX.XXX.XXX.XXX
ipaddress::ipaddress(
    int paramblock1,
    int paramblock2,
    int paramblock3,
    int paramblock4,
    string paramName,
    string paramNotice                   
)
{
    this->block1 = paramblock1;
    this->block2 = paramblock2;
    this->block3 = paramblock3;
    this->block4 = paramblock4;
    this->hostname = paramName;
    this->notice = paramNotice;
};


// Destrukor
ipaddress::~ipaddress() {};

/**
 * IP-Adresse als String abfragen
 * 
 * @return IP-Adresse as String
 */
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

/**
 * IP-Adresse in numerischen Wert umwandeln 
 *
 * @return Ip-Adresse as Long
 */
long ipaddress::getLong() {
    
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
    
    output += this->block1 * pow(10.0,9.0);
    output += this->block2 * pow(10.0,6.0);
    output += this->block3 * pow(10.0,3.0);
    output += this->block4;
    
    // Variable zurückgeben
    return output;
};

/**
 * Abfrage des Hostnamen einer IP-Adresse
 *
 * @return Hostname as String
 */
string ipaddress::getHostName() {
    return this->hostname;
}


/**
 * Abfrage der Notiz zu einer IP-Adresse 
 *
 * @return Notice as String
 */
string ipaddress::getNotice() {
    return this->notice;
}

/**
 * Setzt Hostnamen für eine IP-Adresse
 *
 * @param string paramValue als neuer Hostnamen
 */
void ipaddress::setHostname(string paramValue) {
 this->hostname = paramValue;
}

/**
 * Setzt Notiz für eine IP-Adresse 
 *
 * @param string paramValue als neue Notiz
 */
void ipaddress::setNotice(string paramValue) {
    this->notice = paramValue;
}
#endif