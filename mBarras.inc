;====== Archivo de macros
;====== Barras

print MACRO cadena
    mov ah, 09h
    mov dx, @data 
    mov ds, dx
    mov dx, offset cadena 
    int 21h
ENDM

getChar MACRO
    mov ah, 01h
    int 21h
ENDM

;---------------------------------------
; ARCHIVOS
abrirA MACRO ruta, handle
    mov ah, 3dh
    mov al, 00h ; Abrir en modo lectura
    lea dx, ruta
    int 21h
    mov handle, ax
ENDM

leerA MACRO numbytes, buffer, handle 
    mov ah, 3fh
    mov bx, handle
    mov cx, numbytes
    lea dx, buffer
    int 21h

ENDM

cerrarA MACRO handle
    mov ah, 3ch
    mov handle, bx
    int 21h

ENDM

GuardarNumeros MACRO buffer, cantidad, arreglo, numero
    LOCAL INICIO, RECONOCER, GUARDAR, FIN, SALIR 

    xor bx, bx
    xor si, si
    xor di, di 

    INICIO:
        mov bl, buffer[si]      ;Lectura del archivo caracter con caracter

        cmp bl, 36              ; $
        je FIN
        cmp bl, 48              ; bl = 0
        jl SALIR                ; Saltar si bl < 48
        cmp bl, 57              ; bl = 9
        jg SALIR                ; Saltar si bl > 57

        jmp RECONOCER

    RECONOCER:
        mov bl, buffer[si]
        cmp bl, 48
        jl GUARDAR
        cmp bl, 57
        jg GUARDAR
        inc si
        mov numero[di], bl
        inc di

        jmp RECONOCER

    GUARDAR:
        push si
        
        ConvertirDec numero
        xor bx, bx
        mov bl, cantidad
        mov arreglo[bx], al
        ;....
        ;getChar 

        ;xor ax, ax
        ;cmp al, arreglo[bx]
        ;ConvertirString
        ;print numero
        ;....
        Limpiarbuffer numero, 20
        inc cantidad

        pop si

        xor bx, bx
        xor ax, ax

        jmp INICIO

    SALIR:
        inc si
        xor di, di 

        jmp INICIO

    FIN:
        xor ax, ax
        mov al, cantidad
        mov cantidad2, ax
ENDM

ConvertirDec MACRO numero
    LOCAL INICIO, FIN
    xor ax, ax
    xor bx, bx
    xor cx, cx

    mov bx, 10
    xor si, si

    INICIO:
        mov cl, numero[si]
        cmp cl, 48
        jl FIN 
        cmp cl, 57
        jg FIN 
        inc si
        sub cl, 48
        mul bx
        add ax, cx 
        jmp INICIO 
        
    FIN:
ENDM

Limpiarbuffer MACRO buffer, cant
    LOCAL INICIO, FIN
    xor bx, bx

    INICIO:
        mov buffer[bx], 36
        inc bx 
        cmp bx, cant
        je FIN 

        jmp INICIO

    FIN:
ENDM

copiarArreglo MACRO fuente, destino
    LOCAL INICIO, FIN
    xor si, si
    xor bx, bx

    INICIO:
        mov bl, cantidad 
        cmp si, bx 
        je FIN 
        mov al, fuente[si]
        mov destino[si],al
        inc si
        jmp INICIO

    FIN:
ENDM

