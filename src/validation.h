/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @module name: validation
 * @module desc: reusable and flexible functions that validates user input
 * ****************************************************************/

#ifndef VALIDATION
#define VALIDATION

#include <iostream>
#include <limits>
#include <functional>
#include "text_style.h"

using namespace std;

namespace validation
{
    /**
     * returns a valid value based on type and the parameter `is_valid`
     * Parameters:
     *  - `in`: an instance of `std::istream` like `std::cin`
     *  - `out`: an instance of `std::ostream` like `std::cout`
     *  - `prompt`:<string> message/prompt user to input
     *  - `err_msg`: error message to display when user inputs an invalid value
     *  - `is_valid`: a function to check if the captured value is valid.
     */
    template <typename T>
    T getValidInput(istream &in, ostream &out, string prompt, string err_msg, function<bool(T)> is_valid)
    {
        int n;
        out << prompt;
        in >> n;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!in.fail() && is_valid(n))
            return n;
        else
        {
            out << style::fg::red << err_msg << style::reset;
            if (in.fail())
            {
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            return getValidInput(in, out, prompt, err_msg, isValid);
        }
    }
}

#endif