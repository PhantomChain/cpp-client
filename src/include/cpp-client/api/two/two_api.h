/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_API_H
#define TWO_API_H

#include "api/abstract.h"
#include "api/two/blocks/two_blocks.h"
#include "api/two/delegates/two_delegates.h"
#include "api/two/node/two_node.h"
#include "api/two/peers/two_peers.h"
#include "api/two/transactions/two_transactions.h"
#include "api/two/votes/two_votes.h"
#include "api/two/wallets/two_wallets.h"

namespace Phantom {
namespace Client {
namespace API {
/***/
class Two : public API::Abstract
{
public:
  Phantom::Client::API::TWO::Blocks blocks;
  Phantom::Client::API::TWO::Delegates delegates;
  Phantom::Client::API::TWO::Node node;
  Phantom::Client::API::TWO::Peers peers;
  Phantom::Client::API::TWO::Transactions transactions;
  Phantom::Client::API::TWO::Votes votes;
  Phantom::Client::API::TWO::Wallets wallets;

  Two() : Abstract(2), blocks(http_), delegates(http_), node(http_), peers(http_), transactions(http_), votes(http_), wallets(http_) { }
};
/***/
}
}
}

#endif
