include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

# If pkg-config is not installed on the system, then the
# CHECK_INSTALL_DIR variable must be set to the install
# location of Check. For example, on Windows, this may
# be: C:/Program Files/check
# set(CHECK_INSTALL_DIR "C:/MinGW/lib64")

find_package(Check REQUIRED)
#set(CHECK_INCLUDE_DIRS "C:/MinGW/include")
#set(CHECK_LIBRARY_DIRS "C:/MinGW/lib64")
#set(CHECK_LIBRARIES "${CHECK_LIBRARY_DIRS}/libcheck.dll.a")

include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

set(TEST_SOURCES
  check_filter.c
)

add_executable(check_filter ${TEST_SOURCES})
target_link_libraries(check_filter filter ${CHECK_LIBRARIES})
set_target_properties(check_filter PROPERTIES C_STANDARD 11)
