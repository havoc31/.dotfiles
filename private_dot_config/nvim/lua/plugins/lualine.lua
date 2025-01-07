return {
    "nvim-lualine/lualine.nvim",
    dependencies = { "nvim-tree/nvim-web-devicons" },
    config = function()
        local config = require("lualine")
        config.setup({
            options = {
                theme = "modus-vivendi",
                section_separators = "",
                component_separators = ""
            }
        })
    end,
}
