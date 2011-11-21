/*
Diese Datei beschreibt alle Methoden und Attribute der Klasse 'ipaddress'
wenn du flei√üig an den Funktionen arbeiten mˆchtest, dann schau unter
<ipaddress.cpp>
*/

/* Einbinden der Header f√ºr den String-Datentyp */
#include <string>
/* Using std::string wichtig bei Os X */
using std::string;

class ipaddress {
	private:
		int block1;		// Erster Block (192.)
		int block2;		// Zweiter Block (168.)
		int block3;		// Dritter Block (0.)
		int block4;		// Vierter Block (1)
	public:
		ipaddress();	// Default-Konstruktor (muss vorhanden sein AFAIK)
		ipaddress(
			int block1,
			int block2,
			int block3,
			int block4
		);	// Konstruktor
		string     getIPAsString();		// Gibt die IP als formatieren String in folgendem Format aus XXX.XXX.XXX.XXX
		int	   getIPAsInt();		// Gibt die IP als Int aus, aus 192.168.0.1 wird 192168000001
};
