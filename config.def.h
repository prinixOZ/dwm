#define MODKEY Mod4Mask
#define MODKEY1 Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define CMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }
#include "selfrestart.c"

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *altbarcmd        = "$HOME/bar.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { "Hack:size=12" };
static const char dmenufont[]       = "Hack:size=10";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};


/* tagging */


/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {{ "[T]",tile }, { "[F]",NULL },{ "[M]",monocle }};

// DMENU SOMETHING
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run","-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL, "-nb", "#0F0F0F", "-p", "Run: " };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *lockcmd[] = {"i3lock","-c", "000000", "-R", "1000", "-F", "100", "-O", "0", "-o", "ffffff", "-l", "ffffff", "--no-keyboard-layout", "-T", "1"};

static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* class            instance            title                     tags mask            isfloating         monitor */
	{ "Gimp",           NULL,               NULL,                     0,                   1,                 -1 },
	{ "Firefox",        NULL,               NULL,                     1 << 8,              0,                 -1 },
    { "mpv",            NULL,               NULL,                     0,                   1,                 -1 },
    {  NULL,            NULL,               "float-alacritty",        0,                   1,                 -1 },
};

static Key keys[] = {
//=============================================================================================================================
// ==========================================>    MOVEMENTS KEYS    <=========================================================|
	TAGKEYS(                    XK_1,           0)//                                                                          |
	TAGKEYS(                    XK_2,           1)//                                                                          |
	TAGKEYS(                    XK_3,           2)//                                                                          |
	TAGKEYS(                    XK_4,           3)//                                                                          |
	TAGKEYS(                    XK_5,           4)//                                                                          |
	TAGKEYS(                    XK_6,           5)//                                                                          |
	TAGKEYS(                    XK_7,           6)//                                                                          |
	TAGKEYS(                    XK_8,           7)//                                                                          |
	TAGKEYS(                    XK_9,           8)//                                                                          |
//                                                                                                                            |
//=============================================================================================================================
// ==========================================>    MOVEMENTS KEYS    <=========================================================|
// ## CYCLE LAYOUT                                                                                                            |
{ MODKEY|ShiftMask,             XK_space, cyclelayout,    {.i = +1 } },//                                                     |
// ## TOGGLE(Floting, Sticky, Fullscreen)                                                                                     |
{ MODKEY,                       XK_f,           togglefullscr,                  {0} },//                                      |
{ MODKEY|ShiftMask,             XK_s,           togglesticky,                   {0} },//                                      |
{ MODKEY|ShiftMask,             XK_f,           togglefloating,                 {0} },//                                      |
//## CHANGE WINDOW                                                                                                            |
{ MODKEY,                       XK_h,           shiftview,                      { .i = -1 } },//                              |
{ MODKEY,                       XK_l,           shiftview,                      { .i = +1 } },//                              |
//## CHANGE FOCUS WINDOW                                                                                                      |
{ MODKEY,                       XK_Tab,         focusstack,                     { .i = +1 } },//                              |
{ MODKEY,                       XK_j,           focusstack,                     { .i = +1 } },//                              |
{ MODKEY,                       XK_k,           focusstack,                     { .i = -1 } },//                              |
{ MODKEY,                       XK_space,       togglecanfocusfloating,         {0} },//                                      |
//## Move Window Up and Down                                                                                                  |
{ MODKEY|ShiftMask,             XK_j,           rotatestack,                    {.i = +1 } },//                               |
{ MODKEY|ShiftMask,             XK_k,           rotatestack,                    {.i = -1 } },//                               |
{ MODKEY,                       XK_q,           killclient,                     {0} },//                                      |
{ MODKEY1|ControlMask,          XK_Return,      spawn,                          CMD("killall xinit")},//                      |
//=============================================================================================================================
//                                                                                                                            |
//=============================================================================================================================
// ==========================================>    MOVEMENTS KEYS    <=========================================================|
{ MODKEY,                       XK_minus,       incnmaster,                     {.i = +1 } },//                               |
{ MODKEY,                       XK_equal,       incnmaster,                     {.i = -1 } },//                               |
{ MODKEY|ShiftMask,             XK_z,           zoom,                           {0} },//                                      |
//                                                                                                                            |
//=============================================================================================================================
// =======================================>       BASIC APPLICATIONS     <====================================================|
//## RUN LAUNCHER                                                                                                             |
{ MODKEY,                       XK_d,           spawn,                          CMD("dmenu-picom") },//                       |
{ MODKEY|ShiftMask,             XK_d,           spawn,                          CMD("dmenurun-picom") },//                    |
{ MODKEY|ShiftMask,             XK_p,           spawn,                          CMD("keepmenu") },//                          |
//## TERMINAL                                                                                                                 |
{ MODKEY,                       XK_Return,      spawn,                          CMD("terminal.sh") },//                       |
//## BROWSER                                                                                                                  |
{ MODKEY,                       XK_a,           spawn,                          CMD("librewolf -P default") },//              |
{ MODKEY|ShiftMask,             XK_b,           spawn,                          CMD("librewolf -P") },//                      |
{ MODKEY,                       XK_b,           spawn,                          CMD("brave") },//                             |
//## FILE MANAGER                                                                                                             |
{ MODKEY,                       XK_s,           spawn,                          CMD("alacritty -e lfub") },//                 |
//=============================================================================================================================
//                                                                                                                            |
//=============================================================================================================================
// ========================================>  DUNST CONTROL COMMANDS   <======================================================|
{ MODKEY1,                      XK_space,       spawn,                          CMD("dunstctl close") },//                    |
{ MODKEY1|ShiftMask,            XK_space,       spawn,                          CMD("dunstctl closeall") },//                 |
//                                                                                                                            |
//=============================================================================================================================
//                                                                                                                            |
//=============================================================================================================================
// ========================================>       ROTATE KEYS         <======================================================|
{ MODKEY|ShiftMask,             XK_period,      spawn,                          CMD("xrandr -o left") },//                    |
{ MODKEY|ShiftMask,             XK_comma,       spawn,                          CMD("xrandr -o normal") },//                  |
//                                                                                                                            |
//=============================================================================================================================
//                                                                                                                            |
//=============================================================================================================================
// =============================================>    YTFZF   <================================================================|
{ MODKEY,                       XK_F1,          spawn,                         CMD("ytfzf -D")},//                            |
{ MODKEY,                       XK_F2,          spawn,                         CMD("ytfzf -D -c SI --sort date")},//          |
{ MODKEY,                       XK_F3,          spawn,                         CMD("ytfzf-channel")},//                       |
{ MODKEY,                       XK_F4,          spawn,                         CMD("ytfzf-plylist")},//                       |
{ MODKEY,                       XK_F5,          spawn,                         CMD("ytfzf -c invidious-popular -D 'a'")},//   |
{ MODKEY,                       XK_F6,          spawn,                         CMD("ytfzf -D -H")},//                         |
//=============================================================================================================================
//                                                                                                                            |
//=============================================================================================================================
// ========================================>   MUSIC PLAYER COMMANDS   <======================================================|
{ MODKEY|ControlMask,           XK_space,       spawn,                          CMD("playerctl play-pause") },//              |
{ MODKEY|ControlMask,           XK_comma,       spawn,                          CMD("playerctl previous") },//                |
{ MODKEY|ControlMask,           XK_period,      spawn,                          CMD("playerctl next") },//                    |
//                                                                                                                            |
//=============================================================================================================================
// =======================================>    TERMINAL APPLICATIONS   <======================================================|
{ MODKEY,                       XK_o,           spawn,  CMD("alacritty --title='float-alacritty' -e pulsemixer") },//         |
{ MODKEY,                       XK_c,           spawn,  CMD("alacritty -e gotop") },//                                        |
{ MODKEY,                       XK_u,           spawn,  CMD("alacritty --title='float-alacritty' -e fish --command pu") },//  |
//=============================================================================================================================
//                                                                                                                            |
//=============================================================================================================================
{ MODKEY,                       XK_x,           spawn,                          {.v = lockcmd } },//                          |
{ MODKEY|ShiftMask,             XK_n,           spawn,                          CMD("vpn") },//                               |
{ MODKEY|ShiftMask,             XK_r,           spawn,                          CMD("apolybar")},//                           |
{ MODKEY,                       XK_r,           spawn,                          CMD("polywal")},//                            |
};//                                                                                                                          |
//=============================================================================================================================
//=============================================================================================================================

static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

