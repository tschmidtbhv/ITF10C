#ifndef subnet_functions
#define subnet_functions

// Header für die Klassen einbinden, damit Sie sich selbst kennt.
#include <string>
#include "headers/subnet.h"
#include "headers/ipaddress.h"
using namespace std;

// Default-Konstruktor
subnet::subnet() {};

// Konstruktor mit den wichtigen Parametern
subnet::subnet(
    long paramnetAddress,
    long paramrangeStart,
    long paramrangeEnd,
    long parambroadcast,
    string paramName,
    string paramNotice
)
{
    this->netAddress = paramnetAddress;
    this->rangeStart = paramrangeStart;
    this->rangeEnd = paramrangeEnd;
    this->broadcast = parambroadcast;
    this->name = paramName;
    this->notice = paramNotice;
};

// Destruktor 
subnet::~subnet() {}

/**
 * IP-Adresse hinzufügen
 *
 * @param ipadress paramipaddress
 */
void subnet::addIP(ipaddress paramipaddress) {
    this->usedAddresses.push_back(paramipaddress);
};

/**
 * Entfernt eine IP-Adresse aus dem Vector mit der Auflistung
 * 
 * @param ipaddress paramIp
 */
void subnet::dropIP(ipaddress paramIp) {
    // Jedes Element durchgehen bis wir das gefunden haben das wir löschen wollen.
    for(int i = 0; i < this->usedAddresses.size(); i++) 
    {
        // Wenn wir das zu löschende gefunden haben
        if(this->usedAddresses[i].getLong() == paramIp.getLong())
        {
            // Objekt löschen vom ersten Objekt aus plus der Anzahl an Iterationen
            this->usedAddresses.erase(this->usedAddresses.begin() + i);
            // Arbeit erledigt, raus aus der Schleife
            break;
        }
    }
};

/**
 * Prüft ob eine IP in den Range des Subnetzes passt
 * 
 * @param ipaddress paramIp 
 * @return wenn gefunden dann true, ansonsten false als bool
 */
bool subnet::searchValid(ipaddress paramIp) {
    if(
       this->rangeStart <= paramIp.getLong() &&
       paramIp.getLong() <= this->rangeEnd
       ) 
    {
        return true; 
    } 
    else
    { 
        return false;
    }
}

/**
 * Sucht ob eine Adresse explizit vergeben ist (mit Hostnamen)
 *
 * @param IP-Adresse in numerischer Notation
 * @return wenn gefunden dann true, ansonsten false als bool
 */
bool subnet::searchExists(ipaddress paramIp) {
    for(int i = 0; i < this->usedAddresses.size(); i++)
    {
        if(this->usedAddresses[i].getLong() == paramIp.getLong())
        {
            return true;
        }
    }
    return false;
}

/**
 * Gibt ein Vector-Objekt mit allen defineirten IP-Adressen zurück
 *
 * @return usedAddresses as <vector>ipadress 
 */
vector<ipaddress> subnet::getAddresses() {
    return this->usedAddresses;
}

/**
 * Gibt den Anfang der Ranges in numerische Notation zurück
 * 
 * @return rangeStart as long
 */
long subnet::getRangeStart() {
    return this->rangeStart; 
};

/**
 * Gibt den Ende der Range in numerischer Notation zurück
 *
 * @return rangeEnd as long
 */
long subnet::getRangeEnd() {
    return this->rangeEnd; 
};

/**
 * Gibt die Broadcast-Adresse als numerische Notation zurück
 *
 * @return broadcast as long
 */
long subnet::getBroadCast() {
    return this->broadcast;
};

/**
 * Gibt die Netzadresse als numerische Notation zurück
 *
 * @return netaddress as long
 */
long subnet::getNetAdress() {
    return this->netAddress;
};
#endif