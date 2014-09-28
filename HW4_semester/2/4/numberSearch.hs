numberSearch :: Int -> [Int] -> Int
numberSearch _ [] = -1
numberSearch n (x:xs)
        | (x == n)      = 0
        | (xs == [])    = -1
        | otherwise     = 1 + numberSearch n xs
