;==> DATA

msg db 'Hola Mundo!!', 10,13,'Road Fighter','$'

archivo db 'Ronda1.txt', 00h
msgError1 db 10,13,'Error: No se puede abrir el archivo. $'
msgError2 db 10,13,'Error: No se pudo leer el archivo. $'

limpiar db 11 dup('$')

;==> MENU - MENSAJES

menu_1          db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
			    db	' |%%%%%%%%%% ROAD FIGHTER %%%%%%%%%%|',13,10
			    db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' |%%%|                          |%%%|',13,10
				db	' |%%%| 1- INGRESAR              |%%%|',13,10
				db	' |%%%| 2- REGISTRAR             |%%%|',13,10
				db	' |%%%| 3- SALIR                 |%%%|',13,10
				db	' |%%%|                          |%%%|',13,10
				db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' | > presione un numero: $'

menu_header     db  ' UNIVERSIDAD DE SAN CARLOS DE GUATEMALA',13,10
				db	' FACULTAD DE INGENIERIA',13.10
				db	' CIENCIAS Y SISTEMAS',13,10
				db	' ARQUITECTURA DE COMPUTADORAS Y ENSAMBLADORES 1',13,10
				db	' NOMBRE: JOSE DANIEL LOPEZ GONZALEZ',13,10
				db	' CARNET: 201503836',13,10
				db	' SECCION: A',13,10,' $'

menu_user       db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' |%%%%%%%%%%%%%% MENU %%%%%%%%%%%%%%|',13,10
				db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' |%%%|                          |%%%|',13,10
				db	' |%%%| 1- INICIAR JUEGO         |%%%|',13,10
				db	' |%%%| 2- CARGAR JUEGO          |%%%|',13,10
				db	' |%%%| 3- SALIR                 |%%%|',13,10
				db	' |%%%|                          |%%%|',13,10
				db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' | > presione un numero: $'

menu_admin      db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' |%%%%%%%%%%%%%% MENU %%%%%%%%%%%%%%|',13,10
				db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' |%%%|                          |%%%|',13,10
				db	' |%%%| 1- TOP 10 PUNTOS         |%%%|',13,10
				db	' |%%%| 2- TOP 10 TIEMPOs       |%%%|',13,10
				db	' |%%%| 3- SALIR                |%%%|',13,10
				db	' |%%%|                          |%%%|',13,10
				db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' | > presione un numero: $'

menu_singup     db  ' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' |%%%%%%%%%%%%% SINGUP %%%%%%%%%%%%%|',13,10
				db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10,'$'

menu_login      db  ' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10
				db	' |%%%%%%%%%%%%%  LOGIN %%%%%%%%%%%%%|',13,10
				db	' |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|',13,10,'$'

CRLF        db  10,13,'$'

txt_exit        db  10,13,' Vamos por el 100!!!',10,13,'$'
txt_inUser      db  ' |> Ingresar nombre de usuario (7 max char): $'
txt_inPass      db  ' |> Ingresar contrasena (4 digit max): $'

msg_log01 db  ' |> **ERROR: ya existe el usuario $',13,10
msg_log02 db  ' | * Usuario o contraseña incorrectas',13,10,'$'



;==> USUARIOS
userName 		db 7 dup('$'),'$' 	;Almacena usuario actual
inUser          db 7 dup('$'),'$'	;Entrada para el usuario
inPass          db 4 dup('$'),'$'	;Entrada para la contraseña

userAdmin       db 'admin','$' 	;Administrador
passAdmin       db '1234','$'	;contraseña 

user1           db 7 dup('$'),'$'	;Usuario #1
pass1           db 4 dup('$'),'$' 	
user2           db 7 dup('$'),'$'	;Usuario #2
pass2           db 4 dup('$'),'$' 	
user3           db 7 dup('$'),'$'	;Usuario #3
pass3           db 4 dup('$'),'$' 	
user4           db 7 dup('$'),'$'	;Usuario #4
pass4           db 4 dup('$'),'$' 	
user5           db 7 dup('$'),'$'	;Usuario #5
pass5           db 4 dup('$'),'$' 	
user6           db 7 dup('$'),'$'	;Usuario #6
pass6           db 4 dup('$'),'$' 	
user7           db 7 dup('$'),'$'	;Usuario #7
pass7           db 4 dup('$'),'$' 	
user8           db 7 dup('$'),'$'	;Usuario #8
pass8           db 4 dup('$'),'$' 	
user9           db 7 dup('$'),'$'	;Usuario #9
pass9           db 4 dup('$'),'$' 	
user10          db 7 dup('$'),'$'	;Usuario #10
pass10          db 4 dup('$'),'$' 	
user11          db 7 dup('$'),'$'	;Usuario #11
pass11          db 4 dup('$'),'$' 	
user12          db 7 dup('$'),'$'	;Usuario #12
pass12          db 4 dup('$'),'$' 	
user13          db 7 dup('$'),'$'	;Usuario #13
pass13          db 4 dup('$'),'$' 	
user14          db 7 dup('$'),'$'	;Usuario #14
pass14          db 4 dup('$'),'$' 	
user15          db 7 dup('$'),'$'	;Usuario #15
pass15          db 4 dup('$'),'$' 	
user16          db 7 dup('$'),'$'	;Usuario #16
pass16          db 4 dup('$'),'$' 	
user17          db 7 dup('$'),'$'	;Usuario #17
pass17          db 4 dup('$'),'$' 	
user18          db 7 dup('$'),'$'	;Usuario #18
pass18          db 4 dup('$'),'$' 	
user19          db 7 dup('$'),'$'	;Usuario #19
pass19          db 4 dup('$'),'$' 	
user20          db 7 dup('$'),'$'	;Usuario #20
pass20          db 4 dup('$'),'$' 

;==> Variables de uso general
flagCMP         db '0','$'