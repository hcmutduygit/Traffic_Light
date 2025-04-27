include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(pic_traffic_light_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(pic_traffic_light_default_default_XC8_FILE_TYPE_assemble)
add_library(pic_traffic_light_default_default_XC8_assemble OBJECT ${pic_traffic_light_default_default_XC8_FILE_TYPE_assemble})
    pic_traffic_light_default_default_XC8_assemble_rule(pic_traffic_light_default_default_XC8_assemble)
    list(APPEND pic_traffic_light_default_library_list "$<TARGET_OBJECTS:pic_traffic_light_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(pic_traffic_light_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(pic_traffic_light_default_default_XC8_assemblePreprocess OBJECT ${pic_traffic_light_default_default_XC8_FILE_TYPE_assemblePreprocess})
    pic_traffic_light_default_default_XC8_assemblePreprocess_rule(pic_traffic_light_default_default_XC8_assemblePreprocess)
    list(APPEND pic_traffic_light_default_library_list "$<TARGET_OBJECTS:pic_traffic_light_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(pic_traffic_light_default_default_XC8_FILE_TYPE_compile)
add_library(pic_traffic_light_default_default_XC8_compile OBJECT ${pic_traffic_light_default_default_XC8_FILE_TYPE_compile})
    pic_traffic_light_default_default_XC8_compile_rule(pic_traffic_light_default_default_XC8_compile)
    list(APPEND pic_traffic_light_default_library_list "$<TARGET_OBJECTS:pic_traffic_light_default_default_XC8_compile>")
endif()

add_executable(${pic_traffic_light_default_image_name} ${pic_traffic_light_default_library_list})

target_link_libraries(${pic_traffic_light_default_image_name} PRIVATE ${pic_traffic_light_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
pic_traffic_light_default_link_rule(${pic_traffic_light_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${pic_traffic_light_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${pic_traffic_light_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${pic_traffic_light_default_image_name} ${pic_traffic_light_default_output_dir}/${pic_traffic_light_default_original_image_name}
                    BYPRODUCTS ${pic_traffic_light_default_output_dir}/${pic_traffic_light_default_original_image_name})
