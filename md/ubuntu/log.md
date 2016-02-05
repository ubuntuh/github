# log

### 2016-02-05 Fri

* Ubuntu ではシステムのログが取られているが、代表的なものの一つに /var/log/syslog があり、cat /var/log/syslog とすると見られる。
* logger "test" などとすると、ログを記録することができる。
* こういったログをどの程度で破棄するかはデフォルトで /etc/logrotate.d/rsyslog に書いてある。
