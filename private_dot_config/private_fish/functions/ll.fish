function ll --wraps=ls --wraps='exa -l --icons' --description 'alias ll=exa -l --icons'
  exa -l --icons $argv
        
end
