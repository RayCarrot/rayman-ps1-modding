.set noreorder
addiu $s0, $zero, 4 #new menuEtape
addiu $s1, $zero, 4
jal FUN_801a6a04 #calls INIT_NEW_GAME()
move $a0, $zero
