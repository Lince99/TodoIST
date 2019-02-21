/*
 * Copyright (C) 2019 Lince99
 *   for more info contact me at https://github.com/Lince99
 * This program is under MIT license
 *   for the file refer to LICENSE under TodoIST directory
 */
/*
 * library that manage various level of errors and print
 */

#include <string.h>
#include <stdio.h>
#include "colors.h"
#include <errno.h>
#include <iostream>

#define CRITICAL    5
#define ERROR       4
#define WARNING     3
#define INFO        2
#define DEBUG       1
#define NOTSET      4 /* NOTSET is default (only ERROR and CRITICAL output) */
/* Prefix of logs to distinguish them easily */
#define PREFIX ":: "
#define STR_LEN 2064

/* GLOBALS */
int LOGGING_LVL;
FILE* log_out = NULL;

/* signatures */
int logging_print(char* msg, int lvl);
int logging_warning(char* msg);
int logging_out(FILE* set_log_out);



/*
 * Set verbose level based on program parameters
 * the number of V
 * Default: -v
 */
int logging_auto(int argc, char const *argv[]) {
	int i = 0;
    int j = 0;
    int logging_lvl = 0;

	logging_lvl = NOTSET;

	/* auto logging output STDERR */
	logging_out(stderr);
	for(i = 1; i < argc; i++) {
		/* Seg fault check parameter needs to be -v, others are ignored */
		if(strlen(argv[i]) < 2) {
			continue;
		}
		/* if the argv is a parameter --double minus par is not accepted */
		if(argv[i][0] == '-' && argv[i][1] != '-') {
			int endl;

			logging_lvl = NOTSET;
			endl = strlen(argv[i]);
			for(j = 1; j < endl; j++) {
				if(argv[i][j] == 'v') {
					logging_lvl--;
				}
			}
			if(logging_lvl < DEBUG || logging_lvl > CRITICAL) {
				logging_lvl = DEBUG;
			}
		}
	}
	LOGGING_LVL = logging_lvl;

	return logging_lvl;
}

/*
 *
 */
int logging_set(int lvl) {
    char string[STR_LEN];

    /* Defaults */
    LOGGING_LVL = NOTSET;

    /* Set logging */
	if (NOTSET <= lvl && lvl <= CRITICAL) {
		LOGGING_LVL = lvl;
	} else {
		sprintf(string, "Trying to set (LOGGING_LVL) out of range: %d\n", lvl);
		logging_warning(string);
		return 1;
	}

	return 0;
}

/*
 * base of all logging prints
 */
int logging_print(char* msg, int lvl) {
    int check = 0;

	/* If log_out is not defined */
	if(log_out == NULL)
		// set to stdout
		logging_out(stderr);
	if(LOGGING_LVL > lvl)
		return 1;
	/* print to log_out with error check */
    try {
        fprintf(log_out, "%s\n", msg) < 0)
    } catch(const std::exception& e) {
        /* EVERYTHING IS ON FIRE */
        perror("Error on writing errors\n");
    }

	return 0;
}

/* MSG (Usually spamed) */
int logging_info(char* msg) {
	char log_str[STR_LEN];

	sprintf(log_str, PREFIX "%s", msg);
	logging_print(log_str, INFO);

	return 0;
}

/* BLUE DEBUG MSG (Usually spammed) */
int logging_debug(char* msg) {
	char log_str[STR_LEN];

	sprintf(log_str, PREFIX ANSI_BLUE "DEBUG" ANSI_RESET " %s", msg);
	logging_print(log_str, DEBUG);

	return 0;
}

/* YELLOW WARNING MSG  */
int logging_warning(char* msg) {
	char log_str[STR_LEN];
	sprintf(log_str,
            PREFIX ANSI_BOLD ANSI_YELLOW "WARNING" ANSI_RESET " %s",
            msg);
	logging_print(log_str, WARNING);

	return 0;
}

/* RED ERROR MSG */
int logging_error(char* msg) {
	char log_str[STR_LEN];

	sprintf(log_str, PREFIX ANSI_BOLD ANSI_RED "ERROR" ANSI_RESET " %s\n"
					PREFIX "   %s", msg, strerror(errno));
	logging_print(log_str, ERROR);

	return 0;
}

/* BG RED, WHITE ERROR MSG */
int logging_critical(char* msg) {
	char log_str[2064];

	sprintf(log_str,
            PREFIX ANSI_BOLD ANSI_WHITE ANSI_BG_RED "CRITICAL" ANSI_RESET
            " %s", msg);
	logging_print(log_str, CRITICAL);

	return 0;
}

/*
 * Set default output stream either:
 *   stderr, stdio, or a file
 */
int logging_out(FILE* set_log_out) {
	log_out = set_log_out;

	return 0;
}

/* TODO
typedef struct STR_LOGGING_STACK {

} LOGGING_STACK;
// Stack
int logging_push(int lvl);
int logging_pop();
*/
