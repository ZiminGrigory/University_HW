--Посчитать высоту дерева, а также минимальное расстояние в дереве от корня до листьев.

data BinTree a = Leaf a 
                | Branch (BinTree a) (BinTree a)

minDepth :: BinTree a -> Int
minDepth (Leaf a) = 0
minDepth (Branch l_branch r_branch) = 1 + min (minDepth l_branch) (minDepth r_branch) 

depth :: BinTree a -> Int
depth (Leaf a) = 0
depth (Branch l_branch r_branch) = 1 + max (depth l_branch) (depth r_branch)

