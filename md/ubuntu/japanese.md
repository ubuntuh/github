# Japanese

### 2016-03-20 Sun

- 日本語入力。
- sudo apt-get install ibus-mozc
- restart
- System Settings - Text Entry - Japanese (Mozc) (IBus)

#### Mozc Setting

#### Mozc keymap editor

- keymap style は MS-IME を基本とする。
- mode は、DirectInput、Precomposition、Composition、Conversion、Viewing suggestion、Selecting suggestion という 6 種類がある。
- 日本語キーボードを使い、変換キーで日本語を入力する状態になり、無変換キーで英語を入力する状態になることを求める。
- これらのキーへの割り当てはデフォルトでは次のようになっている。
- Composition	Henkan	Convert
- Conversion	Henkan	Select next candidate
- DirectInput	Henkan	Reconvert
- Precomposition	Henkan	Reconvert
- Composition	Muhenkan	Switch kana type
- Conversion	Muhenkan	Switch kana type
- Precomposition	Muhenkan Set input mode to next kana type
- これらを Henkan については Activate IME に、Muhenkan については Deactivate IME に変更すればよい。