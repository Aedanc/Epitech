cmake_minimum_required(VERSION 3.0.2)
project(PSU_2016_myirc)
set(PROJECT_NAME "myIRC")

set(CMAKE_C_FLAGS " -W -Wall -Wextra -I./include")

set(CMAKE_C_FLAGS_DEBUG " -W -Wall -Wextra -ggdb3 -I./include")

include_directories(
        include/
        include/client
)

set(SRCS
        src/client/main.c
        src/client/init.c
        src/client/execCommand.c
        src/client/my_str_to_word_tab.c
        src/client/free_tab.c
        src/client/functab.c
        src/client/commands/quit.c
        src/client/commands/nick.c)


set(HDRS
        include/client/structClient.h
        include/client/init.h
        include/client/funcTab.h
        include/client/execCommand.h
        include/client/mystrtowordtab.h
        include/client/useCommand.h)

add_executable(client ${SRCS})