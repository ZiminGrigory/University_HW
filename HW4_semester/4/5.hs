--Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:
--0 - exit
--1 - add value to sorted list
--2 - remove value from list
--3 - print list
--Все операции должны сохранять сортированность. Начинаем с пустого списка.
import Data.List 

doLoop :: [Int] -> IO ()
doLoop list = 
    putStr "\n Enter the number of command: \n" >>
    putStr "0 - exit \n" >>
    putStr "1Elem - add value to sorted list \n" >>
    putStr "2Elem - remove value from list \n" >>
    putStr "3 - print list \n> " >>
    getLine >>= 
    \command -> case command of
        '0':_ -> putStrLn "Bye-bye" 
        '1':elem -> doLoop (insert (read elem :: Int) list)
        '2':elem -> doLoop (insert (read elem :: Int) list)
        '3':_ -> putStrLn (show list) >>
                 doLoop list
        _     -> doLoop list

main = doLoop []
