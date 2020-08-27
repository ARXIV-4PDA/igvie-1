cmake_minimum_required(VERSION 3.9)

project(untitled2)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

	

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(DIRECRORY_SHADERS "shaders")
set(DIRECRORY_SOURCE  "source")
set(DIRECRORY_PICTURES "pictures")
set(DIRECRORY_3D_OBJECTS "3D_objects")

file(GLOB SHADERS "${DIRECRORY_SHADERS}/*.txt")
foreach(SHADER ${SHADERS})
    get_filename_component(NAME_SHADER ${SHADER} NAME)
    configure_file(${SHADER} ${DIRECRORY_SHADERS}/${NAME_SHADER} COPYONLY)
endforeach(SHADER)


file(GLOB PICTURES
    "${DIRECRORY_PICTURES}/*.png"
    "${DIRECRORY_PICTURES}/*.jpg"
    )
foreach(PICTURE ${PICTURES})
    get_filename_component(NAME_PICTURE ${PICTURE} NAME)
    #configure_file(${PICTURE} ${DIRECRORY_PICTURES}/${NAME_PICTURE} COPIONLY)
endforeach(PICTURE)



find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(GLEW REQUIRED)
pkg_search_module(GLM REQUIRED glm)
find_package(Assimp REQUIRED) 
add_executable(
     ${PROJECT_NAME}
        "main.cpp"
        "${PROJECT_SOURCE_DIR}/source/shader"
        "${PROJECT_SOURCE_DIR}/source/position.cpp"
        "${PROJECT_SOURCE_DIR}/source/object.cpp"
        "${PROJECT_SOURCE_DIR}/source/window.cpp"
        "${PROJECT_SOURCE_DIR}/source/buffer_vao.cpp"
        "${PROJECT_SOURCE_DIR}/source/display.cpp"
        "${PROJECT_SOURCE_DIR}/source/model.cpp"
        "${PROJECT_SOURCE_DIR}/source/text.cpp"
        "${PROJECT_SOURCE_DIR}/source/chart.cpp"
        "${PROJECT_SOURCE_DIR}/source/input_plate.cpp"
        "${PROJECT_SOURCE_DIR}/source/date_input.cpp"
        "${PROJECT_SOURCE_DIR}/source/time_model.cpp"
)



#file(GLOB SOURCES "${DIRECRORY_SOURCE}/*.cpp")
#add_library(SOURCE ${SOURCES} )
#target_link_libraries(${PROJECT_NAME} ${SOURCE})



#add_subdirectory( ${PROJECT_SOURCE_DIR}/source)
#add_subdirectory( ${PROJECT_SOURCE_DIR}/stb_image)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/GLEW/include
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/GLFW/include
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/assimp-master/include
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/lib/assimp-master/contrib
)

add_compile_options(-fPIC -O3 -march=haswell)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -lXinerama -lXrandr -lXi -lXcursor -lpthread -lGLU  -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11  ")

#target_include_directories(${PROJECT_NAME} PUBLIC
#    ${PROJECT_SOURCE_DIR}/stb_image
#)



target_include_directories(${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/source)
target_include_directories(${PROJECT_NAME}  PUBLIC ${ASSIMP_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${GLM_LIBRARIES}
    ${ASSIMP_LIBRARIES}
#    stb_image
    )

