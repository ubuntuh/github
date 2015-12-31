#!/usr/bin/env runhaskell
module Main (main) where

main :: IO ()
main = do
  interact (unlines . getStrings . lines)
  where
    getStrings :: [String] -> [String]
    getStrings (_: line2 :_) = getStringsFromInts $ map read $ words line2
    getStringsFromInts :: [Int] -> [String]
    getStringsFromInts x = map (unwords . map show) $ getIntss x
    getIntss :: [Int] -> [[Int]]
    getIntss x = x : getIntss' 1 x
    getIntss' :: Int -> [Int] -> [[Int]]
    getIntss' i x
      | length x <= i = []
      | otherwise = sorted : getIntss' (i + 1) sorted
      where
      sorted = sort0 i x
    sort0 :: Int -> [Int] -> [Int]
    sort0 i x
      | length x <= i = x
      | otherwise = sort1 i (x !! i) (i - 1) x
    sort1 :: Int -> Int -> Int -> [Int] -> [Int]
    sort1 i v j x
      | n <= i = x
      | j < 0 = x
      | xj <= v = x
      | otherwise = sort1 i v (j - 1) sorted
      where
      n = length x
      xj = x !! j
      xj' = x !! (j + 1)
      sorted = take j x ++ [xj', xj] ++ drop (j + 2) x

