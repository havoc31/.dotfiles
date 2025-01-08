return {
    {
        "hrsh7th/cmp-nvim-lsp"
    },

    {
        "L3MON4D3/LuaSnip",
        dependencies = {
            "saadparwaiz1/cmp_luasnip",
            "rafamadriz/friendly-snippets",
        },
    },

    {
        "hrsh7th/nvim-cmp",
        config = function()
            local config = require("configs.cmp")
            require("luasnip.loaders.from_vscode").lazy_load()
            require("cmp").setup(config)
        end,
    },
}
