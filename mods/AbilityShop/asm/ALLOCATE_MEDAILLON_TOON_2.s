.set noreorder
sh $v0, -0x0050($t0) #x_pos
nop #init_x_pos
subu $a0, $a2
sh $a0, -0x004e($t0) #y_pos
nop #init_y_pos
