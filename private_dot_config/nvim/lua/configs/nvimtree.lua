vim.keymap.set("n", "<F3>", ":NvimTreeToggle<CR>")

return {
    view = { side = "left", width = 40 },
    update_focused_file = { enable = true, update_cwd = false },
    renderer = {
        highlight_modified = "all",
        highlight_git = true,

        root_folder_label = false,

        icons = { 
            webdev_colors = true, 
            show = { folder_arrow = true }
        },

        indent_markers = { enable = true },
    }
}
