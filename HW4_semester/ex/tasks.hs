import Data.List
import Control.Monad

--3 найти индекс заданного эл-та в списке без рекурсии
f3' :: Int -> [Int] -> Maybe Int
f3' x y = elemIndex x y 

f3_1' :: Int -> [Int] -> [(Int, Int)]
f3_1' y x = filter (\x -> (fst x) == y) $zip x [0..((length x) - 1)]

f3_1 :: Int -> [Int] -> Int
f3_1 y x = if length (f3_1' y x) == 0 then -1 else snd ( head (f3_1' y x))

--1 бесконечный список простых чисел
elim :: Integer -> [Integer] -> [Integer]
elim p xs = [x | x <- xs, mod x p /= 0]

sieve :: [Integer] -> [Integer]
sieve (p:xs) = p : sieve (elim p xs)

primeNumbers :: [Integer]
primeNumbers = sieve [2..]

f1 n = take n (1 : primeNumbers)

--4 функция, что возвращает сумма всех эл-в / пр-е косинусов всех эл-в
f4' :: [Double] -> Double -> Double -> Double
f4' [] sum pr = sum / pr
f4' (x:xs) sum pr = f4' xs (sum + x) (pr * (cos x))

f4 :: [Double] -> Double
f4 x = f4' x 0.0 1.0

--2 определить ф-ю, которая по ДДП возвращает список всех эл-в меньших нуля

data Tree a = Leaf a
            | Branch (Tree a) a (Tree a)

searchTree :: (a -> Bool) -> Tree a -> [a]
searchTree condition tree = searchTree' condition tree []
        where
        searchTree' :: (a -> Bool) -> Tree a -> [a] -> [a]
        searchTree' condition (Leaf node) accum = if condition node then node : accum else accum
        searchTree' condition (Branch l_branch node r_branch) accum = if condition node 
                                                                      then node : searchTree'' else searchTree''
                                         where searchTree'' = searchTree' condition r_branch (searchTree' condition l_branch accum)

--переиспользуем код из домашки 4 № 1
f2 :: (Ord a, Num a) => Tree a -> [a]
f2 a = searchTree (\x -> x < 0) a

--5 разработать тип данных для хранения инф. о печатной продукции: книги (название, автор, цена), журналы (название, год, номер выпуска, цена). Функция дожна по списку данных вернуть общую стоимость.

data Printed = Journal { name :: String
                        ,year :: Int
                        ,number :: Int
                        ,price :: Double
                       }
             | Book { title :: String
                     ,author :: String
                     ,price :: Double
                    }
        deriving (Show)

f5 :: [Printed] -> Double
f5 = sum . map (\x -> price x)
