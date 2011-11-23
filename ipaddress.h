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
	
        // Hostnamen zur IP speichern
        string hostname;
    
        // Notiz zur IP speichern
        string notice;
    
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
		string getString();	
	
        // Gibt die IP als Int aus, aus 192.168.0.1 wird 192168000001
		long getLong();		
    
        // Hostnamen abfragen
        string getHostname();
    
        // Notiz abfragen
        string getNotice();
    
        // Hostnamen ändern
        void setHostname(string paramValue);
    
        // Notiz ändern
        void setNotice(string paramValue);
};
#endif