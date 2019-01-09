
#include "api/two/node/two_node.h"

std::string Phantom::Client::API::TWO::Node::configuration()
{
  return http_.get(Phantom::Client::API::TWO::Paths::Node::configuration);
}

/***/

std::string Phantom::Client::API::TWO::Node::status()
{
  return http_.get(Phantom::Client::API::TWO::Paths::Node::status);
}

/***/

std::string Phantom::Client::API::TWO::Node::syncing()
{
  return http_.get(Phantom::Client::API::TWO::Paths::Node::syncing);
} 
