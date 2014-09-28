--Для типа Graph, разбиравшегося на паре, реализовать алгоритм Дейкстры поиска кратчайшего пути. Поиск пути должен производиться с использованием экземпляров класса типов Monad или MonadPlus


import Data.List
import Control.Monad

data Graph v e = Graph [(Int,v)] [(Int,Int,e)]
        deriving (Show, Eq)

inf = 2 ^ 29 - 1

first (a,b,c) = a
second (a,b,c) = b
third (a,b,c) = c

graphUpd :: Graph v e -> Graph v e
graphUpd (Graph v e) = Graph v (mplus e $ map (\(x,y,z) -> (y,x,z)) e)

buildBase :: (Graph v e) -> Int -> [(Int, Int, Int)]
buildBase (Graph v e) fst' 
        =  (fst$ head $filter (\(x,y) -> x == fst') v, 0 , 0) 
                : map (\(x,y) -> (x,y,fst')) (zip (map (\(x,y) -> x) (filter (\(x,y) -> x /= fst') v)) [inf, inf..]) 

minV :: [Int] -> [(Int, Int, Int)] -> Int
minV visited weights = first $ head $ sortBy (\(x,y,q) (w,z,q')-> compare y z) $filter (\(x,y,z) -> not $ elem x visited) weights

-- w = weight v = visited fst' = cur vertex
recalc :: [(Int,Int,Int)] -> [Int] -> [(Int, Int, Int)] -> Int -> [(Int, Int, Int)]
recalc path v w fst' 
        = recalc' fst' (second $ head (filter (\(x,y,z) -> x == fst') w)) 
                (filter (\(x,y,z) -> x == fst' ) $ filter (\(x,y,z) -> not $elem y v) path) w
        where
         recalc' v add [] w         = w
         recalc' v add (x:path) w   
          = recalc' v add path (map (\(z,y,q) -> if (z == second x && y > (add + third x)) then (z,add + (third x),v) else (z,y,q)) w)

dijkstraAlg :: (Graph v Int) -> Int -> [(Int, Int, Int)]
dijkstraAlg g @(Graph v e) fst' = dijkstraAlg' (graphUpd g) fst' [fst'] (recalc e [fst'] (buildBase g fst') fst')
        where
                dijkstraAlg' (Graph v e) f visited weight 
                        | length v == length visited = weight
                        | otherwise = dijkstraAlg' (Graph v e) f' (f':visited) (recalc e visited weight f')
                        where
                                f' = minV visited weight

searchPath g startV finalV = sP list finalV []
        where
                list = dijkstraAlg g startV
                sP list sV ans | sV == 0 = ans | otherwise = sP list (third $ head $filter (\(x,y,z) -> x == sV) list ) (sV:ans)
                
                
graph :: Graph Char Int
graph = Graph [(1,'a'),(2,'b'),(3,'c'),(4,'d'),(5,'e'),(6,'f')] 
        [(1,3,9),(1,2,7),(1,6,14),(2,3,10),(2,4,15),(6,3,2),(6,5,9),(3,4,11),(5,4,6)]


