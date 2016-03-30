#!/usr/bin/env runhaskell
module Main (main) where
import qualified Data.List
-- Data.List.sort を使っています……。

main :: IO ()
main = do
  interact (unlines . getStrings . lines)
  where
    getStrings :: [String] -> [String]
    getStrings (_: line2 :_) = getStringsFromInts $ map read $ words line2
    getStringsFromInts :: [Int] -> [String]
    getStringsFromInts x = map (unwords . map show) $ getIntss x
    getIntss :: [Int] -> [[Int]]
    getIntss x = x : getIntss' x 1
    getIntss' :: [Int] -> Int -> [[Int]]
    getIntss' x acc
      | length x <= acc = []
      | otherwise  = sorted : getIntss' sorted (acc + 1)
      where
      sorted = sort0 acc x
    sort0 :: Int -> [Int] -> [Int]
    sort0 acc x
      | length x <= acc = x
      | otherwise = Data.List.sort (take (acc + 1) x) ++ drop (acc + 1) x

