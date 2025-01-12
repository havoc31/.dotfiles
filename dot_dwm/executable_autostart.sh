#!/bin/sh

# Keyboard
setxkbmap 'us,ru' -option 'grp:alt_shift_toggle'
setxkbmap -option "ctrl:nocaps"

# Screen saver
xscreensaver --no-splash &

# dwmblocks
# xsetroot -name  " "
DWMBLOCKS_PATH="$HOME/.config/dwmblocks/scripts"
PATH="$PATH:$DWMBLOCKS_PATH" dwmblocks &
# dwmblocks &

# .Xresources
xrdb -merge $HOME/.Xresources

# Reload .Xresources
xdotool key Super+shift+F5

# Notifications
dunst & 


