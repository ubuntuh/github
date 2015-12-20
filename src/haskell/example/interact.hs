#!/usr/bin/env runhaskell
module Main (main) where
main :: IO ()
main = do
  interact getString
  where
    getString :: String -> String
    getString x = (unlines . getLines . lines) x ++ "(::input)"
      where
      getLines :: [String] -> [String]
      getLines [] = []
      getLines (x:xs) = ((unwords . getWords . words) x ++ "(::line)") : getLines xs
        where
        getWords :: [String] -> [String]
        getWords [] = []
        getWords (x:xs) = (addOne x ++ "(::word)") : getWords xs
          where
          addOne :: String -> String
          addOne x = show ((read x :: Int) + 1)
