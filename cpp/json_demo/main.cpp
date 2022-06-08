#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

void test_json()
{
    json j = {
        {"pi", 3.14},
        {"happy", true},
        {"list", {1, 3, 6}},
    };

    std::cout << "j: " << j << std::endl;

    auto j3 = json::parse(R"(
    {
        "happy": true,
        "list": [
            1,
            3,
            6
        ],
        "pi": 3.14
    }
    )");

    auto list = j3["list"].get<std::vector<int>>();
    for (auto&& l : list) {
        std::cout << l << std::endl;
    }

    std::ifstream fid("/home/yeting/work/project/SA_gRPC/configData/config.json");
    json j4;
    fid >> j4;
    fid.close();

    std::cout << "j4: " << j4.dump(4) << std::endl;
    std::cout << j4["AI_application_list"] << std::endl;
}


int main(int, char**)
{
    std::cout << "Hello, world!\n";
    test_json();
}
