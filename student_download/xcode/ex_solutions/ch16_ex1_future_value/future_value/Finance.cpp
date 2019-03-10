#include "Finance.h"

double Finance::calculate_future_value(
    double monthly_investment,
    double yearly_interest_rate, 
    int years) {

    // convert yearly values to monthly values
    double monthly_rate = yearly_interest_rate / 12 / 100;
    int months = years * 12;

    // calculate future value
    double future_value = 0;
    for (int i = 0; i < months; ++i) {
        future_value = (future_value + monthly_investment) *
            (1 + monthly_rate);
    }
    return future_value;
}