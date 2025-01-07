return {
    "alexghergh/nvim-tmux-navigation",
    config = function()
        require("nvim-tmux-navigation").setup({})
        require("configs.tmux-navigation")
    end,
}
