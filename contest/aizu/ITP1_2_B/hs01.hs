#!/usr/bin/env runhaskell
main = do
  interact $ getString . map read . words
  where
    getString :: [Int] -> String
    getString (a:b:c:[])
      | a < b && b < c = "Yes\n"
      | otherwise = "No\n"
