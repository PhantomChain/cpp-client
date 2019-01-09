
#include "gtest/gtest.h"
#include "phantomClient.h"
#include "utils/json.h"

TEST(api, test_one_signature_fees)
{
    Phantom::Client::Connection<Phantom::Client::API::One> connection("5.196.105.32", 4003);

    const auto signaturesFeeResponse = connection.api.signatures.fee();

    DynamicJsonBuffer jsonBuffer(signaturesFeeResponse.size());
    JsonObject& root = jsonBuffer.parseObject(signaturesFeeResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    uint64_t signaturesFee = root["fee"];
    ASSERT_TRUE(signaturesFee == 500000000);
}
