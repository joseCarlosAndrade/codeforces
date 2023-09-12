find_package( OpenCV REQUIRED)

include_directories( ${OpenCV_INCLUDE_DIRS})

add_executable( imageBasics example.cpp)

target_link_libraries(imageBasics ${OpenCV_LIBS})