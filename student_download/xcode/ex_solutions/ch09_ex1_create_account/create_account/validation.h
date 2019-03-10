#ifndef MURACH_VALIDATION_H
#define MURACH_VALIDATION_H

#include <string>

namespace validation {
	bool is_valid_password(std::string password);
	bool is_valid_email(std::string email);
}

#endif