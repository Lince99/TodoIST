#Lince99

CC=gcc
RM=rm -f

#name of the source (include folders if the source isn't in the current dir)
SRC=read_json.cpp
#add user params after the name of the executable
EXC=read_json
#compile params like optimization or other platform targeting
PAR=-lstdc++ -O2 -Wall
#add libraries here
LIBS=-L /include -L /include/json-api

all: clean compile run

help:
	@echo "\nUse make [option]:\n"
	@echo "help \n\tshow this help"
	@echo "compile \n\tcompile from the source and strip it"
	@echo "clean \n\tremove the executable file and reset the terminal"
	@echo "run \n\trun the program (if already compiled) with | less\n"

compile:
	@$(CC) -o $(EXC) $(SRC) $(PAR) $(LIBS)
	@strip $(EXC)

clean:
	@$(RM) $(EXC)

clean_reset:
	@$(RM) $(EXC)
	@reset && clear

run:
	@./$(EXC)

run_less:
	@./$(EXC) | less -r -q -s -C
