;================================ REGISTRAR USUARIO ===================================
registrarUsuario proc
	_Print saltoln
	USUARIO:
		_Print msjRegUser
		leerCadena entradaU
		mVerificarTamanoUsuario entradaU
		cmp al, 0d
		je ERRORTAM
		VERIUSUARIO:
			call verficarExistenciadeUsuario
			cmp al, 1d
			je CONTRASENA
			YAEXISTE:
				mWrite <'-ADVERTENCIA: El usuario ya esta registrado. Intentelo con uno nuevo por favor'>
				_Print saltoln
				jmp USUARIO
		ERRORTAM:
				mWrite <'-ADVERTENCIA: Numero de caracteres de usuario excedido. Intentelo de nuevo por favor'>
				_Print saltoln
				jmp USUARIO
	CONTRASENA:
		_Print msjRegContra
		leerCadena entradaC
		mVerificarTamanoContrasena entradaC
		cmp al, 0d
		je ERRORCON
		VERICONTRA:
			mComprobarSiNumero entradaC
			cmp al, 0d
			je NONUMERO
			call guardarUsuario
			mWrite <'Usurio registrado exitosamente.'>
			leerChar
			cmp numBarras, 20d
			je NOINC
			inc numBarras
			NOINC:
				limpiarCadena entradaU,SIZEOF entradaU,'$'
				limpiarCadena entradaC,SIZEOF entradaC,'$'
				jmp SalirU
			NONUMERO:
				mWrite <'-ADVERTENCIA: Contrasena no valida.'>
				_Print saltoln
				jmp CONTRASENA
		ERRORCON:
			mWrite <'-ADVERTENCIA: Tamano de contrasena incorrecta.'>
			_Print saltoln
			jmp CONTRASENA
	SalirU:
		ret

registrarUsuario endp



