##
## EPITECH PROJECT, 2023
## my_radar
## File description:
## Makefile
##

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

CC				:= gcc
CFLAGS 			:= -c -Wall
LDFLAGS 		:= -lcsfml-graphics -lcsfml-window -lcsfml-system -lm
DEBUG_FLAGS		:= -g -g3
INCLUDES 		:= -I./includes
EXECUTABLE 		:= my_radar
TEST			:= unit_tests

SOURCES_FILES 	:= $(call rwildcard,src/,*.c)
OBJECTS_FILES 	:= $(SOURCES_FILES:.c=.o)

all: $(SOURCES_FILES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS_FILES)
	$(CC) $(LDFLAGS) $(OBJECTS_FILES) -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJECTS_FILES)
	rm -f $(OBJECTS_LIB_FILES)

fclean: clean clean_tests
	rm -f $(EXECUTABLE)
	rm -f test_$(EXECUTABLE)

debug: LDFLAGS += $(DEBUG_FLAGS)
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean clean_tests tests_run coverage debug re