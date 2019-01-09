/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_NODE_H
#define TWO_NODE_H

#include "api/base.h"
#include "api/two/two_paths.h"

namespace Phantom {
namespace Client {
namespace API {
namespace TWO {

class Node : public API::Base
{
public:
  Node(HTTP& http) : API::Base(http) { }

  std::string configuration();
  std::string status();
  std::string syncing();
};

};
};
};
};

#endif
