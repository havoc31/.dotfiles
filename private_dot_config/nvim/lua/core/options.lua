local g = vim.g
local o = vim.o
local opt = vim.opt

o.termguicolors = true

o.colorcolumn = "80"

o.number = true
o.relativenumber = true
o.numberwidth = 2
o.cursorline = true
o.signcolumn = "yes"

o.expandtab = true
o.smarttab = true
o.autoindent = true
o.tabstop = 4
o.shiftwidth = 4

o.ignorecase = true
o.smartcase = true

o.hlsearch = false

o.backup = false
o.writebackup = false
o.undofile = true
o.swapfile = false

o.history = 50

o.splitright = true
o.splitbelow = true

opt.mouse = "a"
opt.clipboard = "unnamedplus"

if g.neovide then
    o.guifont = "Fira Code:h9"
    g.neovide_scale_factor = 1.0

    g.neovide_padding_top = 10
    g.neovide_padding_bottom = 10
    g.neovide_padding_right = 10
    g.neovide_padding_left = 10

    g.neovide_position_animation_length = 0
    g.neovide_cursor_animation_length = 0.00
    g.neovide_cursor_trail_size = 0
    g.neovide_cursor_animate_in_insert_mode = false
    g.neovide_cursor_animate_command_line = false
    g.neovide_scroll_animation_far_lines = 0
    g.neovide_scroll_animation_length = 0.00
end
