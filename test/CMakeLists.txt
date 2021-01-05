include(Catch)

add_executable(${PROJECT_NAME}_test
    main.cpp
    note_test.cpp
    xml_test.cpp
)

target_link_libraries(${PROJECT_NAME}_test
    tnt::${PROJECT_NAME}
    tnt::math
    Catch2::Catch2WithMain
)

catch_discover_tests(${PROJECT_NAME}_test)