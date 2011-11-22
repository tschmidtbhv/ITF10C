// Standard-Includes sonst wird hier gar nichts
#include <iostream>
#include <string>
using namespace std;
using std::string;

// Klassen einbinden damit wir diese instanzieren können
#include "ipaddress.h"
#include "subnet.h"

int main(void) {
	ipaddress* schinken = new ipaddress(0, 1);
	cout << schinken->getIPAsString() << endl;
    cout << schinken->getIPAsLongInt() << endl;
    
	subnet* kaese = new subnet();

	delete kaese;
	delete schinken;

	return EXIT_SUCCESS;
}
