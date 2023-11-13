cmake_minimum_required(VERSION 3.8)

set (This Data_Encryption_Tests)

set(Sources
    CaesarCipherTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Data_Encryption
)

add_test(
    NAME ${This}
    COMMAND ${This}
)