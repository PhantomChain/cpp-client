/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_VOTES_H
#define TWO_VOTES_H

#include "api/base.h"
#include "api/two/two_paths.h"

namespace Phantom {
namespace Client {
namespace API {
namespace TWO {

class Votes : public API::Base
{
public:
  Votes(HTTP& http) : API::Base(http) { }

  std::string get(const char *const identifier);
  std::string all(int limit = 5, int page = 1);
};

};
};
};
};

#endif
