cmake_minimum_required(VERSION 3.10)
project(shadesmar)
SET(CMAKE_VERBOSE_MAKEFILE 1)

find_package(Boost)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-pthread -lstdc++fs")

add_compile_options(-O2)
add_compile_options(-DDEBUG_BUILD)

include_directories(include)

add_executable(publish src/publisher.cpp)
target_link_libraries(publish ${Boost_LIBRARIES} rt stdc++fs)

add_executable(subscribe src/subscriber.cpp)
target_link_libraries(subscribe ${Boost_LIBRARIES} rt stdc++fs)

add_executable(flush_topic src/flush_topic.cpp)
target_link_libraries(flush_topic ${Boost_LIBRARIES} rt stdc++fs)

add_executable(serialize_msg src/serialize_msg.cpp)
target_link_libraries(serialize_msg ${Boost_LIBRARIES} rt stdc++fs)

add_executable(benchmark src/benchmark.cpp)
target_link_libraries(benchmark ${Boost_LIBRARIES} rt stdc++fs)

add_executable(micro_bench src/micro_bench.cpp)
target_link_libraries(micro_bench ${Boost_LIBRARIES} rt stdc++fs)

add_executable(raw_benchmark src/raw_benchmark.cpp)
target_link_libraries(raw_benchmark ${Boost_LIBRARIES} rt stdc++fs)