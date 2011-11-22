// Standard-Includes sonst wird hier gar nichts
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;

// Klassen einbinden damit wir diese instanzieren können
#include "ipaddress.h"
#include "subnet.h"

int main(void) {
	
    ipaddress* schinken = new ipaddress(0, 1);
	cout << schinken->getString() << endl;
    cout << schinken->getLong() << endl;
    
	subnet* kaese = new subnet();
     
    delete kaese;
    delete schinken;
    
        
    // Benutzereingabe - Anzahl Netze
    
    // Array mit der Anzahl von Netzen erzeugen
    
    // Anzahl Clients je Subnetz 
    
    // Subnetze anzeigen
    // Subnetz hinzufügen
    // Hostnamen zu IP-Adresse ablegen
    // IP-Adresse anzeigen
    // IP-Adresse suchen
    // Beenden 
        
	return EXIT_SUCCESS;
}
