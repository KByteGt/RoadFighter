
MENU proc
    _ModTxt             ; Limpia la pantalla
    ;Print init menu
    _PrintF menu_1

    ;Read answerd
    _ReadChar           ; AL = ASCII char readed
    _PrintF CRLF
    cmp al, 49          ; AL = 1
    je LOGIN
    cmp al, 50          ; AL = 2
    je SINGUP
    cmp al, 51          ; AL = 3
    je EXIT
    ;jne MENU

    jmp MENU            ; Imprimir menú

MENU endp

SINGUP proc
    ; SingUp user
    _ModTxt 
    _PrintF menu_singup 

    ; Limpiar variable (inUser)
    _ClrBuffer inUser
    ; Imprimir texto
    _PrintF txt_inUser
    ;Leer cadena, (nombre de usuario)
    _ReadString inUser

    ; Limpiamos variable (inPass)
    _ClrBuffer inPass
    ; Imprimir txto
    _PrintF txt_inPass
    ; Leer cadena, (Contraseña de usuario)
    _ReadString inPass

    ; Buscar usuario
    call SEARCH_USER
    ; AL = status de la busqueda
    ; 00h - No existe
    ; 01h - Admin
    ; 02h - Usuario normal

    cmp al, 00h
    je singup_error
    cmp al, 01h
    je singup_admin
    cmp al, 02h
    je Singup_user

    singup_error:

    singup_admin:

    Singup_user:

    singup_end:
        ret

SINGUP endp

LOGIN proc

    login_menu:
        ; LogIn user
        _ModTxt 
        _PrintF menu_login 

        ; Limpiar variable (inUser)
        _ClrBuffer inUser
        ; Imprimir texto
        _PrintF txt_inUser
        ;Leer cadena, (nombre de usuario)
        _ReadString inUser

        ; Limpiamos variable (inPass)
        _ClrBuffer inPass
        ; Imprimir txto
        _PrintF txt_inPass
        ; Leer cadena, (Contraseña de usuario)
        _ReadString inPass

        ; Buscar usuario
        call SEARCH_USER
        ; AL = status de la busqueda
        ; 00h - No existe
        ; 01h - Admin
        ; 02h - Usuario normal

        cmp al, 00h
        je singup_error
        cmp al, 01h
        je singup_admin
        cmp al, 02h
        je Singup_user

    singup_error:
        _PrintF msg_log02       ; Mostrar msg_log02 (Usuario o contraseña incorrectas)
        _ReadChar               ; Esperar lectura en teclado

        jmp login_menu          ; Mostrar LOGIN

    singup_admin:
        call SESSION_ADMIN
        jmp singup_end

    Singup_user:
        call SESSION_USER
        jmp singup_end

    singup_end:
        ret

LOGIN endp

EXIT proc
    _ModTxt 
    _PrintF txt_exit
    ; Exit program
    mov ah, 04ch
    int 21h
EXIT endp

