//This is the implementation for the class DiscountSale.
#include "discountsale.h"

namespace salesavitch
{
    DiscountSale::DiscountSale() : Sale(0), discount(0)
    {}

    DiscountSale::DiscountSale(double thePrice, double theDiscount)
              : Sale(thePrice), discount(theDiscount)
    {}

    double DiscountSale::bill() const
    {
        double fraction = discount/100;
        return (1 - fraction)*price;
    }
}//salesavitch