#pragma once
#include "exchange_rate_service.h"
#include "euro_to_dollar_calculator.h"
#include <stdexcept>
class euro_to_dollar_calculator_impl :
	public euro_to_dollar_calculator
{
private:
	exchange_rate_service& exchange_rate_service_;
public:
	explicit euro_to_dollar_calculator_impl(exchange_rate_service& exchange_rate_service) :exchange_rate_service_(exchange_rate_service) {};
	[[nodiscard]] double convert(const double euro) const override
	{
	    try {
            return euro * exchange_rate_service_.get_rate_for("USD");
        } catch(...) {
            throw std::runtime_error("Exchange Rate Service ist nicht erreichbar");
        }
	}
};

