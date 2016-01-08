#!/usr/bin/env runhaskell
-- 2016-01-08 Fri
-- 足し算の問題が出題されて、ユーザが回答するコンソールプログラムである。
-- 関数 Prelude.interact :: (String -> String) -> IO () を用いたことはあったが、ユーザとリアルタイムな対話を行ったことはなかった。ユーザとのリアルタイムな対話ができるだろうと思ったが、実際、行うことができた。
-- （モジュール System.Random を用いて、）擬似乱数を、純粋な関数の内部で使うことができるようだと思ったが、実際、行うことができた。
-- （言語仕様である）遅延評価戦略を利用してユーザとの対話を実現することになったが、コードが評価される順序を考慮する必要があった。評価の順序が確かに理解できず、どう書けば目的の動作になるのか悩み、スムーズにコードが書けず、時間がかかった。
-- 動作の内容自体は、C 言語などの命令型言語においては、ごく簡単に書けるものだろう。特に、対話的な処理については、評価順序の明確な、命令型のスタイルの方が、コードが理解しやすいかもしれない。Haskell で書くことにメリットを見出したいが、デメリットの方が大きいかもしれない。
-- しかし、対話的な処理をあえて純粋な関数として実装することで、勉強になった部分もあるだろう。対話的であることと、擬似乱数を利用することを、純粋な関数として実装するという、Haskell を学び始めた者には少し難しいであろうことを、小さく検証できた。
-- もっとずっとよい書き方があるだろうか？
-- 関数型言語に不慣れな私にとって、関数 interact は興味深い。入出力がそれぞれ記号の列であって、出力が先に先頭から評価され、その中で必要に応じて入力が先頭から評価されていく。Haskell の基本であるその遅延評価というものに、頭が慣れない。慣れたい。Haskell の言語仕様は、コードを書こうとする者を論理的な本質に導くようで、魅力的な感じがする。
module Main (main) where
import qualified System.Random

main :: IO ()
main = do
  gen <- System.Random.getStdGen
  interact $ getString gen . lines
  where
    getString :: System.Random.RandomGen g => g -> [String] -> String
    getString gen lines = question ++ result ++ "\n" ++ next
      where
      question :: String
      question = show random1 ++ " + " ++ show random2 ++ " = "
      result :: String
      result
        | lines == [] = ""
        | (read . head) lines == correct = "correct"
        | otherwise = "wrong"
        where
        correct = random1 + random2
      next :: String
      next
        | lines == [] = ""
        | otherwise = getString gen2 $ tail lines
      random1 :: Int
      (random1, gen1) = System.Random.randomR (10, 100) gen
      random2 :: Int
      (random2, gen2) = System.Random.randomR (10, 100) gen1
