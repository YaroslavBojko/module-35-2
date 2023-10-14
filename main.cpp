#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

void print(std::vector<int> &vector)
{
    for (auto &i: vector)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}


int main() {
    std::vector<int> numbers =  {1, 3, 5, 1, 7, 2, 3, 4, 1, 6};
    print(numbers);

    auto lambda = [](std::vector<int>& v)
    {
        auto values = new std::unordered_set<int>();
        auto result = std::make_unique<std::vector<int>>();
        for (auto &i : v) {
            if (values->insert(i).second)
                result->push_back(i);
        }
        return result;
    };

    auto vector = lambda(numbers);
    print(*vector);

}
