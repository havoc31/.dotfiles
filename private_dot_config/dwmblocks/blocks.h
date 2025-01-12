//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {"",        "block_layout",     1,                  0},
    {"",        "block_ssid",       2,                  0},
	{"",        "block_date",	    5,		            0},
	{"",        "block_bat",        1,          		0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

#if EXTRASTATUS_PATCH
static const Block extra_blocks[] = {
    /*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {"",        "block_cpu",        1,                  0},
    {"",        "block_temp",       2,                  0},
    {"",        "block_disk",       5,                  0},
    {"",        "block_mem",        1,                  0},
    {"",        "block_bright",     1,                  0},
    {"",        "block_vol",        1,                  0},
    // {"",        "block_updates",    60,                 0},
    // {"",        "block_kernel",     360,                0},
};

static char statussep[] = ";";
#endif // EXTRASTATUS_PATCH


