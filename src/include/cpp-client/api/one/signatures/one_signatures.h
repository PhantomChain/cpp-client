/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_SIGNATURES_H
#define ONE_SIGNATURES_H

#include "api/base.h"
#include "api/one/one_paths.h"
#include <string>

namespace Phantom {
namespace Client {
namespace API {
namespace ONE {

class Signatures : public API::Base
{
public:
  Signatures(HTTP& http) : API::Base(http) { }

  std::string fee();
};

};
};
};
};

#endif
