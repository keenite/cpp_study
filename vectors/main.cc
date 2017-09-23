#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

static inline std::vector<char> string2vector(std::string str) {
    auto v = std::vector<char>(str.begin(), str.end());
    v.push_back('\0');
    return v;
}

int main()
{
    string str="This is a string";

    //Iterate from the beginning to the end, str.begin() and str.end() are both
    //potiner
    auto vstr = vector<char>(str.begin(), str.end());
    cout << "vstr:" << vstr.data() << '\n';
    cout << "str.begin()=" << *str.begin() << '\n';
    cout << "str.end() - 1=" << *(str.end() - 1) << '\n';

    cout << "---------------------------------------------------"<< '\n';
    std::vector<int> v = {0, 1, 2, 3, 4, 5};
    for (const int& i : v) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';

    for (auto i : v) // access by value, the type of i is int
        std::cout << i << ' ';
    std::cout << '\n';

    for (auto&& i : v) // access by forwarding reference, the type of i is int&
        std::cout << i << ' ';
    std::cout << '\n';

    const auto& cv = v;

    for (auto&& i : cv) // access by f-d reference, the type of i is const int&
        std::cout << i << ' ';
    std::cout << '\n';

    for (int n : {0, 1, 2, 3, 4, 5}) // the initializer may be a braced-init-list
        std::cout << n << ' ';
    std::cout << '\n';

    int a[] = {0, 1, 2, 3, 4, 5};
    for (int n : a) // the initializer may be an array
        std::cout << n << ' ';
    std::cout << '\n';

    for (int n : a)
        std::cout << 1 << ' '; // the loop variable need not be used
    std::cout << '\n';

    cout << "---------------------------------------------------"<< '\n';

    std::vector<std::vector<char>> args {
        string2vector(string("ceph")),
        string2vector("-c"), string2vector(string("ms_dpdk_coremask-val")),
        string2vector("-n"), string2vector(string("ms_dpdk_channel-val")),
    };
    //&& means right value reference
    for (auto&& a: args) {
        std::cout << "Content:" << a.data() << '\n';
    }
    return 0;
}
