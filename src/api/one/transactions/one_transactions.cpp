
#include "api/one/transactions/one_transactions.h"

#include <cstdio>

/**
 * /api/transactions/get?id=
 **/
std::string Phantom::Client::API::ONE::Transactions::get(const char *const id)
{
  char uri[114 + 1] = { };
  snprintf(uri, sizeof(uri), "%s?id=%s", Phantom::Client::API::ONE::Paths::Transactions::get, id);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/transactions/?orderBy=timestamp:desc&limit=10"
 **/
std::string Phantom::Client::API::ONE::Transactions::all(
        int limit,
        const char *const orderBy,
        bool isDescending
) {
  char uri[64] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s?orderBy=%s:%s&limit=%d",
    Phantom::Client::API::ONE::Paths::Transactions::base,
    orderBy,
    isDescending ? "desc" : "asc",
    limit
  );
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/transactions/unconfirmed/get?id=
 **/
std::string Phantom::Client::API::ONE::Transactions::getUnconfirmed(const char *const id)
{
  char uri[126 + 1] = { };
  snprintf(uri, sizeof(uri), "%s?id=%s", Phantom::Client::API::ONE::Paths::Transactions::getUnconfirmed, id);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/transactions/unconfirmed
 **/
std::string Phantom::Client::API::ONE::Transactions::allUnconfirmed()
{
  return http_.get(Phantom::Client::API::ONE::Paths::Transactions::allUnconfirmed);
}
/**/
