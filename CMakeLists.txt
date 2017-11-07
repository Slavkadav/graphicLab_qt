cmake_minimum_required(VERSION 3.8)
project(Graphic_lab_2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH /home/dev/Qt5.9.1/5.9.1/gcc_64/lib/cmake)

set(SOURCE_FILES main.cpp AffinTranslate/AffineTranslate.cpp AffinTranslate/AffineTranslate.h CatAndMouse.cpp CatAndMouse.h Figures/Mouse/Mouse.cpp Figures/Mouse/Mouse.h Figures/Figure.cpp Figures/Figure.h Figures/Cat/Cat.cpp Figures/Cat/Cat.h AffinTranslate/TransformMatrix.cpp AffinTranslate/TransformMatrix.h)
add_executable(Graphic_lab_2 ${SOURCE_FILES})

# включаем поиск библиотек с использованием find_package()
# через REQUIRED указываем, что библиотеки обязательны
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

# указываем, какие библиотеки необходимо подключить
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)