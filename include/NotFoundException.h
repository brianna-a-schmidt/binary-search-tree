#ifndef NOT_FOUND_EXCEPTION_H
#define NOT_FOUND_EXCEPTION_H

#include <stdexcept>
#include <string>

class NotFoundException: public std::logic_error 
{
public :
NotFoundException(const std::string& message) : std::logic_error("Target not found: " + message)
{
}
}; // end NotFoundException
#endif
