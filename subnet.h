#ifndef subnet_header
#define subnet_header
/*
 Diese Datei beschreibt alle Methoden und Attribute der Klasse 'subnet'
 wenn du fleißig an den Funktionen arbeiten möchtest, dann schau unter <subnet.cpp>
 */

// Header einbinden um ipaddress nutzen zu können
#include "ipaddress.h"

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
	
        // Anzahl vergebener IP's
        int usedAddressesCount;   
    
        // Array für extra vergebene IP's
        ipaddress* usedAddresses;
    
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
		void addIP(int ip);  
    
        // IP entfernen
		void dropIP(int ip); 
    
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