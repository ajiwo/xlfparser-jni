cmake_minimum_required (VERSION 2.8.0)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project(xlfparser-jni)
include(CTest)

set(xlfparserjni_src_dir src)
set(xlfparserjni_java_dir java)
set(xlfparserjni_test_dir tests)
set(xlfparserjni_jar_name "xlfparser")

set(xlfparserjni_src_files
    xlfparser-jni.cpp
    javaxlfobject.cpp
    javaxlfarraylist.cpp
    javaxlfhashmap.cpp
    javaxlfmedia.cpp
    javaxlfregion.cpp
    javaxlflayout.cpp
)

find_package(LibXlfParser REQUIRED)
if(LIBXLFPARSER_FOUND)
    set(xlfparserjni_include ${xlfparserjni_include} ${LIBXLFPARSER_INCLUDE_DIRS})
    file(
        STRINGS
        ${LIBXLFPARSER_INCLUDE_DIRS}/xlfparser/xlfparser-config.h
        xlfparser_config_content
    )
else()
    message("lib xlfparser c development file not found")
    return()
endif()

foreach(xlfparser_config_line ${xlfparser_config_content})
    string(REGEX MATCH "^#define[ ]+XLFPARSER_USE_LIBXML2$" outvar ${xlfparser_config_line})
    if(outvar)
        find_package(LibXml2 2.6.18 REQUIRED)
        if(NOT LIBXML2_FOUND)
            message("libxml2 is not found. cannot continue.")
            return()
        endif()
        set(xlfparserjni_libs ${LIBXML2_LIBRARIES})
        #set(xlfparserjni_include ${LIBXML2_INCLUDE_DIR})
    endif()
    string(REGEX MATCH "^#define[ ]+XLFPARSER_USE_LIBROXML$" outvar ${xlfparser_config_line})
    if(outvar)
        find_package(LibROXML REQUIRED)
        if(NOT LIBROXML_FOUND)
            message("libroxml is not found. cannot continue.")
            return()
        endif()
        set(xlfparserjni_libs ${LIBROXML_LIBRARIES})
        #set(xlfparserjni_include ${LIBROXML_INCLUDE_DIRS})
    endif()
endforeach()

find_package(Java REQUIRED)
find_package(JNI REQUIRED)
include(UseJava)
if(NOT JNI_FOUND)
    message("Java development package which provides jni.h is not found. cannot continue")
    return()
endif()
set(xlfparserjni_include ${xlfparserjni_include} ${JAVA_INCLUDE_PATH})
set(xlfparserjni_include ${xlfparserjni_include} ${JAVA_INCLUDE_PATH2})

add_subdirectory("${xlfparserjni_src_dir}")
add_subdirectory("${xlfparserjni_java_dir}")
add_subdirectory("${xlfparserjni_test_dir}")

