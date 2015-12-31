#!/usr/bin/env runhaskell
import Data.List
 
putListLn :: Show a => [a] -> IO ()
putListLn = putStrLn . unwords . map show
getList :: Read a => IO [a]
-- Prelude.fmap :: Functor f => (a -> b) -> f a -> f b
getList = fmap (map read . words) getLine
 
isortStates :: Ord a => [a] -> [[a]]
-- Data.List.tails :: [a] -> [[a]]
-- 例えば tails [1, 2, 3] を評価すると [[1, 2, 3], [2, 3], [3], []] になります。
-- Data.List.insert :: Ord a => a -> [a] -> [a]
-- Prelude.flip :: (a -> b -> c) -> b -> a -> c
-- Prelude.zipWith :: (a -> b -> c) -> [a] -> [b] -> [c]
isortStates l = tail $ zipWith (++) (scanl (flip insert) [] l) (tails l)
 
main :: IO ()
main = do
  -- Prelude.getLine :: IO String
  -- 入力の 1 行目を捨てる。
  _ <- getLine
  ns <- getList :: IO [Int]
  -- 今や、ns は例えば [5, 2, 4, 6, 1, 3] :: [Int] である。
  mapM_ putListLn $ isortStates ns
