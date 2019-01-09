/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_PEERS_H
#define ONE_PEERS_H

#include "api/base.h"
#include "api/one/one_paths.h"

namespace Phantom {
namespace Client {
namespace API {
namespace ONE {

class Peers : public API::Base
{
public:
  Peers(HTTP& http) : API::Base(http) { }

  std::string get(const char *const ip, const int port);
  std::string all(int limit = 5);
  std::string version();
};

};
};
};
};

#endif
