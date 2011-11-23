// Standard-Includes sonst wird hier gar nichts
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Klassen einbinden damit wir diese instanzieren können
#include "headers/ipaddress.h"
#include "headers/subnet.h"

int ipBlock1, ipBlock2,ipBlock3, ipBlock4;

void selectedPoint(int choosenOne);
void splitAndConvert();


int main(void) {
    
    cout << "     Das super Subnet-Tool" << endl;
    cout << "      ein tolles Programm" << endl;
    cout << "         Version 1.0" << endl << endl;
    
    cout << " Wieviele Subnetze möchten Sie anlegen?";
    
    int networkCount = 0;
    scanf ("%d",&networkCount);
    
    /*
        Fehleingaben-Handling?
    */
    vector<subnet> usedSubnets;
    for(int i = 0; i < networkCount; i++) {
        cout << "Subnetz " << (i+1) << ":" << endl;
        cout << "Name? ";
        string name = "";
        cin >> name;
        cout << "Beschreibung? ";
        string notice = "";
        cin >> notice;
        cout << "Größe? ";
        int networkSize = 0;
        scanf("%d",&networkSize);
        
        /*
         Viele tolle Berechnungen von Broadcast,
         Netzadresse, Start und Ende des Range.
         
         Dann objekt hinzufügen:
         usedSubnets.push_back(subnet(0,0,0,0,name,notice));
         */
    }
	
    /*
    ipaddress* schinken = new ipaddress(0, 1);
	cout << schinken->getString() << endl;
    cout << schinken->getLong() << endl;
    
	subnet* kaese = new subnet();
     
    delete kaese;
    delete schinken;
     */
    
    
    
    /* Benutzereingabe - Anzahl Netze
     PSEUDOCODE!
     vector<subnet> subnetze;
     for(int i = 0; i < anzahlNetze; i++) {
        cout << "Größe?" << endl;
        cout << "Name?" << endl;
        cout << "Notiz?" << endl;
        subnetzte.put_back(subnet(größe,name,notiz));
     }
    */
     
    // Array mit der Anzahl von Netzen erzeugen
    
    // Anzahl Clients je Subnetz 
    
    // Subnetze anzeigen
    // Subnetz hinzufügen
    // Hostnamen zu IP-Adresse ablegen (Auch eine Notiz dazu)
    // IP-Adresse anzeigen
    // IP-Adresse suchen
    // Beenden 
    
    /*
     @Nico-X, wäre das was für dich?
      
     !!!Klasse!!! für die Darstellung von IP-Listen und Subnetzen etc.
     
     Output->printSubnets(vector<subnet> paramSubnet) 
     und dann
     
     |   Bereich | Name |       Notiz    |
     -------------------------------------
     | 0-47      | ET   | Elektrotechnik |
     
     Output->printIPsInSubnet(subnet paramSubnet) ...
     Quasi subnet rein und dann schön in einer Tabelle ausgeben
     
     |       Ip        | Hostnamen   |    Notiz    |
     |-----------------|-------------|-------------|
     | 192.168.000.000 | Netzadresse | -  
     | 192.168.000.001 | Celsius     | Deine Mudda |
     | 192.168.000.002 | #########   | ########### | 
     ....
     | 192.168.000.47  | Broadcast   | ping -b :D  |
    */
    
    /*
     Optional anbindung an SQLite um Subnetz-Daten zu speichern und später wieder zu laden.
    */
    
    // 
    
    /*
    int choosenOne;
    
    do {
        printf("\n1 : Subnetz erstellen\n");
        printf("2 : IP einfügen\n");
        printf("3 : IP löschen\n");
        printf("9 : Ende\n");
        printf("Ihre Wahl : ");
        cin << choosenOne;
        if (choosenOne != 9) {
            selectedPoint(int choosenOne);
        } else {
            return;
        }
        
    } while (choosenOne != 9); */
    
	return EXIT_SUCCESS;
} 


/*
 * inputIP
 *  
 * @params int choosenOne  
 *
 */

void selectedPoint(int choosenOne) {
    
    
    switch (choosenOne) {
        case 1:
            //createSubnet();
            break;
            
        case 2:
            splitAndConvert();
            break;
            
        case 3:
            
            //deleteIP();
            break;
        default:
            cout << "Sie haben eine falsche Nummer eingegeben!";
            break;
    }

}


/*
 * splitAndConvert
 * Split the input value and convert char string to int
 * 
 * @return void
 */
void splitAndConvert() {
    
    char ipAdress[16];
    cin >> ipAdress;
    char* ipToken = strtok(ipAdress, "...");
    
    if (ipToken)
    {
        ipBlock1 = atoi(ipToken);
        
        for (int i = 0; i < 4; i++) {
            switch (i) {
                case 1:
                    ipBlock2 =  atoi(strtok(NULL, "..."));
                    break;
                case 2:
                    ipBlock3 =  atoi(strtok(NULL, "..."));
                    break;
                case 3:
                    ipBlock4 =  atoi(strtok(NULL, "..."));
                    break;
                    
                default:
                    break;
            }
        }
        
    }
}
