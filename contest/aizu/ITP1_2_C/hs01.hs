#!/usr/bin/env runhaskell
import qualified Data.List
main = do
  interact $ getString . map read . words
  where
    getString :: [Int] -> String
    getString xs = (unwords . map show . getSorted) xs ++ "\n"
    getSorted :: [Int] -> [Int]
    getSorted xs = Data.List.sort xs
