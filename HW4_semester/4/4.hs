--Проверить, что все элемента списка различны
import Data.List (group, sort)

f :: [Int] -> Bool
f a =  length ( group (sort a)) == length a
