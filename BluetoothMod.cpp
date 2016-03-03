//
//  BluetoothMod.cpp
//  IoTGateway
//
//  Created by Prathamesh N. Saraf on 11/15/15.
//  Copyright (c) 2015 Prathamesh N. Saraf. All rights reserved.
//

#include "BluetoothMod.h"




void * BluetoothMod::startBluetoothThread(void *param)
{

    struct sockaddr_rc loc_addr = {0}, rem_addr = {0};
	char buf[1024] = {0};
	
	bdaddr_t myaddrany = {0};	

	int s,client,bytesread;
	socklen_t opt = sizeof(rem_addr);
#if 0
	s = socket(AF_BLUETOOTH,SOCK_STREAM,BTPROTO_RFCOMM);

	loc_addr.rc_family = AF_BLUETOOTH;
	loc_addr.rc_bdaddr = myaddrany;
	loc_addr.rc_channel = (uint8_t)1;

	bind(s,(struct sockaddr*)&loc_addr,sizeof(loc_addr));

	listen(s,2);

	std::cout<<"Started Listening for bluetooth connections.\n";
	while (1) {
		client = accept(s,(struct sockaddr * )&rem_addr,&opt);
		ba2str(&rem_addr.rc_bdaddr,buf);

		printf("connect recieved from. %s\n",buf);
	}

	close(client);
	close(s);

#endif

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
        prep_stmt = con->prepareStatement("SELECT * from Promotions where aisleNo = ?");
        prep_stmt->setString(1,"4");
        cout << prep_stmt << endl;
//        snprintf(query,255,"SELECT * from Store where barcode = %s",'00381370036913');
	
        res = prep_stmt->executeQuery();
	;
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << res->getString("promotionOffer") << endl;
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
    pthread_exit(NULL);
}


void BluetoothMod::initializeBluetooth()
{
    pthread_t pthreadid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_create(&pthreadid, &attr, &BluetoothMod::startBluetoothThread, NULL);
}
