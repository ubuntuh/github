#!/usr/bin/env runhaskell
module Main (main) where

main :: IO ()
main = do
  interact getString
  where
    getString :: String -> String
    getString x = (show . getValue . read) x ++ "\n"
      where
      getValue :: Int -> Int
      getValue x = x ^ 3
