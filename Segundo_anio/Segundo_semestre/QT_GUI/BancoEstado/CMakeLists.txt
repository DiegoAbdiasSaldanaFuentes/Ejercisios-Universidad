cmake_minimum_required(VERSION 3.16)

# 1. Definir el proyecto y los lenguajes (C y C++)
project(BancoEstado VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES BancoEstado_es_CL.ts)

# donde buscar los archivos .h de la base de datos
include_directories(backend)

# ARCHIVOS
set(PROJECT_SOURCES
        # Archivos Principales
        main.cpp
        loginwindow.cpp loginwindow.h loginwindow.ui
        ventanamenu.cpp ventanamenu.h ventanamenu.ui
        ventanaoperacion.cpp ventanaoperacion.h ventanaoperacion.ui

        cliente.cpp cliente.h
        persona.cpp persona.h

        # Recursos
        recursos.qrc
        ${TS_FILES}

        # Backend (Base de Datos)
        backend/GestorBD.h
        backend/GestorBD.cpp
        backend/sqlite3.h
        backend/sqlite3.c
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)

    qt_add_executable(BancoEstado
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ventanagestionclientes.h ventanagestionclientes.cpp ventanagestionclientes.ui
    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(BancoEstado SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(BancoEstado
            ${PROJECT_SOURCES}
        )
    endif()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(BancoEstado PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


set_target_properties(BancoEstado PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.BancoEstado
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS BancoEstado
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BancoEstado)
endif()
