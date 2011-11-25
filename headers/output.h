#ifndef output_header
#define output_header

#include "ipaddress.h"
#include "subnet.h"
#include <vector>
#include <string>

class output {
    public:
        void showSubnet(vector<subnet> subnetz);
        void showIpAddresses(vector<ipaddress> ipadressen);
    private:
        void center(string text);
};

#endif
