/* See LICENSE file for copyright and license details. */

/* Helper macros for spawning commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }

/* Helper macros for spawning custom scripts for dwm */
#define DWM_SCRIPTS_PATH "$HOME/.config/dwm/scripts"
#define DWM_SCRIPT(SCRIPT) SHCMD("PATH=\"$PATH:" DWM_SCRIPTS_PATH "\" " SCRIPT) 

/* restart patch path to SESSION_FILE */
#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_NONE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char statussep              = ';'; /* separator between status bars */
static const char *fonts[]               = { "FiraCode:size=10:weight=bold:antialias=true" };
static const char dmenufont[]            = "FiraCode:size=10:antialias=true";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)

    RULE(.class = "Nsxiv", .instance = "nsxiv", .isfloating = 1)
    RULE(.class = "Zathura", .instance = "org.pwmt.zathura", .isfloating = 1)
    RULE(.class = "pavucontrol", .instance = "pavucontrol", .isfloating = 1)
    RULE(.class = "Blueman-manager", .instance = "blueman-manager", .isfloating = 1)
    RULE(.class = "Lxappearance", .instance = "lxappearance", .isfloating = 1)

    RULE(.class = "zoom", .instance = "zoom", .isfloating = 1, .tags = 1 << 3)

    RULE(.class = "floorp", .instance = "Navigator", .tags = 1 << 0) 
    RULE(.class = "Emacs", .instance = "emacs", .tags = 1 << 1)
    RULE(.class = "obsidian", .instance = "obsidian", .tags = 1 << 2)

};

static const MonitorRule monrules[] = {
	/* monitor  tag   layout  mfact  nmaster  showbar  topbar */
	{  1,       -1,   2,      -1,    -1,      -1,      -1     }, // use a different layout for the second monitor
	{  -1,      -1,   0,      -1,    -1,      -1,      -1     }, // default
};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
    /* monitor   bar    alignment          widthfunc                 drawfunc                clickfunc                hoverfunc     name */
    { -1,        0,     BAR_ALIGN_LEFT,    width_tags,               draw_tags,              click_tags,              hover_tags,   "tags"        },
    {  0,        0,     BAR_ALIGN_RIGHT,   width_systray,            draw_systray,           click_systray,           NULL,         "systray"     },
    { -1,        0,     BAR_ALIGN_LEFT,    width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,         "layout"      },
    { -1,        0,     BAR_ALIGN_RIGHT,   width_status2d,           draw_status2d,          click_status2d,          NULL,         "status2d"    },
    { -1,        0,     BAR_ALIGN_NONE,    width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,         "awesomebar"  },
    { -1,        1,     BAR_ALIGN_CENTER,  width_status2d_es,        draw_status2d_es,       click_status2d,          NULL,         "status2d_es" },
};
/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|||",      col },
	{ "HHH",      grid },
	{ "---",      horizgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define KEYCHORD(...) &((Keychord){ __VA_ARGS__ }),
#define TAGKEYS(KEY,TAG) \
       KEYCHORD(1, {{MODKEY, KEY}},                                        view,           {.ui = 1 << TAG}) \
       KEYCHORD(1, {{MODKEY|ControlMask, KEY}},                            toggleview,     {.ui = 1 << TAG}) \
       KEYCHORD(1, {{MODKEY|ShiftMask, KEY}},                              tag,            {.ui = 1 << TAG}) \
       KEYCHORD(1, {{MODKEY|ControlMask|ShiftMask, KEY}},                  toggletag,      {.ui = 1 << TAG})

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
    "dmenu_run",
    "-m", dmenumon,
    "-fn", dmenufont,
    "-nb", normbgcolor,
    "-nf", normfgcolor,
    "-sb", selbgcolor,
    "-sf", selfgcolor,
    "-bw", "2", 
    NULL
};
static const char *termcmd[]  = { "st", NULL };

/* Custom dwm scripts */
#define brightupcmd     DWM_SCRIPT("bright_up")
#define brightdowncmd   DWM_SCRIPT("bright_down") 

#define volupcmd    DWM_SCRIPT("vol_up")
#define voldowncmd  DWM_SCRIPT("vol_down") 
#define volmutecmd  DWM_SCRIPT("vol_mute")
/* Custom dwm scripts */

/* Usefult scripts and commands */
#define screenareacmd SHCMD("flameshot gui")
#define screenfullcmd SHCMD("flameshot full")

#define xscreensaverlock SHCMD("xscreensaver-command -lock") 

/* Script to generate RULE(...) macro for window, copy to clipboard */
#define XPROP_RULE "xprop | awk '/^WM_CLASS/{sub(/.* =/, \"\"); sub(/,/, \"\");" \
                   "printf(\"RULE(.class = %s, .instance = %s)\", $2, $1) }'" \
                   "| xclip -selection clipboard"
/* Usefult scripts and commands */

