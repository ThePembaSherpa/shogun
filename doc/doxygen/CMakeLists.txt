SET(DOXYGEN_GENERATE_HTML YES CACHE STRING "Generate HTML documentation with Doxygen.")

SET(DOXYGEN_CONFIG_TEMPLATE Doxyfile_en.in)
SET(DOXYGEN_LAYOUT ${CMAKE_CURRENT_SOURCE_DIR}/DoxygenLayout.xml)
SET(DOXYGEN_IMAGES ${CMAKE_CURRENT_SOURCE_DIR})
SET(DOXYGEN_PAGES "${CMAKE_CURRENT_SOURCE_DIR}/pages")
SET(DOXYGEN_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/xml/index.xml")
SET(DOXYGEN_HTML_OUTPUT_DIR html)
STRING(REGEX REPLACE "([a-zA-Z_]*).in" "${CMAKE_CURRENT_BINARY_DIR}/\\1" DOXYGEN_GENERATED_CONFIG "${DOXYGEN_CONFIG_TEMPLATE}")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/${DOXYGEN_CONFIG_TEMPLATE}" ${DOXYGEN_GENERATED_CONFIG} @ONLY)

add_custom_command(OUTPUT ${DOXYGEN_OUTPUT}
	COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_GENERATED_CONFIG}
	DEPENDS ${DOXYGEN_GENERATED_CONFIG}
	COMMENT "Generating API documentation"
)
add_custom_target(doxygen DEPENDS ${DOXYGEN_OUTPUT})

