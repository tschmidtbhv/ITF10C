// Standard-Includes sonst wird hier gar nichts
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

// Klassen einbinden damit wir diese instanzieren können
#include "headers/ipaddress.h"
#include "headers/subnet.h"
#include "headers/output.h"

int ipBlock1, ipBlock2,ipBlock3, ipBlock4;
vector<subnet> usedSubnets;
output* out = new output();

void createSubnets();
void showSubnetMenu();
void getNetClassDigets();
void searchForIp(long paramIPAddress);
void editSubnet(int menu_input);
void addIPToSubnet (int menu_input);
void editIPInSubnet(int menu_input);
void makeIpBlocks(long max_broadcast);
long splitAndConvert(string paramIPAddress);
int nextExpToTwo(int input);

int main(void) {
    getNetClassDigets();
    createSubnets();
    showSubnetMenu();

    return EXIT_SUCCESS;
}


void getNetClassDigets() {
    string input = "";

    do {
        cout << "Möchten Sie eine andere Netzklasse nutzen als 192.168.0.X ? (Y/N) " << endl; 
        cout << "> ";
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
        cout << "Block 1: " << endl;
        cout << "> ";
        cin.ignore();
        scanf("%d",&ipBlock1);
        if(ipBlock1 < 0 || ipBlock1 > max_broadcast) {
            cout << "Bitte geben Sie eine Zahl zwischen 0 und " << max_broadcast << " ein." << endl;
        }
    } while(ipBlock1 < 0 || ipBlock1 > max_broadcast );

    do {
        cout << "Block 2: " << endl;
        cout << "> ";
        cin.ignore();
        scanf("%d",&ipBlock2);
        if(ipBlock2 < 0 || ipBlock2 > max_broadcast) {
            cout << "Bitte geben Sie eine Zahl zwischen 0 und " << max_broadcast << " ein." << endl;
        }
    } while(ipBlock2 < 0 || ipBlock2 > max_broadcast );

    do {
        cout << "Block 3: " << endl;
        cout << "> ";
        cin.ignore();
        scanf("%d",&ipBlock3);
        if(ipBlock3 < 0 || ipBlock3 > max_broadcast) {
            cout << "Bitte geben Sie eine Zahl zwischen 0 und " << max_broadcast << " ein." << endl;
        }
    } while(ipBlock3 < 0 || ipBlock3 > max_broadcast );

    cout << endl;
}

