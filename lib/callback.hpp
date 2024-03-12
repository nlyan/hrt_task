#pragma once

namespace hrt_task
{

class Caller
{
public:
    template<typename Callable>
    void operator()(Callable&& call, int n)
    {
        call(1, 2, 3, n);
    }
};

} // namespace hrt_task