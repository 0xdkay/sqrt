#include <cassert>
#include <cmath>
#include <iostream>
template<int x,int n=200>
struct const_sqrt
{
        static const double value = const_sqrt<x,n-1>::value/2 + x/(2*const_sqrt<x,n-1>::value);
};
template<int x>
struct const_sqrt<x,0>
{
        static const double value = 1;
};

int main()
{
        assert(std::abs(const_sqrt<1>::value - std::sqrt(1)) < 0.000000001);
        assert(std::abs(const_sqrt<2>::value - std::sqrt(2)) < 0.000000001);
        assert(std::abs(const_sqrt<10>::value - std::sqrt(10)) < 0.000000001);
        assert(std::abs(const_sqrt<47>::value - std::sqrt(47)) < 0.000000001);
        assert(std::abs(const_sqrt<4225>::value - std::sqrt(4225)) < 0.000000001);
        return 0;
}

