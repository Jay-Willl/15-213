phase_4:
   0x000000000040100c <+0>:	sub    $0x18,%rsp                      # alloc 24 on stack
   0x0000000000401010 <+4>:	lea    0xc(%rsp),%rcx                  # move %rsp+12 to param_4
   0x0000000000401015 <+9>:	lea    0x8(%rsp),%rdx                  # move %rsp+8 to param_3
   0x000000000040101a <+14>:	mov    $0x4025cf,%esi                  # move "%d %d" to param_2
   0x000000000040101f <+19>:	mov    $0x0,%eax                       # clear retreg
   0x0000000000401024 <+24>:	call   0x400bf0 <__isoc99_sscanf@plt>
   0x0000000000401029 <+29>:	cmp    $0x2,%eax                       # if input_num != 2, explode
   0x000000000040102c <+32>:	jne    0x401035 <phase_4+41>

   0x000000000040102e <+34>:	cmpl   $0xe,0x8(%rsp)                  # if input_1 > 14, explode
   0x0000000000401033 <+39>:	jbe    0x40103a <phase_4+46>
   0x0000000000401035 <+41>:	call   0x40143a <explode_bomb>
   0x000000000040103a <+46>:	mov    $0xe,%edx
   0x000000000040103f <+51>:	mov    $0x0,%esi
   0x0000000000401044 <+56>:	mov    0x8(%rsp),%edi
   0x0000000000401048 <+60>:	call   0x400fce <func4>
   
   0x000000000040104d <+65>:	test   %eax,%eax
   0x000000000040104f <+67>:	jne    0x401058 <phase_4+76>
   0x0000000000401051 <+69>:	cmpl   $0x0,0xc(%rsp)
   0x0000000000401056 <+74>:	je     0x40105d <phase_4+81>
   0x0000000000401058 <+76>:	call   0x40143a <explode_bomb>
   0x000000000040105d <+81>:	add    $0x18,%rsp
   0x0000000000401061 <+85>:	ret


func4:
   0x0000000000400fce <+0>:	sub    $0x8,%rsp                       # alloc 8 on stack
   0x0000000000400fd2 <+4>:	mov    %edx,%eax
   0x0000000000400fd4 <+6>:	sub    %esi,%eax
   0x0000000000400fd6 <+8>:	mov    %eax,%ecx
   0x0000000000400fd8 <+10>:	shr    $0x1f,%ecx
   0x0000000000400fdb <+13>:	add    %ecx,%eax
   0x0000000000400fdd <+15>:	sar    $1,%eax
   0x0000000000400fdf <+17>:	lea    (%rax,%rsi,1),%ecx
   0x0000000000400fe2 <+20>:	cmp    %edi,%ecx
   0x0000000000400fe4 <+22>:	jle    0x400ff2 <func4+36>
   0x0000000000400fe6 <+24>:	lea    -0x1(%rcx),%edx
   0x0000000000400fe9 <+27>:	call   0x400fce <func4>
   0x0000000000400fee <+32>:	add    %eax,%eax
   0x0000000000400ff0 <+34>:	jmp    0x401007 <func4+57>
   0x0000000000400ff2 <+36>:	mov    $0x0,%eax
   0x0000000000400ff7 <+41>:	cmp    %edi,%ecx
   0x0000000000400ff9 <+43>:	jge    0x401007 <func4+57>
   0x0000000000400ffb <+45>:	lea    0x1(%rcx),%esi
   0x0000000000400ffe <+48>:	call   0x400fce <func4>
   0x0000000000401003 <+53>:	lea    0x1(%rax,%rax,1),%eax
   0x0000000000401007 <+57>:	add    $0x8,%rsp
   0x000000000040100b <+61>:	ret

# ################ Stack
# prev %rsp
# %rsp + 20
# %rsp + 16
# %rsp + 12          <-  input_2
# %rsp + 8           <-  input_1
# %rsp + 4     
# %rsp              
# ################ __isoc99_sscanf
# %rcx            %rsp+12        param_4
# %rdx            %rsp+8         param_3
# %rsi            "%d %d"        param_2
# %rdi            input          param_1
# ################ func4 iter1
# %rdx            0xe            param_3
# %rsi            0x0            param_2
# %rdi            input_1        param_1
# 
# %rax            0b1110         ret
# %rcx            0b1110         <+8>
# %rcx            0x0            <+10>
# %rax            0b1110         <+13>
# %rax            0b0111         <+15>
# %rcx=%rax+%rsi  input_1+7      <+17>
# %rdx            input_1+6      <+24>





