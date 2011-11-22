#ifndef subnet_functions
#define subnet_functions

// Header für die Klassen einbinden, damit Sie sich selbst kennt.
#include "subnet.h"
#include "ipaddress.h"

// Konstruktor
subnet::subnet() {};

subnet::subnet(
    int paramnetAddress,
    int paramrangeStart,
    int paramrangeEnd,
    int parambroadcast
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

void subnet::dropIP(long paramIp) {
    for(int i = 0; i < this->usedAddresses.size(); i++) 
    {
        if(this->usedAddresses[i].getLong() == paramIp)
        {
            this->usedAddresses.erase(this->usedAddresses.begin() + i);
            break;
        }
    }
};

vector<ipaddress> subnet::getIPs() {
    return this->usedAddresses;
}

int subnet::getRangeStart() {
    return this->rangeStart; 
};

int subnet::getRangeEnd() {
    return this->rangeEnd; 
};

int subnet::getBroadCast() {
    return this->broadcast;
};

int subnet::getNetAdress() {
    return this->netAddress;
};
#endif