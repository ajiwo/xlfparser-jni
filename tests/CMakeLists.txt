set(xlfparserjni_jar_file "${PROJECT_BINARY_DIR}/java/${xlfparserjni_jar_name}.jar")
set(CMAKE_JAVA_INCLUDE_PATH ${xlfparserjni_jar_file})
macro(xlfparser_add_jar arg1)
    add_jar(
        ${arg1}
        SOURCES ajiwo/xlfparser/jni/test/${arg1}.java
        INCLUDE_JARS ${xlfparserjni_jar_file}
    )
endmacro(xlfparser_add_jar)

set(XLF_PATH "${PROJECT_SOURCE_DIR}/${xlfparserjni_test_dir}/file.xml")

macro(add_test_jar arg)
    xlfparser_add_jar(${arg}Test)
endmacro(add_test_jar)


add_test_jar("Layout")
add_test_jar("Region")
add_test_jar("Media")



#define a macro to simplify adding tests
macro (do_test section)
    if("${section}" STREQUAL "Layout")
        set(arg1 ${ARGV1})
        set(result ${ARGV2})
        set(section_suffix ${arg1})
    elseif("${section}" STREQUAL "Region")
        set(arg1 ${ARGV1})
        set(arg2 ${ARGV2})
        set(result ${ARGV3})
        set(section_suffix "${arg1}${arg2}")
    elseif("${section}" STREQUAL "Media")
        set(arg1 ${ARGV1})
        set(arg2 ${ARGV2})
        set(arg3 ${ARGV3})
        set(result ${ARGV4})
        set(section_suffix "${arg1}${arg2}${arg3}")
    endif()
    get_target_property(${section}_jar_file ${section}Test JAR_FILE)
    add_test (
        NAME ${section}Test_${section_suffix}
        COMMAND ${Java_JAVA_EXECUTABLE}
            -Djava.library.path=${PROJECT_BINARY_DIR}/${xlfparserjni_src_dir}
            -classpath ${xlfparserjni_jar_file}:${${section}_jar_file}
            ajiwo/xlfparser/jni/test/${section}Test
            ${arg1} ${arg2} ${arg3}
    )

    set_tests_properties(${section}Test_${section_suffix}
        PROPERTIES
        REQUIRED_FILES ${XLF_PATH}
    )

    set_tests_properties(${section}Test_${section_suffix}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro (do_test)

do_test(Layout "dummy" "dummy")
do_test(Layout "width"  "1920")
do_test(Layout "height"  "1080")
do_test(Layout "bgcolor"  "#ffffff")
do_test(Layout "background"  "975.jpg")
do_test(Layout "numregion"  "2")
do_test(Layout "numtag" "1")

do_test(Region "dummy" 0 "dummy")
do_test(Region "id" 0 "1153205596546b3c1237b90")
do_test(Region "width" 0 "1812")
do_test(Region "height" 0 "132")
do_test(Region "left" 0 "54")
do_test(Region "top" 0 "57")
do_test(Region "nummedia" 0 "1")
do_test(Region "numoption" 0 "0")

do_test(Media "id" 0 0 "c962f98bcea442f07bac533f7e8d2bc1")
do_test(Media "type" 0 0 "text")
do_test(Media "render" 0 0 "native")
do_test(Media "duration" 0 0 "5")
do_test(Media "numraw" 0 0 "1")
do_test(Media "numoption" 0 0 "4")

do_test(Region "id" 1 "2033362323546b3f480f7ea")
do_test(Region "width" 1 "1816")
do_test(Region "height" 1 "772")
do_test(Region "left" 1 "54")
do_test(Region "top" 1 "253")
do_test(Region "nummedia" 1 "3")
do_test(Region "numoption" 1 "0")

do_test(Media "id" 1 0 "978")
do_test(Media "type" 1 0 "image")
do_test(Media "render" 1 0 "native")
do_test(Media "duration" 1 0 "10")
do_test(Media "numraw" 1 0 "0")
do_test(Media "numoption" 1 0 "1")

do_test(Media "id" 1 1 "977")
do_test(Media "type" 1 1 "image")
do_test(Media "render" 1 1 "native")
do_test(Media "duration" 1 1 "10")
do_test(Media "numraw" 1 1 "0")
do_test(Media "numoption" 1 1 "4")

do_test(Media "id" 1 2 "976")
do_test(Media "type" 1 2 "image")
do_test(Media "render" 1 2 "native")
do_test(Media "duration" 1 2 "10")
do_test(Media "numraw" 1 2 "0")
do_test(Media "numoption" 1 2 "4")
