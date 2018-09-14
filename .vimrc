execute pathogen#infect()
syntax on
filetype plugin indent on

"set t_Co=256

" Set ctrl + leftarrow to control window focus in VIM
nmap <silent> <A-Up> :wincmd k<CR> 
nmap <silent> <A-Down> :wincmd j<CR> 
nmap <silent> <A-Left> :wincmd h<CR> 
nmap <silent> <A-Right> :wincmd l<CR>

"easymotion
let g:EasyMotion_do_mapping=0
let g:EasyMotion_smartcase=1
map <Leader>j <Plug>(easymotion-j)
map <Leader>k <Plug>(easymotion-k)
map <Leader>l <Plug>(easymotion-bd-jk)
map <Leader>l <Plug>(easymotion-overwin-line)
map <Leader>w <Plug>(easymotion-bd-w)
map <Leader>w <Plug>(easymotion-overwin-w)

set background=dark
"let g:gruvbox_contrast_dark = 'light'
colorscheme gruvbox 

"syntastic
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*
let g:syntastic_always_populate_loc_list=1
let g:syntastic_auto_loc_list=1
let g:syntastic_check_on_open=0
let g:syntastic_check_on_wq=1
let g:syntastic_cpp_compiler_options=' -std=c++0x -Wno-c++11-extension'
let delimitMate_expand_cr=1
let delimitMate_expand_space=1

let g:cpp_class_scope_highlight=1
let g:cpp_member_variable_highlight=1
let g:cpp_class_decl_highlight=1

"ctags
set tags=tags

"remap ctrl-x ctrl-o to just ctrl-space
inoremap <C-@> <c-x><c-o>

let g:airline_powerline_fonts = 1

"JSBeautify
autocmd FileType javascript noremap <buffer>  <c-f> :call JsBeautify()<cr> 
" for json 
autocmd FileType json noremap <buffer> <c-f> :call JsonBeautify()<cr> 
" for jsx
autocmd FileType jsx noremap <buffer> <c-f> :call JsxBeautify()<cr> 
" for html
autocmd FileType html noremap <buffer> <c-f> :call HtmlBeautify()<cr> 
" for css or scss
autocmd FileType css noremap <buffer> <c-f> :call CSSBeautify()<cr>


set backup
set backupdir=~/.vim/backup//
set writebackup
set backupcopy=yes
au BufWritePre * let &bex = '@' . strftime("%F.%H:%M")

"tagbar bound to F8
nmap <F8> :TagbarToggle<CR>

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
