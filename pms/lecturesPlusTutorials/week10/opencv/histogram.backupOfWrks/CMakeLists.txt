cmake_minimum_required(VERSION 2.8)
project( histogram )

find_package( OpenCV REQUIRED )

add_executable( histogram histogram.cpp )
target_link_libraries( histogram ${OpenCV_LIBS} )
