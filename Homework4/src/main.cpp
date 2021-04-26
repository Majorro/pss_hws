// #define DEBUG


#include<string>
#include<iostream>
#include"Database/Db.cpp"
#include"Entities/Address.cpp"
#include"Entities/Admin.cpp"
#include"Entities/AppUser.cpp"
#include"Entities/Car.cpp"
#include"Entities/Driver.cpp"
#include"Entities/Entity.cpp"
#include"Entities/Order.cpp"
#include"Entities/Passenger.cpp"
#include"Entities/SystemUser.cpp"
#include"Enums/CarType.cpp"
#include"Enums/Color.cpp"
#include"Enums/PaymentMethod.cpp"
#include"Utils/Utils.cpp"


int main() {
#ifdef DEBUG
    freopen("out.txt", "w", stdout);
#endif
    std::string dbPath = "../../src/Database/";
    Db::Storage db = Db::InitStorage(dbPath+"db.sqlite");
    db.sync_schema();

    
    
    return 0;
}