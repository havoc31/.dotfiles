return {
    "nvim-lualine/lualine.nvim",
    dependencies = { "nvim-tree/nvim-web-devicons" },
    config = function ()
        local config = require("configs.lualine")
        require("lualine").setup(config)
    end,
}
