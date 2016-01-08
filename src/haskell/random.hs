#!/usr/bin/env runhaskell
module Main (main) where
import qualified System.Random
-- 2016-01-08 Fri
-- System.Random というモジュールについて考える。
-- System.Random というモジュールは、Haskell という言語において、擬似乱数を得るための最も基本的なプラットフォームであるようである。
-- モジュール System.Random においては、任意の random number generator を定義して利用することができるが、デフォルトでは 1 種類の random number generator が実装され提供されている。その唯一の random number generator は、StdGen という型で表される。
-- StdGen は、様々な異なる擬似乱数を生じるために状態を持つが、様々な状態の値は、StdGen 型という集合の要素である。
-- System.Random モジュールにおいては、それぞれの random number generator、実際にはとりあえず StdGen のみであるが、は、RandomGen というクラスの要素、すなわちインスタンスである。クラス RandomGen に含まれる型は、3 つの関数 next、getRange、split の定義域に含まれる。例えば、StdGen 型の任意の値 a について、next a は、(b, c) を返す。ただしここで b は Int 型の値、c は StdGen 型の値である。
-- 実際には、StdGen 型の値は、2 つの 32 ビット符号付き整数 (Data.Int.Int32 型）の値の列である。ただし、コンストラクタ StdGen の名前は露出していないので、この値を直接作ることはできない。
-- StdGen 型の値を得るためには、mkStdGen :: Int -> StdGen が利用できる。mkStdGen は、Int 型の random seed を取って StdGen 型の値を返す。例えば、mkStdGen 0 は StdGen 1 1 を返すようである。
-- generator0 = mkStdGen 0 などとして StdGen 型の値 generator0 を作成し、さらに、(n, generator1) = next generator0 などとすれば、擬似乱数 n と、次の random number generator である generator1 が得られる。
-- あるいは、mkStdGen を使わず、getStdGen :: IO StdGen を用いると、プログラムを実行するたびに異なる擬似乱数を得ることが簡単にできる。この関数 getStdGen は、global random number generator を返す。global random number generator は、唯一存在し、システムによって自動的に初期化される。getStdGen というのは、名前が少し紛らわしいが、「Std」という言葉が global であることを表しているのではないことに留意すべきだろう。言わば、getGlbStdGen とでも称した方がわかりやすいかもしれない。
-- Int や Float などの多くの基本的な型は、デフォルトで、Random というクラスのインスタンスであると定義されている。クラス Random のインスタンスについて使える最も基本的な関数 random :: RandomGen g => g -> (a, g) を用いると、例えば Float 型の擬似乱数が欲しい場合に、得ることができる。
-- 例えば、random (mkStdGen 0) :: (Float, StdGen) の返り値のタプルの第 1 要素には、Float 型の値が得られる。
-- クラス RandomGen の関数 next の型は RandomGen クラスのある型 g について g -> (Int, g) であった。一方で、クラス Random の関数 random の型は、Random クラスのある型 a について、RandomGen g => g -> (a, g) である。つまり、関数 next は Int 型の擬似乱数しか生成できなかったが、それを wrap する random では、任意の型の擬似乱数を生成できる。クラス RandomGen に属するそれぞれの random number generator は、Int 型を出力する方法しか知らないし、クラス Random に属するそれぞれの型は、Int 型の値を自らの型の値にバランスよく変換する方法は知っているが、擬似乱数を生む実装については知らない。
-- Int 型の値からある型の値への変換の方法と、random number generator があれば、ある型の擬似乱数を得ることができる。関数 random によって、Int 型からある型への変換は定義されるので、そこに random number generator としてもし global random number generator を与えるならば、関数 getStdRandom :: (StdGen -> (a, StdGen)) -> IO a を利用して getStdRandom random とすれば、擬似乱数を得られる。あるいは例えば、getStdRandom random :: IO Float としたりまたは、getStdRandom (random :: StdGen -> (Float, StdGen)) とすると Float 型の乱数が得られる。
-- 同じことは単に、クラス Random の関数 randomIO :: IO a を用いて、randomIO :: IO Float などとしても達成できる。
-- また、クラス Random の関数 randoms :: RandomGen g => g -> [a] などを使うと、簡単に擬似乱数のリストを作ることができる。例えば、このリストを関数への引数として渡したならば、このリストの値を遅延評価で利用することで、関数を純粋に保つことができるだろう。
-- しかし実際には、純粋な関数の内部で、任意の部分で任意の型の任意の範囲の値が得られるべきだろう。そう考えると、関数 randoms を用いることは安易かもしれない。
-- こうして、モジュール System.Random の基本的な使い方を眺めてみると、擬似乱数の獲得には必ず副作用が伴うとは言っても、実際に副作用が不可欠なのは、random number generator を最初に無作為に初期化する時だけであって、それ以外では副作用を出さない方法がシンプルに整理されて提供されている。
-- そのため、副作用のある具体的なレイヤーで random number generator を作成し、純粋な関数を呼び出す際に引数として渡すことで、純粋な関数の中で自由に擬似乱数を用いることができるだろう。
-- ...と思って少し書いたが、結局、状態を持ちまわることになるので面倒くさい。順番を意識することになる。少し大きなプログラムを同じ方法で問題なく書けるのだろうか？
-- RandomGen クラスによって実装は抽象化されているが、擬似乱数を生成するプログラムは Int 型でしか乱数を出力できないのと、Random クラスの関数 random などの実装はすでに与えられているということがわかる。もしデフォルトの random number generator である StdGen に不満を持った場合には、この仕様の中でより良いものを使えるのだろうか？
-- ネットの記事によれば、モジュール System.Random による標準的な擬似乱数の生成は、random number generator を非破壊的に扱う仕様のために、高速に処理を行いたい場合には適さないともいう。しかし私は、特に高度なことをする予定もないので、モジュール System.Random を使っていればいいのではないかと思う。
import qualified Data.Time.Clock.POSIX

main :: IO ()
main = do
  time <- fmap floor Data.Time.Clock.POSIX.getPOSIXTime :: IO Int
  putStrLn $ "Random Seed: " ++ show time
  let
    generator = System.Random.mkStdGen time
    (string, _) = pureFunction generator
  putStrLn string
  where
    pureFunction :: System.Random.RandomGen g => g -> (String, g)
    pureFunction gen = (string, gen2)
      where
      string = "Random1: " ++ show random1 ++ "\nRandom2: " ++ show random2
      random1 :: Int
      (random1, gen1) = System.Random.randomR (1, 1000) gen
      random2 :: Int
      (random2, gen2) = System.Random.randomR (1, 1000) gen1
