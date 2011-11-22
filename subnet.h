#ifndef subnet_header
#define subnet_header

#include "ipaddress.h"

/*
Diese Datei beschreibt alle Methoden und Attribute der Klasse 'subnet'
wenn du fleißig an den Funktionen arbeiten möchtest, dann schau unter <subnet.cpp>
*/
class subnet {
	private:
		int broadcast;		// Broadcast-Adresse
		int netaddress;		// Netz-Adresse
		int range_start;	// Adressbereich Anfang	
		int range_end;		// Adressbereich Ende
        ipaddress* addresses;		// Array mit vergebenen Adressen als Objekten
	public:
		subnet();			// Default-Konstruktor (muss vorhanden sein AFAIK)
    
		subnet(int param_netaddress,
				int param_range_start,
				int param_range_end,
				int param_broadcast
		);					 // Konstruktor

		bool search();		 // Suchfunktion
		void addIP(int ip);  // IP hinzufügen
		void dropIP(int ip); // IP entfernen
		int getRangeStart(); // Netzwerk-Adresse Start abfragen
		int getRangeEnd();	 // Netzwerk-Adresse Ende abfragen
		int getBroadCast();	 // Broadcast-Adresse abfragen 
		int getNetAdress();	 // Netzwerk-Adresse abfragen
		int getAdresses();  // vergebene Adresse im Netz abfragen
};
#endif