add_executable(03.1 main.cpp)

target_include_directories(03.1 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(03.1 PUBLIC cxx_std_17)
target_compile_definitions(03.1 PRIVATE SFML_STATIC)

target_link_libraries(03.1 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})