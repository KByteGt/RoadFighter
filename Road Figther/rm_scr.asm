;======================= 
;	MACROS - Screen
;=======================

; Poner pantalla en modo texto
; ModoTexto
_ModoTexto macro 
	mov ax, 0003h
	int 10h
endm

_ModoVideo macro
	mov ah, 00h
	mov al, 13h
	int 10h
	mov ax, 0A000h
	mov es, ax  ; DS = A000h (memoria de graficos).
endm

delayModoVideo macro
	mov ah, 10h
	int 16h
endm

mDelay macro constante
    push ax
    mov ax,constante
    call delay
    pop ax
endm