void createSubnets() {
    cout << "Wieviele Subnetze möchten Sie anlegen? " << endl;
    cout << "> ";

    int networkCount = 0;
    do {
        scanf ("%d",&networkCount);
        cin.ignore();
        if(networkCount < 1 || networkCount > 10) {
            cout << "Bitte wählen Sie eine Zahl im Bereich von 1 bis 10." << endl;
        }
    } while(networkCount < 1 || networkCount > 10);
    cout << endl;

    for(int i = 0; i < networkCount; i++) {
        cout << "Subnetz " << (i+1) << ":" << endl;

        string name = "";
        string description = "";
        int networkSize = 0;
        int usedSize = 0;

        do {
            cout << "Name? " << endl;
            cout << "> ";
            getline(cin,name);
        } while(name == "");

        cout << "Beschreibung? " << endl;
        cout << "> ";
        getline(cin,description);

        do {
            cout << "Größe? " << endl;
            cout << "> ";
            scanf("%d",&networkSize);
            cin.ignore();
            if(networkSize <= 0 || networkSize >= 256) {
                cout << "Diese Größe ist nicht zulässig, wählen Sie eine Größe zwischen 0 und 256." << endl;
            }

            usedSize = networkSize;
            for(int i = 0; i < usedSubnets.size(); i++) {
                usedSize += usedSubnets[i].getSize();
            }
            if(usedSize >= 256) {
                cout << "Eingabe zu groß! Subnetz wurde nicht hinzugefügt." << endl;
                return;
            } else {
                cout << "Es verbleiben noch " << (256-usedSize) << endl;
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
                                  subnet(nextExpToTwo(networkSize),
                                    (splitAndConvert(ipString)),
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
                                  subnet(nextExpToTwo(networkSize),
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

    do {
        out->showSubnet(usedSubnets);
        max_value = (int)usedSubnets.size();

        cout << "0 - Beenden" << endl;
        cout << "Welches Subnetz möchten Sie bearbeiten? Bitte geben Sie die Zahl ein. " << endl;
        cout << "Benutzen Sie -1 um nach IP Adressen zu suchen." << endl;
        cout << "Beenden Sie das Programm in dem Sie 0 eingeben. " << endl;
        cout << "> ";
        scanf("%d",&menu_input);
        cout << endl;

        if (menu_input == -1) {

            string ipAddress = "";
            cout << "Geben Sie die zu suchende IP Adresse ein" << endl;
            cout << "> ";
            cin.ignore();
            getline(cin, ipAddress);
            searchForIp(splitAndConvert(ipAddress));
            break;

        } else if(menu_input == 0) {
            break;
        }
        else if(menu_input > 0 && menu_input <= max_value) {
            editSubnet(menu_input-1);
        } else {
            cout << "Bitte erneut eingeben." << endl;
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
        out->showIpAddresses(usedSubnets[menu_input].getAddresses());
        cout << "Größe: " << usedSubnets[menu_input].getSize() << endl;
        cout << "-----------------------\n" << endl;
        cout << "Was möchten Sie bearbeiten? " << endl;
        cout << "1 - Name" << endl;
        cout << "2 - Beschreibung" << endl;
        cout << "3 - IP Suchen" << endl;
        cout << "4 - IP mit Hostnamen und Beschreibung hinzufügen" << endl;
        cout << "0 - Bearbeitung beenden" << endl;
        cout << "> ";

        scanf("%d",&eingabe);
        switch (eingabe) {

            case 1: {
                string name = "";
                cout << "Geben Sie einen neuen Namen ein:" << endl;
                cout << "> ";
                cin.ignore();
                getline(cin, name);
                usedSubnets[menu_input].setName(name);
                break;
            }

            case 2: {
                string description = "";
                cout << "Geben Sie eine neue Beschreibung ein:" << endl;
                cout << "> ";
                cin.ignore();
                getline(cin, description);
                usedSubnets[menu_input].setNotice(description);
                break;
            }

            case 3: {
                string ipAddress = "";
                cout << "Geben Sie die zu suchende IP Adresse ein" << endl;
                cout << "> ";
                cin.ignore();
                getline(cin, ipAddress);
                searchForIp(splitAndConvert(ipAddress));
                break;
            }

            case 4: {
                addIPToSubnet(menu_input);
                break;
            }

            default: {
                break;
            }
        }
        cout << endl;
    } while (eingabe >= 1 && eingabe <= 3);

    return;
}

/*
 * addIPToSubnet
 * add IP to Subnet
 * @params int menu_input
 * return void
 *
 */

void addIPToSubnet(int menu_input) {

    long max_broadcast = 0;
    bool value = false;
    vector<ipaddress> usedAdresses;
    max_broadcast = usedSubnets[menu_input].getBroadCast();

    cout << "Wie lautet der letzte Block der IP?" << endl;
    cout << "> ";
    scanf("%d",&ipBlock4);

    ipaddress address = ipaddress::ipaddress(ipBlock1,ipBlock2,ipBlock3,ipBlock4);

    if(usedSubnets[menu_input].getRangeStart() <= address.getLong() &&
       address.getLong() <= usedSubnets[menu_input].getRangeEnd()
       )
    {
        usedAdresses = usedSubnets[menu_input].getAddresses();
        for(int i = 0; i < usedAdresses.size(); i++) {
            if(usedAdresses[i].getLong() == address.getLong()) {
                value = true;
            }
        }
        if(value == false) {
            cout << "Ip-Adresse wird hinzugefügt." << endl;
            usedSubnets[menu_input].addIP(address);
        } else {
            cout << "IP-Adresse bereits vorhanden." << endl;
        }
    } else {
        cout << "IP liegt nicht in diesem Subnetz!";
    }

    return;
}

/*
 * editIPInSubnet
 * edit ip in subnet
 * @params int menu_input
 * return void
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

/*
 * searchForIp
 * @params paramIPAddress
 */
void searchForIp(long paramIPAddress) {
    for(int i = 0; i < usedSubnets.size(); i++) {
        if(usedSubnets[i].getNetAdress() <= paramIPAddress &&
           paramIPAddress <= usedSubnets[i].getBroadCast())
        {
            vector<ipaddress> usedIPAdresses = usedSubnets[i].getAddresses();
            
            for(int j = 0; j < usedIPAdresses.size(); j++) {
                if(paramIPAddress == usedIPAdresses[j].getLong()) {
                    cout << "IP-Adresse gehört zum Subnetz " << usedSubnets[i].getName() 
                    << " und hat den Hostname " << usedIPAdresses[j].getHostName() << "." << endl;
                    return;
                }
            } 
            
            cout << "IP-Adresse gehört zum Subnetz " << usedSubnets[i].getName() << "." << endl;
            return;
        } 
    }
    cout << "Die IP-Adresse gehört zu keinem Subnetz." << endl;
}
