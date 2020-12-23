;==> INCLUDES
include rf_mcro.asm; macros

.model small, stdcall
.286

.stack 64

.data 
    include rf_data.inc
    
org 100h
.code 

Inicio:
    include rf_menu.inc

Salir:
    mov ah, 04ch
    int 21h

end
