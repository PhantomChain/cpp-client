
#include "gtest/gtest.h"
#include "phantomClient.h"

TEST(api, test_connection)
{
    Phantom::Client::Connection<Phantom::Client::API::One> oneConnection("5.196.105.32", 4003);
    int oneVersion = oneConnection.api.version();
    ASSERT_EQ(1, oneVersion);

    const char* oneHost = oneConnection.host();
    ASSERT_STREQ("5.196.105.32", oneHost);

    int onePort = oneConnection.port();
    ASSERT_EQ(4003, onePort);


    Phantom::Client::Connection<Phantom::Client::API::Two> twoConnection("167.114.29.55", 4003);
    int twoVersion = twoConnection.api.version();
    ASSERT_EQ(2, twoVersion);

    const char* twoHost = twoConnection.host();
    ASSERT_STREQ("167.114.29.55", twoHost);

    int twoPort = twoConnection.port();
    ASSERT_EQ(4003, twoPort);
}
