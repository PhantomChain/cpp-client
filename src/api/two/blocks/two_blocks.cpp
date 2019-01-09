
#include "api/two/blocks/two_blocks.h"

#include <cstdio>

std::string Phantom::Client::API::TWO::Blocks::get(const char *const blockId)
{
  char uri[80] = { };
  snprintf(uri, sizeof(uri), "%s/%s", Phantom::Client::API::TWO::Paths::Blocks::base, blockId);
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Blocks::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[256] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Phantom::Client::API::TWO::Paths::Blocks::base, limit, page);
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Blocks::transactions(const char *const blockId)
{
  char uri[256] = {  };
  snprintf(uri, sizeof(uri), "%s/%s/transactions", Phantom::Client::API::TWO::Paths::Blocks::base, blockId);
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Blocks::search(
  const std::map<std::string, std::string>& bodyParameters,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[96] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Phantom::Client::API::TWO::Paths::Blocks::search, limit, page);
  std::string parameterBuffer;
  for (const auto& p : bodyParameters) {
    parameterBuffer += p.first + '=' + p.second + '&';
  }
  return http_.post(uri, parameterBuffer.c_str());
}
