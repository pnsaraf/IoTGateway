//
//  MQTTBroker.cpp
//  IoTGateway
//
//  Created by Prathamesh N. Saraf on 11/14/15.
//  Copyright (c) 2015 Prathamesh N. Saraf. All rights reserved.
//

#include "MQTTBroker.h"


void * MQTTBroker::startMQTTThread(void *param)
{
 
//    MQTTBroker *obj = (MQTTBroker *)param;
//    addrinfo details,*nextStruct = NULL;
//    
//    memset(&details, 0, sizeof(struct addrinfo));
//    
//    details.ai_family = AF_UNSPEC;
//    details.ai_socktype = SOCK_STREAM;
//    details.ai_flags = AI_PASSIVE;
//    
//    if(!getaddrinfo(NULL, "1883", &details, &nextStruct)) {
//        obj->sockDesp = socket(nextStruct->ai_family, nextStruct->ai_socktype, nextStruct->ai_protocol);
//        if (obj->sockDesp < 0) {
//            std::cerr<<"Error opening socket\n";
//            pthread_exit(NULL);
//        }
//        
//        if(::bind(obj->sockDesp, nextStruct->ai_addr, nextStruct->ai_addrlen) < 0) {
//            std::cerr<<"Error in binding socket\n";
//            pthread_exit(NULL);
//        }
//        
//        
//        std::cout<<"Begin thread\n";
//        
//        if(!listen(obj->sockDesp, 10)) {
//            struct sockaddr_storage client;
//            socklen_t len = sizeof(sockaddr_storage);
//            int newSock = accept(obj->sockDesp, (sockaddr *)&client, &len);
//            if(newSock > 0) {
//                char buf[1024] = {0};
//                int size = recv(newSock, buf, sizeof(buf), 0);
//                std::cout<<buf<<std::endl;
//            }
//        }
//    }

    
    std::cout << "new thread started\n";
    try {
        sql::Driver *driver;
        sql::Connection *con;
        
        sql::Statement *stmt;
        sql::ResultSet *res;
        sql::PreparedStatement  *prep_stmt;
	
        
        driver = get_driver_instance();
        con = driver->connect("tcp://storedb.czwwhp5szq3i.us-west-2.rds.amazonaws.com:3306","psaraf","295B1234");
        
        con->setSchema("StoreDB");
        string code = "00381370036913";
        prep_stmt = con->prepareStatement("SELECT * from Store where barcode = ?");
        prep_stmt->setString(1,"00381370036913");
        cout << prep_stmt << endl;
//        snprintf(query,255,"SELECT * from Store where barcode = %s",'00381370036913');
        res = prep_stmt->executeQuery();
	cout << "I am here\n";
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << res->getString("itemname") << endl;
            cout << "\t... MySQL says it again: ";
            /* Access column fata by numeric offset, 1 is the first column */
            cout << res->getString(1) << endl;
        }
        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException *e) {
       
        cout << "# ERR: " << e->what();
        cout << " (MySQL error code: " << e->getErrorCode();
        cout << ", SQLState: " << e->getSQLState() << " )" << endl;
    }

   // initilaizeMqttLib();
    
    pthread_exit(NULL);
}


void MQTTBroker::initializeMQTT()
{
    pthread_t pthreadid = 0;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int rats = 0;
//    std::cout<<"Begin thread\n";

    pthread_create(&pthreadid, &attr, &MQTTBroker::startMQTTThread, NULL);
    

}

void MQTTBroker::displaySomething()
{
    std::cout<<"Displayed\n";
}



void display ()
{
    MQTTBroker obj;
    obj.displaySomething();
}
