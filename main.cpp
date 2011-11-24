// Standard-Includes sonst wird hier gar nichts
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// Klassen einbinden damit wir diese instanzieren können
#include "headers/ipaddress.h"
#include "headers/subnet.h"

int ipBlock1, ipBlock2,ipBlock3, ipBlock4;
vector<subnet> usedSubnets;

void selectedPoint(int choosenOne);
long splitAndConvert(string paramIPAddress);
int nextExpToTwo(int input);

void createSubnets();
void showSubnetMenu();
void getNetClassDigets();
void searchForIp(long paramIPAddress);

int main(void) {
    getNetClassDigets();
    createSubnets();
    showSubnetMenu();
    
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
            createSubnets();
            break;
            
        case 2:
            //splitAndConvert();
            break;
            
        case 3:
            
            //deleteIP();
            break;
        default:
            cout << "Sie haben eine falsche Nummer eingegeben!";
            break;
    }
    
}

void getNetClassDigets() {
    string input = "";
    
    do {
        cout << "Möchten Sie eine andere Netzklasse nutzen als 192.168.0.X ? (Y/N) "; 
        getline(cin,input); 
        // Eingabe in Kleinschreibung umwandeln
        transform(input.begin(),input.end(),input.begin(),::tolower);
        
    } while(input != "n" && input != "y");
    
    if(input == "y") {
        
        /* Jeden Einzelnen Block nach extra Parametern abfragen, die zwischen 1 und 255 liegen */
        
        do {
            cout << "Block 1: ";
            cin.ignore();
            scanf("%d",&ipBlock1);
            if(ipBlock1 < 0 || ipBlock1 > 255) {
                cout << "Bitte geben Sie eine Zahl zwischen 0 und 255 ein." << endl;
            }
        } while(ipBlock1 < 0 || ipBlock1 > 255 );
        
        do {
            cout << "Block 2: ";
            cin.ignore();
            scanf("%d",&ipBlock2);
            if(ipBlock2 < 0 || ipBlock2 > 255) {
                cout << "Bitte geben Sie eine Zahl zwischen 0 und 255 ein." << endl;
            }
        } while(ipBlock2 < 0 || ipBlock2 > 255 );
        
        do {
            cout << "Block 3: ";
            cin.ignore();
            scanf("%d",&ipBlock3);
            if(ipBlock3 < 0 || ipBlock3 > 255) {
                cout << "Bitte geben Sie eine Zahl zwischen 0 und 255 ein." << endl;
            }
        } while(ipBlock3 < 0 || ipBlock3 > 255 );
        
        cout << endl;
        
    } else {
        ipBlock1 = 192;
        ipBlock2 = 168;
        ipBlock3 = 0;
    }
    
    ipBlock4 = 0;
    
    return;
}

void createSubnets() {
    cout << "Wieviele Subnetze möchten Sie anlegen? ";
    
    int networkCount = 0;
    do {
        scanf ("%d",&networkCount);
        cin.ignore();
        if(networkCount <= 0 || networkCount >= 11) {
            cout << "Bitte wählen Sie eine Zahl im Bereich von 1 bis 10." << endl;
        }
    } while(networkCount <= 0 || networkCount >= 11);
    cout << endl;

    for(int i = 0; i < networkCount; i++) {
        cout << "Subnetz " << (i+1) << ":" << endl;
        
        string name = "";
        string description = "";
        int networkSize = 0;

        do {
            cout << "Name? ";
            getline(cin,name);
        } while(name == "");
        
        
        cout << "Beschreibung? ";
        getline(cin,description);
                
        do {
            cout << "Größe? ";
            scanf("%d",&networkSize);
            cin.ignore();
            if(networkSize <= 0 || networkSize >= 256) {
                cout << "Diese Größe ist nicht zulässig, wählen Sie eine Größe zwischen 0 und 256." << endl;
            }
        } while(networkSize <= 0 || networkSize >= 256);
        cout << endl;

        
        //Das erste Subnetz wird erstellt
        if (i == 0) {
            /*
             Abfragen ob es wirklich ein 192.168.0. Netz ist,
             gibt ja auch 172.16.XXX.XXX für VPNs
             
              192.168.0.0/24, das /24 muss berücksichtigt werden.
              In der offiziellen Aufgabe ist es AFAIK ein /25 
            */
            
            stringstream ipStream;
            ipStream << ipBlock1 << ".";
            ipStream << ipBlock2 << ".";
            ipStream << ipBlock3 << ".";
            ipStream << ipBlock4;
            
            string ipString = ipStream.str();
            
            usedSubnets.push_back(
                                  subnet(splitAndConvert(ipString),
                                    (splitAndConvert(ipString)+1),
                                    (splitAndConvert(ipString)+nextExpToTwo(networkSize)-1),
                                    (splitAndConvert(ipString)+nextExpToTwo(networkSize)),
                                    name,
                                    description)
                                );
        } else {
            
            /* @Thomas, bitte nochmal drüber schauen ob das hier alles so Sinn macht */
            
            long max_broadcast = 0;
            for (int i = 0; i< usedSubnets.size(); i++) {
                if( usedSubnets[i].getBroadCast() > max_broadcast) {
                    max_broadcast = usedSubnets[i].getBroadCast();
                }
            }
            
            usedSubnets.push_back(
                                  subnet(
                                    max_broadcast+1,
                                    max_broadcast+2,
                                    max_broadcast+(nextExpToTwo(networkSize)-1),
                                    max_broadcast+(nextExpToTwo(networkSize)),
                                    name,
                                    description)
                                );
            
        }
    }
}

