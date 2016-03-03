all:
	g++ -std=c++11 main.cpp BluetoothMod.cpp MQTTBroker.cpp lib/libbrok.so -ldl -lm -luuid -lssl -lcrypto -lpthread -lbluetooth -I Mosquitto/src/ lib/libmysqlcppconn-static.a -I MySQL/ -o gateway.exe