DeterminarMayor MACRO
    LOCAL BURBUJA, VERIFICARMENOR, RESETEAR, FIN, MENOR 

    xor si, si
    xor ax, ax
    xor bx, bx
    xor cx, cx
    xor dx, dx 

    mov dx, cantidad2 
    dec dx 

    ;Ordenamiento decendente
    BURBUJA:
        mov al, arreglo[si]
        mov bl, arreglo[si+1]
        cmp al, bl 
        jl MENOR
        inc si
        inc cx 
        cmp cx, dx 
        jne BURBUJA

        mov cx, 0
        mov si, 0
        jmp VERIFICARMENOR

    MENOR: 
        mov arreglo[si], bl
        mov arreglo[si+1], al
        inc si
        inc cx 
        cmp cx, dx 
        jne BURBUJA
        mov cx, 0
        mov si, 0
        jmp VERIFICARMENOR

    VERIFICARMENOR:
        mov al, arreglo[si]
        mov bl, arreglo[si+1]
        cmp al, bl 
        jl RESETEAR
        inc si
        inc cx
        cmp cx, dx 
        jne VERIFICARMENOR
        jmp FIN 

    RESETEAR:
        mov al, 0
        mov cx, 0
        jmp BURBUJA
    FIN:
        xor ax, ax

        ;Guardar el número mayor
        mov al, arreglo[0]
        mov maximo, ax

ENDM

Burbuja MACRO 
    ; Convertir velocidad en Hz
    mov cl, 9
    sub cl, velocidad1
    inc cl 

    mov ax, 500
    mov bl, cl

    mul bl ; ax = ax * bl

    mov tiempo, ax

    BurbujaAsc


ENDM

BurbujaAsc MACRO 
    LOCAL BURBUJA, VERIFICARMAYOR, RESETEAR, FIN, MAYOR 

    
    xor si, si
    xor ax, ax
    xor bx, bx
    xor cx, cx
    xor dx, dx 

    mov dl, cantidad
    dec dx 

    Graficar arreglo

    BURBUJA:
        mov al, arreglo[si]
        mov bl, arreglo[si+1]
        cmp al, bl
        jg MAYOR
        inc si
        inc cx 
        cmp cx, dx 
        jne BURBUJA 
        mov cx, 0
        mov si, 0

        jmp VERIFICARMAYOR
    MAYOR:  
        mov arreglo[si], bl
        mov arreglo[si+1], si

        Graficar arreglo

        inc si 
        inc cx 

        cmp cx, dx 
        jne BURBUJA
        mov cx, 0
        mov si, 0

        jmp VERIFICARMAYOR

    VERIFICARMAYOR:
        mov al, arreglo[si]
        mov bl, arreglo[si+1]
        cmp al, bl 
        jl RESETEAR
        inc si
        inc cx
        cmp cx, dx 
        jne VERIFICARMAYOR
        jmp FIN 

    RESETEAR:
        mov al, 0
        mov cx, 0
        jmp BURBUJA

    FIN:
        GraficarFinal arreglo
    

ENDM

Graficar MACRO arreglo
    pushear ; Mete a pila todos los registros
    obtenerNumeros
    DeterminarTamano tamanioX, espacio, cantidad2, espaciador

    pushearVideo arreglo

    ModoGrafico
    imprimirVN numerosMOs, 16h, 02h     ;x, y

    poppearVideo arreglo
    graficarBarras cantidad2, espacio2, arreglo

    ModoTexto

    poppear ; Saca de la pila todos los registros
ENDM

ModoGrafico MACRO 
    ; Iniciar modo VIDEO
    mov ax, 0013h
    int 10h 

    mov ax, 0A000h
    mov ds, ax          ; DS = 0A000h (memoria de graficos ) (segmento de datos)
ENDM

imprimirVN MACRO cadena, fila, columna
    push ds 
    push dx 
    xor dx, dx 
    mov ah, 02h 
    mov bh, 0
    mov dh, fila
    mov dl, columna 
    int 10h 

    mov ax, @data 
    mov ds, ax 
    mov ah, 09
    mov dx, offset cadena 
    int 21h 

    pop dx 
    pop ds
ENDM

