/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef BASE_H
#define BASE_H

#include "http/http.h"

namespace Phantom {
namespace Client {
namespace API {
/**
 * Phantom::Client::API::Base 
 **/
class Base {
protected:
  HTTP& http_;

  Base(HTTP& http) : http_(http) { }
};
/**/
};
};
};

#endif
