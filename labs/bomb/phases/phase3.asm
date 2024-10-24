phase_3:
   0x0000000000400f43 <+0>:	sub    $0x18,%rsp                      # alloc 24 on stack
   0x0000000000400f47 <+4>:	lea    0xc(%rsp),%rcx                  # move %rsp+12 to param_4
   0x0000000000400f4c <+9>:	lea    0x8(%rsp),%rdx                  # move %rsp+8 to param_3
   0x0000000000400f51 <+14>:	mov    $0x4025cf,%esi                  # move "%d %d" to param_2
   0x0000000000400f56 <+19>:	mov    $0x0,%eax                       # clear retreg
   0x0000000000400f5b <+24>:	call   0x400bf0 <__isoc99_sscanf@plt> 
   0x0000000000400f60 <+29>:	cmp    $0x1,%eax                 
   0x0000000000400f63 <+32>:	jg     0x400f6a <phase_3+39>
   0x0000000000400f65 <+34>:	call   0x40143a <explode_bomb>

   0x0000000000400f6a <+39>:	cmpl   $0x7,0x8(%rsp)                  # if input_1 < 7, explode
   0x0000000000400f6f <+44>:	ja     0x400fad <phase_3+106>
   0x0000000000400f71 <+46>:	mov    0x8(%rsp),%eax                  # assign %eax = input_1
   0x0000000000400f75 <+50>:	jmp    *0x402470(,%rax,8)              # input_1 * 8 + 0x402470

   # ################
   # input_1 = 0 -> jmp 0x400f7c <+57>
   # input_1 = 1 -> jmp 0x400fb9 <+118>
   # input_1 = 2 -> jmp 0x400f83 <+64>
   # input_1 = 3 -> jmp 0x400f8a <+71>
   # input_1 = 4 -> jmp 0x400f91 <+78>
   # input_1 = 5 -> jmp 0x400f98 <+85>

   0x0000000000400f7c <+57>:	mov    $0xcf,%eax                      # assign %eax = 207 << input_1 = 1
   0x0000000000400f81 <+62>:	jmp    0x400fbe <phase_3+123>
   0x0000000000400f83 <+64>:	mov    $0x2c3,%eax                     # assign %eax = 707 << input_1 = 3
   0x0000000000400f88 <+69>:	jmp    0x400fbe <phase_3+123>
   0x0000000000400f8a <+71>:	mov    $0x100,%eax                     # assign %eax = 256 << input_1 = 4
   0x0000000000400f8f <+76>:	jmp    0x400fbe <phase_3+123>
   0x0000000000400f91 <+78>:	mov    $0x185,%eax                     # assign %eax = 389 << input_1 = 5
   0x0000000000400f96 <+83>:	jmp    0x400fbe <phase_3+123>
   0x0000000000400f98 <+85>:	mov    $0xce,%eax                      # assign %eax = 195 << input_1 = 6
   0x0000000000400f9d <+90>:	jmp    0x400fbe <phase_3+123>
   0x0000000000400f9f <+92>:	mov    $0x2aa,%eax                     # assign %eax = 682
   0x0000000000400fa4 <+97>:	jmp    0x400fbe <phase_3+123>
   0x0000000000400fa6 <+99>:	mov    $0x147,%eax                     # assign %eax = 327
   0x0000000000400fab <+104>:	jmp    0x400fbe <phase_3+123>
   0x0000000000400fad <+106>:	call   0x40143a <explode_bomb>
   0x0000000000400fb2 <+111>:	mov    $0x0,%eax
   0x0000000000400fb7 <+116>:	jmp    0x400fbe <phase_3+123>
   0x0000000000400fb9 <+118>:	mov    $0x137,%eax                     # assign %eax = 311 << input_1 = 2
   0x0000000000400fbe <+123>:	cmp    0xc(%rsp),%eax                  # cmp input_2 with %eax
   0x0000000000400fc2 <+127>:	je     0x400fc9 <phase_3+134>          
   0x0000000000400fc4 <+129>:	call   0x40143a <explode_bomb>
   0x0000000000400fc9 <+134>:	add    $0x18,%rsp
   0x0000000000400fcd <+138>:	ret


# ################ Stack
# prev %rsp
# %rsp + 20
# %rsp + 16
# %rsp + 12          <-  input_2
# %rsp + 8           <-  input_1
# %rsp + 4     
# %rsp              
# ################ Regs
# %rcx              <prev%rsp+12> param_4
# %rdx              <prev%rsp+8>  param_3
# %rsi              "%d %d"       param_2
# %rdi              input         param_1
# ################