/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <cstring>

/**/
/**/

#if (defined ARDUINO || defined ESP8266 || defined ESP32)

#define USE_IOT

// Including missing implementations of std::to_string
#include "stl/details/to_string.h"

/**/

#include <Arduino.h>
#include <pgmspace.h>

/**/
// undef the C macros to allow the C++ STL to take over
// This is to have compatibility with various board implementations of the STL
#undef min
#undef max
/**/

#endif

#endif
