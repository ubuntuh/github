# Cron

### 2016-02-05 Fri

* Ubuntu （など）であるプログラムを定期的に実行したい場合には cron という機能を使えばよいらしい。cron という名前は、ギリシャ語で時間を意味するクロノスから来ている。
* Cron は job scheduler であり、実行する対象それぞれを job と言う。
* どのプログラムをどの時刻に実行するかが書かれたファイルを cron table と言い、crontab と言う。crontab には crontab の書式がある。
* crontab には、システム共通のものが 1 つと、ユーザ個別のものが任意個ある。
* ユーザ個別の crontab は /var/spool/cron/crontabs ディレクトリにあり、crontab コマンドを通して操作する。
* システム共通の crontab は、/etc/crontab である。
* /etc/cron.daily、/etc/cron.hourly、/etc/cron.monthly、/etc/cron.weekly というディレクトリがあるが、ここにあるスクリプトは /etc/crontab から実行される。/etc/crontab の内容は cat /etc/crontab とすれば見られる。
* システム共通の crontab では、実行ユーザを指定する項がある。
* test -x /usr/sbin/anacron || ... となっているのは、anacron があれば以下のコマンドを実行しないということである。cd / は、ルートディレクトリをカレントディレクトリにする。run-parts コマンドは、与えられたディレクトリの中のスクリプトを全て実行する。
* anacron は、コンピュータがしばらく起動していなかった時、もし起動していたならば実行されたであろう crontab 項目を遅れてでも実行する機能である。
* cron は、サーバなど、起動しつづけるコンピュータを想定している。anacron はそうではない。anacron については、/etc/anacrontab や、anacrontab コマンドがある。
* job が実行できたかどうかは、/var/log/syslog を見れば確認できるらしい。

# >/dev/null 2>&1

* cron によってプログラムを自動的に実行する場合、プログラムからの出力を捨てるために、bash スクリプト上で >/dev/null 2>&1 という書く方法が用いられる。
* 他の書き方もあるようだが、この書き方が最も汎用性があるのだろう。