void showSubnetMenu() {
    int menu_input = 0;
    int max_value = 0;
    
    cout << "0 - Beenden" << endl;
    
    /* HIER! Müsste Nico's Output-Klasse zum Einsatz kommen --> */
    for(int i = 0; i < usedSubnets.size(); i++) {
        cout << (i+1) << " - " << usedSubnets[i].getName() << " (" << usedSubnets[i].getNotice() << ")" << endl;
        max_value = (i+1);
    }
    /* <-- bis hier */
    
    cout << "Welches Subnetz möchten Sie bearbeiten? Bitte geben Sie die Zahl ein. " << endl;
    cout << "Beenden Sie das Programm in dem Sie 0 eingeben." << endl;
    
    do {
        scanf("%d",&menu_input);
        if(menu_input > 0 && menu_input < max_value) {
                // Subnetz aufrufen, IP-Adresse hinzufügen, Anzeige-Option und wieder 0 - Beenden
        }
    } while(menu_input != 0);
    
    return;
}

/**
 * splitAndConvert
 * Split the input value and convert char string to int
 * 
 * @return void
 */
long splitAndConvert(string paramIPAddress) {
    
    long output = 0;
    int iteration = 0;
    char* IPAddress =  strdup(paramIPAddress.c_str());
    char* pch = strtok(IPAddress, ".");
    
    while(pch != NULL) {
        switch(iteration) {
            case 0:
                output += atoi(pch) * pow(10,9);
                break;
            case 1:
                output += atoi(pch) * pow(10,6);
                break;
            case 2:
                output += atoi(pch) * pow(10,3);
                break;
            case 3:
                output += atoi(pch);
                break;
        }
        pch = strtok (NULL, ".");
        iteration++;
    }
    
    return output;
}

/**
 * Nächst größere Zahl auf Basis der zwei Bestimmen 
 *
 * @param Zahl zu der die größere Zahl bestimmt werden soll
 * @return Zahl größer als input, auf Basis von zwei
 */
int nextExpToTwo(int input) {
    
    int calculate = 0;
    
    for(int i = 0; calculate <= input; i++) {
        calculate = pow(2,i);
    }
    
    return calculate;
}

void searchForIp(long paramIPAddress) {
    for(int i = 0; i < usedSubnets.size(); i++) {
        if(usedSubnets[i].getRangeStart() > paramIPAddress && paramIPAddress < usedSubnets[i].getRangeEnd()) {
            vector<ipaddress> usedIPAdresses = usedSubnets[i].getAddresses();
            for(int j = 0; j < usedIPAdresses.size(); j++) {
                if(paramIPAddress == usedIPAdresses[j].getLong()) {
                    cout << "IP-Adresse gehört zum Subnetz " << usedSubnets[i].getName() << " und hat den Hostname " << usedIPAdresses[j].getHostName() << "." << endl;
                    return;
                }
            } 
            cout << "IP-Adresse gehört zum Subnetz " << usedSubnets[i].getName() << ".";
        } else {
            cout << "Die IP-Adresse gehört zu keinem Subnetz." << endl;
        }
    }
}
