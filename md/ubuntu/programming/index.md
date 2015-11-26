# Programming

### 2015-11-26 Thu

#### example.h: no such file...

- 例えば C 言語で書いたプログラムを `gcc helloworld.c` などとコンパイルした際、`fatal error: example/example.h: No such file or directory` などというエラーが出てコンパイルできなかった場合には、ブラウザで [Ubuntu Packages Search](http://packages.ubuntu.com/) にアクセスして、"Search the contents of packages" のところでこの場合 "exmaple/example.h" を検索するとよい。すると、（もしあれば、）`sudo apt-get install ..." すべきパッケージが表示される。インストールすれば、先のプログラムがコンパイルできるようになる、ことがある。
- apt-file というコマンドをインストールしてあれば、同じことをコマンドラインから行える。apt-file をインストールするには、`sudo apt-get update` してから `sudo apt-get install apt-file` とすればよい。`apt-file update` とすると、検索に必要な情報が（ローカルに）キャッシュされる。そのあと、`apt-file search example/example.h` とすれば、（もしあれば、）そのファイルが含まれるパッケージがわかる。なお、`apt-file update` は、`sudo apt-file update` でもよい。前者の場合、ユーザの領域にデータがキャッシュされ、後者では共有の領域にキャッシュされる。
- コマンドラインから行えるのみならず、オフラインで行える点で、apt-file コマンドの方が優れている。しかしもちろん、不足しているパッケージが判明しても、オンラインでなければインストールはできないだろう。

#### -

- Pascal のソースファイルの拡張子は .pas が標準的である。
- fpc でコンパイルした際に `warning: link.res contains output sections; did you forget -T?` という警告が出るが、無視しておけばいいらしい。簡単には消せないらしい。
- `sudo apt-get install fp-docs` などとして Free Pascal のドキュメントをインストールしたならば、file:///usr/share/doc/fp-docs/2.6.4/fpctoc.html といったパスにあるファイルを xdg-open などで開くことで、ドキュメントを閲覧できる。
- eglibc ないし glibc のバージョンを知りたければ `/lib/x86_64-linux-gnu/libc.so.6` とすればいいらしい。
- あるいは、`aptitude show libc6` としてもいいらしい。
- C プログラムなどをコンパイルしていて "warning: implicit declaration of function 'write'" などと警告が出たら、そのコマンドの man ページを確認して、適切なヘッダファイルを #include すればいい。
- 同じ名前のコマンドが複数あって、man ページが複数ある場合、例えば `whatis write` として概要を知り、`man 2 write` などとして特定のものを閲覧すればよい。
- kernel のバージョンを知りたければ、`uname -r` とすればよい。

