
#include "api/one/accounts/one_accounts.h"

#include <cstdio>

/**
 * /api/accounts/getBalance?address=phantomAddress
 **/
std::string Phantom::Client::API::ONE::Accounts::balance(const char *const phantomAddress)
{
  char uri[68 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Phantom::Client::API::ONE::Paths::Accounts::balance, phantomAddress);
  return http_.get(uri);
}
/**/

/***/

/**
 * api/accounts/getPublickey?address=phantomAddress
 **/
std::string Phantom::Client::API::ONE::Accounts::publickey(const char *const phantomAddress)
{
  char uri[94 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Phantom::Client::API::ONE::Paths::Accounts::publicKey, phantomAddress);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/accounts/delegates/fee?address=phantomAddress
 **/
std::string Phantom::Client::API::ONE::Accounts::delegatesFee(const char *const phantomAddress)
{
  char uri[95 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Phantom::Client::API::ONE::Paths::Accounts::delegatesFee, phantomAddress);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/accounts/delegates?address=phantomAddress
 **/
std::string Phantom::Client::API::ONE::Accounts::delegates(const char *const phantomAddress)
{
  char uri[91 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Phantom::Client::API::ONE::Paths::Accounts::delegates, phantomAddress);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/accounts?address=phantomAddress
 **/
std::string Phantom::Client::API::ONE::Accounts::get(
    const char *const phantomAddress
) {
  char uri[81 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Phantom::Client::API::ONE::Paths::Accounts::base, phantomAddress);
  return http_.get(uri);
}
/**/
