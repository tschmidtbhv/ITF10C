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
void editSubnet(int menu_input);
void addIPToSubnet (int menu_input);
void editIPInSubnet(int menu_input);
void makeIpBlocks(long max_broadcast);


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
        
        makeIpBlocks(255);
        
    } else {
        ipBlock1 = 192;
        ipBlock2 = 168;
        ipBlock3 = 0;
    }
    
    ipBlock4 = 0;
    
    return;
}

void makeIpBlocks(long max_broadcast) {
    /* Jeden Einzelnen Block nach extra Parametern abfragen, die zwischen 1 und 255 liegen */
    
    do {
        cout << "Block 1: ";
        cin.ignore();
        scanf("%d",&ipBlock1);
        if(ipBlock1 < 0 || ipBlock1 > max_broadcast) {
            cout << "Bitte geben Sie eine Zahl zwischen 0 und " << max_broadcast << " ein." << endl;
        }
    } while(ipBlock1 < 0 || ipBlock1 > max_broadcast );
    
    do {
        cout << "Block 2: ";
        cin.ignore();
        scanf("%d",&ipBlock2);
        if(ipBlock2 < 0 || ipBlock2 > max_broadcast) {
            cout << "Bitte geben Sie eine Zahl zwischen 0 und " << max_broadcast << " ein." << endl;
        }
    } while(ipBlock2 < 0 || ipBlock2 > max_broadcast );
    
    do {
        cout << "Block 3: ";
        cin.ignore();
        scanf("%d",&ipBlock3);
        if(ipBlock3 < 0 || ipBlock3 > max_broadcast) {
            cout << "Bitte geben Sie eine Zahl zwischen 0 und " << max_broadcast << " ein." << endl;
        }
    } while(ipBlock3 < 0 || ipBlock3 > max_broadcast );
    
    cout << endl;
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
            editSubnet(menu_input);
                // Subnetz aufrufen, IP-Adresse hinzufügen, Anzeige-Option und wieder 0 - Beenden
        } else {
            cout << "Bitte erneut eingeben.";
        }
    } while(menu_input != 0);
    
    return;
}


/*
 * editSubnet 
 * Edit name or Description
 * @params int menu_input
 * return void
 *
 */
 
void editSubnet(int menu_input){
    
    int eingabe;
    
    do {
        
        
        cout << "Sie bearbeiten Subnetz: " << usedSubnets[menu_input].getName() << endl;
        cout << "Beschreibung: " << usedSubnets[menu_input].getNotice() << endl;
        cout << "-----------------------\n" << endl;
        cout << "Was möchten Sie bearbeiten? " << endl;
        cout << "1 - Name" << endl;
        cout << "2 - Beschreibung" << endl;
        cout << "3 - IP hinzufügen" << endl;
        cout << "0 - Bearbeitung beenden" << endl;
        
        cin >> eingabe;
        switch (eingabe) {
            
            case 1: {
                
                string name = "";
                cout << "Geben Sie einen neuen Namen ein:" << endl;
                getline(cin, name); 
                usedSubnets[menu_input].name = name;
                break;
            }
                
            case 2: {
                string description = "";
                cout << "Geben Sie eine neue Beschreibung ein:" << endl;
                getline(cin, description); 
                usedSubnets[menu_input].notice = description;
                break;
            }
            
            case 3: {
                addIPToSubnet(menu_input);
                break;
            }

            default: {
                break;
            }
        }
    } while (eingabe != 0 && (eingabe == 1 || eingabe == 2 || eingabe == 3));
    
    return;
}

/*
 * addIPToSubnet
 * add IP to Subnet
 * @params int menu_input
 * return void
 *
 */ 

void addIPToSubnet (int menu_input) {
    long max_broadcast;
    max_broadcast = usedSubnets[menu_input].getBroadCast();
    
    char  ip[3] = ""; 
    cout << "Geben Sie die IP ein:" << endl;
    makeIpBlocks(max_broadcast);
    cout << "Block 4: " << endl;
    cin >> ip;
    ipBlock4 = atoi(ip);
    
    ipaddress ipaddress = ipaddress::ipaddress(ipBlock1,ipBlock2,ipBlock3,ipBlock4);
    if (splitAndConvert(ip) < max_broadcast) {
        usedSubnets[menu_input].addIP(ipaddress);
    }
    return;
}

/*
 * editIPInSubnet
 * edit ip in subnet
 * @params int menu_input
 * return void
 *  
 */

void editIPInSubnet(int menu_input) {
    
    vector<ipaddress> addresses = usedSubnets[menu_input].getAddresses();
    cout << "ip te: " << addresses[1].getString();
    for (int i = 0; i < addresses.size(); i++) {
        cout << "ip: " << addresses[i].getString();
    }
    
    
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
