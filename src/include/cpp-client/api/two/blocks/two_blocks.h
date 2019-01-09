/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_BLOCKS_H
#define TWO_BLOCKS_H

#include "api/base.h"
#include "api/two/two_paths.h"

#include <string>
#include <map>

namespace Phantom {
namespace Client {
namespace API {
namespace TWO {

class Blocks : public API::Base
{
public:
  Blocks(HTTP& http) : API::Base(http) { }

  std::string get(const char *const blockId);
  std::string all(int limit = 5, int page = 1);
  std::string transactions(const char *const blockId);
  std::string search(const std::map<std::string, std::string>& bodyParameters, int limit = 5, int page = 1);
};

};
};
};
};

#endif
