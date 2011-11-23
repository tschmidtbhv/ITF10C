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
s

int main(void) {
    
    cout << splitAndConvert("192.168.0.1") << endl;
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
