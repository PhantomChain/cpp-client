/**
 * This file is part of Phantom Cpp Client.
 *
 * (c) PhantomChain <info@phantom.org>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_API_H
#define ONE_API_H

#include "api/abstract.h"
#include "api/one/accounts/one_accounts.h"
#include "api/one/blocks/one_blocks.h"
#include "api/one/delegates/one_delegates.h"
#include "api/one/loader/one_loader.h"
#include "api/one/peers/one_peers.h"
#include "api/one/signatures/one_signatures.h"
#include "api/one/transactions/one_transactions.h"

namespace Phantom {
namespace Client {
namespace API {
/**/
class One : public API::Abstract
{
public:
  Phantom::Client::API::ONE::Accounts accounts;
  Phantom::Client::API::ONE::Blocks blocks;
  Phantom::Client::API::ONE::Delegates delegates;
  Phantom::Client::API::ONE::Loader loader;
  Phantom::Client::API::ONE::Peers peers;
  Phantom::Client::API::ONE::Signatures signatures;
  Phantom::Client::API::ONE::Transactions transactions;
        
  One() : Abstract(1), accounts(http_), blocks(http_), delegates(http_), loader(http_), peers(http_), signatures(http_), transactions(http_) { }
};
/**/
};
};
};

#endif
