#ifndef subnet_functions
#define subnet_functions

// Header für die Klassen einbinden, damit Sie sich selbst kennt.
#include "subnet.h"
#include "ipaddress.h"

// Konstruktor
subnet::subnet(){}

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
    this->usedAddressesCount = 0;
};

void subnet::addIP(ipaddress paramipaddress) {
    this->usedAddressesCount++;
    this->usedAddresses = new ipaddress[this->usedAddressesCount];
    
    
};

void subnet::dropIP(long paramIp) {

};

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