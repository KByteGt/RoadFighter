;======== Programa de barras
include mBarras.inc

.model small

.stack 100h

.data
    ;Manejo de menu
    velocidadmsg db 0ah, 0dh, 'Ingresar una velocidad (0-9)',32,'$'
    opcion          db  0ah, 0dh,'Seleccionar una opción: ',32,'$'
    opcion1         db  0ah, 0dh,'1. Cargar datos:  ',32,'$'
    opcion2         db  0ah, 0dh,'2. Graficas: ',32,'$'
    opcion3         db  0ah, 0dh,'3. Salir',32,'$'

    ;Manejo de archivo
    ruta            db 'entrada.xml', 00h
    handlerFichero  db  ?
    bufferLectura   db  100 dup('$')

    ;Variables de las graficas
    arreglo         db  30 dup(0); arreglo(30)
    arregloInicial  db  30 dup(0)
    arregloBurbuja  db  30 dup(0)

    velocidad1      db  0b
    cantidad        db  0b
    cantidad2       dw  0b
    maximo          dw  0b

    tiempo          dw  500

    tamanioX        dw  0
    espacio         db  0
    espaciador      dw  0

    espacio2        dw  0

    ;Variables extra
    numero          db  20 dup('$')
    numerosMos      db  60 dup('$')
    resultado       db  20 dup('$')

.code

    main proc
        Menu:
            print opcion1
            print opcion2
            print opcion3
            print opcion

            getChar

            cmp al, 49
            je CARGAR
            cmp al, 50
            je BUBBLE
            cmp al, 51
            je SALIR
            
            jmp Menu
;-----------------------------------------------------------------------------------
        CARGAR:
            abrirA ruta, handlerFichero
            leerA SIZEOF bufferLectura, bufferLectura, handlerFichero
            cerrarA handlerFichero

            GuardarNumeros bufferLectura, cantidad, arreglo, numero

            copiarArreglo arreglo, arregloInicial

            DeterminarMayor
            copiarArreglo arregloInicial, arreglo

            jmp Menu
;-----------------------------------------------------------------------------------
        BUBBLE:
            print velocidadmsg
            getChar
            sub al, 48
            mov velocidad1, al
            Burbuja 

            copiarArreglo arreglo, arregloBurbuja
            copiarArreglo arregloInicial, arreglo

            jmp Menu
;-----------------------------------------------------------------------------------
        SALIR:
            mov ah, 4ch
            int 21h
    main endp
end