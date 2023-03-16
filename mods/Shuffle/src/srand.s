.set noreorder
.align 2
.global srand
.type srand, @function

srand:
li $t2,0xa0
jr $t2
li $t1,0x30
