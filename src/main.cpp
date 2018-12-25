#include <iostream>
#include <nlohmann/json.hpp>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    using json = nlohmann::json;

    // map 模式
    json j2 = {
        {"pi",      3.141},
        {"happy",   true},
        {"name",    "Niels"},
        {"nothing", nullptr},
        {
            "answer",  {
                {"everything", 42}
            }
        },
        {"list",    {       1, 0, 2}},
        {
            "object",  {
                {"currency",   "USD"},
                {"value", 42.99}
            }
        }
    };
    std::cout << j2 << std::endl;
    std::cout << j2.dump() << std::endl;
    std::cout << j2.dump(4) << std::endl;

    // 字符串模式
    json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
    std::cout << j << std::endl;

    // raw string
    auto j3 = R"(
      {
        "happy": true,
        "pi": 3.141
      }
    )"_json;
    std::cout << j3 << std::endl;

    // 动态解析
    auto j4 = json::parse("{ \"happy\": true, \"pi\": 3.141 }");
    std::cout << j4 << std::endl;

    // 空数组
    json empty_array_explicit = json::array();
    std::cout << empty_array_explicit << std::endl;

    // 空对象
    json empty_object_implicit = json({});
    std::cout << empty_object_implicit << std::endl;

    // 空对象
    json empty_object_explicit = json::object();
    std::cout << empty_object_explicit << std::endl;
    // 输出数组
    json array_not_object = json::array({ {"currency", "USD"}, {"value", 42.99} });
    std::cout << array_not_object << std::endl;


    json j5;

    j5["pi"] = 3.141;
    j5["happy"] = true;
    j5["name"] = "Niels";
    j5["nothing"] = nullptr;
    j5["answer"]["everything"] = 42;
    j5["list"] = { 1, 0, 2 };
    j5["object"] = { {"currency", "USD"}, {"value", 42.99} };


    if (j5["pi"] == 3.141) {
        std::cout << j5["pi"] << std::endl;
    }

    if (j5["happy"] == true) {
        std::cout << j5["happy"] << std::endl;
    }

    if (j5["name"] == "Niels") {
        std::cout << j5["name"] << std::endl;
    }

    if (j5["nothing"] == nullptr) {
        std::cout << j5["nothing"] << std::endl;
    }

    if (j5["answer"]["everything"] == 42) {
        std::cout << j5["answer"]["everything"] << std::endl;
    }


    if (j5["list"][0] == 1 ) {
        std::cout << j5["list"] << std::endl;
    }

    if (j5["object"]["value"] == 42.99) {
        std::cout << j5["object"] << std::endl;
    }


    // 获取 json value
    json j_string = "this is a string";
    auto cpp_string = j_string.get<std::string>();

    std::cout << cpp_string << std::endl;


    // 获取 json value
    std::string cpp_string2;
    j_string.get_to(cpp_string2);

    std::cout << cpp_string2 << std::endl;

    // 序列化
    std::string serialized_string = j_string.dump();

    std::cout << serialized_string << std::endl;

    std::cout << cpp_string << " == " << cpp_string2 << " == " << j_string.get<std::string>() << '\n';

    // 默认序列化
    std::cout << j_string << " == " << serialized_string << std::endl;


    return 0;
}