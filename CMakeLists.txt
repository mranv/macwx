cmake_minimum_required(VERSION 3.0)
project(YourProjectName)

# Find wxWidgets components
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})


include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/resource)
# Add your source files
set(SOURCES
        src/main.cpp
        src/frame.cpp
        src/taskbar.cpp
        src/resource_provider.cpp
        # Add other source files here
)

# Add the executable
add_executable(YourExecutableName ${SOURCES})

# Link against wxWidgets libraries
target_link_libraries(YourExecutableName ${wxWidgets_LIBRARIES})
