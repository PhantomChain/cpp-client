
#include "api/two/votes/two_votes.h"

#include <cstdint>
#include <cstdio>

std::string Phantom::Client::API::TWO::Votes::get(const char *const identifier)
{
  char uri[96] = { };
  snprintf(uri, sizeof(uri), "%s/%s", Phantom::Client::API::TWO::Paths::Votes::base, identifier);
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Votes::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Phantom::Client::API::TWO::Paths::Votes::base, limit, page);
  return http_.get(uri);
}
