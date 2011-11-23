// Standard-Includes sonst wird hier gar nichts
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// Klassen einbinden damit wir diese instanzieren können
#include "headers/ipaddress.h"
#include "headers/subnet.h"

int ipBlock1, ipBlock2,ipBlock3, ipBlock4;

void selectedPoint(int choosenOne);
long splitAndConvert(string paramIPAddress);
void createSubnet();
int nextExpToTwo(int input);

int main(void) {
    createSubnet();
    //cout << splitAndConvert("192.168.0.1") << endl;
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
            createSubnet();
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


void createSubnet() {
    cout << " Wieviele Subnetze möchten Sie anlegen?";
    
    int networkCount = 0;
    scanf ("%d",&networkCount);
    
    vector<subnet> usedSubnets;
    for(int i = 0; i < networkCount; i++) {
        cout << "Subnetz " << (i+1) << ":" << endl;
        
        cout << "Name? ";
        string name = "";
        cin.ignore();
        getline(cin,name);
        
        
        cout << "Beschreibung? ";
        string description = "";
        cin.ignore();
        getline(cin,description);
        
        
        cout << "Größe? ";
        int networkSize = 0;
        scanf("%d",&networkSize);
        
        //Das erste Subnetz wird erstellt
        if (i == 0) {
            /*
             Abfragen ob es wirklich ein 192.168.0. Netz ist,
             gibt ja auch 172.16.XXX.XXX für VPNs
             
              192.168.0.0/24, das /24 muss berücksichtigt werden.
              In der offiziellen Aufgabe ist es AFAIK ein /25 
            */
            
            usedSubnets[i] = subnet(splitAndConvert("192.168.0.1"),
                                    (splitAndConvert("192.168.0.1")+1),
                                    (splitAndConvert("192.168.0.1")+nextExpToTwo(networkSize)-1),
                                    (splitAndConvert("192.168.0.1")+nextExpToTwo(networkSize)),
                                    name,
                                    description);
        } else {
            
            /* @Thomas, bitte nochmal drüber schauen ob das hier alles so Sinn macht */
            
            long max_broadcast = 0;
            for (int i = 0; i< usedSubnets.size(); i++) {
                if( usedSubnets[i].getBroadCast() > max_broadcast) {
                    max_broadcast = usedSubnets[i].getBroadCast();
                }
            }
            
            usedSubnets[i] = subnet(
                                    max_broadcast+1,
                                    max_broadcast+2,
                                    max_broadcast+(nextExpToTwo(networkSize)-1),
                                    max_broadcast+nextExpToTwo(networkSize),
                                    name,
                                    description);
            
        }
        /*
         Viele tolle Berechnungen von Broadcast,
         Netzadresse, Start und Ende des Range.
         
         Dann objekt hinzufügen:
         usedSubnets.push_back(subnet(0,0,0,0,name,notice));
         */
    }
}

/*
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

/*
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
