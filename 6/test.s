	.file	"test.cpp"
.lcomm __ZStL8__ioinit,1,1
	.section .rdata,"dr"
LC0:
	.ascii "constructor\0"
	.section	.text$_ZN1AC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN1AC1Ev
	.def	__ZN1AC1Ev;	.scl	2;	.type	32;	.endef
__ZN1AC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	$11111111, (%eax)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$96, %esp
	movl	$___gxx_personality_sj0, 52(%esp)
	movl	$LLSDA1026, 56(%esp)
	leal	60(%esp), %eax
	movl	%ebp, (%eax)
	movl	$L5, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	movl	$4, (%esp)
	movl	$-1, 32(%esp)
	call	__Znwj
	movl	%eax, 24(%esp)
	movl	%eax, (%esp)
	movl	$1, 32(%esp)
	call	__ZN1AC1Ev
	movl	24(%esp), %eax
	movl	%eax, 88(%esp)
	leal	88(%esp), %eax
	movl	%eax, 92(%esp)
	movl	$0, %eax
	movl	%eax, 24(%esp)
	jmp	L7
L5:
	movl	36(%esp), %eax
	movl	%eax, 20(%esp)
	movl	24(%esp), %ecx
	movl	%ecx, (%esp)
	call	__ZdlPv
	movl	20(%esp), %eax
	movl	%eax, (%esp)
	movl	$-1, 32(%esp)
	call	__Unwind_SjLj_Resume
L7:
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	24(%esp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1026:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1026-LLSDACSB1026
LLSDACSB1026:
	.uleb128 0
	.uleb128 0
LLSDACSE1026:
	.text
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L8
	cmpl	$65535, 12(%ebp)
	jne	L8
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___dso_handle, 8(%esp)
	movl	$__ZStL8__ioinit, 4(%esp)
	movl	$__ZNSt8ios_base4InitD1Ev, (%esp)
	call	___cxa_atexit
L8:
	leave
	ret
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (GNU) 4.9.3"
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	___real__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	___cxa_atexit;	.scl	2;	.type	32;	.endef
