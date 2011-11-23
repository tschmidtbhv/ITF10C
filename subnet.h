#ifndef subnet_header
#define subnet_header
/*
 Diese Datei beschreibt alle Methoden und Attribute der Klasse 'subnet'
 wenn du fleißig an den Funktionen arbeiten möchtest,
 dann schau unter <subnet.cpp>
 */

// Header einbinden um ipaddress nutzen zu können
#include "ipaddress.h"
#include <vector>
using namespace std;

class subnet {
	private:
        /* 
         Größe der Benutzereingabe
         ???? int realSize;
         bsp: 28;
         Größe in der Kalkulation
         ??? int virtualSize;
         bsp: 28 -> 32; 
         
         Brauchen wir das, macht das Sinn? 
         Dann klickt bitte auf Daumen hoch neben ndiesem Kommentar. xD 
        */
        
        // Broadcast-Adresse
		long broadcast;		
    
        // Netz-Adresse
		long netAddress;	
	
        // Adressbereich Anfang
		long rangeStart;		
    
        // Adressbereich Ende
		long rangeEnd;	
     
        // Name für das Subnetz
        string name;
    
        // Notiz zum Subnetz
        string notice;
    
        // Array für extra vergebene IP's
        vector<ipaddress> usedAddresses;
        vector<ipaddress>::iterator i;
    
	public:
        // Default-Konstruktor (muss vorhanden sein)
		subnet();			
    
        // Konstruktor
		subnet(long paramnetaddress,
				long paramrangeStart,
				long paramrangeEnd,
				long parambroadcast,
                string paramName,
                string paramNotice
		);	
    
        
        // Destruktor
        ~subnet();

        // Suchfunktion ob im Subnetz
		bool searchValid(ipaddress paramIp);	
    
        // Suchfunktion ob im Subnetz vergeben
        bool searchExists(ipaddress paramIp);
    
        // IP hinzufügen
		void addIP(ipaddress paramIp);  
    
        // IP's auflisten
        vector<ipaddress> getAddresses();
    
        // IP entfernen
		void dropIP(ipaddress paramIp); 
    
        // Netzwerk-Adresse Start abfragen
		long getRangeStart(); 
    
        // Netzwerk-Adresse Ende abfragen
		long getRangeEnd();	 
    
        // Broadcast-Adresse abfragen 
		long getBroadCast();	 
    
        // Netzwerk-Adresse abfragen
		long getNetAdress();
};
#endif