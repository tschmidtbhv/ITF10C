#ifndef ipaddress_header
#define ipaddress_header
/*
Diese Datei beschreibt alle Methoden und Attribute der Klasse 'ipaddress'
wenn du fleißig an den Funktionen arbeiten möchtest, dann schau unter
<ipaddress.cpp>
*/

/* Einbinden der Header für den String-Datentyp */
#include <string>
/* Using std::string wichtig bei Os X */
using std::string;

class ipaddress {
	private:
        // Erster Block (192.)
		int block1;	
	
        // Zweiter Block (168.)
		int block2;		
    
        // Dritter Block (0.)
		int block3;		
    
        // Vierter Block (1)
		int block4;		
	public:

        // Default-Konstruktor
        ipaddress();
    
        // Konstruktor für 192.168.XXX.XXX 
		ipaddress(
            int paramblock3,
            int paramblock4
        );	
    
    	// Konstruktor für XXX.XXX.XXX.XXX
		ipaddress(
			int paramblock1,
			int paramblock2,
			int paramblock3,
			int paramblock4
		);
    
        // Gibt die IP als formatieren String in folgendem Format aus XXX.XXX.XXX.XXX
		string getIPAsString();	
	
        // Gibt die IP als Int aus, aus 192.168.0.1 wird 192168000001
		long getIPAsLong();		
};
#endif