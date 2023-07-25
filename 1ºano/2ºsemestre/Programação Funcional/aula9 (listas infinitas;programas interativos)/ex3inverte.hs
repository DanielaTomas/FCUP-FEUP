module Main where

inverter :: String -> [String]
inverter s = map reverse (lines s)

printlista :: [String] -> IO()
printlista [] = return()
printlista (x:xs) = do
                    putStrLn x
                    printlista xs

main :: IO()
main = do
    linha <- getContents
    printlista (inverter linha)
