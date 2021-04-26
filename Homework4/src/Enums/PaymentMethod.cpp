#pragma once

#include<ostream>

enum PaymentMethod
{
    Card,
    Cash
};

std::ostream& operator<<(std::ostream& out, const PaymentMethod paymentMethod)
{
    switch (paymentMethod)
    {
    case PaymentMethod::Card:
        out << "Card";
        break;
    
    case PaymentMethod::Cash:
        out << "Cash";
        break;
    }
    return out;
}
