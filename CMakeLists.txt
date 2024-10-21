cmake_minimum_required(VERSION 3.30)
project(BankMasterv3)

set(CMAKE_CXX_STANDARD 23)


include_directories(${PROJECT_SOURCE_DIR}/cpp-httplib)
include_directories(${PROJECT_SOURCE_DIR}/json)

find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)
if(OPENSSL_FOUND)
    set(HTTPLIB_IS_USING_OPENSSL TRUE)
endif()


include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)



add_executable(ServerExecutable Server.cpp)
add_executable(UserExecutable User.cpp)

target_link_libraries(UserExecutable PRIVATE CURL::libcurl)


