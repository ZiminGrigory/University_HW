--Реализовать тип данных BinarySearchTree и соответствующие функции для работы с ним: добавление, удаление, поиск, размер (число элементов), высота

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show, Eq)
------
insert :: (Ord a) => a -> Tree a -> Tree a
insert x Empty = Node Empty x Empty
insert x this @(Node left a right)
        | x == a = this
        | x <  a = (Node (insert x left) a right)
        | x >  a = (Node left a (insert x right))

------

remove :: (Ord a) => a -> Tree a -> Tree a
remove x Empty = Empty
remove x this @(Node left k right)
        | x == k = removeTree this
        | x < k  = Node (remove x left) k right
        | x > k  = Node left k (remove x right)

removeTree :: (Ord a) => Tree a -> Tree a
removeTree (Node Empty _ right) = right
removeTree (Node left _ Empty)  = left
removeTree (Node left _ right)  = (Node left k' (remove k' right))
        where k' = minElem right

minElem :: (Ord a) => Tree a -> a
minElem (Node Empty k _) = k
minElem (Node left _ _)  = minElem left

-----
    
findElem :: (Ord a) => a -> Tree a -> Bool
findElem x_ Empty = False
findElem x (Node left k right)
        | k == x = True
        | k > x  = findElem x left
        | k < x  = findElem x right

------

height :: (Num a, Ord a) => Tree a -> Int
height Empty        = -1
height (Node l _ r) = 1 + (max (height l) (height r))

------

treeToList :: (Ord a) => Tree a -> [a]
treeToList Empty        = []
treeToList (Node l k r) = treeToList l ++ [k] ++ treeToList r

size :: (Ord a) => Tree a -> Int
size tree = length $ treeToList tree
