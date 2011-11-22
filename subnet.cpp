#ifndef subnet_functions
#define subnet_functions

// Header für die Klassen einbinden, damit Sie sich selbst kennt.
#include "subnet.h"
#include "ipaddress.h"

// Konstruktor
subnet::subnet() {};

subnet::subnet(
    long paramnetAddress,
    long paramrangeStart,
    long paramrangeEnd,
    long parambroadcast
)
{
    this->netAddress = paramnetAddress;
    this->rangeStart = paramrangeStart;
    this->rangeEnd = paramrangeEnd;
    this->broadcast = parambroadcast;
};

void subnet::addIP(ipaddress paramipaddress) {
    this->usedAddresses.push_back(paramipaddress);
};

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

// Sucht ob eine IP in ein Subnetz gehört
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

// Sucht ob die IP im Subnetz mit Hostnamen vergeben ist
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

// Vector-Objekt mit allen Adressen zurückgeben, für die Darstellung
vector<ipaddress> subnet::getIPs() {
    return this->usedAddresses;
}

// Anfang des IP-Bereiches abfragen
long subnet::getRangeStart() {
    return this->rangeStart; 
};

long subnet::getRangeEnd() {
    return this->rangeEnd; 
};

long subnet::getBroadCast() {
    return this->broadcast;
};

long subnet::getNetAdress() {
    return this->netAddress;
};
#endif