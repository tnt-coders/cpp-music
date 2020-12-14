tnt_project_AddLibrary(${PROJECT_NAME}
  TARGET
    music
  SOURCES
    music.cpp
)

target_compile_features(music PUBLIC cxx_std_17)