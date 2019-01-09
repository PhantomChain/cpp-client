/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_LOADER_H
#define ONE_LOADER_H

#include "api/base.h"
#include "api/one/one_paths.h"
#include <string>

namespace Phantom {
namespace Client {
namespace API {
namespace ONE {

class Loader : public API::Base
{
public:
  Loader(HTTP& http) : API::Base(http) { }

  std::string autoconfigure();
  std::string status();
  std::string sync();
};

};
};
};
};

#endif
