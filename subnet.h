#ifndef subnet_header
#define subnet_header
/*
 Diese Datei beschreibt alle Methoden und Attribute der Klasse 'subnet'
 wenn du fleißig an den Funktionen arbeiten möchtest, dann schau unter <subnet.cpp>
 */

// Header einbinden um ipaddress nutzen zu können
#include "ipaddress.h"
#include <vector>
using namespace std;

class subnet {
	private:
        // Broadcast-Adresse
		int broadcast;		
    
        // Netz-Adresse
		int netAddress;	
	
        // Adressbereich Anfang
		int rangeStart;		
    
        // Adressbereich Ende
		int rangeEnd;	
     
        // Array für extra vergebene IP's
        vector<ipaddress> usedAddresses;
    
	public:
        // Default-Konstruktor (muss vorhanden sein)
		subnet();			
    
        // Konstruktor
		subnet(int paramnetaddress,
				int paramrangeStart,
				int paramrangeEnd,
				int parambroadcast
		);					 

        // Suchfunktion
		bool search();	
    
        // IP hinzufügen
		void addIP(ipaddress paramIp);  
    
        // IP's auflisten
        vector<ipaddress> showIPs();
    
        // IP entfernen
		void dropIP(long paramIp); 
    
        // Netzwerk-Adresse Start abfragen
		int getRangeStart(); 
    
        // Netzwerk-Adresse Ende abfragen
		int getRangeEnd();	 
    
        // Broadcast-Adresse abfragen 
		int getBroadCast();	 
    
        // Netzwerk-Adresse abfragen
		int getNetAdress();	 
    
        // vergebene Adresse im Netz abfragen
		ipaddress* getAdresses();  
};
#endif