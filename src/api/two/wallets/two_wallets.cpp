
#include "api/two/wallets/two_wallets.h"

#include <cstdio>

std::string Phantom::Client::API::TWO::Wallets::get(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s/%s?limit=%d&page=%d", Phantom::Client::API::TWO::Paths::Wallets::base, identifier, limit, page);
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Wallets::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Phantom::Client::API::TWO::Paths::Wallets::base, limit, page);
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Wallets::top(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Phantom::Client::API::TWO::Paths::Wallets::top, limit, page);
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Wallets::transactions(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s/%s/transactions?limit=%d&page=%d",
    Phantom::Client::API::TWO::Paths::Wallets::base,
    identifier,
    limit,
    page
  );
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Wallets::transactionsSent(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s/%s/transactions/sent?limit=%d&page=%d",
    Phantom::Client::API::TWO::Paths::Wallets::base,
    identifier,
    limit,
    page
  );
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Wallets::transactionsReceived(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s/%s/transactions/received?limit=%d&page=%d",
    Phantom::Client::API::TWO::Paths::Wallets::base,
    identifier,
    limit,
    page
  );
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Wallets::votes(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s/%s/votes?limit=%d&page=%d",
    Phantom::Client::API::TWO::Paths::Wallets::base,
    identifier,
    limit,
    page
  );
  return http_.get(uri);
}

/***/

std::string Phantom::Client::API::TWO::Wallets::search(
  const std::map<std::string, std::string>& bodyParameters,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[96] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s?limit=%d&page=%d",
    Phantom::Client::API::TWO::Paths::Wallets::search,
    limit,
    page
  );
  std::string parameterBuffer;
  for (const auto& p : bodyParameters) {
    parameterBuffer += p.first + '=' + p.second + '&';
  }
  return http_.post(uri, parameterBuffer.c_str());
}
