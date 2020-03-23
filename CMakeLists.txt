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
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


add_executable(${PROJECT_NAME} ${SRC_LIST} src/main.cpp include/IClass.h include/Joystick.h src/Joystick.cpp include/Display.h src/Display.cpp include/Page.h src/Page.cpp include/pages/HomePage.h src/pages/HomePage.cpp include/pages/Menu.h src/pages/Menu.cpp include/pages/Settings.h src/pages/Settings.cpp)
