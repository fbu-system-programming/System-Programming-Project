cmake_minimum_required(VERSION 3.16)
project(student_information_system VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use pkg-config to find libpqxx
find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

include_directories(${PQXX_INCLUDE_DIRS} include)
link_directories(${PQXX_LIBRARY_DIRS})

add_library(sis_core
  src/db_config.cpp
  src/validation.cpp
  src/student_repo.cpp
)

target_include_directories(sis_core PUBLIC include)
target_link_libraries(sis_core PUBLIC ${PQXX_LIBRARIES})

add_executable(sis_app src/main.cpp)
target_link_libraries(sis_app PRIVATE sis_core)

# Put the app binary directly under build/
set_target_properties(sis_app PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

enable_testing()
add_executable(unit_validation tests/test_validation.cpp)
target_link_libraries(unit_validation PRIVATE sis_core)

# Put the test binary directly under build/
set_target_properties(unit_validation PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

add_test(NAME unit_validation COMMAND unit_validation)
