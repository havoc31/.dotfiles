return { 
    "miikanissi/modus-themes.nvim", 
    lazy = false,
    priority = 1000,
    config = function()
        local modus = require("modus-themes")
        modus.setup({
            style = "modus_vivendi",    

            on_colors = function (colors)
                colors.bg_hl_line = colors.bg_active
            end,

            on_highlights = function (highlights, color)
                highlights.NvimTreeNormal.bg = color.black
            end,
        })
        vim.cmd.colorscheme("modus")
    end
}
