digits :: Int -> [Int]
digits 0 = []
digits n = r:(digits k)
    where k = div n 10; r = mod n 10

sumOfNumbers n = foldr (+) 0 (digits (abs(n)))

