;===========================MACROS=================================
include rmacros.asm
include rm_juego.asm
include rm_bar.asm
include rm_scr.asm
;====================DECLARACION DEL PROCESADOR====================
.model small, stdcall
.286
;=====================SEGMENTO DE PILA=============================
.stack 
	include rf_pro.inc
;=====================SEGMENTO DE DATO=============================
.data
	include rf_data.asm
;=====================SEGMENTO DE CODIGO===========================
.code
	include rf_log1.asm
	include rf_log2.inc
	include rf_juego.inc
	include rf_bar.inc
end main