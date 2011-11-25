#ifndef output_functions
#define output_functions

// Header für IO einbinden
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Header für Klassen einbinden
#include "headers/ipaddress.h"
#include "headers/subnet.h"
#include "headers/output.h"

//Funktion um Ausgabe zu zentrieren
void output::center(string text)
{
  //Textlänge herausfinden
	int len = (int)text.length();
    //Test ob länge durch 2 teilbar
	if (len%2 != 0)
		{
			text = text + " ";
			len = (int)text.length();
		}
	//Test ob maximal länge der Spalte überschritten wird
	else if (len > 23 )
		{
			//kürzen der Ausgabe
			text = text.substr(0,20);
			//auffüllen mit Punkten
			text = text + "...";
		}
    len = (24-len)/2;
	//Ausgabe eines |
    printf("%s","|");
	//Platzhalter links
    printf("%*s",len,"");
	//Text
    cout<<text;
	//Platzhalter rechts
    printf("%*s",len,"");
}

string output::convert(long paramInput)
{	
	stringstream input;

    input << paramInput;
    
	return input.str();
}

//Zeigt Subnetze in Liste an
void output::showSubnet(vector<subnet> subnetz)
{
	//Header definieren
	string bereich = "Bereich";
    string name = "Name";
    string notiz = "Notiz";
    printf("%s","+--");
    printf("%s","+------------------------");
    printf("%s","+------------------------");
    printf("%s","+------------------------+");
    cout<<"\n";
	
	//Ausgabe
	printf("%s","|Nr");
	center(bereich);
    center(name);
    center(notiz);
    cout<<"|\n";

    printf("%s","+--");
    printf("%s","+------------------------");
    printf("%s","+------------------------");
    printf("%s","+------------------------+");
    cout<<"\n";

	//Ausgabe der Subnetzeigenschaften
	for(int i = 0; i < subnetz.size();i++)
	{
		if (i<10)
		{
            cout<<"| ";
            printf("%i",i);
        }
        else
        {
            cout<<"|";
            printf("%i",i);
        }
        
        string netaddress = convert(subnetz[i].getNetAdress());
        netaddress = netaddress.substr(9,3);
        
        string broadcast =  convert(subnetz[i].getBroadCast());
        broadcast = broadcast.substr(9,3);
        
        string range = netaddress + " - " + broadcast;
        
		center(range);
		center(subnetz[i].getName());
		center(subnetz[i].getNotice());
		cout<<"|\n";
	}
	printf("%s","+--");
	printf("%s","+------------------------");
    printf("%s","+------------------------");
    printf("%s","+------------------------+");
    cout<<"\n";
}

//Zeigt IP-Adressen in Liste an
void output::showIpAddresses(vector<ipaddress> ipadressen)
{
	//Header definieren
	string ip = "IP";
    string name = "Hostnamen";
    string notiz = "Notiz"; 
    printf("%s","+------------------------");
    printf("%s","+------------------------");
    printf("%s","+------------------------+");
    cout<<"\n";
	
	//Ausgabe
	center(ip);
    center(name);
    center(notiz);
    cout<<"|\n";
    printf("%s","+------------------------");
    printf("%s","+------------------------");
    printf("%s","+------------------------+");
    cout<<"\n";

	//Ausgabe der IP Eigenschaften
	for(int i = 0; i < ipadressen.size();i++)
	{
		center(ipadressen[i].getString());
		center(ipadressen[i].getHostName());
		center(ipadressen[i].getNotice());
		cout<<"|\n";
	}
	printf("%s","+------------------------");
    printf("%s","+------------------------");
    printf("%s","+------------------------+");
    cout<<"\n";

}
#endif