obtenerNumeros MACRO
    LOCAL INICIO, FIN
    pushear
    
    xor si, si 
    xor dx, dx 

    mov dl, cantidad 
    Limpiarbuffer numerosMos, 60

    INICIO:
        Limpiarbuffer resultado, 20
        cmp si, dx 
        je FIN 

        push si 
        push dx 

        xor ax, ax 

        mov al, arreglo[si]
        ConvertirString resultado 
        insertarNumero resultado

        pop dx 
        pop si
        inc si 
        jmp INICIO

    FIN:
    
    poppear
ENDM

ConvertirString MACRO buffer
    LOCAL DIVIDIR, DIVIDIR2, FINCR3, NEGATIVO, FIN2, FIN

    xor si, si 
    xor cx, cx 
    xor bx, bx 
    xor dx, dx 
    mov di, 10

    test ax, 1000000000000000
    jnz NEGATIVO 
    jmp DIVIDIR2

    NEGATIVO: 
        neg ax          ; Tiene el dato obtenido en el proceso anterior
        mov buffer[si], 45
        inc si 
        jmp DIVIDIR2

    DIVIDIR:
        xor ah, ah 
    
    DIVIDIR2:
        div dl  ; ax / al
        inc cx 
        push ax 
        cmp al, 00h     ; al = residuo de la división
        je FINCR3
        jmp DIVIDIR

    FINCR3:
        pop ax 
        add ah, 30h
        mov buffer[si], ah
        inc si 
        loop FINCR3
        mov ah, 24h
        mov buffer[si], ah
        inc si 
    FIN: 
ENDM

insertarNumero MACRO cadena
LOCAL INICIO, FIN, SIGUIENTE 
    xor si, si 
    xor di, di 

    INICIO:
        cmp si, 60
        je FIN 
        mov al, numerosMos[si]
        cmp al, 36
        je SIGUIENTE
        inc si 
        jmp INICIO

    SIGUIENTE:
        mov al, cadena[di]
        cmp al, 36
        je FIN 
        mov numerosMos[si], al 
        inc di 
        inc si 
        jmp SIGUIENTE

    FIN:
        mov numerosMos[si], 32
ENDM

DeterminarTamano MACRO tamanoX, espacio, cantidad, espaciador 
    mov ax, 260         ; Tamaño que tenemos para dibujar de largo
    mov bx, cantidad    ; Cantidad de datos que hay
    xor bh, bh 
    div bl              ; ax / bx - 260 / cantidad
    xor dx, dx 
    mov dl, al          ; Guardando el cosciente en dl
    mov espaciador, dx  ;Guardar en espaciador el cociente
    xor ah, ah 
    mov bl, 25 
    mul bl              ; 
    mov bl, 100
    div bl              ; Sacar el 25%

    mov espacio, al     ; Guardar el cociente en espacio, el 25%
    mov bx, espaciador
    sub bl, espacio     ; Restamos el espacio entre cada barra
    mov tamanoX, bx     ; Guardamos el ancho en tamañoX
ENDM

pushear MACRO 
    push ax 
    push bx 
    push cx 
    push dx
    push si 
    push di 
ENDM

poppear MACRO 
    pop di 
    pop si 
    pop dx 
    pop cx
    pop bx 
    pop ax  
ENDM

pushearVideo MACRO arreglo
    pushArreglo arreglo 
    push maximo 
    push tamanioX
    push espaciador
    push cantidad2
    push tiempo
ENDM

poppearVideo MACRO arreglo
    pop tiempo
    pop cantidad2
    pop espaciador
    pop tamanioX
    pop maximo 
    pophArreglo arreglo 

ENDM

pushArreglo MACRO arreglo
    LOCAL INICIO, FIN 
    xor si, si 
    INICIO:
        xor ax, ax 
        cmp si, cantidad2
        je FINmov al, arreglo[si]
        push ax 
        inc si 
        jmp INICIO 
    FIN:
ENDM

popArreglo MACRO arreglo
LOCAL INICIO, FIN 
    xor si, si
    mov si, cantidad2 
    dec si 
    INICIO: 
        cmp al, 0
        jl FIN 
        pop ax 
    FIN:
ENDM