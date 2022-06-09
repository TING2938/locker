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

namespace struct_json1
{
struct Person
{
    std::string name;
    std::string addr;
    int age;
};

void to_json(json& j, const Person& p)
{
    j = json{{"name", p.name}, {"addr", p.addr}, {"age", p.age}};
}

void from_json(const json& j, Person& p)
{
    j.at("name").get_to(p.name);
    j.at("addr").get_to(p.addr);
    j.at("age").get_to(p.age);
}
}  // namespace struct_json1

namespace struct_json2
{
struct Person
{
    std::string name;
    std::string addr;
    int age;

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Person, name, addr, age);
};

// NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Person, name, addr, age);
}  // namespace struct_json2

int main(int, char**)
{
    std::cout << "Hello, world!\n";
    test_json();


    struct_json2::Person p{"Name", "Addr", 15};
    json j = p;
    std::cout << j << std::endl;
    auto p2 = j.get<struct_json2::Person>();
    assert(p.name == p2.name);
}
