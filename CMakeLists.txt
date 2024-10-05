cmake_minimum_required(VERSION 3.26)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

add_compile_options(
	-Werror
	-Wall
	-Wextra
	-Wpedantic
	-Wcast-align
	-Wcast-qual
	-Wconversion
	-Wctor-dtor-privacy
	-Wenum-compare
	# -Wfloat-equal
	-Wnon-virtual-dtor
	-Wold-style-cast
	-Woverloaded-virtual
	-Wredundant-decls
	-Wsign-conversion
	-Wsign-promo
)

project(MyBinarySearch)			# Название проекта

option(MYLIB_TESTING "Включить модульное тестирование" ON)

option(MYLIB_DOC "Сгенерировать документацию" ON)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} STATIC)

set(SOURCE_EXE src/MyBinarySearch.cc)		# Установка переменной со списком исходников для исполняемого файла

target_sources(${PROJECT_NAME}
    PRIVATE
	${SOURCE_EXE}
)

if(NOT MYLIB_TESTING)
    message(STATUS "Тестирование проекта выключено")
else()
    add_subdirectory(tests)
endif()

if(NOT MYLIB_DOC)
    message(STATUS "Генерация документации выключена")
else()
    add_subdirectory(docs)
endif()
