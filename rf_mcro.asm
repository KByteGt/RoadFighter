;==> M A C R O S


;Comparación de dos arreglos
;inicio: 
;mov al, arreglo1[si]
;mov bl, arreglo2[di]

;cmp al, bl
;jne et_fin

;cmp al, 36; $
;je opcion2;

;inc si
;inc dl

;jmp inicio

_PrintF MACRO txt

    ;Seve data ax y dx
    push ax
    push dx

    mov ah, 09h             ; Función visualizar cadena de caracteres
    mov dx, @data           ; Segmento de data
    mov ds, dx 
    mov dx, offset txt 
    int 21h                 ; Ejecutar interrupción de sistema

    ;Restore registers
    pop dx
    pop ax
ENDM

_ReadChar MACRO
    ; Read Char

    mov ah, 01h             ; Función entrada de caracter
    int 21h

    ;Return AL = ASCII of read char
ENDM

_ReadString MACRO buffer
    local for, end
    push cx 
    push si

    xor si, si
    for:
        _ReadChar
        cmp al, 0dh         ; Saldo de linea
        je end

        mov buffer[si], al
        inc si
        jmp for
    end: 
        mov al, 24h         ; al = $
        mov buffer[si], al

    pop si
    pop cx
    
ENDM

_ClrBuffer MACRO buffer
    local ciclo
    push si
    push cx

    xor si, si              ; Limpiamos registro, SI = 0    
    xor cx, cx              ; Limpiamos registro, CX = 0

    mov cx, SIZEOF buffer

    ciclo:
        mov buffer[si], '$'
        inc si
        loop ciclo

    pop cx
    pop si

ENDM

; Comparar dos cadenas
; Entrada: cadena1, cadena2, flag
; Salida: nada, solo modifica el valor de flag
_CMPString MACRO buffer1, buffer2, flag
    local for, same, diferent, end

    push si                
    push ax
    push cx

    xor si, si
    xor cx, cx

    mov cx, SIZEOF buffer1

    for:
        mov al, buffer1[si]
        cmp al, buffer2[si]
        jnz diferent
        inc si

        loop for

        mov flag, 1h    ; TRUE
        jmp end
    diferent:
        mov flag, 0h    ; FALSE

    end:
        pop cx
        pop ax
        pop si

ENDM

; Copia el contenido de una cadena a otra
; Entrada: cadena1, cadena2
; Salida: nada
_CopyString MACRO entrada, buffer
    local for, end

    push si
    push ax
    push cx
    ;push di
    xor si, si 
    xor cx, cx

    mov cx, SIZEOF entrada

    ;mov si, offset buffer
    ;mov di, offset entrada

    for:
        mov al, entrada[si]
        cmp al, '$'
        ;cmp byte prt[di], '$'   ; Condición de salida
        je end

        ;Guardar caracter por caracter
        ;mov bl, byte prt[di]
        ;mov byte ptr[si], bl
        mov buffer[si], al
        inc si 
        ;inc di
        ;jmp for
        loop for

    end:
        mov buffer[si], '$'
        ;mov byte ptr[si], '$'

    pop cx
    pop ax
    ;pop di 
    pop si
    
ENDM


_ModTxt MACRO 
    mov ax, 0003h
    int 10h
    
ENDM