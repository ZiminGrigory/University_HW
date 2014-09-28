myAppend :: [a] -> [a] -> [a]
myAppend [] x = x
myAppend (x:xs) y = x:(myAppend xs y)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) x
