-- Записать следующую функцию в point-free стиле: func x l = map (\y -> y*x) l.

--func x l = map (\y -> y*x) l
--func1 x = map (\y -> y*x)
--func2 x = map (* x)
--func4 x = (map . (*)) x

func = map . (*)
