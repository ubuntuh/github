	// gcc -g example.S
	// gdb a.out などとして実行できます。start で開始し、ni で進みます。i r rax や p $rax などとしてレジスタの値を確認できます。c で自動的に実行し、q で gdb を終了します。
	.text
	.global main
main:
	movq $1, %rax	// mov 命令は値をコピーします。
	movq $2, %rax	// レジスタ RAX に 2 を格納します。
	movq $3, %rax	// $ は即値、% はレジスタ名の意味です。
	movq $4, %rax	// movq の末尾の q は 64 bit を意味します。
	movq $18446744073709551615, %rax	// 64 bit unsigned integer の最大値を格納します。
	movq $9223372036854775807, %rax	// 64 bit signed integer の最大値を格納します。
	movq $-1, %rax	// -1 を格納します。結果は、64 bit unsigned integer の最大値を格納した場合と同じです。
	movb $1, %al	// レジスタ RAX の下位 8 bit に 1 を格納します。
	movb $1, %ah	// RAX の下位 16 bit の上位 8 bit に 1 を格納します。
	movw $1, %ax	// RAX の下位 16 bit に 1 を格納します。
	movl $2, %eax	// RAX の下位 32 bit に 2 を格納します。32 bit レジスタを使うと上位 32 bit は 0 になります。

	movq $60, %rax	// 60 は exit システムコールを意味します。
	xorq %rdi, %rdi	// レジスタ RDI を 0 にします。
	syscall		// システムコールを実行します。
