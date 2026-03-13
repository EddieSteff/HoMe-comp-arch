data segment
txt1 db "Type the number: ", '$'
text1 db "Quadrat der zahl " , '$'
text2 db " ist", '$'
key dd ?
outputStr db 5 dup (?), '$'
fin = $-1
ergebnis dw ?
data ends

stack segment
db 100 dup(?)
stack ends

assume ds:data, cs:code, ss:stack

code segment
mov bx, data
mov ds, bx

mov dx, offset txt1
mov ah, 09h
int 21h


mov ah, 0Ah
int 21h
xor ax,ax
mov al, offset key
sub al, 24h
call pow2
mov ergebnis, ax
mov dx, offset text1
mov ah, 09h
int 21h
std

lea di, fin-1
mov cx, 10
loop1:
xor dx, dx
div cx
xchg ax, dx
add al, '0'
stosb
xchg ax, dx
or ax,ax
jne  loop1
;call print
;mov dx, ax
mov ah, 09h
lea dx, [di+1]
int 21h
mov dx, offset text2
mov ah, 09h
int 21h
mov ah, 4ch
int 20h
code ends


;print proc
;   std
;  pop ax
; lea di, fin
;mov bx, 10
; loop1:
; xor dx, dx
; div bx
;xchg ax, dx
;add al, 0
;stosb
;xchg ax, dx
;or ax,ax
;jne  loop1
;ret
;endp


pow2 proc
push dx
push cx

mov dx, ax
mov ax, 0
mov cx, 1
inc dx
_loop:
push cx
shl cx, 1
dec cx
add ax, cx
pop cx


inc cx
cmp cx, dx

jne _loop

pop cx
pop dx

ret
endp
