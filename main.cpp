//
//  main.cpp
//  IoTGateway
//
//  Created by Prathamesh N. Saraf on 11/14/15.
//  Copyright (c) 2015 Prathamesh N. Saraf. All rights reserved.
//

#include "MQTTBroker.h"
#include "BluetoothMod.h"

extern "C" {
    #include "Mosquitto/src/mosquitto_broker.h"
}


int main(int argc, const char * argv[]) {
    
    int pipefds[2];
    pipe(pipefds);
    if(!fork()) {
        MQTTBroker obj;
	BluetoothMod blueObj;
        char buf[1024] = {0};
        blueObj.initializeBluetooth();
        read(pipefds[0], buf, sizeof(buf));
        std::cout<<buf<<"\n";
        obj.initializeMQTT();
        
    } else {
//        close(pipefds[0]);
        initilaizeMqttLib(pipefds);
    }
    
    pthread_exit(NULL);
}


