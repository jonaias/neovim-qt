
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

set(GUI_SOURCES main.cpp basegui.cpp gui.cpp windowwidget.cpp basewindow.cpp)
add_executable(neovim-gui ${GUI_SOURCES})
target_link_libraries(neovim-gui Qt5::Widgets Qt5::Network ${MSGPACK_LIBRARIES} neovim-qt)


