#include <iostream>
#include <coroutine>

// https://hsiaofongw.notion.site/C-Coroutine-68692896052a4a1296ee98150e5e7f89

struct generator
{
    struct promise_type
    {
        void return_void() {}

        std::suspend_always initial_suspend()
        {
            return {};
        }

        std::suspend_always final_suspend() noexcept
        {
            return {};
        }

        std::suspend_always yield_value(const int &value)
        {
            valuePtr = std::addressof(value);
            return {};
        }

        generator get_return_object()
        {
            return {handle_type::from_promise(*this)};
        }

        void unhandled_exception()
        {
            std::terminate();
        }

        const int *valuePtr;
    };

    using handle_type = std::coroutine_handle<promise_type>;

    handle_type handle;

    generator(handle_type h) : handle(h) {}

    ~generator()
    {
        if (handle)
        {
            handle.destroy();
        }
    }

    struct iterator
    {
        handle_type h_;
        iterator(handle_type h) : h_(h) {}
        iterator() = default;

        bool operator==(const iterator &) const
        {
            if (h_ && h_.done())
            {
                return true;
            }
            return false;
        }

        iterator &operator++()
        {
            if (h_ && !h_.done())
            {
                h_.resume();
            }
            return *this;
        }
        iterator &operator++(int) = delete;

        int operator*() const
        {
            if (h_)
            {
                auto valPtr = h_.promise().valuePtr;
                if (valPtr)
                {
                    return *valPtr;
                }
            }
        }
        int operator->() const = delete;
    };

    iterator begin()
    {
        handle.resume();
        return {handle};
    }
    iterator end()
    {
        return {};
    }
};

generator my_range(int x)
{
    for (int i = 0; i < 10; i++)
    {
        co_yield x;
        ++x;
    }
}

int main(int, char **)
{
    std::cout << "Hello, from coroutine_demo!\n";

    for (auto x : my_range(0))
    {
        std::cout << x << std::endl;
    }
}
