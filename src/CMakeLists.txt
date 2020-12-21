tnt_project_AddLibrary(${PROJECT_NAME}
  TARGET
    ${PROJECT_NAME}
  SOURCES
    note.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE tnt::math)