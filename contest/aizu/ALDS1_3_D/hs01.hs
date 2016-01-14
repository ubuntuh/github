#!/usr/bin/env runhaskell
data Pond = Pond Int Int Int deriving Show
main = do
  interact (unlines . getStrings)
  where
    getStrings :: String -> [String]
    getStrings xs = [line1, line2]
      where
      line1 = show total
      line2
        | numPonds == 0 = show numPonds
        | otherwise = show numPonds ++ " " ++ (unwords $ map show pondSizes)
      (total, ponds) = getTotal xs 0 [] 0 []
        where
        getTotal :: String -> Int -> [Int] -> Int -> [Pond] -> (Int, [Pond])
        getTotal [] _ _ total ponds = (total, reverse ponds)
        getTotal (x:xs) position stack total ponds
          | x == '\\' = getTotal xs (position + 1) (position : stack) total ponds
          | x == '/' =
            if stack == [] then
              getTotal xs (position + 1) stack total ponds
            else
              getTotal xs (position + 1) ys (total + size) (pond : ponds)
          | otherwise = getTotal xs (position + 1) stack total ponds
          where
            (y:ys) = stack
            size = position - y
            pond = Pond y position size
      reducedPonds = getReducedPonds ponds []
        where
        getReducedPonds :: [Pond] -> [Pond] -> [Pond]
        getReducedPonds [] stack = reverse stack
        getReducedPonds (x:xs) [] = getReducedPonds xs [x]
        getReducedPonds (x:xs) (y:ys)
          | end1 < start2 = getReducedPonds xs (x:y:ys)
          | otherwise = getReducedPonds (sumPond:xs) ys
          where
          Pond start1 end1 size1 = y
          Pond start2 end2 size2 = x
          sumPond = Pond start2 end2 (size1 + size2)
      numPonds = length reducedPonds
      pondSizes = map getSize reducedPonds
        where
        getSize (Pond _ _ size) = size
