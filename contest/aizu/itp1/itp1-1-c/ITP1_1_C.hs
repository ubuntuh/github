#!/usr/bin/env runhaskell
module Main (main) where

main :: IO ()
main = do
  interact getString
  where
    getString :: String -> String
    getString x = (unwords . getWords . words) x ++ "\n"
      where
      getWords :: [String] -> [String]
      getWords x = (map show . getInts . map read) x
        where
        getInts :: [Int] -> [Int]
        getInts (width : height : []) = area : perimeter : []
          where
          rectangle = Rectangle width height
          area = getArea rectangle
          perimeter = getPerimeter rectangle

class HasArea a where
  getArea :: a -> Int
class HasPerimeter a where
  getPerimeter :: a -> Int
data Rectangle = Rectangle Int Int
instance HasArea Rectangle where
  getArea (Rectangle width height) = width * height
instance HasPerimeter Rectangle where
  getPerimeter (Rectangle width height) = 2 * (width + height)
