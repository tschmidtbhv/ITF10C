// Header für die Klassen einbinden, damit Sie sich selbst kennt.
#include "ipaddress.h"

// Header für String
#include <string>

// Header um Konvertierung von Int zu String zu ermöglichen
#include <sstream>

// Nötig für Os X und spart schreiben
using std::string;
using std::stringstream;

ipaddress::ipaddress(
	/* Parameter */
)
{
	/* Initialisieren */
    this->block1 = 192;
    this->block2 = 168;
    this->block3 = 0;
    this->block4 = 1;
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
