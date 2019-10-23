cmake_minimum_required(VERSION 3.2)
project(espboard)

include(CMakeListsPrivate.txt)
include_directories(.piolibdeps/ESP8266_SSD1306_ID562/src)

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


add_executable(${PROJECT_NAME} ${SRC_LIST} src/main.cpp include/configuration.h include/Joystick.h src/Joystick.cpp include/UI/PageInterface.h include/Display.h include/UI/Drawable.h include/UI/Text.h src/Display.cpp src/UI/Text.cpp include/Page/MainPage.h)
