local null_ls = require("null-ls")

return {
    sources = {
        null_ls.builtins.diagnostics.ruff,
        null_ls.builtins.formatting.black,
    }
}

