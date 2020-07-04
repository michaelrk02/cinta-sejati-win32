cmake_minimum_required(VERSION 3.0)

project("cinta-sejati")

set(srcfiles
    "cinta-sejati-win32.rc"

    "main.cpp"
    "main_dlg_proc.cpp"
    "seed.cpp"
    "update_accuracy.cpp"
    "view_result.cpp"
)

set(srcfiles_new "")
foreach(srcfile IN LISTS srcfiles)
    set(srcfiles_new ${srcfiles_new} "${CMAKE_CURRENT_SOURCE_DIR}/src/${srcfile}")
endforeach(srcfile)

set(compile_defs)
set(link_opts "")
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(compile_defs "UNICODE" "_UNICODE")
    set(link_opts "${link_opts} /MACHINE:X86 /ENTRY:wWinMainCRTStartup /MANIFEST:NO")
endif()

set(CMAKE_EXE_LINKER_FLAGS ${link_opts})

add_executable(${PROJECT_NAME} WIN32 ${srcfiles_new})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${compile_defs})