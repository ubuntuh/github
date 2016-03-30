#!/usr/bin/env runhaskell
main = do
  interact $ getString . read
  where
    getString :: Int -> String
    getString x = show h ++ ":" ++ show m ++ ":" ++ show s ++ "\n"
      where
      h = div x (60 * 60)
      m = div (mod x (60 * 60)) 60
      s = mod x 60
