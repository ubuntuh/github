#!/usr/bin/env runhaskell
module Main (main) where

main :: IO ()
main = do
  interact getString
  where
    getString :: String -> String
    getString x = "Hello World\n"
