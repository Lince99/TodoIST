/*
 * Copyright (C) 2019 Lince99
 *   for more info contact me at https://github.com/Lince99
 * This program is under MIT license
 *   for the file refer to LICENSE under TodoIST directory
 */
/*
 * library dedicated only to define constant string that change
 * text color or background on terminals that support ANSI escape characters
 */
/*
 * escape codes inspired by
 * https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
 */
/*
 * \033[38;2;r;g;b
 * \033[48;2;r;g;b
 * for any supported color of text and background
 */

/* move cursor */
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

/* clear the screen */
#ifndef ANSI_CLEAN
    #define ANSI_CLEAN "\033[H\033[J"
#endif

/* font colors (foreground) */
#ifndef ANSI_BLACK
    #define ANSI_BLACK "\033[30m"
#endif

#ifndef ANSI_RED
    #define ANSI_RED "\033[31m"
#endif

#ifndef ANSI_GREEN
    #define ANSI_GREEN  "\033[32m"
#endif

#ifndef ANSI_YELLOW
    #define ANSI_YELLOW  "\033[33m"
#endif

#ifndef ANSI_BLUE
    #define ANSI_BLUE    "\033[34m"
#endif

#ifndef ANSI_MAGENTA
    #define ANSI_MAGENTA "\033[35m"
#endif

#ifndef ANSI_CYAN
    #define ANSI_CYAN    "\033[36m"
#endif

#ifndef ANSI_WHITE
    #define ANSI_WHITE     "\033[37m"
#endif



/* background colors */
#ifndef ANSI_BG_BLACK
    #define ANSI_BG_BLACK     "\033[40m"
#endif

#ifndef ANSI_BG_RED
    #define ANSI_BG_RED     "\033[41m"
#endif

#ifndef ANSI_BG_GREEN
    #define ANSI_BG_GREEN   "\033[42m"
#endif

#ifndef ANSI_BG_YELLOW
    #define ANSI_BG_YELLOW  "\033[43m"
#endif

#ifndef ANSI_BG_BLUE
    #define ANSI_BG_BLUE    "\033[44m"
#endif

#ifndef ANSI_BG_MAGENTA
    #define ANSI_BG_MAGENTA "\033[45m"
#endif

#ifndef ANSI_BG_CYAN
    #define ANSI_BG_CYAN    "\033[46m"
#endif

#ifndef ANSI_BG_WHITE
    #define ANSI_BG_WHITE     "\033[47m"
#endif

#ifndef ANSI_REVERSE
    #define ANSI_REVESE     "\033[7m"
#endif


/* font styles */
#ifndef ANSI_BOLD
    #define ANSI_BOLD    "\033[1m"
#endif

#ifndef ANSI_ITALIC
    #define ANSI_ITALIC    "\033[3m"
#endif

#ifndef ANSI_UNDERLINE
    #define ANSI_UNDERLINE    "\033[4m"
#endif

#ifndef ANSI_NOT_OVERLINE
    #define ANSI_NOT_OVERLINE    "\033[24m"
#endif

#ifndef ANSI_OVERLINE
    #define ANSI_OVERLINE    "\033[53m"
#endif



/* restore the original foreground and background colors */
#ifndef ANSI_RESET
    #define ANSI_RESET   "\033[0m"
#endif
