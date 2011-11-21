//
//  IPList.h
//  IPAdder
//
//  Created by Thomas Schmidt on 21.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

class IPList {
    
    
public:
    //Vars
    IPList *nextIP;
    string currentIP;
    
    //Methods
    void addIPToList(string ip);
    void deleteIP(string ip);
    
    
};