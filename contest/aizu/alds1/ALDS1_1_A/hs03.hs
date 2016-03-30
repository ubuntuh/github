#!/usr/bin/env runhaskell
module Main (main) where
import qualified Data.List

main :: IO ()
main = do
  interact (unlines . getStrings . lines)
  where
    getStrings :: [String] -> [String]
    getStrings (_: line2 :_) = getStringsFromInts $ map read $ words line2
    getStringsFromInts :: [Int] -> [String]
    getStringsFromInts xs = map (unwords . map show) $ getIntss xs
    getIntss :: [Int] -> [[Int]]
    getIntss xs = xs : (snd $ insertionSort xs)
    insertionSort :: [Int] -> ([Int], [[Int]])
    insertionSort (x:xs) = insertionSort' [x] xs []
    insertionSort' :: [Int] -> [Int] -> [[Int]] -> ([Int], [[Int]])
    insertionSort' xs [] log = (xs, log)
    insertionSort' xs (y:ys) log = insertionSort' inserted ys (log ++ result)
      where
      inserted = Data.List.insert y xs
      result = [inserted ++ ys]

