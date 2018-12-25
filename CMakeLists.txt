cmake_minimum_required(VERSION 3.13)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.23.33.tar.gz"
        SHA1 "acbf4b9b77b5a0160adc1da1cdda35f64b14196a"
)


project(nlohmann_json_examples)

set(CMAKE_CXX_STANDARD 14)


hunter_add_package(Boost COMPONENTS regex system filesystem)
find_package(Boost CONFIG REQUIRED regex system filesystem)

hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

#find_package(nlohmann_json 3.2.0 REQUIRED)



add_executable(nlohmann_json_examples src/main.cpp)

target_link_libraries(nlohmann_json_examples PUBLIC nlohmann_json::nlohmann_json Boost::regex Boost::system Boost::filesystem)