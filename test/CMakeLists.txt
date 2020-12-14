include(Catch)

add_executable(music_test
    # TODO: <files>
    main.cpp
)

target_link_libraries(music_test
    @namespace@::music
    Catch2::Catch2WithMain
)

gtest_discover_tests(music_test)