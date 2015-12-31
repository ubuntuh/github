#!/usr/bin/env runhaskell
import Data.List
 
putListLn :: Show a => [a] -> IO ()
putListLn = putStrLn . unwords . map show
getList :: Read a => IO [a]
getList = fmap (map read . words) getLine
 
insertionSortWith :: Ord a => (([a], [a]) -> IO b) -> ([a], [a]) -> IO ([a], [a])
insertionSortWith _ (sorted, []) = do
  return (sorted, [])
insertionSortWith f (sorted, n:ns) = do
  let inserted = insert n sorted
  f (inserted, ns)
  insertionSortWith f (inserted, ns)
 
main :: IO ()
main = do
  _ <- getLine
  ns <- getList :: IO [Int]
  insertionSortWithPrint ns
  return ()
  where
    insertionSortWithPrint ns = insertionSortWith (putListLn . concat') ([], ns)
    concat' (l1, l2) = l1++l2
