# 源文件
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Declare the executable target built from your sources                        
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link your application with OpenCV libraries           
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# 安装
install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
