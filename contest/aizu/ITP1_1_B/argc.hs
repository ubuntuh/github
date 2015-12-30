#!/usr/bin/env runhaskell
module Main (main) where
import qualified System.Environment

main :: IO ()
main = do
  args <- System.Environment.getArgs
  putStrLn ("argc: " ++ (show . length) args)
  putStr (getString args 1)
  where
    getString :: [String] -> Int -> String
    getString [] _ = ""
    getString (x:xs) acc = "argv #" ++ show acc ++ ": " ++ x ++ "\n" ++ getString xs (acc + 1)
