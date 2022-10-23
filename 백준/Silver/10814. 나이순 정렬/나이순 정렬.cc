#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

bool cmp(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
	return a.first < b.first;
}

int main()
{
    int N;
    
    std::cin >> N;
    
    std::vector<std::pair<int, std::string>> members;
    
    for (int i = 0; i < N; i++)
    {
        int age;
        std::string name;
        std::cin >> age >> name;
        
        members.push_back({age, name});
    }
    
    stable_sort(members.begin(), members.end(), cmp);

    for(auto mem : members)
    {
        std::cout << mem.first << " " << mem.second << '\n';
    }
}