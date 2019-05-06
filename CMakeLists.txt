cmake_minimum_required(VERSION 3.2)
project(espboard)

include(CMakeListsPrivate.txt)

add_custom_target(
    PLATFORMIO_BUILD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_target(
    PLATFORMIO_BUILD_AND_UPLOAD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload --upload-port=com5
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


add_executable(${PROJECT_NAME} ${SRC_LIST} src/main.cpp include/configuration.h include/Display.h include/Singleton.h src/Singleton.cpp include/Menu.h include/menu/MenuPoint.h src/Display.cpp src/menu/Menu.cpp include/Joystick.h src/Joystick.cpp include/menu/About.h src/menu/About.cpp)
