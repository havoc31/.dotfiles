#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER " | "

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

#define BLOCKS_DIR "$HOME/.config/dwmblocks-async/scripts/"

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X) \
    X("", BLOCKS_DIR "block_layout", 1, 0) \
    X("", BLOCKS_DIR "block_ssid",  1, 0) \
    X("", BLOCKS_DIR "block_date", 1, 0) \
    X("", BLOCKS_DIR "block_bat", 1, 0) \
    X("", BLOCKS_DIR "block_cpu", 1, 0) \
    X("", BLOCKS_DIR "block_mem", 1, 0) \
    X("", BLOCKS_DIR "block_bright", 1, 0) \
    X("", BLOCKS_DIR "block_vol", 1, 0)

#endif  // CONFIG_H
