	.file	"hello.rc"
	.text
	.align	16, 0x90
	.type	_ZN9intrinsic6TyDesc6TyDesc6TyDesc17_fc12f15392cba55a3_00E,@function
_ZN9intrinsic6TyDesc6TyDesc6TyDesc17_fc12f15392cba55a3_00E:
	.cfi_startproc
	cmpq	%fs:112, %rsp
	ja	.LBB0_0
	movabsq	$8, %r10
	movabsq	$0, %r11
	callq	__morestack
	ret
.LBB0_0:
	pushq	%rbp
.Ltmp2:
	.cfi_def_cfa_offset 16
.Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp4:
	.cfi_def_cfa_register %rbp
	movabsq	$0, %rax
	addq	$8, %rax
	shlq	$1, %rax
	movq	%rdx, %rsi
	movq	%rax, %rdx
	callq	memcpy@PLT
	popq	%rbp
	ret
.Ltmp5:
	.size	_ZN9intrinsic6TyDesc6TyDesc6TyDesc17_fc12f15392cba55a3_00E, .Ltmp5-_ZN9intrinsic6TyDesc6TyDesc6TyDesc17_fc12f15392cba55a3_00E
	.cfi_endproc

	.globl	_ZN4main17_266a6f8e4cc1d94a3_00E
	.align	16, 0x90
	.type	_ZN4main17_266a6f8e4cc1d94a3_00E,@function
_ZN4main17_266a6f8e4cc1d94a3_00E:
	.cfi_startproc
	cmpq	%fs:112, %rsp
	ja	.LBB1_0
	movabsq	$40, %r10
	movabsq	$0, %r11
	callq	__morestack
	ret
.LBB1_0:
	pushq	%rbp
.Ltmp8:
	.cfi_def_cfa_offset 16
.Ltmp9:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp10:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movabsq	$0, %rax
	addq	$16, %rax
	leaq	-32(%rbp), %rcx
	leaq	-16(%rbp), %rdx
	leaq	str1802(%rip), %rsi
	#APP
	# io::println("hello?"); (hello.rs:2:1: 2:23)
	#NO_APP
	movq	%rsi, -16(%rbp)
	movq	$7, -8(%rbp)
	movq	%rcx, %rdi
	movq	%rdx, %rsi
	movq	%rax, %rdx
	callq	memcpy@PLT
	leaq	-32(%rbp), %rdx
	callq	_ZN2io7println16_1d552823be4e11c3_05E@PLT
	addq	$32, %rsp
	popq	%rbp
	ret
.Ltmp11:
	.size	_ZN4main17_266a6f8e4cc1d94a3_00E, .Ltmp11-_ZN4main17_266a6f8e4cc1d94a3_00E
	.cfi_endproc

	.globl	_rust_main
	.align	16, 0x90
	.type	_rust_main,@function
_rust_main:
	.cfi_startproc
	cmpq	%fs:112, %rsp
	ja	.LBB2_0
	movabsq	$8, %r10
	movabsq	$0, %r11
	callq	__morestack
	ret
.LBB2_0:
	pushq	%rbp
.Ltmp14:
	.cfi_def_cfa_offset 16
.Ltmp15:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp16:
	.cfi_def_cfa_register %rbp
	callq	_ZN4main17_266a6f8e4cc1d94a3_00E@PLT
	popq	%rbp
	ret
.Ltmp17:
	.size	_rust_main, .Ltmp17-_rust_main
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:
	.cfi_startproc
	cmpq	%fs:112, %rsp
	ja	.LBB3_0
	movabsq	$24, %r10
	movabsq	$0, %r11
	callq	__morestack
	ret
.LBB3_0:
	pushq	%rbp
.Ltmp20:
	.cfi_def_cfa_offset 16
.Ltmp21:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp22:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	_rust_main@GOTPCREL(%rip), %rax
	movq	_rust_crate_map_toplevel@GOTPCREL(%rip), %rcx
	movq	%rdi, -8(%rbp)
	movq	%rax, %rdi
	movq	-8(%rbp), %rax
	movq	%rsi, -16(%rbp)
	movq	%rax, %rsi
	movq	-16(%rbp), %rdx
	callq	rust_start@PLT
	addq	$16, %rsp
	popq	%rbp
	ret
.Ltmp23:
	.size	main, .Ltmp23-main
	.cfi_endproc

	.type	_rust_crate_map_toplevel,@object
	.section	.data.rel,"aw",@progbits
	.globl	_rust_crate_map_toplevel
	.align	16
_rust_crate_map_toplevel:
	.long	1
	.zero	4
	.quad	_ZN7cleanup10annihilate17_bde425c43da4f4993_05E
	.quad	_rust_mod_map
	.quad	_rust_crate_map_core_0.5_c3ca5d77d81b46c1
	.quad	0
	.size	_rust_crate_map_toplevel, 40

	.type	_ZN9intrinsic6TyDesc6TyDesc7descrim16_af0dd4bac48d69d3_00E,@object
	.section	.rodata,"a",@progbits
	.globl	_ZN9intrinsic6TyDesc6TyDesc7descrim16_af0dd4bac48d69d3_00E
	.align	8
_ZN9intrinsic6TyDesc6TyDesc7descrim16_af0dd4bac48d69d3_00E:
	.quad	0
	.size	_ZN9intrinsic6TyDesc6TyDesc7descrim16_af0dd4bac48d69d3_00E, 8

	.type	str1802,@object
str1802:
	.asciz	 "hello?"
	.size	str1802, 7

	.type	_rust_mod_map,@object
	.local	_rust_mod_map
	.comm	_rust_mod_map,16,8
	.type	rust_abi_version,@object
	.globl	rust_abi_version
	.align	8
rust_abi_version:
	.quad	1
	.size	rust_abi_version, 8


	.section	".note.GNU-stack","",@progbits
