# 添加源文件
set(SRCFILES EigenFace.cpp  
  )

# 添加头文件
set(HEADFILES dirent.h  
  )

# 添加可执行文件的生成
add_executable(${PROJECT_NAME} ${SRCFILES} ${HEADFILES})
target_link_libraries(${PROJECT_NAME}
  ${ROOT_LIBRARIES}
  ${OpenCV_LIBS}
  ${Boost_LIBRARIES}
  ${Qt5Core_LIBRARIES}
  ${Qt5Gui_LIBRARIES}
  ${Qt5Widgets_LIBRARIES}
  ${Qt5Network_LIBRARIES}
  ${Qt5OpenGL_LIBRARIES}
  ${Qt53DCore_LIBRARIES}
  ${Qt5PrintSupport_LIBRARIES}
  ${Qt5WebEngine_LIBRARIES}
  ${Qt5Xml_LIBRARIES})

# 安装
install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin)
# install(TARGETS ${PROJECT_NAME}
#   LIBRARY DESTINATION lib)
