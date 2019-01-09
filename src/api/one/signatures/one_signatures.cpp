
#include "api/one/signatures/one_signatures.h"

/**
 * /api/signatures/fee
 **/
std::string Phantom::Client::API::ONE::Signatures::fee()
{
  return http_.get(Phantom::Client::API::ONE::Paths::Signatures::fee);
}
/**/
