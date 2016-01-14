#!/usr/bin/env runhaskell
main = do
  interact $ getString . map read . words
  where
    getString :: [Int] -> String
    getString (a:b:c:_) = (unwords $ map show $ getSorted a b c) ++ "\n"
    getSorted :: Int -> Int -> Int -> [Int]
    getSorted a b c =
      if a <= b then
        if a <= c then
          if b <= c then
            [a, b, c]
          else
            [a, c, b]
        else
          [c, a, b]
      else
        if b <= c then
          if a <= c then
            [b, a, c]
          else
            [b, c, a]
        else
          [c, b, a]
