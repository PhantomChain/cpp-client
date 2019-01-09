
#include "gtest/gtest.h"
#include "phantomClient.h"
#include "utils/json.h"

/* test_two_node_configuration
 * https://dexplorer.phantom.org:8443/api/v2/node/configuration
 * Expected Response:
    {
    "data": {
        "nethash": "string",
        "token": "string",
        "symbol": "string",
        "explorer": "string",
        "version": int,
        "ports": {
            "@phantomchain\/core-p2p": "int",
            "@phantomchain\/core-api": "int"
        },
        "constants": {
            "height": uint64_t,
            "reward": uint64_t,
            "activeDelegates": int,
            "blocktime": 8,
            "block": {
                "version": int,
                "maxTransactions": int,
                "maxPayload": int
            },
            "epoch": "string",
            "fees": {
                "dynamic": bool,
                "transfer": uint64_t,
                "secondSignature": uint64_t,
                "delegateRegistration": uint64_t,
                "vote": uint64_t,
                "multiSignature": uint64_t,
                "ipfs": int,
                "timelockTransfer": int,
                "multiPayment": int,
                "delegateResignation": int
            },
            "dynamicOffsets": {
                "transfer": int,
                "secondSignature": int,
                "delegateRegistration": int,
                "vote": int,
                "multiSignature": int,
                "ipfs": int,
                "timelockTransfer": int,
                "multiPayment": int,
                "delegateResignation": int
            }
        },
        "feeStatistics": [
        {
            "type": 0,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        },
        {
            "type": 3,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        },
        {
            "type": 1,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        },
        {
            "type": 2,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        },
        {
            "type": 4,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        }
        ]
    }
    }
*/
TEST(api, test_two_node_configuration)
{
    Phantom::Client::Connection<Phantom::Client::API::Two> connection("167.114.29.54", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto nodeConfiguration = connection.api.node.configuration();

    DynamicJsonBuffer jsonBuffer(nodeConfiguration.size());
    JsonObject& root = jsonBuffer.parseObject(nodeConfiguration);

    JsonObject& data = root["data"];

    const char* nethash = data["nethash"];
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", nethash);

    const char* token = data["token"];
    ASSERT_STREQ("DXPH", token);

    const char* symbol = data["symbol"];
    ASSERT_STREQ("Dⓟ", symbol);

    const char* explorer = data["explorer"];
    ASSERT_STREQ("https://dexplorer.phantom.org", explorer);

    int version = data["version"];
    ASSERT_EQ(30, version);


    JsonObject& ports = data["ports"];

    int core_p2p = ports["@phantomchain/core-p2p"];
    ASSERT_EQ(4002, core_p2p);

    int core_api = ports["@phantomchain/core-api"];
    ASSERT_EQ(4003, core_api);
}

/* test_two_node_status
 * https://dexplorer.phantom.org:8443/api/v2/node/status
 * Expected Response:
    {
        "data": {
            "synced": bool,
            "now": int,
            "blocksCount": int
        }
    }
 */
TEST(api, test_two_node_status)
{
    Phantom::Client::Connection<Phantom::Client::API::Two> connection("167.114.29.54", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto nodeStatus = connection.api.node.status();

    DynamicJsonBuffer jsonBuffer(nodeStatus.size());
    JsonObject& root = jsonBuffer.parseObject(nodeStatus);

    JsonObject& data = root["data"];

    bool synced = data["synced"];
    ASSERT_TRUE(synced || !synced);

    int now = data["now"];
    ASSERT_GE(now, 0);

    const char* blocksCount = data["blocksCount"];
    ASSERT_STRNE("", blocksCount);
}

/* test_two_node_status
 * 167.114.29.54:4003/api/v2/node/syncing
 * Expected Response:
    {
    "data": {
        "syncing": bool,
        "blocks": int,
        "height": uint64_t,
        "id": "string"
    }
    }
 */
TEST(api, test_two_node_syncing)
{
    Phantom::Client::Connection<Phantom::Client::API::Two> connection("167.114.29.54", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto nodeSyncing = connection.api.node.syncing();

    DynamicJsonBuffer jsonBuffer(nodeSyncing.size());
    JsonObject& root = jsonBuffer.parseObject(nodeSyncing);

    JsonObject& data = root["data"];

    bool syncing = data["syncing"];
    ASSERT_TRUE(syncing || !syncing);

    const char* blocks = data["blocks"];
    ASSERT_STRNE("", blocks);

    uint64_t height = data["height"];
    ASSERT_TRUE(height >= 0);

    const char* id = data["id"];
    ASSERT_STRNE("", id);
}
