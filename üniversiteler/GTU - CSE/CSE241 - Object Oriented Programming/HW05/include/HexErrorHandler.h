/*
* Author: Muhammed Oguz

* This header represents a error class for Hex classes.

*/

#ifndef HEXERRORHANDLER_H
#define HEXERRORHANDLER_H

#include <exception>
#include <stdexcept>


namespace HexOguz
{
    class HexErrorHandler: public std::runtime_error
    {
        public:
        HexErrorHandler(std::string msg): std::runtime_error(msg)
        {}
    };
}

#endif // HEXERRORHANDLER_H