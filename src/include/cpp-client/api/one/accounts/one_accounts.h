/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_ACCOUNTS_H
#define ONE_ACCOUNTS_H

#include "http/http.h"
#include "api/base.h"
#include "api/one/one_paths.h"
#include <string>

namespace Phantom {
namespace Client {
namespace API {
namespace ONE {

class Accounts : public API::Base
{
public:
  Accounts(HTTP& http) : API::Base(http) { }

  std::string balance(const char *const phantomAddress);
  std::string publickey(const char *const phantomAddress);
  std::string delegatesFee(const char *const phantomAddress);
  std::string delegates(const char *const phantomAddress);
  std::string get(const char *const phantomAddress);
};

};
};
};
};

#endif
