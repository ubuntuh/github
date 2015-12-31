#!/usr/bin/env runhaskell
insertionSortVerbose :: Ord a => [a] -> [[a]]
-- Prelude.length :: [a] -> Int
-- Prelude.scanl :: (a -> b -> a) -> a -> [b] -> [a]
-- scanl の初期値 xs は scanl の返り値の頭にそのまま返されるのと、[0..length xs-1] の 0 の場合には step の引数 es がそのまま返されるので、最初の同一の形の値が 2 回現れてしまう。これを処理するためにここでは tail で頭を捨てているが、[0..length xs-1] の 0 を 1 とし、tail は行わないこともできるだろう。
insertionSortVerbose xs = scanl step xs [0..length xs-1]
    where
        step es n = let
            -- Prelude.splitAt :: Int -> [a] -> ([a], [a])
            (pre,x:post) = splitAt n es
            in
                insertOrderd x pre ++ post

-- 第 2 引数 ts を頭から眺め、第 1 引数 x よりも大きな数が現れたら、その直前に x を挿入して、リストを返す。
-- 特に、ts が昇順に整列済みの場合、整列される位置に x を挿入し、整列されたリストを返す。        
insertOrderd :: Ord a => a -> [a] -> [a]
-- Prelude.span :: (a -> Bool) -> [a] -> ([a], [a])
insertOrderd x ts = let (pre,post) = span (< x) ts
                        in
                            pre ++ (x:post)
 
 
main = do
    -- Prelude.getLine :: IO String
    -- 標準入力から 1 行読み込む。
    -- ここでは入力サイズ n が不要なので捨てている。
    _ <- getLine
    -- Prelude.(>>=) :: forall a b. m a -> (a -> m b) -> m b (infixl 1)
    -- bind operator。左のモナドの内容を右の関数に渡す。
    -- よって一時的に変数？ temp を使って次のように書いても同じ。
    -- temp <- getLine
    -- mapM_ (putStrLn . unwords . map show)
    --   . tail . insertionSortVerbose
    --   . map (read :: String -> Int)
    --   . words $ temp
    -- Prelude.words :: String -> [String]
    -- Prelude.read :: Read a => String -> a
    -- read の型が指定してあるが、しなければ、型が曖昧であるとしてコンパイルエラーになる。
    -- Prelude.map :: (a -> b) -> [a] -> [b]
    -- Prelude.tail :: [a] -> [a]
    -- Prelude.show :: Show a => a -> String
    -- Prelude.unwords :: [String] -> String
    -- Prelude.putStrLn :: String -> IO ()
    -- Prelude.mapM_ :: Monad m => (a -> m b) -> [a] -> m()
    getLine >>= mapM_ (putStrLn . unwords . map show) . tail .
        insertionSortVerbose . map (read :: String -> Int) . words
