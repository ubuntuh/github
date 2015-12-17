#!/usr/bin/env runhaskell
module Main (main) where
import qualified Data.Char
import qualified Debug.Trace
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
  f10
  f11
  f12
  f13
  f14
  f15
  f16

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

f10 :: IO ()
f10 = do
  print [1, 2, 3, 4, 5]
  print $ [1, 2, 3, 4, 5] !! 3
  print [1..5]
  print $ [1, 2, 3] ++ [4, 5]
  print $ 1 : [2..5]
  print $ 1 : 2 : [3..5]
  print $ [1..4] ++ [5]
  print $ "abcde"
  print $ ['a', 'b', 'c', 'd', 'e']
  print $ ['a'..'e']
  print $ 'a' : "bcde"
  print $ 'a' : 'b' : "cde"
  print $ "abc" ++ "de"
  print $ "abcde" !! 3
  print $ getFirst [1..5]
  print $ getFirst "abcdef"
  print $ getSecond [1..5]
  print $ getSecond "abcdef"
  where
    getFirst (x : xs) = x
    getSecond (_ : x : _) = x

f11 :: IO ()
f11 = do
  print $ length [1, 2, 3]
  print $ sum [1..5]
  print $ product [1..5]
  print $ take 2 [1, 2, 3]
  print $ drop 2 [1, 2, 3]
  print $ reverse [1..5]
  print $ getLength [1, 2, 3]
  print $ getSum [1..5]
  print $ getProduct [1..5]
  print $ take''' 2 [1, 2, 3]
  print $ drop''' 2 [1, 2, 3]
  print $ reverse''' [1..5]
  print $ reverse'''' [1..5]
  print $ fact''' 5
  where
    getLength [] = 0
    getLength (_:xs) = 1 + getLength xs
    getSum [x] = x
    getSum (x:xs) = x + getSum xs
    getProduct [x] = x
    getProduct (x:xs) = x * getProduct xs
    take''' 0 _ = []
    take''' y (x:xs)
      | 1 <= y  = x : take''' (y - 1) xs
    drop''' 0 xs = xs
    drop''' y (x:xs)
      | 1 <= y = drop''' (y - 1) xs
    reverse''' [] = []
    reverse''' (x:xs) = reverse''' xs ++ [x]
    reverse'''' xs = f xs []
      where
        -- 1 つ目のリストの最初の要素を取り外して 2 つ目のリストの先頭に追加するような動作をする関数です。
        f :: [a] -> [a] -> [a]
        f [] ys = ys
        f (x:xs) ys = f xs (x:ys)
    fact''' x
      | 1 <= x = product [1..x]

f12 :: IO ()
f12 = do
  print $ addsub 1 2
  print v0
  print v1
  let
    p0 = (1, 2)
  print $ fst p0
  print $ snd p0
  let
    p3 = (1, 2, 3)
  print p3
  let
    (_, _, p3z) = p3
  print p3z
  print $ perpPoint 0 2 1 (-1) 0
  print $ perpPoint' (0, 2) (1, -1, 0)
  where
    addsub x y = (x + y, x - y)
    (v0, v1) = addsub 1 2
    -- 点 (p, q) から直線 ax + bx + c に下した垂線の交点。
    -- perp = perpendicular （垂線）?
    perpPoint p q a b c = (x, y)
      where
        c2OnB2 = q - (b / a) * p
        x = (-c2OnB2 + c / b) * (a * b) / (a * a + b * b)
        y = - a / b * x + c / b
    -- 正解。
    perpPoint' (p, q) (a, b, c) = (x, y)
      where
        x = (a * c + b * d) / (a * a + b * b)
        y = (b * c - a * d) / (a * a + b * b)
        d = b * p - a * q

f13 :: IO ()
f13 = do
  print $ Data.Char.ord 'A'
  print $ Data.Char.chr 65
  print $ rot13 "HELLOWORLD"
  print $ rot13' "Hello, World!"
  print $ rot13'' "Hello, World!"
  where
    rot13 :: [Char] -> [Char]
    rot13 [] = []
    rot13 (x:xs) = rot13Char x : rot13 xs
    rot13Char :: Char -> Char
    rot13Char x = Data.Char.chr num1
      where
        num0 = Data.Char.ord x - Data.Char.ord 'A'
        num1 = rot13Num num0 + Data.Char.ord 'A'
    rot13Num :: Int -> Int
    rot13Num x = mod (x + 13) 26
    -- 正解。
    rot13' "" = ""
    rot13' (x:xs) = rot13ch' x : rot13' xs
    rot13ch' ch
      | 'A' <= ch && ch <= 'M' || 'a' <= ch && ch <= 'm'
        = Data.Char.chr $ Data.Char.ord ch + 13
      | 'N' <= ch && ch <= 'Z' || 'n' <= ch && ch <= 'z'
        = Data.Char.chr $ Data.Char.ord ch - 13
      | otherwise = ch
    --
    rot13'' :: [Char] -> [Char]
    rot13'' [] = []
    rot13'' (x:xs) = rot13Char'' x : rot13'' xs
     where
      rot13Char'' :: Char -> Char
      rot13Char'' x
        | 'A' <= x && x <= 'Z' = rot13Capital'' x
        | 'a' <= x && x <= 'z' = rot13Small'' x
        | otherwise = x
       where
        rot13Capital'' :: Char -> Char
        rot13Capital'' x = rot13CharOffset'' 'A' x
        rot13Small'' :: Char -> Char
        rot13Small'' x = rot13CharOffset'' 'a' x
        rot13CharOffset'' :: Char -> Char -> Char
        rot13CharOffset'' offset x = char0
         where
          num0 = Data.Char.ord x - Data.Char.ord offset
          num1 = rot13Num'' num0
          char0 = Data.Char.chr $ num1 + Data.Char.ord offset
          rot13Num'' x = mod (x + 13) 26

f14 :: IO ()
f14 = do
  print $ isort [4, 6, 9, 8, 3, 5, 1, 7, 2]
  where
    isort [] = []
    isort (x:xs) = insert x (isort xs)
     where
      insert x [] = [x]
      insert x (y:ys)
        | x < y = x : y : ys
        | otherwise = y : insert x ys

f15 :: IO ()
f15 = do
  Debug.Trace.traceIO $ show $ test 5
  where
    test x = Debug.Trace.trace ("test " ++ show x) x

f16 :: IO ()
f16 = do
  Debug.Trace.traceIO $ show $ isort [4, 6, 9, 8, 3, 5, 1, 7, 2]
  where
    insert x [] = [x]
    insert x (y:ys)
      | x < y = x : y : ys
      | otherwise = y : insert x ys
    isort [] = []
    isort (x:xs) = Debug.Trace.trace dbg1 $ Debug.Trace.trace dbg2 ret
     where
      ret = insert x xs'
      xs' = isort xs
      dbg1 = "isort " ++ show (x:xs) ++ " = " ++
             "insert " ++ show x ++
             " (isort " ++ show xs ++ ")"
      dbg2 = "insert " ++ show x ++ "," ++ show xs' ++
             " = " ++ show ret



