# gcc

### 2016-03-07 Mon

#### -fno-asynchronous-unwind-tables

- コンパイラ gcc で単に gcc example.c などとすると、a.out などとして実行ファイルが生成される。./a.out などとして実行できる。
- gcc -S example.c とすると、実行ファイルは作られず、example.s などとアセンブリが作られる。
- こうして作られたアセンブリは、.cfi_startproc といった、CFI directive が書き込まれていて、場合によっては邪魔である。これを避けるためには、gcc の -fno-asynchronous-unwind-tables というオプションが使える。
- また、手に入る情報はしばしば x86 (32 bits) のためのものなので、x64 環境であっても x86 アセンブリにコンパイルすることが便利な場合がある。そのために、gcc の -m32 オプションが使える。
- また、最適化を防ぐことは、gcc の -O0 オプションで行える。
- これらを考慮すると例えば、gcc -m32 -O0 -S -fno-asynchrounous-unwind-tables example.c というコマンドが便利である。
