# X Window System

### 2015-12-07 Mon

- X Window System についての概要を、現在的な Ubuntu 環境に絞って考える。
- Unix 系 OS の GUI 環境は、X Window System によって担われている。X Window System は、X という名前の window system であるという意味である。
- X Windows System は、1984 年に最初のバージョンの X1 が登場したが、1987 年に登場した X11 以来、プロトコルは安定しており、2012 年に更新されたバージョンでも名称は X11R7.7 であって、「11」というバージョンが続いている。
- X Window System は、歴史的にネットワークに強い Unix 系 OS らしく、ネットワークを通じた利用が想定された仕様が定められている。例えば、X server と X client という概念が大切である。一見、ユーザに近いローカルな側が X client かと誤解しかねないが、表示能力しかなくてよいユーザの側が X server であり、プログラムの実装が実在しているリモート側が X client である。
- 今や実用的とは言えないが、X Window System の上で提供される基本的なアプリケーションとして、terminal emulator である xterm、テキストエディタである xedit、電卓である xcalc、ウィンドウの情報を得る xwininfo、時計を表示する xclock、マウスポインタに追随する目線を表示する xeyes、画像編集プログラム bitmap などがある。これらは、現在の Ubuntu でもインストールされていて、ターミナルでその名前を打てば動く。
- そのような、個々のプログラムそれぞれが X client である。X application とも言う。
- Unix 系 OS では一般に、それぞれのユーザが認証を受けてシステムを利用することになるが、個々のユーザのログイン状況はそれぞれ login session として管理される。また、login session らは、login manager というプログラムによって管理されるが、login manager は、login のためのユーザインタフェースについても責任を持っている。
- login 動作は、シンプルにはテキストターミナルで行われるが、これをグラフィカルに行う場合には、グラフィカルな種類の login manager を使うことになる。それはすなわち、（X Window System を用いた）X display manager である。X display manager は単に DM と表されることがある。
- XDM と呼ばれる X Window Display Manager というものがあるが、これは X display manager の一種であって、X display manager そのものではない。
- X display manager には様々なものがあるが、現在の Ubuntu では lightdm というものが使われている。Ubuntu 11.10 から lightdm がデフォルトである。それ以前は gdm (GNOME Display Manager) が用いられていたらしい。
- X display manager は、ログイン画面の外観を定めるのみならず、login session 全体を管理している。
- X display manager は、テキストターミナルにおける getty プログラムのグラフィカルな相似だと言える。

#### server-client

- X Window System 上の個々のアプリケーションはそれぞれ X client である。
- X client は、X Server からマウスクリックなどのイベントを受け取り、X Server へウィンドウなどの描画命令を返す。
- 描画を計算する負荷をローカル側で担当できるようになっている。

#### -

- X display manager は、login 要求をする前に X server を開始する。
    - これは、X server を開始しなければグラフィカルな描画ができず、また login ユーザインタフェースはグラフィカルにしたいのが X display manager であるから、ほとんど必然的であると考えられる。
- desktop environment として、Unity や GNOME や KDE や xfce などがある。desktop environment が、デスクトップの使用感や、ウィンドウが表示されるデザイン、付属するユーティリティソフトを決める。
- Ubuntu の desktop environment は Unity である。ただしより正確には、Unity は単に GNOME desktop environment 上の shell の一種であるらしい。なお GNOME のデフォルトの shell は GNOME Shell と言う。つまり Ubuntu は GNOME Shell ではなく Unity を使っているが、基本的には GNOME desktop environment に近い（あるいはそのものである）と言える。
- desktop environment という言葉とは別に window manager という言葉もある。意味はよくわからない。window manager の方がずっと小さいものであるようだ。
- X window system を終了するには `sudo service lightdm stop` とすればよいらしい。開始するには `sudo service lightdm start` とすればよいらしい。しかし不安定になるかもしれない。


