#!/bin/sh

# Keyboard
setxkbmap 'us,ru' -option 'grp:alt_shift_toggle'
setxkbmap -option "ctrl:nocaps"

# Screen saver
xscreensaver --no-splash &

# .Xresources
xrdb $HOME/.Xresources

# dwmblocks
xsetroot -name  " "
DWMBLOCKS_PATH="$HOME/.config/dwmblocks/scripts"
PATH="$PATH:$DWMBLOCKS_PATH" dwmblocks &

# Reload .Xresources
xdotool key Super+shift+F5

# Notifications
dunst & 
