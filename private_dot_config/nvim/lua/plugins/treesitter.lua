return {
    {
        "nvim-treesitter/nvim-treesitter",
        build = ":TSUpdate",
        config = function()
            local config = require("configs.treesitter")
            require("nvim-treesitter.configs").setup(config)
        end
    }
}
