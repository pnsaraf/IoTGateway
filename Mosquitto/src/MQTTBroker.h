//
//  MQTTBroker.cpp
//  IoTGateway
//
//  Created by Prathamesh N. Saraf on 11/14/15.
//  Copyright (c) 2015 Prathamesh N. Saraf. All rights reserved.
//

#ifndef Class_MQTTBroker

#define Class_MQTTBroker

#ifdef __cplusplus
#include "GlobalHeaders.h"
#endif

#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <stdlib.h>


extern "C" {
    void display ();
}

#ifdef __cplusplus
class MQTTBroker {
private:
    void openSocketandListen();
    static void * startMQTTThread(void * param);
    int sockDesp;
public:
    void initializeMQTT();
    void displaySomething();
    
};
#endif

#endif