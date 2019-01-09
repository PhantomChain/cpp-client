
#include "api/one/loader/one_loader.h"

/**
 * /api/loader/autoconfigure
 **/
std::string Phantom::Client::API::ONE::Loader::autoconfigure()
{
  return http_.get(Phantom::Client::API::ONE::Paths::Loader::autoconfigure);
}
/**/

/***/

/**
 * /api/loader/status
 **/
std::string Phantom::Client::API::ONE::Loader::status()
{
  return http_.get(Phantom::Client::API::ONE::Paths::Loader::status);
}
/**/

/***/

/**
 * /api/loader/status/sync
 **/
std::string Phantom::Client::API::ONE::Loader::sync()
{
  return http_.get(Phantom::Client::API::ONE::Paths::Loader::sync);
}
/**/
