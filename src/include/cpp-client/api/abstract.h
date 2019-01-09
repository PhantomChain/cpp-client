/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ABSTRACT_H
#define ABSTRACT_H

#include "http/http.h"

namespace Phantom {
namespace Client {
namespace API {

/**
 * Phantom::Client::API::Abstract
 **/
class Abstract {
protected:
  HTTP http_;
  int version_;

  Abstract(int version) : version_(version) { }

public:
  int version() const noexcept { return this->version_; }
  const char* host() const noexcept { return http_.host(); };
  int port() const noexcept { return http_.port(); };

  void setHost(const char *const newHost, int newPort) {
    http_.setHostHTTP(newHost, newPort, version_);
  }
};
/**/
};
};
};

#endif
