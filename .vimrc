execute pathogen#infect()
syntax on
filetype plugin indent on

"easymotion
let g:EasyMotion_do_mapping = 0
let g:EasyMotion_smartcase = 1
map <Leader>j <Plug>(easymotion-j)
map <Leader>k <Plug>(easymotion-k)
map <Leader>l <Plug>(easymotion-bd-jk)
map <Leader>l <Plug>(easymotion-overwin-line)
map <Leader>w <Plug>(easymotion-bd-w)
map <Leader>w <Plug>(easymotion-overwin-w)

set background=dark
let g:gruvbox_contrast_dark = 'medium'
colorscheme gruvbox 

"syntastic
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*
let g:syntastic_always_populate_loc_list=1
let g:syntastic_auto_loc_list=1
let g:syntastic_check_on_open=0
let g:syntastic_check_on_wq=1
let g:syntastic_cpp_compiler_options = ' -std=c++0x -Wno-c++11-extension'
let delimitMate_expand_cr = 1
let delimitMate_expand_space = 1

let g:cpp_class_scope_highlight = 1
let g:cpp_member_variable_highlight = 1
let g:cpp_class_decl_highlight = 1

"remap ctrl-x ctrl-o to just ctrl-space
inoremap <C-@> <c-x><c-o>

set number
set ruler
set laststatus=2
set showmode
set cursorline
set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set smarttab
set nojoinspaces
set shiftround
set autoindent
set showmatch
set list
set nofoldenable
