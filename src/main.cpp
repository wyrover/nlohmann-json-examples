#include <iostream>
#include <nlohmann/json.hpp>
#include <chrono>



inline uint64_t unixtime_ms()
{
    return (std::chrono::system_clock::now().time_since_epoch()
            / std::chrono::milliseconds(1));
}

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

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // C++ 14
    for (auto& el: j2.items()) {
        std::cout << el.key() << " : " << el.value() << std::endl;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // C++ 17
//    for (auto& [key, value]: j2.items()) {
//        std::cout << key << " : " << value << std::endl;
//    }


    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    for (json::iterator it = j2.begin(); it != j2.end(); ++it) {
        std::cout << it.key() << " : " << it.value() << std::endl;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

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


    // 显式类型转换
    std::cout << "显式类型转换" << std::endl;
    std::cout << j5["pi"].get<double>() << std::endl;
    std::cout << j5["happy"].get<bool>() << std::endl;



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




    // a JSON value
    json j_original = R"({
      "baz": ["one", "two", "three"],
      "foo": "bar"
    })"_json;

    // access members with a JSON pointer (RFC 6901)
    std::cout << j_original["/baz/1"_json_pointer] << std::endl;
    // "two"


    // a JSON patch (RFC 6902)
    json j_patch = R"([
      { "op": "replace", "path": "/baz", "value": "boo" },
      { "op": "add", "path": "/hello", "value": ["world"] },
      { "op": "remove", "path": "/foo"}
    ])"_json;

    // apply the patch
    json j_result = j_original.patch(j_patch);

    std::cout << j_result << std::endl;

    std::cout << json::diff(j_result, j_original) << std::endl;




    json period = json::array({
                                      {9, 0, 10, 15},
                                      {10, 30, 11, 30},
                                      {13, 30, 15, 0}
                              });


    std::cout << period << std::endl;

    std::cout << unixtime_ms() << std::endl;


    json nperiod = json::array({
                                       {{"AU", "AG", "sc"},
                                               {21, 0, 02, 30}},
                                       {{"CU", "AL", "ZN", "PB", "SN", "NI"},
                                               {21, 0, 01, 0}},
                                       {{"RU", "RB", "HC", "BU"},
                                               {21, 0, 23, 0}},
                                       {{"P", "J", "M", "Y", "A", "B", "JM", "I"},
                                               {21, 0, 23, 30}},
                                       {{"SR", "CF", "RM", "MA", "TA", "ZC", "FG", "OI"},
                                               {21, 0, 23, 30}},
                               });


    //std::cout << nperiod.dump(4) << std::endl;

    std::cout << nperiod.size() << std::endl;


    for (size_t i = 0; i < nperiod.size(); ++i) {

        std::cout << nperiod[i] << std::endl;

    }


    return 0;
}