static const Keychord *keychords[] = {
    /* keys                                                     function                argument */
    KEYCHORD(1, {{ MODKEY, XK_p }},                             spawn,                  {.v = dmenucmd })
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_Return }},              spawn,                  {.v = termcmd })
    KEYCHORD(1, {{ MODKEY, XK_b }},                             togglebar,              {0})
    KEYCHORD(1, {{ MODKEY, XK_j }},                             focusstack,             {.i = +1 })
    KEYCHORD(1, {{ MODKEY, XK_k }},                             focusstack,             {.i = -1 })
    KEYCHORD(1, {{ MODKEY, XK_i }},                             incnmaster,             {.i = +1 })
    KEYCHORD(1, {{ MODKEY, XK_d }},                             incnmaster,             {.i = -1 })
    KEYCHORD(1, {{ MODKEY, XK_h }},                             setmfact,               {.f = -0.05})
    KEYCHORD(1, {{ MODKEY, XK_l }},                             setmfact,               {.f = +0.05})
    KEYCHORD(1, {{ MODKEY, XK_Return }},                        zoom,                   {0})
    KEYCHORD(1, {{ MODKEY, XK_Tab }},                           view,                   {0})
    KEYCHORD(1, {{ MODKEY|ControlMask, XK_z }},                 showhideclient,         {0})
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_c }},                   killclient,             {0})
    KEYCHORD(2, {{ MODKEY|ShiftMask, XK_q }, {0, XK_q}},        quit,                   {0})
    KEYCHORD(2, {{ MODKEY|ShiftMask, XK_q }, {0, XK_r}},        quit,                   {1})
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_F5 }},                  xrdb,                   {.v = NULL })
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_i }},                   spawn,                  SHCMD(XPROP_RULE))
    /*Layouts*/
    KEYCHORD(1, {{ MODKEY, XK_t }},                             setlayout,              {.v = &layouts[0]})
    KEYCHORD(1, {{ MODKEY, XK_f }},                             setlayout,              {.v = &layouts[1]})
    KEYCHORD(1, {{ MODKEY, XK_m }},                             setlayout,              {.v = &layouts[2]})
    KEYCHORD(1, {{ MODKEY, XK_c }},                             setlayout,              {.v = &layouts[3]})
    KEYCHORD(1, {{ MODKEY, XK_g }},                             setlayout,              {.v = &layouts[4]})
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_h }},                   setlayout,              {.v = &layouts[5]})
    KEYCHORD(1, {{ MODKEY, XK_space }},                         setlayout,              {0})
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_space }},               togglefloating,         {0})
    KEYCHORD(1, {{ MODKEY, XK_0 }},                             view,                   {.ui = ~0 })
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_0 }},                   tag,                    {.ui = ~0 })
    KEYCHORD(1, {{ MODKEY, XK_comma }},                         focusmon,               {.i = -1 })
    KEYCHORD(1, {{ MODKEY, XK_period }},                        focusmon,               {.i = +1 })
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_comma }},               tagmon,                 {.i = -1 })
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_period }},              tagmon,                 {.i = +1 })
    /*Hide win patch*/
    KEYCHORD(1, {{ MODKEY, XK_o }},                             hidewin,                {0})
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_o }},                   restorewin,             {0})
    KEYCHORD(1, {{ MODKEY, XK_w }},                             hideotherwins,          {0})
    KEYCHORD(1, {{ MODKEY|ShiftMask, XK_w }},                   restoreotherwins,       {0})
    /*Volume*/
    KEYCHORD(1, {{ 0, XF86XK_AudioMute }},                      spawn,                  volmutecmd)
    KEYCHORD(1, {{ 0, XF86XK_AudioLowerVolume }},               spawn,                  voldowncmd)
    KEYCHORD(1, {{ 0, XF86XK_AudioRaiseVolume }},               spawn,                  volupcmd)
    /*Brightness*/
    KEYCHORD(1, {{ 0, XF86XK_MonBrightnessDown }},              spawn,                  brightdowncmd)
    KEYCHORD(1, {{ 0, XF86XK_MonBrightnessUp }},                spawn,                  brightupcmd)
    /*Screenshot*/
    KEYCHORD(1, {{ MODKEY | ShiftMask, XK_Print }},             spawn,                  screenareacmd) 
    KEYCHORD(1, {{ MODKEY, XK_Print }},                         spawn,                  screenfullcmd) 
     /*Xscreensaver*/
    KEYCHORD(1, {{ MODKEY | ShiftMask, XK_l }},                 spawn,                  xscreensaverlock) 
    /*Doom Emacs*/
    KEYCHORD(2, {{ MODKEY, XK_e }, { 0, XK_e }},                spawn,                  SHCMD("emacsclient -c -a 'emacs'")) 
    /*Tags*/ 
    TAGKEYS(XK_1, 0)
    TAGKEYS(XK_2, 1)
    TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3)
    TAGKEYS(XK_5, 4)
    TAGKEYS(XK_6, 5)
    TAGKEYS(XK_7, 6)
    TAGKEYS(XK_8, 7)
    TAGKEYS(XK_9, 8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

