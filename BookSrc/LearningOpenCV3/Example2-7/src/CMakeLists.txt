aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_FILES)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

install(TARGETS ${PROJECT_NAME}
   RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)
