#ifndef subnet_functions
#define subnet_functions
// Header für die Klassen einbinden, damit Sie sich selbst kennt.
#include "subnet.h"
#include "ipaddress.h"

// Konstruktor
subnet::subnet(
	/* Parameter */
)
{
	this->addresses = new ipaddress[0];
}
#endif