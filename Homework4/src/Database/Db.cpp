#pragma once

#include<string>
#include <sqlite_orm/sqlite_orm.h>
using namespace sqlite_orm;

#include"../Entities/Address.cpp"
#include"../Entities/Admin.cpp"
// #include"../Entities/AppUser.cpp"
#include"../Entities/Car.cpp"
#include"../Entities/Driver.cpp"
// #include"../Entities/Entity.cpp"
#include"../Entities/Order.cpp"
#include"../Entities/Passenger.cpp"
// #include"../Entities/SystemUser.cpp"

namespace Db
{
    inline static auto InitStorage(std::string path)
    {
        return make_storage(path,
                            make_table("Address",
                                       make_column("Id", &Address::Id, autoincrement(), primary_key()),
                                       make_column("X", &Address::X),
                                       make_column("Y", &Address::Y)),
                            make_table("Admin",
                                       make_column("Id", &Admin::Id),
                                       make_column("Login", &Admin::Login, primary_key()),
                                       make_column("Password", &Admin::Password)),
                            make_table("Car",
                                       make_column("Id", &Car::Id, autoincrement(), primary_key()),
                                       make_column("Model", &Car::Model),
                                    //    make_column("Type", &Car::Type),
                                    //    make_column("CurrentAddress", &Car::CurrentAddress),
                                    //    make_column("CarColor", &Car::CarColor),
                                       make_column("Number", &Car::Number, unique()),
                                       make_column("FreeBottleOfWater", &Car::FreeBottleOfWater)),
                            make_table("Driver",
                                       make_column("Id", &Driver::Id),
                                       make_column("Login", &Driver::Login, primary_key()),
                                       make_column("Password", &Driver::Password),
                                       make_column("Name", &Driver::Name),
                                       make_column("Rating", &Driver::Rating),
                                       make_column("RatedCnt", &Driver::RatedCnt),
                                    //    make_column("OrderHistory", &Driver::OrderHistory), //AAAAAAAAAA
                                    //    make_column("Cars", &Driver::Cars), //AAAAAAAAAAAAAAAAAAAAAAA
                                       make_column("IsWorking", &Driver::IsWorking),
                                       make_column("IsInRide", &Driver::IsInRide)),
                            make_table("Order",
                                       make_column("Id", &Order::Id, autoincrement(), primary_key()),
                                       make_column("Hours", &Order::Hours),
                                       make_column("Minutes", &Order::Minutes)
                                    //    make_column("From", &Order::From),
                                    //    make_column("To", &Order::To)
                                    ),
                            make_table("Passenger",
                                       make_column("Id", &Passenger::Id),
                                       make_column("Login", &Passenger::Login, primary_key()),
                                       make_column("Password", &Passenger::Password),
                                       make_column("Name", &Passenger::Name),
                                       make_column("Rating", &Passenger::Rating),
                                       make_column("RatedCnt", &Passenger::RatedCnt)
                                    //    make_column("OrderHistory", &Passenger::OrderHistory), //AAAAAAAAAAAAAAAAA
                                    //    make_column("PaymentMethods", &Passenger::PaymentMethods) //AAAAAAAAAAAAAAAA
                                    //    make_column("PinnedAddresses", &Passenger::PinnedAddresses) //AAAAAAAAAAAAAAAAAAA
                                        )
                                );
    }

    using Storage = decltype(InitStorage(""));
};

