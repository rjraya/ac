	.file	"prod2.c"
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC1:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$96, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	leal	80(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	clock_gettime
	movl	N, %eax
	testl	%eax, %eax
	movl	%eax, 56(%esp)
	je	.L2
	sall	$2, %eax
	movl	%eax, 68(%esp)
	movl	$0, 28(%esp)
	movl	$0, 36(%esp)
.L3:
	movl	28(%esp), %eax
	movl	$C, 32(%esp)
	movl	$0, 40(%esp)
	leal	A(%eax), %edi
	addl	$B, %eax
	movl	%edi, 52(%esp)
	movl	%eax, 24(%esp)
.L13:
	movl	24(%esp), %eax
	movl	$0, 48(%esp)
	movl	%eax, 44(%esp)
	movl	32(%esp), %eax
	movl	%eax, 64(%esp)
.L12:
	movl	44(%esp), %eax
	movl	52(%esp), %edx
	movl	$10, 60(%esp)
	movl	%eax, 72(%esp)
	.p2align 4,,7
	.p2align 3
.L9:
	movl	64(%esp), %ebx
	xorl	%edi, %edi
	.p2align 4,,7
	.p2align 3
.L4:
	movl	72(%esp), %eax
	movl	(%eax,%edi,4), %esi
	xorl	%eax, %eax
	.p2align 4,,7
	.p2align 3
.L7:
	movl	(%ebx,%eax,4), %ecx
	imull	%esi, %ecx
	addl	%ecx, (%edx,%eax,4)
	addl	$1, %eax
	cmpl	$10, %eax
	jne	.L7
	addl	$1, %edi
	addl	68(%esp), %ebx
	cmpl	$10, %edi
	jne	.L4
	movl	68(%esp), %eax
	addl	%eax, 72(%esp)
	addl	%eax, %edx
	subl	$1, 60(%esp)
	jne	.L9
	addl	$10, 48(%esp)
	movl	48(%esp), %eax
	addl	$40000, 64(%esp)
	addl	$40, 44(%esp)
	cmpl	%eax, 56(%esp)
	ja	.L12
	addl	$10, 40(%esp)
	movl	40(%esp), %eax
	addl	$40, 52(%esp)
	addl	$40, 32(%esp)
	cmpl	%eax, 56(%esp)
	ja	.L13
	addl	$10, 36(%esp)
	movl	36(%esp), %eax
	addl	$40000, 28(%esp)
	cmpl	%eax, 56(%esp)
	ja	.L3
.L2:
	leal	88(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$0, (%esp)
	call	clock_gettime
	movl	N, %eax
	movl	$.LC1, 4(%esp)
	movl	$1, (%esp)
	movl	%eax, 16(%esp)
	movl	88(%esp), %eax
	subl	80(%esp), %eax
	movl	%eax, 76(%esp)
	movl	92(%esp), %eax
	subl	84(%esp), %eax
	fildl	76(%esp)
	movl	%eax, 76(%esp)
	fildl	76(%esp)
	fdivs	.LC0
	faddp	%st, %st(1)
	fstpl	8(%esp)
	call	__printf_chk
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.comm	C,4000000,32
	.comm	B,4000000,32
	.comm	A,4000000,32
	.globl	N
	.data
	.align 4
	.type	N, @object
	.size	N, 4
N:
	.long	1000
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC0:
	.long	1315859240
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
