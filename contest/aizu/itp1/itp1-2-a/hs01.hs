#!/usr/bin/env runhaskell
main = do
  interact $ getString . map read . words
  where
    getString :: [Int] -> String
    getString (a:b:_)
      | a < b = "a < b\n"
      | a > b = "a > b\n"
      | otherwise = "a == b\n"
