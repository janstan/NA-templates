#pragma once
#include <utility>
#include <cstddef>
template<typename T>
class container_wrapper{
public:
container_wrapper() = default;

container_wrapper(T arg): _value(std::move(arg))
{
}
container_wrapper(const container_wrapper &)=default;
container_wrapper(container_wrapper &&) = default;
container_wrapper & operator=(const container_wrapper &) = default;
container_wrapper & operator=(container_wrapper &&)=default;

std::size_t size() const
{
return _value.size();
}
private:
T _value;
};





template<typename T>
class container_wrapper<boost::optional<T>>
{
public:
container_wrapper() = default;

container_wrapper(boost::optional<T> arg): _value(std::move(arg))
{
}
container_wrapper(const container_wrapper &)=default;
container_wrapper(container_wrapper &&) = default;
container_wrapper & operator=(const container_wrapper &) = default;
container_wrapper & operator=(container_wrapper &&)=default;

std::size_t size() const
{
return _value ? 1:0;
}
private:
boost::optional<int> _value;
};

