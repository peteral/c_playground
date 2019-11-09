set(LIB_SOURCES
  filter.c
)

set(MAIN_SOURCES
  main.c
)

set(HEADERS 
  ${CONFIG_HEADER}
  filter.h
)

add_library(filter STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main filter)

set_target_properties(filter main PROPERTIES C_STANDARD 11)

install(TARGETS filter
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/filter.h DESTINATION include)