return {
  "nvim-tree/nvim-tree.lua",
  version = "*",
  lazy = false,
  dependencies = {
    "nvim-tree/nvim-web-devicons",
  },
  config = function()
    local config = require("nvim-tree")
    config.setup({
        vim.keymap.set("n", "<F3>", ":NvimTreeToggle<CR>"),
        view = { side = "left", width = 40 },
        update_focused_file = { enable = true, update_cwd = false },
        renderer = {
          highlight_modified = "all",
          highlight_git = true,

          root_folder_label = false,

          icons = { webdev_colors = false, show = { folder_arrow = false } },
          indent_markers = { enable = true },
        }
    })
  end,
}


