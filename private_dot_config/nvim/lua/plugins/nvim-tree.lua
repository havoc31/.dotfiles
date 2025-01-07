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
        vim.keymap.set("n", "<F3>", ":NvimTreeToggle<CR>")
    })
  end,
}


