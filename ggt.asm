data segment

String  db    5 dup (?),'$'
fin = $-1
ergebnis dw ?

textX db "Input value of x: ", '$'
textY db "Input value of y: ", '$'
textErgeb db "GGT of these two numbers is: ", '$'
key db ?
xVal dw ?
yVal dw ?



maxSize  db 128
sizeOf db 0
buf   db 128 dup(?)
bufInt db 0

data ends

stack segment
db 100 dup(?)
stack ends

assume ds:data, cs:code, ss:stack

code segment
mov bx, data
mov ds, bx

mov dx, offset textX
mov ah, 09h
int 21h

lea dx, buf-2
mov ah, 0Ah
int 21h

call toInt
mov al, bufInt
mov xVal, ax

mov  dx, offset textY
mov ah, 09h
int 21h

lea dx, buf-2
mov ah, 0Ah
int 21h

call toInt
mov al, bufInt
mov yVal, ax


mov ax, [xVal]
mov bx, [yVal]

call equlid

mov dx, offset textErgeb
mov ah, 09h
int 21h

std
lea di, fin-1
mov cx, 10
mov ax, ergebnis
loop1:
xor dx, dx
div cx
xchg ax, dx
add al, '0'
stosb
xchg ax, dx
or ax, ax
jne loop1

mov ah, 9
lea dx, [di+1]
int 21h
int 20h

code ends

toInt proc
mov cl, sizeOf
xor ax ,ax
mov bufInt, al
_isEqualCX:
cmp cl, 0
jne _convert
je _return

_convert:
xor ax ,ax

mov bl, 10
mov al, buf[0]
sub ax, 30h
mov dl, cl
dec dx
dec cx
jmp _isEqualDX


_zeropoint:
mul bl
cmp dl, 0
dec dl
jne  _zeropoint
je _int

_isEqualDX:
cmp dl, 0
jne _zeropoint
je _int

_int:
add bufInt, al
jmp _isEqualCX


_return:
ret
endp

equlid proc

XgY:
cmp ax, bx
je XeY
ja XgYsub


YgX:
cmp bx, ax
je XeY
ja YgXsub

XgYsub:
sub ax, bx
jmp XgY

YgXsub:
sub bx, ax
jmp YgX

XeY:
mov ergebnis, ax
ret
endp

