//
//  main.cpp
//  IoTGateway
//
//  Created by Prathamesh N. Saraf on 11/14/15.
//  Copyright (c) 2015 Prathamesh N. Saraf. All rights reserved.
//


#include <mosquitto_broker.h>



int main(int argc, const char * argv[]) {
    
//    obj.initializeMQTT();
    
    printf("Beginnging custom main\n");
     initilaizeMqttLib(argc,argv);
    
    pthread_exit(NULL);
}
