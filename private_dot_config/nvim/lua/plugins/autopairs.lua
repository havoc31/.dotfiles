return {
    'windwp/nvim-autopairs',
    event = "InsertEnter",
    config = function()
        local config = require("nvim-autopairs")
        config.setup({ map_cr = true })
    end
}
