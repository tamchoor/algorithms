
# clang++ -std=c++17 binarySearchTect.cc -lgtest -lgmock -pthread

project(binarySearchTest)

set(SOURCE_EXE binarySearchTest.cc)

add_executable(${PROJECT_NAME} ${SOURCE_EXE})

set(GTEST_PATH /opt/homebrew/Cellar/googletest/1.13.0)

include_directories(${GTEST_PATH}/include/)

target_link_libraries(${PROJECT_NAME}
					${GTEST_PATH}/lib/libgtest.a
					${GTEST_PATH}/lib/libgtest_main.a
					${CMAKE_BINARY_DIR}/libMyBinarySearch.a
					)
					

set (CMAKE_THREAD_LIBS_INIT "-lpthread")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set (CMAKE HAVE THREADS LIBRARY 1)
set (CMAKE USE PTHREADS_ INIT 1)
set (THREADS_ PREFER_ PTHREAD_FLAG ON)

add_custom_target(check ALL COMMAND ${PROJECT_NAME})
