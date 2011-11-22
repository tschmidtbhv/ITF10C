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
    
    /*
     Klasse für die Darstellung von IP-Listen und Subnetzen etc.
     Quasi vector<ipadressen> rein und dann schön in einer Tabelle ausgeben
     
     |       Ip        | Hostnamen |
     |-----------------|-----------|
     | 192.168.000.001 | Celsius   |
    */
    
    /*
     Optional anbindung an SQLite um Subnetz-Daten zu speichern und später wieder zu laden. 
    */
    
	return EXIT_SUCCESS;
}
