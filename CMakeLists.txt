# project name
PROJECT(yolov5ncnn)
# requirement of cmake version
cmake_minimum_required(VERSION 3.5)

# set the directory of executable files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(OpenCV_DIR /home/yrc/opencvlib/lib/cmake/opencv4/)
message("opencv FOUND ")
set(ncnn_DIR /home/yrc/文档/ncnn/ncnn/build/install/lib/cmake/ncnn/)

# find required opencv
find_package(OpenCV 4.5.2 REQUIRED)
# find required ncnn
find_package(ncnn REQUIRED)

if(NOT TARGET ncnn)
    message(WARNING "ncnn NOT FOUND!  Please set ncnn_DIR environment variable")
else()
    message("ncnn FOUND ")
endif()


# directory of opencv ncnn headers
include_directories(${OpenCV_INCLUDE_DIRS}
                    ${ncnn_INCLUDE_DIRS})


# name of executable file and path of source file
add_executable(yolov5 src/YoloV5.cpp)

# directory of opencv ncnn library
link_directories(${OpenCV_LIBRARY_DIRS}
                ${ncnn_LIBRARY_DIRS})

# message("ncnn_INCLUDE_DIRS="${ncnn_INCLUDE_DIRS})
# message("ncnn_LIBRARY_DIRS="${ncnn_LIBRARY_DIRS})
# message("OpenCV_INCLUDE_DIRS="${OpenCV_INCLUDE_DIRS})
# message("OpenCV_LIBRARY_DIRS="${OpenCV_LIBRARY_DIRS})
# opencv libraries
target_link_libraries(yolov5 ncnn ${OpenCV_LIBS} )
