addi x5, x0, 3
addi x6, x0, 3
addi x7, x0, 0
LOOPI:    
    addi x29, x0, 0
    addi x30, x10, 0
    blt x7, x5, LOOPJ
LOOPJ:
    bge x29, x6, ENDJ
    add x28, x7, x29 
    sw x28, 0(x30)
    addi x30, x30, 16 
    addi x29, x29, 1 
    jal x0, LOOPJ
ENDJ:
    addi x7, x7, 1 
    jal x0, LOOPI    