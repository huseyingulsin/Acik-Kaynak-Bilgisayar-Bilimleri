;Not: Float kýsýmlarý dahil edilmediðinden ve 16'dan küçük sayýlarda float kýsým çýkartýldýðýnda 0 kaldýðýndan 
;sonuç yaklaþýk olarak 3 eksik veya fazla çýkmaktadýr
;Direkt 16'nýn katlarý sayýlarda hatasýz,16'nýn katý olmayýp 16'dan yüksek sayýlarda daha az hatayla hesaplmakatadýr.


load R0,16			;Sayaç iþlemi.
load R1,Sayilar		;Toplamak istenilen sayýlarý, aþþaðýya giriniz.
load R2,11110000b		;Sayýlarý 16 ile bölündüðünde tam sayý vermesi için gereklidir.
load R3,0			;Sayýlarýn Toplanacaðý Yer.
load R4,0			
load R5,1
load R7,240

Islemler:
load R6,[R1]
store R6,[R7]		;memory'de deðerleri gösterir.
and R6,R6,R2		;16'ya tam bölünür hale getirir.
ror R6,4			;16'ya böler
addi R3,R3,R6		
addi R1,R1,R5
addi R4,R4,R5
addi R7,R7,R5
jmpEQ R4=R0,jump
jmp Islemler

jump:
move R0,R3			;R0 içinde depolar
store R0,[00]		;Memory 0000 içinde depolar
halt


;Toplanýlmasýný istediðiniz sayýlarý giriniz.
Sayilar:	db 01011010b,10101001b,01010010b,01001011b,01010001b,11110100b,10001000b,11100101b,10010110b,01001101b,10100100b,00100100b,01001000b,10001001b,01001000b,11001110b
