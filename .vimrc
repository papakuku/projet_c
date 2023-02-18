set number
set tabstop=4
set shiftwidth=4
set autoindent
set mouse=a


call  plug#begin()

Plug 'vim-airline/vim-airline'
Plug  'scrooloose/nerdtree'


call  plug#end()




:map  <C-n>  :NERDTree    
:map <C-y> "+y
:map <C-p> "+p


