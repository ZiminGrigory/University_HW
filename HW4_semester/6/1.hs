--Для двоичного дерева, элементы которого – символы, реализовать две функции: одна по дереву строит его представление в виде строки, а вторая функция по этой строке восстанавливает исходное дерево. 

import Data.List
data BinTree a = Empty | Leaf a | Branch (BinTree a) a (BinTree a)
        deriving (Show, Eq)

f1 :: BinTree Char -> String -> String
f1 (Leaf a) ans = 'N':a:'e':'e':ans
f1 (Empty) ans = 'e':ans
f1 (Branch a b c) ans = 'N' : b : (f1 c (f1 a ans))


f2' :: String -> String -> String
f2' (x:xs:l:r:str) ans | (l /= 'N' && r /= 'N') = (ans ++ x:xs:l:r:"") 
                       | l == 'N' = f2' (l:r:str) (ans ++ x:xs:"")
                       | r == 'N' = f2' (r:str) (ans ++ x:xs:l:"")
f2'' :: String -> String
f2'' str = str \\ (f2' str "")

pre_f2 :: String -> BinTree Char
pre_f2 "e" = Empty
pre_f2 (x:xs:l:r:str) = (Branch left xs right) 
        where
                left | l /= 'N' = if l == 'e' then (Empty) else (Leaf l) | otherwise = pre_f2 (f2' (l:r:str) "")
                right | l /= 'N' && r /= 'N' = if r == 'e' then (Empty) else (Leaf r) 
                      | l == 'N' = pre_f2 (f2'' (l:r:str)) | otherwise = pre_f2 (f2' (r:str) "")

simplify :: BinTree Char -> BinTree Char
simplify (Branch l x r) | l == Empty && r == Empty = (Leaf x)
                        | l /= Empty && r /= Empty = Branch (simplify l) x (simplify r)
                        | l /= Empty = Branch (simplify l) x r
                        | r /= Empty = Branch l x (simplify r)

rotate :: BinTree Char -> BinTree Char
rotate (Branch l x r) | (l /= Empty) && (r /= Empty) = Branch (rotate r) x (rotate l)
                      | (l /= Empty) = Branch r x (rotate l)
                      | (r /= Empty) = Branch (rotate r) x l
rotate (Leaf x) = Leaf x

f2 :: String -> BinTree Char
f2 str = rotate $ simplify $pre_f2 str

tree :: BinTree Char
tree = Branch (Branch (Leaf '2') '5' (Branch (Leaf '6') '7' (Empty))) '8' (Leaf '9')
