#!/usr/bin/env runhaskell
module Main (main) where

main :: IO ()
main = do
  interact $ unlines . getLines . lines
  where
    getLines :: [String] -> [String]
    getLines (_: line1 :_) = (unwords $ map show sorted) : show numSwap : []
      where
      unsorted :: [Int]
      unsorted = map read $ words line1
      (sorted, numSwap) = bubbleSort unsorted
        where
        bubbleSort :: [Int] -> ([Int], Int)
        bubbleSort [] = ([], 0)
        bubbleSort [x] = ([x], 0)
        bubbleSort xs = bubbleSort' xs 0
        bubbleSort' :: [Int] -> Int -> ([Int], Int)
        bubbleSort' xs numSwap
          | continue = bubbleSort' xs1 numSwap1
          | otherwise = (xs1, numSwap1)
          where
          (xs1, numSwap1, continue) = bubbleSort'' xs numSwap False (length xs - 1)
        bubbleSort'' :: [Int] -> Int -> Bool -> Int -> ([Int], Int, Bool)
        bubbleSort'' xs numSwap continue j
          | j < 1 = (xs, numSwap, continue)
          | xj < xjPrev = bubbleSort'' swapped (numSwap + 1) True (j - 1)
          | otherwise = bubbleSort'' xs numSwap continue (j - 1)
          where
          swapped = before ++ xj : xjPrev : after
          (before, xjPrev : xj : after) = splitAt (j - 1) xs
