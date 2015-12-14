#!/usr/bin/env runhaskell
module Main (main) where
main :: IO ()
main = do
  f00
  f01
  f02
  f03
  f04
  f05
  f06
  f07
  f08
  f09

f00 :: IO ()
f00 = print "f00"

f01 :: IO ()
f01 = do
  print "f01"

v0 = 1
v1 = 2
v2 = v0 + v1

f02 :: IO ()
f02 = do
  print v2

f03 :: IO ()
f03 = do
  print v2
  where
    v0 = 10
    v1 = 20
    v2 = v0 + v1

f04 :: IO ()
f04 = do
  let
    v0 = 100
    v1 = 200
    v2 = v0 + v1
  print v2

f05 :: IO ()
f05 = do
  print v0
  print (f0 200)
  print $ f0 300
  where
    v0 = f0 100
    f0 x = x + 1

f06 :: IO ()
f06 = do
  print $ add 1 2
  print $ 3 `add` 4
  print $ 1 ++++ 2
  print $ (++++) 3 4
  where
    add x y = 10 * x + 100 * y
    (++++) x y = 1000 * x + 10000 * y

f07 :: IO ()
f07 = do
  print $ 5 + 2
  print $ 5 - 2
  print $ 5 * 2
  print $ 5 / 2
  print $ div 5 2
  print $ mod 5 2
  print $ 5 `div` 2
  print $ 5 `mod` 2

f08 :: IO ()
f08 = do
  if v0 == 1
    then do
      print "1"
      print "11"
    else do
      print "?"
      print "??"
  print $ f 0
  print $ f 1
  print $ getFactorial 5
  print $ getFactorial2 6
  -- print $ getFactorial3 (-1)
  print $ getFactorial4 7
  where
    v0 = 1
    f 1 = "1"
    f _ = "?"
    getFactorial 0 = 1
    getFactorial x = x * getFactorial (x - 1)
    getFactorial2 x
      | x == 0 = 1
      | otherwise = x * getFactorial2 (x - 1)
    getFactorial3 0 = 1
    getFactorial3 x
      | 0 < x = x * getFactorial3 (x - 1)
    getFactorial4 x = case x of
      0 -> 1
      _
        | 0 < x -> x * getFactorial4 (x - 1)

f09 :: IO ()
f09 = do
  print $ fib1 9
  print $ fib2 9
  print $ fib3 9
  where
    fib1 1 = 0
    fib1 2 = 1
    fib1 x = (fib1 (x - 2)) + (fib1 (x - 1))
    fib2 x
      | x == 1 = 0
      | x == 2 = 1
      | 3 <= x = (fib2 (x - 2)) + (fib2 (x - 1))
    fib3 x = case x of
      1 -> 0
      2 -> 1
      _
        | 3 <= x -> (fib3 (x - 2)) + (fib3 (x - 1))

