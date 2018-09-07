# 设定需要的CMake的最小版本
cmake_minimum_required(VERSION 2.8.11)

# 设定项目的名字
project(EigenFace)

# 一些设定
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 一些设定
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC OFF)
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC OFF)
set(CMAKE_CXX_STANDARD 11)

# 查找需要的Qt模块
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt53DCore REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Qt5WebEngine REQUIRED)
find_package(Qt5Xml REQUIRED)
if(Qt5Widgets_FOUND AND Qt5Core_FOUND AND Qt5Gui_FOUND AND Qt5Network_FOUND AND Qt5OpenGL_FOUND AND Qt53DCore_FOUND AND Qt5PrintSupport_FOUND AND Qt5WebEngine_FOUND AND Qt5Xml_FOUND)
  message(STATUS "查找到Qt: ${Qt5Core_VERSION_STRING}" )
else(Qt5Widgets_FOUND AND Qt5Core_FOUND AND Qt5Gui_FOUND AND Qt5Network_FOUND AND Qt5OpenGL_FOUND AND Qt53DCore_FOUND AND Qt5PrintSupport_FOUND AND Qt5WebEngine_FOUND AND Qt5Xml_FOUND)
  message(WARNING "未查找Qt" )
endif(Qt5Widgets_FOUND AND Qt5Core_FOUND AND Qt5Gui_FOUND AND Qt5Network_FOUND AND Qt5OpenGL_FOUND AND Qt53DCore_FOUND AND Qt5PrintSupport_FOUND AND Qt5WebEngine_FOUND AND Qt5Xml_FOUND)
  
# 查找需要的ROOT模块
find_package(ROOT REQUIRED)
if(ROOT_FOUND)
  message(STATUS "查找到ROOT: ${ROOT_VERSION}")
else(ROOT_FOUND)
  message(WARNING "未查找到ROOT")
endif(ROOT_FOUND)

# 查找需要的OpenCV模块
find_package(OpenCV REQUIRED)

# 查找需要的Boost模块
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

################################################################################
# 添加子目录
add_subdirectory(src)


################################################################################
# 安装
install(FILES LICENSE README.md
  DESTINATION doc)
install(DIRECTORY doc/
  DESTINATION doc)
# install(PROGRAMS test.py
#   DESTINATION bin)
