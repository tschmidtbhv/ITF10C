// Header für die Klassen einbinden, damit Sie sich selbst kennt.
#include "ipaddress.h"

// Header für String
#include <string>

// Header um Konvertierung von Int zu String zu ermöglichen
#include <sstream>

// Nötig für Os X und spart schreiben
using std::string;
using std::stringstream;

// Konstruktor für 192.168.XXX.XXX
ipaddress::ipaddress(
    int paramblock3,
    int paramblock4
)
{
	/* Initialisieren */
    this->block1 = 192;
    this->block2 = 168;
    this->block3 = paramblock3;
    this->block4 = paramblock4;
}


// Konstruktor für XXX.XXX.XXX.XXX
ipaddress::ipaddress(
    int paramblock1,
    int paramblock2,
    int paramblock3,
    int paramblock4
)
{
	/* Initialisieren */
    this->block1 = 192;
    this->block2 = 168;
    this->block3 = paramblock3;
    this->block4 = paramblock4;
}

string ipaddress::getIPAsString() {

    // Stringstream für die Konvertierung anlegen
    stringstream output;
    
    // Werte in den Stringstream schreiben
    output << this->block1 << ".";
    output << this->block2 << ".";
    output << this->block3 << ".";
    output << this->block4;
    
    // Stringstream als String gewandelt zurückgeben
    return output.str();
}

int ipaddress::getIPAsInt() {
    
    /*
     Beispiel:
     192168000001
     192.........
        168......
           000...
              001
    */
    
    // Variable anlegen
    int output = 0;
    
    output = output + this->block1 * 10^9;
    output = output + this->block2 * 10^6;
    output = output + this->block3 * 10^3;
    output = output + this->block4;
    
    // Variable zurückgeben
    return output;
}
