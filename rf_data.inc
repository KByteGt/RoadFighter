;==> DATA


txt_exit        db  10,13,' Vamos por el 100!!!',10,13,'$'
txt_inUser      db  ' |> Ingresar nombre de usuario (7 max char): $'
txt_inPass      db  ' |> Ingresar contrasena (4 max digit): $'

msg_log01 		db  ' |> **ERROR: ya existe el usuario $',13,10
msg_log02 		db  ' | * Usuario o contrasena incorrectas',13,10,'$'
msg_log03		db  ' | ** ERROR: No se aceptan usuarios sin nombre',13,10,'$'

msg db 'Hola Mundo!!', 10,13,'Road Fighter','$'

archivo 		db 'rf-usr.txt', 00h
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
				db	' |%%%| 2- TOP 10 TIEMPOs        |%%%|',13,10
				db	' |%%%| 3- SALIR                 |%%%|',13,10
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

;==> USUARIOS
userName 		db 7 dup('$'),'$' 	;Almacena usuario actual
userLevel		db '0','$'
userPts			db 	0
userMin 		db  0
userSeg 		db 	0

inUser          db 7 dup('$'),'$'	;Entrada para el usuario
inPass          db 4 dup('$'),'$'	;Entrada para la contraseña

userAdmin       db 'admin','$' 	;Administrador
passAdmin       db '1234','$'	;contraseña 

user1           db 7 dup('$'),'$'	;Usuario #1
pass1           db 4 dup('$'),'$' 	
level1 			db '0','$'
puntos1 		db 	0
minutos1		db 	0
segundos1		db 	0
user2           db 7 dup('$'),'$'	;Usuario #2
pass2           db 4 dup('$'),'$' 	
level2 			db '0','$'
puntos2 		db 	0
minutos2		db 	0
segundos2		db 	0
user3           db 7 dup('$'),'$'	;Usuario #3
pass3           db 4 dup('$'),'$' 	
level3 			db '0','$'
puntos3 		db 	0
minutos3		db 	0
segundos3		db 	0
user4           db 7 dup('$'),'$'	;Usuario #4
pass4           db 4 dup('$'),'$' 
level4 			db '0','$'
puntos4 		db 	0
minutos4		db 	0
segundos4		db 	0	
user5           db 7 dup('$'),'$'	;Usuario #5
pass5           db 4 dup('$'),'$' 	
level5 			db '0','$'
puntos5 		db 	0
minutos5		db 	0
segundos5		db 	0
user6           db 7 dup('$'),'$'	;Usuario #6
pass6           db 4 dup('$'),'$' 	
level6 			db '0','$'
puntos6 		db 	0
minutos6		db 	0
segundos6		db 	0
user7           db 7 dup('$'),'$'	;Usuario #7
pass7           db 4 dup('$'),'$' 	
level7 			db '0','$'
puntos7 		db 	0
minutos7		db 	0
segundos7		db 	0
user8           db 7 dup('$'),'$'	;Usuario #8
pass8           db 4 dup('$'),'$' 	
level8 			db '0','$'
puntos8 		db 	0
minutos8		db 	0
segundos8		db 	0
user9           db 7 dup('$'),'$'	;Usuario #9
pass9           db 4 dup('$'),'$' 	
level9 			db '0','$'
puntos9 		db 	0
minutos9		db 	0
segundos9		db 	0
user10          db 7 dup('$'),'$'	;Usuario #10
pass10          db 4 dup('$'),'$' 	
level10 		db '0','$'
puntos10 		db 	0
minutos10		db 	0
segundos10		db 	0
user11          db 7 dup('$'),'$'	;Usuario #11
pass11          db 4 dup('$'),'$' 	
level11 		db '0','$'
puntos11 		db 	0
minutos11		db 	0
segundos11		db 	0
user12          db 7 dup('$'),'$'	;Usuario #12
pass12          db 4 dup('$'),'$' 	
level12 		db '0','$'
puntos12 		db 	0
minutos12		db 	0
segundos12		db 	0
user13          db 7 dup('$'),'$'	;Usuario #13
pass13          db 4 dup('$'),'$' 	
level13 		db '0','$'
puntos13 		db 	0
minutos13		db 	0
segundos13		db 	0
user14          db 7 dup('$'),'$'	;Usuario #14
pass14          db 4 dup('$'),'$' 	
level14 		db '0','$'
puntos14 		db 	0
minutos14		db 	0
segundos14		db 	0
user15          db 7 dup('$'),'$'	;Usuario #15
pass15          db 4 dup('$'),'$' 	
level15 		db '0','$'
puntos15 		db 	0
minutos15		db 	0
segundos15		db 	0
user16          db 7 dup('$'),'$'	;Usuario #16
pass16          db 4 dup('$'),'$' 	
level16 		db '0','$'
puntos16 		db 	0
minutos16		db 	0
segundos16		db 	0
user17          db 7 dup('$'),'$'	;Usuario #17
pass17          db 4 dup('$'),'$' 	
level17 		db '0','$'
puntos17 		db 	0
minutos17		db 	0
segundos17		db 	0
user18          db 7 dup('$'),'$'	;Usuario #18
pass18          db 4 dup('$'),'$' 	
level18 		db '0','$'
puntos18 		db 	0
minutos18		db 	0
segundos18		db 	0
user19          db 7 dup('$'),'$'	;Usuario #19
pass19          db 4 dup('$'),'$' 	
level19 		db '0','$'
puntos19 		db 	0
minutos19		db 	0
segundos19		db 	0
user20          db 7 dup('$'),'$'	;Usuario #20
pass20          db 4 dup('$'),'$' 
level20 		db '0','$'
puntos20 		db 	0
minutos20		db 	0
segundos20		db 	0

;==> Variables de uso general
flagCMP         db '0','$'