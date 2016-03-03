//
//  BluetoothMod.h
//  IoTGateway
//
//  Created by Prathamesh N. Saraf on 11/15/15.
//  Copyright (c) 2015 Prathamesh N. Saraf. All rights reserved.
//

#ifndef Class_BluetoothMod
#define Class_BluetoothMod


#include <stdio.h>

#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include "GlobalHeaders.h"

class BluetoothMod {
private:
    void openSocketandListen();
    static void * startBluetoothThread(void * param);
public:
    void initializeBluetooth();
};

#endif /* defined(Class_BluetoothMod) */
