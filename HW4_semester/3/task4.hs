--Вывести первую позицию в списке, на которой сумма двух соседних элементов максимальна. Например, для [1, 5, 6, 2] функция должно вернуть значение 2.
import Data.Maybe
import Data.List


findPosition :: [Int] -> Int
findPosition [] = -1
findPosition [_] = -1
findPosition xs = fromJust $ elemIndex (maximum $ sum xs) (sum xs)
        where 
                sum :: [Int] -> [Int]
                sum xs = zipWith (+) xs (0 : xs) 
