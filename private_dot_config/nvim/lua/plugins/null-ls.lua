return {
    "jose-elias-alvarez/null-ls.nvim",
    dependencies = { "nvim-lua/plenary.nvim" },
    config = function()
        local config = require("configs.null-ls")
        require("null-ls").setup(config)
    end
}
