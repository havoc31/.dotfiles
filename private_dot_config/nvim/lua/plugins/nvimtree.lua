return {
    "nvim-tree/nvim-tree.lua",
    version = "*",
    lazy = false,
    dependencies = {
        "nvim-tree/nvim-web-devicons",
    },

    config = function()
        local config = require("configs.nvimtree")
        require("nvim-tree").setup(config)
    end,
}


