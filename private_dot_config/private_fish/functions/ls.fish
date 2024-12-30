function ls --wraps='exa -l --icon' --wraps='exa -l --icons' --description 'alias ls=exa -l --icons'
  exa -l --icons $argv
        
end
