
if(NOT "H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-subbuild/sqliteorm-populate-prefix/src/sqliteorm-populate-stamp/sqliteorm-populate-gitinfo.txt" IS_NEWER_THAN "H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-subbuild/sqliteorm-populate-prefix/src/sqliteorm-populate-stamp/sqliteorm-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: 'H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-subbuild/sqliteorm-populate-prefix/src/sqliteorm-populate-stamp/sqliteorm-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "F:/prg/Git/cmd/git.exe"  clone --no-checkout --config "advice.detachedHead=false" "https://github.com/fnc12/sqlite_orm" "sqliteorm-src"
    WORKING_DIRECTORY "H:/repos/pss_hws/Homework4/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/fnc12/sqlite_orm'")
endif()

execute_process(
  COMMAND "F:/prg/Git/cmd/git.exe"  checkout origin/dev --
  WORKING_DIRECTORY "H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'origin/dev'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "F:/prg/Git/cmd/git.exe"  submodule update --recursive --init 
    WORKING_DIRECTORY "H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-subbuild/sqliteorm-populate-prefix/src/sqliteorm-populate-stamp/sqliteorm-populate-gitinfo.txt"
    "H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-subbuild/sqliteorm-populate-prefix/src/sqliteorm-populate-stamp/sqliteorm-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'H:/repos/pss_hws/Homework4/build/_deps/sqliteorm-subbuild/sqliteorm-populate-prefix/src/sqliteorm-populate-stamp/sqliteorm-populate-gitclone-lastrun.txt'")
endif()

