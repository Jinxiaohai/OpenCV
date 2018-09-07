# 添加文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRCFILES)
file(GLOB HEADFILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

# 进行MOC编译
qt5_wrap_cpp(HEAD_FILES ${HEADFILES})

# 添加可执行文件的生成
add_executable(${PROJECT_NAME} ${SRCFILES} ${HEAD_FILES})
target_link_libraries(${PROJECT_NAME}
  ${ROOT_LIBRARIES}
  ${OpenCV_LIBS}
  ${Boost_LIBRARIES}
  ${Qt5Core_LIBRARIES}
  ${Qt5Gui_LIBRARIES}
  ${Qt5Widgets_LIBRARIES}
  ${Qt5Network}
  ${Qt5OpenGL}
  ${Qt53DCore}
  ${Qt5PrintSupport}
  ${Qt5WebEngine}
  ${Qt5Xml})

# 设置依赖
set_property(TARGET ${PROJECT_NAME} PROPERTY INSTALL_RPATH_USE_LINK_PATH TRUE)

# 安装
install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin)
# install(TARGETS ${PROJECT_NAME}
#   LIBRARY DESTINATION lib)
