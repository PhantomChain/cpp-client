
#include "api/one/peers/one_peers.h"

#include <cstdio>

/**
 * /api/peers/get?ip=167.114.29.55&port=4002
 **/
std::string Phantom::Client::API::ONE::Peers::get(
    const char *const ip,
    const int port
) {
  char uri[68 + 1] = { };
  snprintf(uri, sizeof(uri), "%s?ip=%s&port=%d", Phantom::Client::API::ONE::Paths::Peers::get, ip, port);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/peers?limit=10
 **/
std::string Phantom::Client::API::ONE::Peers::all(int limit)
{
  char uri[24] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d", Phantom::Client::API::ONE::Paths::Peers::base, limit);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/peers/version
 **/
std::string Phantom::Client::API::ONE::Peers::version()
{
  return http_.get(Phantom::Client::API::ONE::Paths::Peers::version);
}
/**/
