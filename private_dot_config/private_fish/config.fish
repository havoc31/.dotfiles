set fish_greeting

if status is-interactive
    # Commands to run in interactive sessions can go here
end

zoxide init fish | source

# Exports
export EDITOR="nvim"
export MANPAGER="nvim +Man!"
