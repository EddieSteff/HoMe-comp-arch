;Deklarationen von C nach Assembler

a DD ?
c DD ?
e DD ?
i DD ?

s DW 0

feld DD 10 DUP(?)
farbe DB ?

text DB 10 DUP(?)


;Zuweisungen von C nach Assembler

mov a, 0x3b
mov c, 20

mov ax, a
mul c
mov s, ax

mov ax, a
add ax, c
mov e, ax

mov text, "c"


