################################################################################
cmake_minimum_required(VERSION 2.8) 		# Проверка версии CMake.
						# Если версия установ леной
						# программы старее указаной,
						# про-изайдёт аварийный выход.
project(BFSboost) 				# Название проекта
set(SOURCE_EXE main.cpp)
						# Установка переменной
						# со списком исходников
						# для исполняемого файла
################################################################################
set(CMAKE_BUILD_TYPE DEBUG)
set(MYLIB "-I/usr/local/lib")
set(MYINC "-I/usr/local/include")
if(APPLE)
set(ERRLIM "-ferror-limit=2")
set(MYCXXFLAGS " -fcxx-exceptions -Wno-c++11-extensions")
set(MYCMACROS "-DMACOS -D_DARWIN_C_SOURCE -D_POSIX_C_SOURCE=200809")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 ${ERRLIM} ${MYCMACROS} -DDEBUG=4 ${MYINC} ${MYLIB}")
set(CMAKE_C_FLAGS_RELEASE " -O2 ${ERRLIM} ${MYCMACROS} -DNDEBUG  ${MYINC} ${MYLIB}")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 ${ERRLIM} ${MYCMACROS} -DDEBUG=4 ${MYCXXFLAGS} ${MYINC} ${MYLIB}")
set(CMAKE_CXX_FLAGS_RELEASE " -O2 ${ERRLIM} ${MYCMACROS} -DNDEBUG  ${MYCXXFLAGS} ${MYINC} ${MYLIB}")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
set(MYCMACROS "-DLINUX -D_GNU_SOURCE -D_POSIX_C_SOURCE=200809")
set(CMAKE_C_FLAGS_DEBUG "-g -std=c99 -O0 ${MYCMACROS} -DDEBUG=4 ${MYINC} ${MYLIB}")
set(CMAKE_C_FLAGS_RELEASE " -std=c99 -O2 ${MYCMACROS} -DNDEBUG  ${MYINC} ${MYLIB}")
set(CMAKE_CXX_FLAGS_DEBUG "-g -std=c++11 -O0 ${MYCMACROS} -DDEBUG=4 ${MYINC} ${MYLIB}")
set(CMAKE_CXX_FLAGS_RELEASE " -std=c++11 -O2 ${MYCMACROS} -DNDEBUG  ${MYINC} ${MYLIB}")
elseif(UNIX)
set(MYCMACROS "-DUNIX -D_POSIX_C_SOURCE=200809")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 ${MYCMACROS} -DDEBUG=4 ${MYINC} ${MYLIB}")
set(CMAKE_C_FLAGS_RELEASE " -O2 ${MYCMACROS} -DNDEBUG  ${MYINC} ${MYLIB}")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 ${MYCMACROS} -DDEBUG=4 ${MYINC} ${MYLIB}")
set(CMAKE_CXX_FLAGS_RELEASE " -O2 ${MYCMACROS} -DNDEBUG  ${MYINC} ${MYLIB}")
elseif(WIN32)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -DWINDOWS -DDEBUG=4")
set(CMAKE_C_FLAGS_RELEASE " -O2 -DWINDOWS -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DWINDOWS -DDEBUG=4")
set(CMAKE_CXX_FLAGS_RELEASE " -O2 -DWINDOWS -DNDEBUG")
endif()
################################################################################
include_directories(include)
					# Тоже самое, но для
					# библиотеки
add_executable(BFSboost main.cpp)	# Создает исполняемый
					# файл с именем BFSboost
					# из исходника main.cpp
target_link_libraries(BFSboost pthread) # Линковка программы с библиотекой
################################################################################
