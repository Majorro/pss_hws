add_executable(wendex)
target_link_libraries(wendex PUBLIC sqlite_orm::sqlite_orm)

target_sources(wendex 
    PUBLIC 
        main.cpp
)
