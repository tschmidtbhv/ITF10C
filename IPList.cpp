//
//  IPList.cpp
//  IPAdder
//
//  Created by Thomas Schmidt on 21.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//


#include "IPList.h"


IPList *nextIP = NULL;
IPList *begin = NULL;

/*
 * Add IP To List
 * @params string ip
 * return void
 */

void IPList::addIPToList(string ip){
    IPList *zeiger;
    
    //Is there a IP ?
    if (begin == NULL) {
        
        //no Ip`s available
        zeiger = new IPList();
        zeiger->currentIP = ip;
        zeiger->nextIP = NULL;
    } else {
        zeiger = begin;
        while (zeiger->nextIP != NULL) {
            zeiger = zeiger->nextIP;
        }
        
        zeiger->nextIP = new IPList();
        zeiger = zeiger->nextIP;
        zeiger->currentIP = ip;
        zeiger->nextIP = NULL;
    }
    
}



/*
 * Delete Ip from List
 * @params
 * return void
 *
 */ 

void IPList::deleteIP(string ip) {
    
    IPList *temp, *temp2;
    if (begin != NULL) {
        if (begin->currentIP == ip) {
            
            
            temp = begin->nextIP;
            
            free(begin);
            
            //set new begin
            begin = temp;
        } else {
            temp = begin;
            while (begin->nextIP != NULL) {
                
                temp2 = temp->nextIP;
                if (temp2->currentIP == ip) {
                    temp->nextIP = temp2->nextIP;
                    free(temp2);
                    break;
                }
                temp = temp2;
            }
            
        }
    }else {
        cout << "No Ip's to delete. \n";
    }
}
