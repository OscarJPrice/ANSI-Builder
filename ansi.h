/**
 * @file defines.h
 * @brief Defines ANSI escape sequences for styling text in terminal applications.
 *
 * This file includes macros for various ANSI escape sequences which are used
 * to format text output in terminal applications, such as changing colors, styles, 
 * and controlling cursor movements.
 * https://en.wikipedia.org/wiki/ANSI_escape_code
 *
 * @note This file doesn't cover all ANSI escape sequences, only those used in this project. 
 * Compatibility with all terminal types is not guaranteed.
 */

#ifndef ansi_H
#define ansi_H

    // Base ANSI escape sequence start
    #define ANSI_START "\033["

    // Resets any ANSI formatting to the terminal's default
    #define ANSI_NORMAL "\033[0m"

    // Foreground color definitions
    #define BLACK_FG ANSI_START "30m"           // Black foreground
    #define RED_FG ANSI_START "31m"             // Red foreground
    #define GREEN_FG ANSI_START "32m"           // Green foreground
    #define YELLOW_FG ANSI_START "33m"          // Yellow foreground
    #define BLUE_FG ANSI_START "34m"            // Blue foreground
    #define MAGENTA_FG ANSI_START "35m"         // Magenta foreground
    #define CYAN_FG ANSI_START "36m"            // Cyan foreground
    #define WHITE_FG ANSI_START "37m"           // White foreground
    #define GRAY_FG ANSI_START "90m"            // Gray foreground
    #define BRIGHT_RED_FG ANSI_START "91m"      // Bright red foreground
    #define BRIGHT_GREEN_FG ANSI_START "92m"    // Bright green foreground
    #define BRIGHT_YELLOW_FG ANSI_START "93m"   // Bright yellow foreground
    #define BRIGHT_BLUE_FG ANSI_START "94m"     // Bright blue foreground
    #define BRIGHT_MAGENTA_FG ANSI_START "95m"  // Bright magenta foreground
    #define BRIGHT_CYAN_FG ANSI_START "96m"     // Bright cyan foreground
    #define BRIGHT_WHITE_FG ANSI_START "97m"    // Bright white foreground

    // Background color definitions
    #define BLACK_BG ANSI_START "40m"           // Black background
    #define RED_BG ANSI_START "41m"             // Red background
    #define GREEN_BG ANSI_START "42m"           // Green background
    #define YELLOW_BG ANSI_START "43m"          // Yellow background
    #define BLUE_BG ANSI_START "44m"            // Blue background
    #define MAGENTA_BG ANSI_START "45m"         // Magenta background
    #define CYAN_BG ANSI_START "46m"            // Cyan background
    #define WHITE_BG ANSI_START "47m"           // White background
    #define GRAY_BG ANSI_START "100m"           // Gray background
    #define BRIGHT_RED_BG ANSI_START "101m"     // Bright red background
    #define BRIGHT_GREEN_BG ANSI_START "102m"   // Bright green background
    #define BRIGHT_YELLOW_BG ANSI_START "103m"  // Bright yellow background
    #define BRIGHT_BLUE_BG ANSI_START "104m"    // Bright blue background
    #define BRIGHT_MAGENTA_BG ANSI_START "105m" // Bright magenta background
    #define BRIGHT_CYAN_BG ANSI_START "106m"    // Bright cyan background
    #define BRIGHT_WHITE_BG ANSI_START "107m"   // Bright white background

    // Text style definitions
    #define NORMAL ANSI_START "0m"            // Normal style
    #define BOLD ANSI_START "1m"              // Bold style
    #define BRIGHT BOLD                       // Alias for bold
    #define FAINT ANSI_START "2m"             // Faint style
    #define ITALIC ANSI_START "3m"            // Italic style
    #define UNDERLINE ANSI_START "4m"         // Underlined text
    #define SLOW_BLINK ANSI_START "5m"        // Slow blink
    #define RAPID_BLINK ANSI_START "6m"       // Rapid blink
    #define STRIKETHROUGH ANSI_START "9m"     // Strikethrough
    #define FONT_DEFAULT ANSI_START "10m"     // Default font
    #define FRAKTUR ANSI_START "20m"          // Fraktur style

    // More text style options
    #define DOUBLE_UNDERLINE_or_unbold ANSI_START "21m"// Double underline or unbold
    #define NORMAL_INTENSITY ANSI_START "22m"          // Normal intensity
    #define NOT_ITALIC_or_NOT_FRAKTUR ANSI_START "23m" // Neither italic nor Fraktur
    #define UNDERLINE_OFF ANSI_START "24m"             // Turns off underline
    #define BLINK_OFF ANSI_START "25m"                 // Turns off blinking

    // Border styles
    #define FRAMED ANSI_START "51m"                    // Framed text
    #define ENCIRCLED ANSI_START "52m"                 // Encircled text
    #define OVERLINED ANSI_START "53m"                 // Overlined text
    #define NOT_FRAMED_or_ENCIRCLED ANSI_START "54m"   // Neither framed nor encircled
    #define NOT_OVERLINED ANSI_START "55m"             // Turns off overline

    // End of ANSI formatting sequences
    #define ANSI_END NORMAL
    #define RESET NORMAL

    // Cursor control sequences
    #define CURSOR_UP(n) std::cout << ANSI_START << n << "A"                    // Move cursor up n lines
    #define CURSOR_DOWN(n) std::cout << ANSI_START << n << "B"                  // Move cursor down n lines
    #define CURSOR_FORWARD(n) std::cout << ANSI_START << n << "C"               // Move cursor forward n columns
    #define CURSOR_BACK(n) std::cout << ANSI_START << n << "D"                  // Move cursor back n columns
    #define CURSOR_NEXT_LINE(n) std::cout << ANSI_START << n << "E"             // Move cursor to the beginning of the line n lines down
    #define CURSOR_PREVIOUS_LINE(n) std::cout << ANSI_START << n << "F"         // Move cursor to the beginning of the line n lines up
    #define CURSOR_HORIZONTAL_ABSOLUTE(n) std::cout << ANSI_START << n << "G"   // Move cursor to column n
    #define CURSOR_TO(n, m) std::cout << ANSI_START << n << ";" << m << "H"     // Move cursor to row n, column m
    #define CURSOR_TO_ALT(n, m) std::cout << ANSI_START << n << ";" << m << "f" // Alternative command to move cursor to row n, column m

    // Enumeration for different erase operations
    enum Erase {
        CURSOR_TO_END = 0,           // Erase from cursor to the end of the screen
        CURSOR_TO_BEGINNING = 1,     // Erase from cursor to the beginning of the screen
        ENTIRE_LINE = 2              // Erase the entire line
    };

    // Erase and scroll commands
    #define ERASE_DISPLAY(n) std::cout << ANSI_START << n << "J"           // Erase part of the display
    #define ERASE_LINE(n) std::cout << ANSI_START << n << "K"              // Erase part of the line
    #define SCROLL_UP(n) std::cout << ANSI_START << n << "S"               // Scroll up n lines
    #define SCROLL_DOWN(n) std::cout << ANSI_START << n << "T"             // Scroll down n lines

    // Non-standard ANSI commands for cursor saving and restoring
    #define CURSOR_SAVE ANSI_START "s"    // Save cursor position (non-standard)
    #define CURSOR_RESTORE ANSI_START "u" // Restore cursor position (non-standard)

#endif

#ifdef ANSI_COLORS_255
    // Check if extended ANSI color support is enabled
    #ifndef ANSI_COLORS_255_H
    #define ANSI_COLORS_255_H
       
        // Extended ANSI color definitions
        #define ANSI_255_FG(n) ANSI_START "38;5;" + std::to_string(n) + "m" // 255 foreground color
        #define ANSI_255_BG(n) ANSI_START "48;5;" + std::to_string(n) + "m" // 255 background color
    
    #endif
#endif

#ifdef ANSI_COLORS_24bit
    // Check if 16 million color support is enabled
    #ifndef ANSI_COLORS_16M_H
    #define ANSI_COLORS_16M_H

        // 16 million color definitions
        #define ANSI_16M_FG(r, g, b) ANSI_START "38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" std::to_string(b) "m" // 24-bit foreground color
        #define ANSI_16M_BG(r, g, b) ANSI_START "48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" std::to_string(b) "m" // 24-bit background color

    #endif
#endif
