#include <catch2/catch_all.hpp>
#include <fakeit.hpp>

#include <callback.hpp>

using namespace fakeit;
using namespace hrt_task;

struct CallbackMock
{
    virtual void operator()(int a, int b, int c, int d) = 0;
};

TEST_CASE("Simple callback test", "[Callback]")
{
    Caller cb;
    Mock<CallbackMock> callback;

    When(Method(callback, operator())).Do([](int a, int b, int c, int d)
    {
        REQUIRE(a == 1);
        REQUIRE(b == 2);
        REQUIRE(c == 3);
        REQUIRE(d == 4);
    });

    cb(callback.get(), 4);
    Verify(Method(callback, operator())).Once();
}
