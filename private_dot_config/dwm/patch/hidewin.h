static void hidewin(const Arg *arg);
static void restorewin(const Arg *arg);
static void hideotherwins(const Arg *arg);
static void restoreotherwins(const Arg *arg);
static int issinglewin(const Arg *arg);
static void focuswin(const Arg *arg);

#define hiddenWinStackMax 100
static int hiddenWinStackTop = -1;
static Client *hiddenWinStack[hiddenWinStackMax];
