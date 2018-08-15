# Declare the executable target built from your sources                        
add_executable(at.exe ${CMAKE_CURRENT_SOURCE_DIR}/at.cpp)
# Link your application with OpenCV libraries           
target_link_libraries(at.exe ${OpenCV_LIBS})

# Declare the executable target built from your sources                        
add_executable(iter.exe ${CMAKE_CURRENT_SOURCE_DIR}/iter.cpp)
# Link your application with OpenCV libraries           
target_link_libraries(iter.exe ${OpenCV_LIBS})

# Declare the executable target built from your sources                        
add_executable(ptr.exe ${CMAKE_CURRENT_SOURCE_DIR}/ptr.cpp)
# Link your application with OpenCV libraries           
target_link_libraries(ptr.exe ${OpenCV_LIBS})


# 安装
install(TARGETS at.exe iter.exe ptr.exe
  RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