;==> BUSQUEDA DE USUARIO
;   variable a usar (inUSer)
;   salida: AL = status
;   se almacena el usuario en (userName)
SEARCH_USER proc
    cmp inUser[0], '$'
    je notExist

    ;Comparar cadena con ADMIN
    _CMPString userAdmin, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassAdmin       ; Es admin, validar password

    ;Comparar cadena con User1
    _CMPString user1, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser1
    ;Comparar cadena con User2
    _CMPString user2, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser2
    ;Comparar cadena con User3
    _CMPString user3, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser3
    ;Comparar cadena con User4
    _CMPString user4, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser4
    ;Comparar cadena con User5
    _CMPString user5, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser5
    ;Comparar cadena con User6
    _CMPString user6, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser6
    ;Comparar cadena con User7
    _CMPString user7, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser7
    ;Comparar cadena con User8
    _CMPString user8, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser8
    ;Comparar cadena con User9
    _CMPString user9, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser9
    ;Comparar cadena con User10
    _CMPString user10, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser10
    ;Comparar cadena con User11
    _CMPString user11, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser11
    ;Comparar cadena con User12
    _CMPString user12, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser12
    ;Comparar cadena con User13
    _CMPString user13, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser13
    ;Comparar cadena con User14
    _CMPString user14, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser14
    ;Comparar cadena con User15
    _CMPString user15, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser15
    ;Comparar cadena con User16
    _CMPString user16, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser16
    ;Comparar cadena con User17
    _CMPString user17, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser17
    ;Comparar cadena con User18
    _CMPString user18, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser18
    ;Comparar cadena con User19
    _CMPString user19, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser19
    ;Comparar cadena con User20
    _CMPString user20, inUser, flagCMP
    cmp flagCMP, 1h
    jz vPassUser20
    jnz notExist

    vPassAdmin:
        ;Comparar cadena con Password
        _CMPString passAdmin, inPass, flagCMP
        cmp flagCMP, 1h   
        jz isAdmin      ; Contraseña igual, AL = 01h
        jnz endSearch   ; La contraseña no es igual

    vPassUser1:
        _CMPString pass1, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user1, userName
        jmp isUser

    vPassUser2:
        _CMPString pass2, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user2, userName
        jmp isUser

    vPassUser3:
        _CMPString pass3, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user3, userName
        jmp isUser

    vPassUser4:
        _CMPString pass4, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user4, userName
        jmp isUser

    vPassUser5:
        _CMPString pass5, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user5, userName
        jmp isUser

    vPassUser6:
        _CMPString pass6, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user6, userName
        jmp isUser

    vPassUser7:
        _CMPString pass7, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user7, userName
        jmp isUser

    vPassUser8:
        _CMPString pass8, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user8, userName
        jmp isUser

    vPassUser9:
        _CMPString pass9, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user9, userName
        jmp isUser

    vPassUser10:
        _CMPString pass10, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user10, userName
        jmp isUser

    vPassUser11:
        _CMPString pass11, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user11, userName
        jmp isUser

    vPassUser12:
        _CMPString pass12, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user12, userName
        jmp isUser

    vPassUser13:
        _CMPString pass13, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user13, userName
        jmp isUser

    vPassUser14:
        _CMPString pass14, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user14, userName
        jmp isUser

    vPassUser15:
        _CMPString pass15, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user15, userName
        jmp isUser

    vPassUser16:
        _CMPString pass16, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user16, userName
        jmp isUser

    vPassUser17:
        _CMPString pass17, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user17, userName
        jmp isUser

    vPassUser18:
        _CMPString pass18, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user18, userName
        jmp isUser

    vPassUser19:
        _CMPString pass19, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user19, userName
        jmp isUser

    vPassUser20:
        _CMPString pass20, inPass, flagCMP
        cmp flagCMP, 1h
        jnz endSearch   ; La contraseña no es igual
        ;Copiar usuario a (userName)
        _CopyString user20, userName
        jmp isUser

    isAdmin:
        mov al, 01h
        jmp endSearch

    isUser:
        mov al, 02h
        jmp endSearch

    notExist:
        mov al, 00h

    endSearch:
        ret

SEARCH_USER endp

;==> MENU DE USUARIO
SESSION_USER proc
    user_menu:
        ; Imprimir menu
        _ModTxt             ; Limpiar pantalla
        _PrintF menu_user
        _ReadChar           ; AL = ASCII char readed
        _PrintF CRLF
        cmp al, 49          ; AL = 1
        je user_game
        cmp al, 50          ; AL = 2
        je user_upload
        cmp al, 51          ; AL = 3
        je user_end

    user_game:
        ;Iniciar Juego Road Figther

        jmp admin_menu

    user_upload:
        ;Cargar archivos de juego

        jmp admin_menu

    user_end:
        ret
SESSION_USER endp

;==>  MENU DE ADMIN
SESSION_ADMIN proc
    admin_menu:
        ; Imprimir menu
        _ModTxt             ; Limpiar pantalla
        _PrintF menu_admin
        _ReadChar           ; AL = ASCII char readed
        _PrintF CRLF
        cmp al, 49          ; AL = 1
        je admin_topPTS
        cmp al, 50          ; AL = 2
        je admin_topTMS
        cmp al, 51          ; AL = 3
        je admin_end

    admin_topPTS:
        ;Mostrar Top 10 putos

        jmp admin_menu

    admin_topTMS:
        ;Mostrar Top 10 tiempos

        jmp admin_menu

    admin_end:
        ret
SESSION_ADMIN endp