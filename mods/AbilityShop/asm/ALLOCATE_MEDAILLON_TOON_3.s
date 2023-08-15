.set noreorder
sh $zero, h_scroll_speed
sh $zero, v_scroll_speed
sh $zero, -0x22($t0) #active_timer
sb $zero, -0x07($t0) #active_flag
addiu $v0, $zero, 7
j 0x80161b74
sb $v0, -0x02($t0) #display_prio, 7 seems to be the furthest back
