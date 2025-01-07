return {
    "nvim-lualine/lualine.nvim",
    dependencies = { "nvim-tree/nvim-web-devicons" },
    config = function ()
        local config = require("lualine")

        local themes_path = vim.fn.stdpath("config")
        local custom_modus_vivendi = require("colors.modus-lualine")
        config.setup({
            options = {
                theme = custom_modus_vivendi,
                section_separators = "",
                component_separators = "",
            }
        })
    end,
}
