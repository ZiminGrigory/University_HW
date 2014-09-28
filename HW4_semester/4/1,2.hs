--Реализовать функцию поиска по некоторому условию в двоичном дереве. Условие передается в качестве параметра.

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

--Реализовать функцию свертки для бинарного дерева.

mFoldr :: (Eq a) => (a -> b -> b) -> b -> Tree a -> b
mFoldr f acc tree = foldr f acc $ searchTree (\x -> x == x) tree

mFoldl :: (Eq b) => (a -> b -> a) -> a -> Tree b -> a
mFoldl f acc tree = foldl f acc $ searchTree (\x -> x == x) tree



