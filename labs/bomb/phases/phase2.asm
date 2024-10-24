phase_2:
   0x0000000000400efc <+0>:	push   %rbp                         # callee save
   0x0000000000400efd <+1>:	push   %rbx                         # callee save


   0x0000000000400efe <+2>:	sub    $0x28,%rsp                   # alloc 40 on stack
   0x0000000000400f02 <+6>:	mov    %rsp,%rsi
   0x0000000000400f05 <+9>:	call   0x40145c <read_six_numbers>
   0x0000000000400f0a <+14>:	cmpl   $0x1,(%rsp)                  # (%rsp) should be 1
   0x0000000000400f0e <+18>:	je     0x400f30 <phase_2+52>        
   0x0000000000400f10 <+20>:	call   0x40143a <explode_bomb>
   0x0000000000400f15 <+25>:	jmp    0x400f30 <phase_2+52>
   0x0000000000400f17 <+27>:	mov    -0x4(%rbx),%eax              # %eax = (val in previous loop)
   0x0000000000400f1a <+30>:	add    %eax,%eax                    # %eax *= 2
   0x0000000000400f1c <+32>:	cmp    %eax,(%rbx)                  # (%rsp+4) should be 2
   0x0000000000400f1e <+34>:	je     0x400f25 <phase_2+41>        
   0x0000000000400f20 <+36>:	call   0x40143a <explode_bomb>
   0x0000000000400f25 <+41>:	add    $0x4,%rbx                    # %rbx = %rsp+8
   0x0000000000400f29 <+45>:	cmp    %rbp,%rbx                    
   0x0000000000400f2c <+48>:	jne    0x400f17 <phase_2+27>        # if %rbx != %rsp+24, *2
   0x0000000000400f2e <+50>:	jmp    0x400f3c <phase_2+64>
   0x0000000000400f30 <+52>:	lea    0x4(%rsp),%rbx               # %rbx = %rsp+4
   0x0000000000400f35 <+57>:	lea    0x18(%rsp),%rbp              # %rbp = %rsp+24
   0x0000000000400f3a <+62>:	jmp    0x400f17 <phase_2+27>
   0x0000000000400f3c <+64>:	add    $0x28,%rsp

   0x0000000000400f40 <+68>:	pop    %rbx                         # callee save
   0x0000000000400f41 <+69>:	pop    %rbp                         # callee save
   0x0000000000400f42 <+70>:	ret


read_six_numbers:
   0x000000000040145c <+0>:     sub    $0x18,%rsp                 # %rsp - 24
   0x0000000000401460 <+4>:     mov    %rsi,%rdx                  # move prev %rsp to param_3
   0x0000000000401463 <+7>:     lea    0x4(%rsi),%rcx             # move prev %rsp+4 to param_4
   0x0000000000401467 <+11>:    lea    0x14(%rsi),%rax            # move prev %rsp+20 to %rax
   0x000000000040146b <+15>:    mov    %rax,0x8(%rsp)             # push %rax to stack
   0x0000000000401470 <+20>:    lea    0x10(%rsi),%rax            # move prev %rsp+16 to %rax
   0x0000000000401474 <+24>:    mov    %rax,(%rsp)                # push %rax to stack
   0x0000000000401478 <+28>:    lea    0xc(%rsi),%r9              # move prev %rsp+12 to param_6
   0x000000000040147c <+32>:    lea    0x8(%rsi),%r8              # move prev %rsp+8 to param_5
   0x0000000000401480 <+36>:    mov    $0x4025c3,%esi             # param_2
   0x0000000000401485 <+41>:    mov    $0x0,%eax
   0x000000000040148a <+46>:    call   0x400bf0 <__isoc99_sscanf@plt>
   0x000000000040148f <+51>:    cmp    $0x5,%eax
   0x0000000000401492 <+54>:    jg     0x401499 <read_six_numbers+61>
   0x0000000000401494 <+56>:    call   0x40143a <explode_bomb>
   0x0000000000401499 <+61>:    add    $0x18,%rsp
   0x000000000040149d <+65>:    ret

# ################ Stack
# prev %rsp
# %rsp + 20
# %rsp + 16
# %rsp + 12
# %rsp + 8          <prev%rsp+20> param_8
# %rsp + 4     
# %rsp              <prev%rsp+16> param_7
# ################ Regs
# %r9               <prev%rsp+12> param_6
# %r8               <prev%rsp+8>  param_5
# %rcx              <prev%rsp+4>  param_4
# %rdx              <prev%rsp>    param_3
# ################ __isoc99_sscanf
# ######## parameters
# param_1: const char *s         %rdi           input
# param_2: const char *format    %$0x4025c3     "%d %d %d %d %d %d %d"
# param_3 to n: param_3 - 8  
# ######## return value
# prev%rsp - prev%rsp+20
# ################