verficarExistenciadeUsuario proc
	;verifico con el administrador
	compararCadena entradaU,userAdmin
	je YAEXISTE
	;verifico si esta lleno el usuario y si si lo comparo
	cmp usuario1[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario1
	je YAEXISTE
	cmp usuario2[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario2
	je YAEXISTE
	cmp usuario3[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario3
	je YAEXISTE
	cmp usuario4[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario4
	je YAEXISTE
	cmp usuario5[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario5
	je YAEXISTE
	cmp usuario6[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario6
	je YAEXISTE
	cmp usuario7[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario7
	je YAEXISTE
	cmp usuario8[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario8
	je YAEXISTE
	cmp usuario9[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario9
	je YAEXISTE
	cmp usuario10[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario10
	je YAEXISTE
	cmp usuario11[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario11
	je YAEXISTE
	cmp usuario12[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario12
	je YAEXISTE
	cmp usuario13[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario13
	je YAEXISTE
	cmp usuario14[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario14
	je YAEXISTE
	cmp usuario15[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario15
	je YAEXISTE
	cmp usuario16[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario16
	je YAEXISTE
	cmp usuario17[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario17
	je YAEXISTE
	cmp usuario18[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario18
	je YAEXISTE
	cmp usuario19[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario19
	je YAEXISTE
	cmp usuario20[0],'$'
	je NOEXISTE
	compararCadena entradaU, usuario20
	je YAEXISTE
	jmp NOEXISTE
	YAEXISTE:
		mov al, 0d
		jmp SalirE
	NOEXISTE:
		mov al, 1d
	SalirE:
		ret

verficarExistenciadeUsuario endp



ComprobarSiNumero proc
	INICIO:
		cmp bl, 4d
		je FIN
		mov cl, byte ptr[di]
		cmp cl, 48d
		jl ERROR
		cmp cl, 57d
		jg ERROR
		inc bl
		inc di
		jmp INICIO
	ERROR:
		mov al, 0d
		jmp SalirC
	FIN:
		mov al, 1d
	SalirC:
		ret

ComprobarSiNumero endp



guardarUsuario proc
	cmp usuario1[0],'$'
	je GUARDAR1
	cmp usuario2[0],'$'
	je GUARDAR2
	cmp usuario3[0],'$'
	je GUARDAR3
	cmp usuario4[0],'$'
	je GUARDAR4
	cmp usuario5[0],'$'
	je GUARDAR5
	cmp usuario6[0],'$'
	je GUARDAR6
	cmp usuario7[0],'$'
	je GUARDAR7
	cmp usuario8[0],'$'
	je GUARDAR8
	cmp usuario9[0],'$'
	je GUARDAR9
	cmp usuario10[0],'$'
	je GUARDAR10
	cmp usuario11[0],'$'
	je GUARDAR11
	cmp usuario12[0],'$'
	je GUARDAR12
	cmp usuario13[0],'$'
	je GUARDAR13
	cmp usuario14[0],'$'
	je GUARDAR14
	cmp usuario15[0],'$'
	je GUARDAR15
	cmp usuario16[0],'$'
	je GUARDAR16
	cmp usuario17[0],'$'
	je GUARDAR17
	cmp usuario18[0],'$'
	je GUARDAR18
	cmp usuario19[0],'$'
	je GUARDAR19
	cmp usuario20[0],'$'
	je GUARDAR20
	jmp GUARDAR20
	GUARDAR1:
		mCopiarCadena usuario1, entradaU
		mCopiarCadena contra1, entradaC
		jmp FINISHG
	GUARDAR2:
		mCopiarCadena usuario2, entradaU
		mCopiarCadena contra2, entradaC
		jmp FINISHG
	GUARDAR3:
		mCopiarCadena usuario3, entradaU
		mCopiarCadena contra3, entradaC
		jmp FINISHG
	GUARDAR4:
		mCopiarCadena usuario4, entradaU
		mCopiarCadena contra4, entradaC
		jmp FINISHG
	GUARDAR5:
		mCopiarCadena usuario5, entradaU
		mCopiarCadena contra5, entradaC
		jmp FINISHG
	GUARDAR6:
		mCopiarCadena usuario6, entradaU
		mCopiarCadena contra6, entradaC
		jmp FINISHG
	GUARDAR7:
		mCopiarCadena usuario7, entradaU
		mCopiarCadena contra7, entradaC
		jmp FINISHG
	GUARDAR8:
		mCopiarCadena usuario8, entradaU
		mCopiarCadena contra8, entradaC
		jmp FINISHG
	GUARDAR9:
		mCopiarCadena usuario9, entradaU
		mCopiarCadena contra9, entradaC
		jmp FINISHG
	GUARDAR10:
		mCopiarCadena usuario10, entradaU
		mCopiarCadena contra10, entradaC
		jmp FINISHG
	GUARDAR11:
		mCopiarCadena usuario11, entradaU
		mCopiarCadena contra11, entradaC
		jmp FINISHG
	GUARDAR12:
		mCopiarCadena usuario12, entradaU
		mCopiarCadena contra12, entradaC
		jmp FINISHG
	GUARDAR13:
		mCopiarCadena usuario13, entradaU
		mCopiarCadena contra13, entradaC
		jmp FINISHG
	GUARDAR14:
		mCopiarCadena usuario14, entradaU
		mCopiarCadena contra14, entradaC
		jmp FINISHG
	GUARDAR15:
		mCopiarCadena usuario15, entradaU
		mCopiarCadena contra15, entradaC
		jmp FINISHG
	GUARDAR16:
		mCopiarCadena usuario16, entradaU
		mCopiarCadena contra16, entradaC
		jmp FINISHG
	GUARDAR17:
		mCopiarCadena usuario17, entradaU
		mCopiarCadena contra17, entradaC
		jmp FINISHG
	GUARDAR18:
		mCopiarCadena usuario18, entradaU
		mCopiarCadena contra18, entradaC
		jmp FINISHG
	GUARDAR19:
		mCopiarCadena usuario19, entradaU
		mCopiarCadena contra19, entradaC
		jmp FINISHG
	GUARDAR20:
		mCopiarCadena usuario20, entradaU
		mCopiarCadena contra20, entradaC
		jmp FINISHG
	FINISHG:
		ret

guardarUsuario endp



copiarCadena proc
	INICIOCC:
	cmp byte ptr[di],'$' ;pregunto si no es dolar el caracter de entrada
	je FINALIZO
	;Guardo caracter por caracter mov buffer,entrada
	mov bl, byte ptr[di]
	mov byte ptr[si], bl
	inc si


	inc di
	jmp INICIOCC
	FINALIZO:
		mov byte ptr[si],'$'
		ret

copiarCadena endp



copiarInformacion proc
	;di = buffer
	;si = posicion del caracter a copiar
	INICIOCI:
		cmp bufferInformacion[si],','
		je FIN
		cmp bufferInformacion[si], 59d  ; ";"
		je FIN
		;Guardo caracter por caracter mov buffer,entrada
		mov bl, bufferInformacion[si]
		mov byte ptr[di], bl
		inc si
		inc di
		jmp INICIOCI
	FIN:
		ret

copiarInformacion endp


copiarPersonaje proc
	;di = buffer
	;si = posicion del caracter a copiar
	INICIOCP:
		cmp bufferInformacion[si],13d ;13d = retorno de carro
		je FIN
		;Guardo caracter por caracter mov buffer,entrada
		mov bl, bufferInformacion[si]
		mov byte ptr[di], bl
		inc si
		inc di
		jmp INICIOCP
	FIN:
		ret

copiarPersonaje endp


imprimirUsuario proc
	;---------------------------------------------------------------------------------
        ;   Recibe:      ax = numero de Usuario
		;
        ;
        ;   Devuelve:    nada
        ;
        ;   Comentarios: Imprime en pantalla el usuario correspondiente a su numero
        ;----------------------------------------------------------------------------
    cmp ax, 1d
    je U1
	cmp ax, 2d
    je U2
    cmp ax, 3d
    je U3
    cmp ax, 4d
    je U4
    cmp ax, 5d
    je U5
    cmp ax, 6d
    je U6
    cmp ax, 7d
    je U7
    cmp ax, 8d
    je U8
    cmp ax, 9d
    je U9
    cmp ax, 10d
    je U10
    cmp ax, 11d
    je U11
    cmp ax, 12d
    je U12
    cmp ax, 13d
    je U13
    cmp ax, 14d
    je U14
    cmp ax, 15d
    je U15
    cmp ax, 16d
    je U16
    cmp ax, 17d
    je U17
    cmp ax, 18d
    je U18
    cmp ax, 19d
    je U19
    cmp ax, 20d
    je U20
    jmp FIN
    U1:
    	_Print usuario1
    	jmp FIN
    U2:
    	_Print usuario2
    	jmp FIN
    U3:
    	_Print usuario3
    	jmp FIN
    U4:
    	_Print usuario4
    	jmp FIN
    U5:
    	_Print usuario5
    	jmp FIN
    U6:
    	_Print usuario6
    	jmp FIN
    U7:
    	_Print usuario7
    	jmp FIN
    U8:
    	_Print usuario8
    	jmp FIN
    U9:
    	_Print usuario9
    	jmp FIN
    U10:
    	_Print usuario10
    	jmp FIN
    U11:
    	_Print usuario11
    	jmp FIN
    U12:
    	_Print usuario12
    	jmp FIN
    U13:
    	_Print usuario13
    	jmp FIN
    U14:
    	_Print usuario14
    	jmp FIN
    U15:
    	_Print usuario15
    	jmp FIN
    U16:
    	_Print usuario16
    	jmp FIN
    U17:
    	_Print usuario17
    	jmp FIN
    U18:
    	_Print usuario18
    	jmp FIN
    U19:
    	_Print usuario19
    	jmp FIN
    U20:
    	_Print usuario20
   	FIN:
   		ret

imprimirUsuario endp


;============================= INGRESAR USUARIO ===============================
ingresarUsuario proc
	_Print saltoln
	INGRESO:
		limpiarCadena entradaU,SIZEOF entradaU,'$'
		limpiarCadena entradaC,SIZEOF entradaC,'$'
		_Print msjU
		leerCadena entradaU
		_Print msjC
		leerCadena entradaC
		call buscarUsuario
		cmp al, 0d
		je INCO
		cmp al, 1d
		je REGUS
		cmp al, 2d
		je REGAD
		INCO:
			mWrite <'Usuario o contrasena incorrecta.'>
			_Print saltoln
			jmp INGRESO
		REGUS:
			call SesionUsuario
			jmp TERMINAR
		REGAD:
			call SesionAdministrador
			jmp TERMINAR
		TERMINAR:
			ret

ingresarUsuario endp


buscarUsuario proc
	cmp entradaU[0],'$' ;en caso de que le de enter a los dos
	je NOEXISTE
	cmp entradaC[0],'$'
	je NOEXISTE
	;COMPARAR CON ADMISTRADOR
	compararCadena userAdmin, entradaU
	je UADMIN
	;COMPARAR CON LOS USUARIOS
	compararCadena usuario1, entradaU
	je U1
	compararCadena usuario2, entradaU
	je U2
	compararCadena usuario3, entradaU
	je U3
	compararCadena usuario4, entradaU
	je U4
	compararCadena usuario5, entradaU
	je U5
	compararCadena usuario6, entradaU
	je U6
	compararCadena usuario7, entradaU
	je U7
	compararCadena usuario8, entradaU
	je U8
	compararCadena usuario9, entradaU
	je U9
	compararCadena usuario10, entradaU
	je U10
	compararCadena usuario11, entradaU
	je U11
	compararCadena usuario12, entradaU
	je U12
	compararCadena usuario13, entradaU
	je U13
	compararCadena usuario14, entradaU
	je U14
	compararCadena usuario15, entradaU
	je U15
	compararCadena usuario16, entradaU
	je U16
	compararCadena usuario17, entradaU
	je U17
	compararCadena usuario18, entradaU
	je U18
	compararCadena usuario19, entradaU
	je U19
	compararCadena usuario20, entradaU
	je U20
	jmp NOEXISTE
	UADMIN:
		compararCadena contraAdmin, entradaC
		je ESADMIN
		jne NOEXISTE
	U1:
		compararCadena contra1, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario1 ;guardo ya que se logueo
		jmp EXISTE
	U2:
		compararCadena contra2, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario2
		jmp EXISTE
	U3:
		compararCadena contra3, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario3
		jmp EXISTE
	U4:
		compararCadena contra4, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario4
		jmp EXISTE
	U5:
		compararCadena contra5, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario5
		jmp EXISTE
	U6:
		compararCadena contra6, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario6
		jmp EXISTE
	U7:
		compararCadena contra7, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario7
		jmp EXISTE
	U8:
		compararCadena contra8, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario8
		jmp EXISTE
	U9:
		compararCadena contra9, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario9
		jmp EXISTE
	U10:
		compararCadena contra10, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario10
		jmp EXISTE
	U11:
		compararCadena contra11, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario11
		jmp EXISTE
	U12:
		compararCadena contra12, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario12
		jmp EXISTE
	U13:
		compararCadena contra13, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario13
		jmp EXISTE
	U14:
		compararCadena contra14, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario14
		jmp EXISTE
	U15:
		compararCadena contra15, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario15
		jmp EXISTE
	U16:
		compararCadena contra16, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario16
		jmp EXISTE
	U17:
		compararCadena contra17, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario17
		jmp EXISTE
	U18:
		compararCadena contra18, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario18
		jmp EXISTE
	U19:
		compararCadena contra19, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario19
		jmp EXISTE
	U20:
		compararCadena contra20, entradaC
		jne NOEXISTE
		mCopiarCadena usuarioLogueado, usuario20
		jmp EXISTE
	ESADMIN:
		mov al, 2d
		jmp FINAL
	EXISTE:
		mov al, 1d
		jmp FINAL
	NOEXISTE:
		mov al, 0d
	FINAL:
		ret

buscarUsuario endp

;======================= SESION DE USUARIO ==================================
SesionUsuario proc
	MenuUsuario:
		_ModoTexto ;limpia la pantalla
		_Print encabezado
		_Print menuUser
		_Print escoja
		leerChar
		cmp al, '1'
		je Iniciar
		cmp al, '2'
		je Cargar
		cmp al, '3'
		je SalirMU
		jmp MenuUsuario
		Iniciar:
			cmp juegoCargado, 0d
			je NOCARGADO
			mIniciarJuego
			_ModoTexto ;para escribir en la pantalla normal
			mWrite<'JUEGO TERMINADO!'>
			_Print saltoln
			mWrite <'Informacion de partida jugada guardada!'>
			leerChar
			jmp MenuUsuario
			NOCARGADO:
				_Print saltoln
				mWrite<'No se ha cargado las configuraciones del juego.'>
				leerChar
			jmp MenuUsuario
		Cargar:
			;mCargarJuego
			call cargarJuego
			jmp MenuUsuario
		SalirMU:
			ret

SesionUsuario endp

;=================================== INICIAR JUEGO ==============================
iniciarJuego proc
	mSetUp
	mGame
	ret

iniciarJuego endp

;=================================== CARGAR JUEGO ===========================

cargarJuego proc
	CARGA:
		limpiarCadena bufferentrada, SIZEOF bufferentrada, 24h; limpia la cadena con caracteres de dolar
		_Print saltoln
		mWrite<' | > Ingrese la ruta del archivo de entrada:'>
		_Print saltoln
		leerRuta bufferentrada
		abrirFichero bufferentrada, handlerentrada
		cmp siabrio, 0d
		je CARGA

		mWrite<' | - Archivo abierto.'>
		limpiarCadena bufferInformacion, SIZEOF bufferInformacion, 24h
		leerFichero handlerentrada, bufferInformacion, SIZEOF bufferInformacion ;numero de bytes maximo a leer
		cerrarFichero handlerentrada
		mWrite<' ..'>
		_Print saltoln
		_Print bufferInformacion
		;call almacenarConfiguracion
		call ConfiguracionNiveles
		_Print saltoln
		mWrite<' | - Archivo de entrada cargado exitosamente.'>
		mov juegoCargado, 1d
		leerChar
		ret

cargarJuego endp

;=======================================================================================
; Lee el archivo y almacena la configuración para los 
; 3 niveles únicos, delimitado por "," y fin de línea ";"
; NIVEL,nivel,TiempoNivel,TiempoObstaculos,TiempoPremio,PuntosObstaculos,PuntosPremios;
;=======================================================================================
ConfiguracionNiveles proc 
	push si 

	xor si, si 
	; La información se almacena en: bufferInformacion[]
	FORLEVEL1:
		L_1:
			cmp bufferInformacion[si], ',' ; Compara con ","
			je LEVEL_1
			inc si 
			jmp L_1

		; Configuración nivel 1
		LEVEL_1: 					
			; Obtener el número del nivel
			inc si 
			mov al, bufferInformacion[si]
			mov nombreNivel1[0], al 
			inc si
			inc si
			; Obtener tiempo de nivel
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov TiempoNivel1, ax

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener tiempo obstaculos
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov tiempo1Obs, al

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener tiempo premio
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov tiempo1Premio, al

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener puntos obstaculos
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov puntosObsN1, ax

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener puntos premio
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov puntosPremiosN1, ax

			cmp bufferInformacion[si], 59d ;Fin de linea 3Bh = 59d = ;
			je L_2
			jne LEVEL_END


		L_2:
			cmp bufferInformacion[si], ',' ; Compara con ","
			je LEVEL_2
			inc si 
			jmp L_2

		LEVEL_2:
			; Configuración nivel 2
			; Obtener el número del nivel
			inc si 
			mov al, bufferInformacion[si]
			mov nombreNivel2[0], al 
			inc si
			inc si
			; Obtener tiempo de nivel
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov TiempoNivel2, ax

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener tiempo obstaculos
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov tiempo2Obs, al

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener tiempo premio
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov tiempo2Premio, al

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener puntos obstaculos
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov puntosObsN2, ax

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener puntos premio
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov puntosPremiosN2, ax

			cmp bufferInformacion[si], 59d ;Fin de linea 3Bh = 59d = ;
			je L_3
			jne LEVEL_END

		L_3:
			cmp bufferInformacion[si], ',' ; Compara con ","
			je LEVEL_3
			inc si 
			jmp L_3

		LEVEL_3:
			; Configuración nivel 2
			; Obtener el número del nivel
			inc si 
			mov al, bufferInformacion[si]
			mov nombreNivel3[0], al 
			inc si
			inc si
			; Obtener tiempo de nivel
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov TiempoNivel3, ax

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener tiempo obstaculos
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov tiempo3Obs, al

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener tiempo premio
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov tiempo3Premio, al

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener puntos obstaculos
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov puntosObsN3, ax

			limpiarCadena bufferaux, SIZEOF bufferaux, 24h
			inc si
			; Obtener puntos premio
			mCopiarInformacion bufferaux
			ConvertirAscii bufferaux ;numero en ax
			mov puntosPremiosN3, ax

		LEVEL_END:
		_Print saltoln
		mWrite <' | NIVEL: '>
		_Print nombreNivel1
		_Print saltoln
		mWrite <' | NIVEL: '>
		_Print nombreNivel2
		_Print saltoln
		mWrite <' | NIVEL: '>
		_Print nombreNivel3
		_Print saltoln
	pop si
	ret
ConfiguracionNiveles endp

;======================= SESION DE ADMINISTRADOR ============================
SesionAdministrador proc
	MenuManager:
		_ModoTexto ;limpia la pantalla
		_Print encabezado
		_Print menuAdmin
		_Print escoja
		leerChar
		cmp al, '1'
		je TOPPUNTOS
		cmp al, '2'
		je TOPTIEMPO
		cmp al, '3'
		je SalirMA
		jmp MenuManager
		TOPPUNTOS:
			_ModoTexto
			mTop10Puntos
			jmp MenuManager
		TOPTIEMPO:
			_ModoTexto
			mTop10Tiempo
			jmp MenuManager
		SalirMA:
			ret

SesionAdministrador endp

;============================ TOP 10 PUNTOS ===============================

Top10Puntos proc
	mCalcularPuntosDescendente
	mMostrarTopPuntos
	leerChar
	mArchivoTopPuntos
	leerChar
	cmp al,20h		;barra espaciadora
	je BARRAS
	jmp FIN
	BARRAS:
		mIniciarBarrasPuntos
	FIN:
		ret

Top10Puntos endp


calcularPuntosDescendente proc
	;--------------------------------------------------------------------
        ;   Recibe:      si = para recorrer en i
		;				 di = para recorrer en j
        ;                ax = auxiliar
        ;   Devuelve:    nada
        ;
        ;   Comentarios: Ordena en forma descendente para el top puntos
        ;----------------------------------------------------------------
	xor si,si
	mov di,si
	inc di
	inc di
	CONDICION:
		mov ax, punteoU[si]
		cmp ax, punteoU[di]
		jae SIGJ
		;AUX = VALOR1
		mov ax, numUsuario[si] 	;usuario
		mov usuarioaux, ax
		mov ax, punteoU[si]  	;punteo
		mov punteoaux, ax
		mov ax, tiempoU[si] 	;tiempo
		mov tiempoaux, ax
		mov ax, nivelU[si]
		mov nivelaux,ax 		;nivel
		;VALOR1 = VALOR2
		mov ax, numUsuario[di]
		mov numUsuario[si],ax
		mov ax, punteoU[di]
		mov punteoU[si], ax
		mov ax, tiempoU[di]
		mov tiempoU[si],ax
		mov ax, nivelU[di]
		mov nivelU[si],ax
		;VALOR2 = AUX
		mov ax, usuarioaux
		mov numUsuario[di],ax
		mov ax, punteoaux
		mov punteoU[di],ax
		mov ax, tiempoaux
		mov tiempoU[di],ax
		mov ax, nivelaux
		mov nivelU[di],ax
		SIGJ:
			cmp di, 38d
			je SIGI
			inc di
			inc di
			jmp CONDICION
		SIGI:
			cmp si,36d
			je FIN
			inc si
			inc si
			mov di, si
			inc di
			inc di
			jmp CONDICION
	FIN:
		ret

calcularPuntosDescendente endp


mostrarTopPuntos proc
	_Print toptituloP
	NO1:
		_Print top1
		_Print tab2
		mImprimirUsuario numUsuario[0]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[0]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[0]
		ConvertirString numeroaux
		_Print numeroaux
	NO2:
		_Print top2
		_Print tab2
		mImprimirUsuario numUsuario[2]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[2]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[2]
		ConvertirString numeroaux
		_Print numeroaux
	NO3:
		_Print top3
		_Print tab2
		mImprimirUsuario numUsuario[4]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[4]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[4]
		ConvertirString numeroaux
		_Print numeroaux
	NO4:
		_Print top4
		_Print tab2
		mImprimirUsuario numUsuario[6]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[6]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[6]
		ConvertirString numeroaux
		_Print numeroaux
	NO5:
		_Print top5
		_Print tab2
		mImprimirUsuario numUsuario[8]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[8]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[8]
		ConvertirString numeroaux
		_Print numeroaux
	NO6:
		_Print top6
		_Print tab2
		mImprimirUsuario numUsuario[10]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[10]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[10]
		ConvertirString numeroaux
		_Print numeroaux
	NO7:
		_Print top7
		_Print tab2
		mImprimirUsuario numUsuario[12]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[12]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[12]
		ConvertirString numeroaux
		_Print numeroaux
	NO8:
		_Print top8
		_Print tab2
		mImprimirUsuario numUsuario[14]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[14]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[14]
		ConvertirString numeroaux
		_Print numeroaux
	NO9:
		_Print top9
		_Print tab2
		mImprimirUsuario numUsuario[16]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[16]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[16]
		ConvertirString numeroaux
		_Print numeroaux
	NO10:
		_Print top10
		_Print tab2
		mImprimirUsuario numUsuario[18]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[18]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[18]
		ConvertirString numeroaux
		_Print numeroaux
	FIN:
		ret

mostrarTopPuntos endp


;====================== ARCHIVO PUNTOS.REP =============================
archivoTopPuntos proc
	crearFichero rutapuntos, handlerentrada
	call EscribirTopPuntos
	cerrarFichero handlerentrada
	_Print saltoln
	mWrite <'Archivo Puntos.rep generado correctamente!'>
	ret

archivoTopPuntos endp



EscribirTopPuntos proc
	escribirFichero handlerentrada, toptituloP, 17d
	NO1:
		escribirFichero handlerentrada, top1, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[0]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[0]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[0]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO2:
		escribirFichero handlerentrada, top2, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[2]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[2]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[2]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO3:
		escribirFichero handlerentrada, top3, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[4]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[4]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[4]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO4:
		escribirFichero handlerentrada, top4, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[6]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[6]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[6]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO5:
		escribirFichero handlerentrada, top5, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[8]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[8]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[8]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO6:
		escribirFichero handlerentrada, top6, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[10]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[10]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[10]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO7:
		escribirFichero handlerentrada, top7, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[12]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[12]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[12]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO8:
		escribirFichero handlerentrada, top8, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[14]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[14]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[14]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO9:
		escribirFichero handlerentrada, top9, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[16]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[16]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[16]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO10:
		escribirFichero handlerentrada, top10, 5d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[18]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[18]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, punteoU[18]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	FIN:
		ret

EscribirTopPuntos endp


escribirFicheroUsuario proc
	;----------------------------------------------------------------------------------
        ;   Recibe:      ax = numero de Usuario
		;
        ;
        ;   Devuelve:    nada
        ;
        ;   Comentarios: Escribe en el archivo el usuario correspondiente a su numero
        ;------------------------------------------------------------------------------
    cmp ax, 1d
    je U1
	cmp ax, 2d
    je U2
    cmp ax, 3d
    je U3
    cmp ax, 4d
    je U4
    cmp ax, 5d
    je U5
    cmp ax, 6d
    je U6
    cmp ax, 7d
    je U7
    cmp ax, 8d
    je U8
    cmp ax, 9d
    je U9
    cmp ax, 10d
    je U10
    cmp ax, 11d
    je U11
    cmp ax, 12d
    je U12
    cmp ax, 13d
    je U13
    cmp ax, 14d
    je U14
    cmp ax, 15d
    je U15
    cmp ax, 16d
    je U16
    cmp ax, 17d
    je U17
    cmp ax, 18d
    je U18
    cmp ax, 19d
    je U19
    cmp ax, 20d
    je U20
    jmp FIN
    U1:
    	String_size usuario1
		mov cx, ax
		escribirFichero handlerentrada, usuario1, cx
    	jmp FIN
    U2:
    	String_size usuario2
		mov cx, ax
		escribirFichero handlerentrada, usuario2, cx
    	jmp FIN
    U3:
    	String_size usuario3
		mov cx, ax
		escribirFichero handlerentrada, usuario3, cx
    	jmp FIN
    U4:
    	String_size usuario4
		mov cx, ax
		escribirFichero handlerentrada, usuario4, cx
    	jmp FIN
    U5:
    	String_size usuario5
		mov cx, ax
		escribirFichero handlerentrada, usuario5, cx
    	jmp FIN
    U6:
    	String_size usuario6
		mov cx, ax
		escribirFichero handlerentrada, usuario6, cx
    	jmp FIN
    U7:
    	String_size usuario7
		mov cx, ax
		escribirFichero handlerentrada, usuario7, cx
    	jmp FIN
    U8:
    	String_size usuario8
		mov cx, ax
		escribirFichero handlerentrada, usuario8, cx
    	jmp FIN
    U9:
    	String_size usuario9
		mov cx, ax
		escribirFichero handlerentrada, usuario9, cx
    	jmp FIN
    U10:
    	String_size usuario10
		mov cx, ax
		escribirFichero handlerentrada, usuario10, cx
    	jmp FIN
    U11:
    	String_size usuario11
		mov cx, ax
		escribirFichero handlerentrada, usuario11, cx
    	jmp FIN
    U12:
    	String_size usuario12
		mov cx, ax
		escribirFichero handlerentrada, usuario12, cx
    	jmp FIN
    U13:
    	String_size usuario13
		mov cx, ax
		escribirFichero handlerentrada, usuario13, cx
    	jmp FIN
    U14:
    	String_size usuario14
		mov cx, ax
		escribirFichero handlerentrada, usuario14, cx
    	jmp FIN
    U15:
    	String_size usuario15
		mov cx, ax
		escribirFichero handlerentrada, usuario15, cx
    	jmp FIN
    U16:
    	String_size usuario16
		mov cx, ax
		escribirFichero handlerentrada, usuario16, cx
    	jmp FIN
    U17:
    	String_size usuario17
		mov cx, ax
		escribirFichero handlerentrada, usuario17, cx
    	jmp FIN
    U18:
    	String_size usuario18
		mov cx, ax
		escribirFichero handlerentrada, usuario18, cx
    	jmp FIN
    U19:
    	String_size usuario19
		mov cx, ax
		escribirFichero handlerentrada, usuario19, cx
    	jmp FIN
    U20:
    	String_size usuario20
		mov cx, ax
		escribirFichero handlerentrada, usuario20, cx
   	FIN:
   		ret

escribirFicheroUsuario endp


;============================= TOP 10 TIEMPO ============================

Top10Tiempo proc
	mCalularTiempoDescendente
	mMostrarTopTiempo
	leerChar
	mArchivoTopTiempo
	leerChar
	cmp al,20h		;barra espaciadora
	je BARRAS
	jmp FIN
	BARRAS:
		mIniciarBarrasTiempo
	FIN:
		ret

Top10Tiempo endp



calcularTiempoDescendente proc
	;--------------------------------------------------------------------
        ;   Recibe:      si = para recorrer en i
		;				 di = para recorrer en j
        ;                ax = auxiliar
        ;   Devuelve:    nada
        ;
        ;   Comentarios: Ordena en forma descendente para el top tiempo
        ;----------------------------------------------------------------
	xor si,si
	mov di,si
	inc di
	inc di
	CONDICION:
		mov ax, tiempoU[si]
		cmp ax, tiempoU[di]
		jae SIGJ
		;AUX = VALOR1
		mov ax, numUsuario[si] 	;usuario
		mov usuarioaux, ax
		mov ax, punteoU[si]  	;punteo
		mov punteoaux, ax
		mov ax, tiempoU[si] 	;tiempo
		mov tiempoaux, ax
		mov ax, nivelU[si]
		mov nivelaux,ax 		;nivel
		;VALOR1 = VALOR2
		mov ax, numUsuario[di]
		mov numUsuario[si],ax
		mov ax, punteoU[di]
		mov punteoU[si], ax
		mov ax, tiempoU[di]
		mov tiempoU[si],ax
		mov ax, nivelU[di]
		mov nivelU[si],ax
		;VALOR2 = AUX
		mov ax, usuarioaux
		mov numUsuario[di],ax
		mov ax, punteoaux
		mov punteoU[di],ax
		mov ax, tiempoaux
		mov tiempoU[di],ax
		mov ax, nivelaux
		mov nivelU[di],ax
		SIGJ:
			cmp di, 38d
			je SIGI
			inc di
			inc di
			jmp CONDICION
		SIGI:
			cmp si,36d
			je FIN
			inc si
			inc si
			mov di, si
			inc di
			inc di
			jmp CONDICION
	FIN:
		ret

calcularTiempoDescendente endp


mostarTopTiempo proc
	_Print toptituloT
	NO1:
		_Print top1
		_Print tab2
		mImprimirUsuario numUsuario[0]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[0]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[0]
		ConvertirString numeroaux
		_Print numeroaux
	NO2:
		_Print top2
		_Print tab2
		mImprimirUsuario numUsuario[2]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[2]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[2]
		ConvertirString numeroaux
		_Print numeroaux
	NO3:
		_Print top3
		_Print tab2
		mImprimirUsuario numUsuario[4]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[4]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[4]
		ConvertirString numeroaux
		_Print numeroaux
	NO4:
		_Print top4
		_Print tab2
		mImprimirUsuario numUsuario[6]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[6]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[6]
		ConvertirString numeroaux
		_Print numeroaux
	NO5:
		_Print top5
		_Print tab2
		mImprimirUsuario numUsuario[8]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[8]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[8]
		ConvertirString numeroaux
		_Print numeroaux
	NO6:
		_Print top6
		_Print tab2
		mImprimirUsuario numUsuario[10]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[10]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[10]
		ConvertirString numeroaux
		_Print numeroaux
	NO7:
		_Print top7
		_Print tab2
		mImprimirUsuario numUsuario[12]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[12]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[12]
		ConvertirString numeroaux
		_Print numeroaux
	NO8:
		_Print top8
		_Print tab2
		mImprimirUsuario numUsuario[14]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[14]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[14]
		ConvertirString numeroaux
		_Print numeroaux
	NO9:
		_Print top9
		_Print tab2
		mImprimirUsuario numUsuario[16]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[16]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[16]
		ConvertirString numeroaux
		_Print numeroaux
	NO10:
		_Print top10
		_Print tab2
		mImprimirUsuario numUsuario[18]
		_Print tab4
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[18]
		ConvertirString numeroaux
		_Print numeroaux
		_Print tab3
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[18]
		ConvertirString numeroaux
		_Print numeroaux
	FIN:
		ret

mostarTopTiempo endp



;=========================== ARCHIVO TIEMPOS.REP ===========================

archivoTopTiempo proc
	crearFichero rutatiempos, handlerentrada
	call EscribirTopTiempos
	cerrarFichero handlerentrada
	_Print saltoln
	mWrite <'Archivo Tiempos.rep generado correctamente!'>
	ret

archivoTopTiempo endp


EscribirTopTiempos proc
	escribirFichero handlerentrada, toptituloT, 23d
	NO1:
		escribirFichero handlerentrada, top1, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[0]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[0]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[0]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO2:
		escribirFichero handlerentrada, top2, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[2]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[2]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[2]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO3:
		escribirFichero handlerentrada, top3, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[4]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[4]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[4]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO4:
		escribirFichero handlerentrada, top4, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[6]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[6]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[6]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO5:
		escribirFichero handlerentrada, top5, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[8]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[8]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[8]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO6:
		escribirFichero handlerentrada, top6, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[10]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[10]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[10]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO7:
		escribirFichero handlerentrada, top7, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[12]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[12]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[12]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO8:
		escribirFichero handlerentrada, top8, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[14]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[14]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[14]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO9:
		escribirFichero handlerentrada, top9, 4d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[16]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[16]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[16]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	NO10:
		escribirFichero handlerentrada, top10, 5d
		escribirFichero handlerentrada, tab2, 2d
		mEscribirFicheroUsuario numUsuario[18]
		escribirFichero handlerentrada, tab4, 4d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, nivelU[18]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
		escribirFichero handlerentrada, tab3, 3d
		limpiarCadena numeroaux, SIZEOF numeroaux, 24h
		mov ax, tiempoU[18]
		ConvertirString numeroaux
		String_size numeroaux
		mov cx, ax
		escribirFichero handlerentrada, numeroaux, cx
	FIN:
		ret

EscribirTopTiempos endp



;================================================= PARA INICIAR GRAFICA SOBRE PUNTOS ======================================

iniciarBarrasPuntos proc
	call almacenarPuntos 	;almacenamos los puntos en tamBarra[]
	mov ax, punteoU[0]
	mov valorMaximo, ax 	;guardamos el punteo mayor para la referencia con las barras
	mSetUpBarras
	mMenuOrden
	ret

iniciarBarrasPuntos endp

almacenarPuntos proc
	mov ax, punteoU[0]
	mov tamBarra[0], ax
	mov ax, punteoU[2]
	mov tamBarra[2], ax
	mov ax, punteoU[4]
	mov tamBarra[4], ax
	mov ax, punteoU[6]
	mov tamBarra[6], ax
	mov ax, punteoU[8]
	mov tamBarra[8], ax
	mov ax, punteoU[10]
	mov tamBarra[10], ax
	mov ax, punteoU[12]
	mov tamBarra[12], ax
	mov ax, punteoU[14]
	mov tamBarra[14], ax
	mov ax, punteoU[16]
	mov tamBarra[16], ax
	mov ax, punteoU[18]
	mov tamBarra[18], ax
	mov ax, punteoU[20]
	mov tamBarra[20], ax
	mov ax, punteoU[22]
	mov tamBarra[22], ax
	mov ax, punteoU[24]
	mov tamBarra[24], ax
	mov ax, punteoU[26]
	mov tamBarra[26], ax
	mov ax, punteoU[28]
	mov tamBarra[28], ax
	mov ax, punteoU[30]
	mov tamBarra[30], ax
	mov ax, punteoU[32]
	mov tamBarra[32], ax
	mov ax, punteoU[34]
	mov tamBarra[34], ax
	mov ax, punteoU[36]
	mov tamBarra[36], ax
	mov ax, punteoU[38]
	mov tamBarra[38], ax
	FIN:
		ret

almacenarPuntos endp


;================================================= PARA INICIAR GRAFICA SOBRE TIEMPOS ======================================

iniciarBarrasTiempo proc
	call almacenarTiempos 	;almacenamos los tiempos en tamBarra[]
	mov ax, tiempoU[0]
	mov valorMaximo, ax 	;guardamos el tiempo mayor para la referencia con las barras
	mSetUpBarras
	mMenuOrden
	ret

iniciarBarrasTiempo endp


almacenarTiempos proc
	mov ax, tiempoU[0]
	mov tamBarra[0], ax
	mov ax, tiempoU[2]
	mov tamBarra[2], ax
	mov ax, tiempoU[4]
	mov tamBarra[4], ax
	mov ax, tiempoU[6]
	mov tamBarra[6], ax
	mov ax, tiempoU[8]
	mov tamBarra[8], ax
	mov ax, tiempoU[10]
	mov tamBarra[10], ax
	mov ax, tiempoU[12]
	mov tamBarra[12], ax
	mov ax, tiempoU[14]
	mov tamBarra[14], ax
	mov ax, tiempoU[16]
	mov tamBarra[16], ax
	mov ax, tiempoU[18]
	mov tamBarra[18], ax
	mov ax, tiempoU[20]
	mov tamBarra[20], ax
	mov ax, tiempoU[22]
	mov tamBarra[22], ax
	mov ax, tiempoU[24]
	mov tamBarra[24], ax
	mov ax, tiempoU[26]
	mov tamBarra[26], ax
	mov ax, tiempoU[28]
	mov tamBarra[28], ax
	mov ax, tiempoU[30]
	mov tamBarra[30], ax
	mov ax, tiempoU[32]
	mov tamBarra[32], ax
	mov ax, tiempoU[34]
	mov tamBarra[34], ax
	mov ax, tiempoU[36]
	mov tamBarra[36], ax
	mov ax, tiempoU[38]
	mov tamBarra[38], ax
	FIN:
		ret

almacenarTiempos endp


;====================================== ORDENAMIENTOS ==================================
menuOrden proc
	MENUSORT:
		_ModoTexto
		_Print msjMenuOrden
		_Print escoja
		leerChar
		cmp al,'1'
		je BSORT
		cmp al,'2'
		je QSORT
		cmp al,'3'
		je SSORT
		cmp al,'4'
		je FIN
		jmp MENUSORT
		BSORT:
			mov tipoOrden,1d
			jmp VELO
		QSORT:
			mov tipoOrden,2d
			jmp VELO
		SSORT:
			mov tipoOrden,3d
		VELO:
			_Print msjvelocidad
			leerChar
			cmp al, '0'
			jb ERVEL
			cmp al, '9'
			ja ERVEL
			jmp GUVEL
			ERVEL:
				_Print saltoln
				mWrite<'Error en velocidad, ingrese un numero entre 0 a 9 por favor.'>
				leerChar
				jmp VELO
			GUVEL:
				mov velocidad[0], al
			FORMA:
				_Print msjASDEC
				_Print escoja
				leerChar
				cmp al, '1'
				je DESC
				cmp al, '2'
				je ASC
				jmp FORMA
				DESC:
					mov formaOrden, 1d
					jmp ORDENAR
				ASC:
					mov formaOrden, 2d
			ORDENAR:
				mGameBarras
				;REINICIAR TIEMPO
				mov estadoSegundoB, 0d
				mov contadorMinutosB, 0d
				mov minutoBarra[0],'0'
				mov minutoBarra[1],'0'
	jmp MENUSORT
	FIN:
		ret

menuOrden endp