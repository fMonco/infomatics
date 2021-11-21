#include <iostream>
#include <algorithm>
#include <set>
 
std::set<std::string> set;
 
void foo(std::string& s, const int& d = 0) {
    if (d == 6) {
        std::swap(s[0], s[3]);
        set.insert(s);
        std::swap(s[0], s[3]);
        return;
    }
    for (int i(d); i < (d < 3 ? 3 : 6); ++i) {
        std::swap(s[d], s[i]);
        foo(s, d + 1);
        std::swap(s[d], s[i]);
    }
}
 
 
int main()
{
    std::string s;
    std::cin >> s;
 
    std::swap(s[0], s[3]);
    foo(s);
    std::cout << set.size() << '\n';
    for (auto& it : set) {
        std::cout << it << '\n';
    }
 
    return 0;
}